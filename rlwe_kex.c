/* This is free and unencumbered software released into the public domain.
 *
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 *
 * See LICENSE for complete information.
 */

#if !defined(RLWE_RANDOMNESS_USE_OPENSSL_AES) && !defined(RLWE_RANDOMNESS_USE_OPENSSL_RC4) && !defined(RLWE_RANDOMNESS_USE_OPENSSL_RAND) && !defined(RLWE_RANDOMNESS_USE_C_RANDOM_INSECURE)
	#warning "No PRNG specified. Using OpenSSL AES";
	#define RLWE_RANDOMNESS_USE_OPENSSL_AES
#endif

#include "rlwe_kex.h"

#if defined(RLWE_RANDOMNESS_USE_OPENSSL_AES)
#include "rlwe_rand_openssl_aes.c"
#elif defined(RLWE_RANDOMNESS_USE_OPENSSL_RC4)
#include "rlwe_rand_openssl_rc4.c"
#elif defined(RLWE_RANDOMNESS_USE_OPENSSL_RAND)
#include "rlwe_rand_openssl_rand.c"
#elif defined(RLWE_RANDOMNESS_USE_C_RANDOM_INSECURE)
#include "rlwe_rand_c.c"
#else
#error "No randomness generation algorithm defined."
#endif


#ifdef UNIFORM

#if defined GAUSSIAN || defined GAUSSIAN_CT || defined BINOMIAL
	#error "Must compile with one of -DGAUSSIAN, -DGAUSSIAN_CT, -DUNIFORM, or -DBINOMIAL"
#endif


/*
Sample the secret key. Each coefficient uniform in [-B,B].
Set the m'th coefficient to be 0 if m is prime.
*/
void sample_secret(RINGELT s[m]) {
	RANDOM_VARS;
	uint16_t i = 0;
	uint64_t r = RANDOM64;
	uint64_t l, shifts = 0;

#if MISPOWEROFTWO
	while (i < m) {
#else
	while (i < m-1) {
#endif	
		l = r & BMASK;
		if (l < BB) {
		/*Take this sample*/
			s[i] = small_coeff_table[l];
			i++;
		}
		/*Shift r along and continue*/
		shifts++;
		if (shifts * LOG2B >= 64) {
			/*Need a new random value*/
			r = RANDOM64;
			shifts = 0;
		}
		else r = (r >> LOG2B);
	}		
#if !MISPOWEROFTWO
	s[m-1] = 0;
#endif	
}

#endif //UNIFORM

#if defined GAUSSIAN || defined GAUSSIAN_CT

#if defined UNIFORM || defined BINOMIAL
	#error "Must compile with one of -DGAUSSIAN, -DGAUSSIAN_CT, -DUNIFORM, or -DBINOMIAL"
#endif


#define setbit(a,x) ((a)[(x)/64] |= (((uint64_t) 1) << (uint64_t) ((x)%64)))
#define getbit(a,x) (((a)[(x)/64] >> (uint64_t) ((x)%64)) & 1)
#define clearbit(a,x) ((a)[(x)/64] &= ((~((uint64_t) 0)) - (((uint64_t) 1) << (uint64_t) ((x)%64))))
#include "rlwe_table.h"
#define RANDOM192(c) c[0] = RANDOM64; c[1] = RANDOM64; c[2] = RANDOM64


/* Auxiliary functions for constant-time comparison */

/*
 * Returns 1 if x != 0
 * Returns 0 if x == 0
 * x and y are arbitrary unsigned 64-bit integers
 */
static uint64_t ct_isnonzero_u64(uint64_t x) {
    return (x|-x) >> 63;
}

/*
 * Returns 1 if x != y
 * Returns 0 if x == y
 * x and y are arbitrary unsigned 64-bit integers
 */
static uint64_t ct_ne_u64(uint64_t x, uint64_t y) {
    return ((x-y)|(y-x)) >> 63;
}

/*
 * Returns 1 if x == y
 * Returns 0 if x != y
 * x and y are arbitrary unsigned 64-bit integers
 */
#ifdef GAUSSIAN_CT
static uint64_t ct_eq_u64(uint64_t x, uint64_t y) {
	return 1 ^ ct_ne_u64(x, y);
}
#endif
/* Returns 1 if x < y
 * Returns 0 if x >= y
 * x and y are arbitrary unsigned 64-bit integers
 */
static uint64_t ct_lt_u64(uint64_t x, uint64_t y) {
	return (x^((x^y)|((x-y)^y))) >> 63;
}


/* Returns 0xFFFF..FFFF if bit != 0
 * Returns            0 if bit == 0
 */
static uint64_t ct_mask_u64(uint64_t bit)
{
	return 0 - (uint64_t)ct_isnonzero_u64(bit);
}

/* Conditionally return x or y depending on whether bit is set
 * Equivalent to: return bit ? x : y
 * x and y are arbitrary 64-bit unsigned integers
 * bit must be either 0 or 1.
 */
#ifdef GAUSSIAN_CT
static uint64_t ct_select_u64(uint64_t x, uint64_t y, uint64_t bit) {
	uint64_t _m = ct_mask_u64(bit);
	return (x&_m) | (y&~_m);
}
#endif
/* Returns 0 if a >= b
 * Returns 1 if a < b
 * Where a and b are both 3-limb 64-bit integers.
 * This function runs in constant time.
 */
static int cmplt_ct(uint64_t *a, uint64_t *b) {

	uint64_t r = 0; /* result */
	uint64_t _m = 0; /* mask   */
	int i;
	for(i = 2; i >= 0; i--) {
		r |= ct_lt_u64(a[i], b[i]) & ~_m;
		_m |= ct_mask_u64(ct_ne_u64(a[i], b[i])); /* stop when a[i] != b[i] */
	}
	return r & 1;
}

#ifdef GAUSSIAN
static uint32_t single_sample(uint64_t *in) {
	uint32_t lower_index = 0, this_index = 32, upper_index = 64;
	int i;
	for (i = 0; i <= 6; i++) {
		if (cmplt_ct(in, rlwe_table[this_index])) {
			upper_index = this_index;
		} else {
			lower_index = this_index;
		}
		this_index = (lower_index + upper_index) / 2;		
	}
	return upper_index;
}
#endif

/* Constant time version. */
#ifdef GAUSSIAN_CT
static uint32_t single_sample_ct(uint64_t *in) {
	uint32_t index = 0, i;
	int c, flag = 1;
	for (i = 0; i < 52; i++) {
		c = cmplt_ct(in, rlwe_table[i]);
		index = ct_select_u64(i, index,  c & flag);		
		flag &= (1-c);
	}
	return index;
}
#endif

#ifdef GAUSSIAN_CT
void sample_secret(RINGELT s[m]) {
	RANDOM_VARS
	int ind = 0;
	uint64_t r = 0, rnd[3];
	ind = 0;
#if MISPOWEROFTWO
	while (ind < m) {
#else
	while (ind < m-1) {
#endif	
		if (!(ind&0x3F)) r = RANDOM64;
		RANDOM192(rnd);		
		s[ind] = single_sample_ct(rnd);
		RINGELT t = q - s[ind];
		s[ind] = ct_select_u64(t, s[ind], ct_eq_u64(r&1, 1) & ct_ne_u64(s[ind], 0));
		r >>= 1;
		ind++;		
	}
#if !MISPOWEROFTWO
	s[m-1] = 0;
#endif
}

#else

/*Set the m'th coefficient to be 0 in the prime case*/
void sample_secret(RINGELT s[m]) {
	RANDOM_VARS
	int ind = 0;
	uint64_t r = 0, rnd[3];
	ind = 0;
#if MISPOWEROFTWO
	while (ind < m) {
#else
	while (ind < m-1) {
#endif	
		if (!(ind&0x3F)) r = RANDOM64;
		RANDOM192(rnd);		
		s[ind] = single_sample(rnd);
		if (s[ind] > 0 && r&1) {
			s[ind] = q - s[ind];
		}		
		r >>= 1;
		ind++;		
	}
#if !MISPOWEROFTWO
	s[m-1] = 0;
#endif
}

#endif //CONSTANT TIME

#endif //GAUSSIAN


#ifdef BINOMIAL
#if defined UNIFORM || defined GAUSSIAN
	#error "Must compile with one of -DGAUSSIAN, -DGAUSSIAN_CT, -DUNIFORM, or -DBINOMIAL"
#endif

/*Set the m'th coefficient to be 0 in the prime case*/
void sample_secret(RINGELT s[m]) {
	RANDOM_VARS
	int ind = 0, j, v;
	uint64_t r, b = 0;
	int bit0, bit1;
	ind = 0;
	r = RANDOM64;
#if MISPOWEROFTWO
	while (ind < m) {
#else
	while (ind < m-1) {
#endif	
		v = 0;
		for (j = 0; j < BINOMK; ++j) {
			if (b == 64) {
				b = 0; r = RANDOM64;
			}
			bit0 = (r & 1);
			r >>= 1;
			bit1 = (r & 1);
			r >>= 1;
			b += 2;
			v += (bit1 - bit0);
		}	
		if (v >= 0) s[ind] = (RINGELT) v;
		else {
			s[ind] = (RINGELT) (q + v);
		}		
		ind++;		
	}
#if !MISPOWEROFTWO
	s[m-1] = 0;
#endif
}

#endif //BINOMIAL


#ifdef NHRECONCILE

/* Newhope-style reconciliation. Returns keybit of x given the subcell.
   Entries of x are coefficients in range [0,q-1] */
int nh_keycell(RINGELT x[rdim], uint16_t subcell[rdim]){
	const uint16_t rmaskplus = (1<<(rsize+1))-1;
	uint32_t Br[rdim], dist = 0;
	int j;
	int keybit=0;

	// work mod q*2*2**rsize (8q)
	// subcell is mod 2**rsize (4), so scale up by 2 for now
	for(j=0;j<rdim-1;j++)
		Br[j] = ( (subcell[j]<<1) + subcell[rdim-1]  ) & rmaskplus;
	Br[rdim-1] = subcell[rdim-1];

	for(j=0;j<rdim;j++){
	        uint32_t quo, diff;
		uint32_t xx=x[j]; // must hold up to q*(2+1)*2**rsize
		// xx is mod q, scale up to mod q*2*2**rsize
		xx <<= rsize + 1;
		// subtract helper
		xx +=  q * ( ( 1 << (rsize+1) ) - Br[j] );
		// find difference to nearest multiple of q*2*2**rsize (8q)

		/* ********************************** */
		/* function of xx in range [0,(q<<(rsize+1))-1], output is diff in range [0,(q<<rsize)-1] */
		quo = ( xx + (q<<rsize) ) / (q<<(rsize+1));
		diff = ( xx > (quo*(q<<(rsize+1))) ) ? ( xx - (quo*(q<<(rsize+1))) ) : ( (quo*(q<<(rsize+1))) - xx ); // scaled by 8q to range [0,4q]
       
		dist += diff;

        }

	// dist is scaled by rdim*q*2**rsize/2 (8q)
	if(dist > (rdim*(q<<(rsize-1))) ){ // key bit 1
	        keybit = 1;
        } 

	return keybit;
}

/* Newhope-style reconciliation. Reconcile v using helprec data. */
void rec(uint64_t key[muwords], const RINGELT v[m], const uint64_t helprec[recwords]) {
	int i = 0;
	const uint16_t rmask = (1<<rsize)-1;
	int word = 0, pos = 0;

	memset((void *) key, 0, muwords*sizeof(uint64_t));
  
	for(i=0;i<muwords*64;i++) {
	        // extract helprec vector
	        RINGELT x[rdim];
		int j;
		uint16_t subcell[rdim];
		int keybit;

		// extract rdim coeffs
		for(j=0;j<rdim;j++)
			x[j]=v[i+j*muwords*64];

		// unpack subcell from helprec
		for(j=0;j<rdim;j++) {
	                subcell[j] = ( helprec[word] >> pos ) & rmask;
			pos += rsize;
			if ( pos > 64){
	                        word++; pos -=64;
				subcell[j] |= ( helprec[word] << ( rsize - pos ) ) & rmask;
                        }
			if(pos == 64) {
	                        word++; pos = 0;
                        }
                 }
	  
		keybit = nh_keycell(x, subcell);

		key[ i >> 6 ] |= ((uint64_t)keybit) << ( i & 0x3f );

	}
}


/* Newhope-style reconciliation. Computes subcell of x and returns its keybit.
   Entries of x are coefficients that have been doubled and edge-blurred, they are in range [0,2q-1]
   Entries of subcell are computed in range [0,2**rsize-1] */
int nh_subcell(uint16_t subcell[rdim], RINGELT x[rdim]){
	const uint16_t rmask = (1<<rsize)-1;
	uint16_t v0[rdim], v1[rdim];
	uint32_t dist = 0;
	int j;
	int keybit;
	
	for(j=0;j<rdim;j++){
		uint32_t quo, diff;
		uint32_t xx=x[j];
		// CVP: work mod q*2*2**rsize

		/* ******************************************* */
		/* function of xx, output (diff,v0[j],v1[j]) */
		xx <<= rsize;
		// xx is in range [0,(2q-1)*2**rsize], take mod difference to nearest multiple of 2q
		// and output this if 1-norm is less than 1, otherwise output nearest multiple at offset q
		// so for rsize=2: range is [0,8q-4]
		quo = xx / q; // divides into eigths (2*2**rsize)
		v0[j] = (quo+1)>>1; // [0,4] ([0,2**rsize]) remember to mod 4 (2**rsize) later
		diff = ( xx > v0[j]*(q<<1) ) ? ( xx - v0[j]*(q<<1) ) : ( v0[j]*(q<<1) - xx ); // scaled by 2q to range [0,q]
		v0[j] &= rmask; // [0,3]
		v1[j] = quo>>1; // [0,3]
		v1[j] &= rmask; // [0,3]
		/* ******************************************* */
	  
		dist += diff;
	}

	// dist is scaled by rdim*q/2
	if(dist < ( (rdim*q+1) >> 1 ) ){ // v0 closest
		for(j=0;j<rdim-1;j++)
			subcell[j] = ( v0[j] - v0[rdim-1] ) & rmask;
		keybit = v0[rdim-1] >> ( rsize - 1 );
		subcell[rdim-1] = ( v0[rdim-1] << 1 ) & rmask;
	}
	else{ // v1 closest
		for(j=0;j<rdim-1;j++)
			subcell[j] = ( v1[j] - v1[rdim-1] ) & rmask;
		keybit = v1[rdim-1] >> ( rsize - 1 );
		subcell[rdim-1] = ( 1 + ( v1[rdim-1] << 1 ) ) & rmask;
	}
	  
	return keybit;
}

/* Newhope-style reconciliation. Computer helprec data and key for v */
void help_rec(uint64_t key[muwords], uint64_t helprec[recwords], const RINGELT v[m]) {
	RANDOM_VARS;
	int i = 0;
	uint64_t rnd = RANDOM64;
	int word = 0, pos = 0, rbit = 0;

	memset((void *) key, 0, muwords*sizeof(uint64_t));
	memset((void *) helprec, 0, recwords*sizeof(uint64_t));

	for(i=0;i<muwords*64;i++){
		RINGELT x[rdim];
		int j;
		uint16_t subcell[rdim];
		int keybit;

		// extract rdim coeffs
		for(j=0;j<rdim;j++)
			x[j]=v[i+j*muwords*64];

		for(j=0;j<rdim;j++){
			// double
			x[j] <<= 1;
		}
		// add 1 w.p. 1/2
		if (rnd & 1) {
			for(j=0;j<rdim;j++) {
				x[j] += 1;
			}
		}
		rbit++;
		if (rbit >= 64) {
			rnd = RANDOM64; rbit = 0;
		}
		else rnd = (rnd >> 1);
	  
		keybit = nh_subcell(subcell,x);

		// pack subcell into helprec
		for(j=0;j<rdim;j++) {
			helprec[word] |=  ( (uint64_t) subcell[j] ) << pos;
			pos += rsize;
			if ( pos > 64){
				word++; pos -=64;
				helprec[word] |= subcell[j] >> ( rsize - pos );
			}
			if(pos == 64) {
				word++; pos = 0;
			}
		}

		// pack keybit into key
		key[ i >> 6 ] |= ((uint64_t)keybit) << ( i & 0x3f );

	}	    
}

#else // NHRECONCILE

/* Peikert-style Round and cross-round */
void help_rec(uint64_t modular_rnd[muwords], uint64_t cross_rnd[recwords], const RINGELT v[m]) {
	RANDOM_VARS;
	uint16_t i = 0;
	uint64_t r = RANDOM64;
	RINGELT word = 0, pos = 0, rbit = 0, val;

	memset((void *) modular_rnd, 0, muwords*sizeof(uint64_t));
	memset((void *) cross_rnd, 0, muwords*sizeof(uint64_t));

#if MISPOWEROFTWO
	for (i = 0; i < m; ++i) {
#else	
	for (i = 0; i < m - 1; ++i) {
#endif	
		val = v[i];
		/*Randomize rounding procedure - probabilistic nudge*/
		if (qmod4 == 1) {
			if (val == 0) {
				if (r & 1) val = (q-1);
				rbit++;
				if (rbit >= 64) {
					r = RANDOM64; rbit = 0;
				}
				else r = (r >> 1);
			}
			else if (val == q_1_4-1) {
				if (r & 1) val = q_1_4;
				rbit++;
				if (rbit >= 64) {
					r = RANDOM64; rbit = 0;
				}
				else r = (r >> 1);
			}
		}
		else {
			if (val == 0) {
				if (r & 1) val = (q-1);
				rbit++;
				if (rbit >= 64) {
					r = RANDOM64; rbit = 0;
				}
				else r = (r >> 1);
			}
			else if (val == q_3_4-1) {
				if (r & 1) val = q_3_4;
				rbit++;
				if (rbit >= 64) {
					r = RANDOM64; rbit = 0;
				}
				else r = (r >> 1);
			}
		}

		/*Modular rounding process*/
		if (val > q_1_4 && val < q_3_4) modular_rnd[word] |= (1UL << pos);

		/*Cross Rounding process*/
		if ((val > q_1_4 && val <= q_2_4) || val >= q_3_4) cross_rnd[word] |= (1UL << pos);
		
		pos++;
		if (pos == 64) {
			word++; pos = 0;
		}

	}


}


/* Peikert-style Reconcile */ 
void rec(uint64_t r[muwords], const RINGELT w[m], const uint64_t b[recwords]) {
	RINGELT i = 0;
	RINGELT word = 0, pos = 0;

	memset((void *) r, 0, muwords*sizeof(uint64_t));

#if MISPOWEROFTWO
	for (i = 0; i < m; ++i) {
#else	
	for (i = 0; i < m - 1; ++i) {
#endif	
		if ((b[word] >> pos) & 1UL) {
			if (w[i] > r1_l && w[i] < r1_u) r[word] |= (1UL << pos);
		}
		else {
			if (w[i] > r0_l && w[i] < r0_u) r[word] |= (1UL << pos);
		}
		pos++;
		if (pos == 64) {
			word++; pos = 0;
		}
	}
}

#endif // NHRECONCILE

/* Construct Alice's private / public key pair. Return all elements in the Fourier Domain
 * input:  none
 * output: private key s_1=s[n]...s[2*n-1] in Fourier Domain
 *         noise term s_0=s[0]...s[n-1] in Fourier Domain, not needed again
 *         public key b in Fourier Domain
 */	
void KEM1_Generate(RINGELT s[2*m], RINGELT b[m]) {

	sample_secret(s);	sample_secret(s+m);	
	/*Fourier Transform secret keys*/
	FFT_forward(s); FFT_forward(s+m);
	POINTWISE_MUL_ADD(b, a, s+m, s); //Combine with a to produce s_1*a+s_0 in the Fourier domain. Alice's public key.

}

/* Encapsulation routine. Returns an element in R_q x R_2
 * input:  Alice's public key b in Fourier Domain
 * output: Bob's public key u in Fourier Domain
 *         reconciliation data cr_v
 *         shared secret mu
 */
void KEM1_Encapsulate(RINGELT u[m], uint64_t cr_v[recwords], uint64_t mu[muwords], RINGELT b[m]) {
	RINGELT e[3*m];
	RINGELT v[m];

	/*Sample Bob's ephemeral keys*/	
	sample_secret(e);	sample_secret(e+m); sample_secret(e+2*m);	
	/*Fourer Transform e0 and e1*/
	FFT_forward(e); FFT_forward(e+m);
	POINTWISE_MUL_ADD(u, a, e, e+m); //Combine with a to produce e_0*a+e_1 in the Fourier domain. Bob's public key.

	POINTWISE_MUL(v, b, e); //Create v = e0*b
	FFT_backward(v); //Undo the Fourier Transform
	MAPTOCYCLOTOMIC(v);
	
	POINTWISE_ADD(v, v, e+2*m); //Create v = e0*b+e2
	
	help_rec(mu, cr_v, v);
	  
}

/* Decapsulation routine.
 * input:  Bob's public key u in Fourier Domain
 *         Alice's private key s_1 in Fourier Domain
 *         reconciliation data cr_v
 * output: shared secret mu
 */
void KEM1_Decapsulate(uint64_t mu[muwords], RINGELT u[m], RINGELT s_1[m], uint64_t cr_v[recwords]) {
	RINGELT w[m];

	POINTWISE_MUL(w, s_1, u); //Create w = s1*u
	FFT_backward(w); //Undo the Fourier Transform
	MAPTOCYCLOTOMIC(w);

	rec(mu, w, cr_v);

}



