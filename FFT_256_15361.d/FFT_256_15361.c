/* This is free and unencumbered software released into the public domain.
 *
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 *
 * See LICENSE for complete information.
 */

/* Code to compute a Number Theoretic Transform for multiplication in the ring 
F_q[x] / <x^n+1>.
	n = 256, q = 15361	*/


#include "FFT_256_15361.h"

/*Set n and q*/
static const FFTSHORT n = 256;
static const FFTSHORT q = 15361;


#include "FFT_256_15361_constants.c"


/*
We use Gentleman-Sande, decimation-in-frequency FFT, for the forward FFT.
Note that we will not perform the usual scambling / bit-reversal procedure here because we will invert 
the fourier transform using decimation-in-time.
*/
void FFT_forward_256_15361(FFTSHORT x[256]) {
	FFTSHORT index, step;
	FFTSHORT i,j,m;
	FFTSHORT t0,t1;

	step = 1;
	for (m = n>>1; m >= 1; m=m>>1) {
		index = 0;
		for (j = 0 ; j < m; ++j) {
			for (i = j; i < n; i += (m<<1)) {
				ADD_MOD(t0, x[i], x[i+m], q);
				ADD(t1, x[i], q - x[i+m]);
				MUL_MOD(x[i+m], t1, W[index], q);				
				x[i] = t0;				
			}
			SUB_MODn(index, index, step);
		}
		step = step << 1;
	}	 
}

/*
We use Cooley-Tukey, decimation-in-time FFT, for the inverse FFT.
Note that we will not perform the usual scambling / bit-reversal procedure here because we will the forward
fourier transform is using decimation-in-frequency.
*/
void FFT_backward_256_15361(FFTSHORT x[256]) {
	FFTSHORT index, step;
	FFTSHORT i,j,m;
	FFTSHORT t0,t1;

	step = n>>1;
	for (m = 1; m < n; m=m<<1) {
		index = 0;
		for (j = 0 ; j < m; ++j) {
			for (i = j; i < n; i += (m<<1)) {							
				t0 = x[i];
				t0 -= (t0 >= q) ? q : 0;
				MUL_MOD(t1, x[i+m], W_rev[index], q);				
				ADD(x[i], t0, t1);
				ADD(x[i+m], t0, q - t1);
				
			}
			SUB_MODn(index, index, step);
		}
		step = step >> 1;
	}	
	for (i = 0; i < n; ++i) {
		x[i] -= (x[i] >= q) ? q : 0;
	}
}


/*
We use Gentleman-Sande, decimation-in-frequency FFT, for the forward FFT.
We premultiply x by the 2n'th roots of unity to affect a Discrete Weighted Fourier Transform, 
so when we apply pointwise multiplication we obtain the negacyclic convolution, i.e. multiplication 
modulo x^n+1.
Note that we will not perform the usual scambling / bit-reversal procedure here because we will invert 
the fourier transform using decimation-in-time.
*/
void FFT_twisted_forward_256_15361(FFTSHORT x[256]) {
	FFTSHORT index, step;
	FFTSHORT i,j,m;
	FFTSHORT t0,t1;

	//Pre multiplication for twisted FFT
	j = 0;
	for (i = 0; i < n>>1; ++i) {
		MUL_MOD(x[j], x[j], W[i], q);
		j++;	
		MUL_MOD(x[j], x[j], W_sqrt[i], q);	
		j++;
	}

	step = 1;
	for (m = n>>1; m >= 1; m=m>>1) {
		index = 0;
		for (j = 0 ; j < m; ++j) {
			for (i = j; i < n; i += (m<<1)) {				
				ADD_MOD(t0, x[i], x[i+m], q);
				ADD(t1, x[i], q - x[i+m]);
				MUL_MOD(x[i+m], t1, W[index], q);				
				x[i] = t0;						
			}
			SUB_MODn(index, index, step);
		}
		step = step << 1;
	}	 
}

/*
We use Cooley-Tukey, decimation-in-time FFT, for the inverse FFT.
We postmultiply x by the inverse of the 2n'th roots of unity * n^-1 to affect a Discrete Weighted Fourier Transform, 
so when we apply pointwise multiplication we obtain the negacyclic convolution, i.e. multiplication 
modulo x^n+1.
Note that we will not perform the usual scambling / bit-reversal procedure here because we will the forward
fourier transform is using decimation-in-frequency.
*/
void FFT_twisted_backward_256_15361(FFTSHORT x[256]) {
	FFTSHORT index, step;
	FFTSHORT i,j,m;
	FFTSHORT t0,t1;

	step = n>>1;
	for (m = 1; m < n; m=m<<1) {
		index = 0;
		for (j = 0 ; j < m; ++j) {
			for (i = j; i < n; i += (m<<1)) {							
				t0 = x[i];
				t0 -= (t0 >= q) ? q : 0;
				MUL_MOD(t1, x[i+m], W_rev[index], q);				
				ADD(x[i], t0, t1);
				ADD(x[i+m], t0, q - t1);
			}
			SUB_MODn(index, index, step);
		}
		step = step >> 1;
	}

	//Post multiplication for twisted FFT
	j = 0;
	for (i = 0; i < n>>1; ++i) {
		MUL_MOD(x[j], x[j], W_rev[i], q);
		j++;	
		MUL_MOD(x[j], x[j], W_sqrt_rev[i], q);
		j++;
	} 
}


/*O(n^2) cyclic convolution code for testing*/
void slow_cyclic_convolution_256_15361(FFTSHORT z[256], FFTSHORT x[256], FFTSHORT y[256]) {
	FFTSHORT i,j,t;
	for (i = 0; i < n; ++i) {
		z[i] = 0;
		for (j = 0; j <= i; ++j) {
			MUL_MOD(t, x[j], y[i-j], q);
			ADD_MOD(z[i], z[i], t, q);
		}
		for (j = i+1; j < n; ++j) {
			MUL_MOD(t, x[j], y[n+i-j], q);
			ADD_MOD(z[i], z[i], t, q);			
		}		
	}		
}


/*O(nlogn) cyclic convolution*/
void cyclic_convolution_256_15361(FFTSHORT z[256], FFTSHORT x[256], FFTSHORT y[256]) {

	FFT_forward_256_15361(x);
	FFT_forward_256_15361(y);
	
	FFTSHORT i;
	for (i = 0; i < n; ++i) {
		MUL_MOD(z[i], x[i], y[i], q);
	}
	FFT_backward_256_15361(z);
	/*Multiply by n^-1 mod q*/
	for (i = 0; i < n; ++i) {
		MUL_MOD(z[i], z[i], 15301UL, q);	
	}
}


/*O(n^2) negacyclic convolution code for testing*/
void slow_negacyclic_convolution_256_15361(FFTSHORT z[256], FFTSHORT x[256], FFTSHORT y[256]) {
	FFTSHORT i,j,t;
	for (i = 0; i < n; ++i) {
		z[i] = 0;
		for (j = 0; j <= i; ++j) {
			MUL_MOD(t, x[j], y[i-j], q);
			ADD_MOD(z[i], z[i], t, q);			
		}
		for (j = i+1; j < n; ++j) {
			MUL_MOD(t, x[j], y[n+i-j], q);
			SUB_MOD(z[i], z[i], t, q);			
		}		
	}	
}


/*O(nlogn) negacyclic convolution*/
void negacyclic_convolution_256_15361(FFTSHORT z[256], FFTSHORT x[256], FFTSHORT y[256]) {

	FFT_twisted_forward_256_15361(x);
	FFT_twisted_forward_256_15361(y);
	
	FFTSHORT i;
	for (i = 0; i < n; ++i) {
		MUL_MOD(z[i], x[i], y[i], q);
	}
	FFT_twisted_backward_256_15361(z);
	/*Multiply by n^-1 mod q*/
	for (i = 0; i < n; ++i) {	
		MUL_MOD(z[i], z[i], 15301UL, q);	
	}
}

