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
	n = 631, q = 44171	*/


#include "FFT_631_44171.h"

/*Set n, q and N*/
static const FFTSHORT n = 631;
static const FFTSHORT q = 44171;
static const FFTSHORT N = 2048;

#include "FFT_631_44171_constants.c"


/*
We use Bluestein's trick and integer convoution by CRT.
*/
void FFT_forward_631_44171(FFTSHORT x[631]) {
	FFTSHORT x0[2048], x1[2048];
	FFTSHORT i;
	FFTLONG x_crt[2048];
	const FFTSHORT q0 = 8816641, Ninvq0 = 8812336;	
	const FFTSHORT q1 = 17633281, Ninvq1 = 17624671;
	const FFTLONG h0 = 17633282UL, h1 = 17633281UL;
	const FFTLONG q0q1 = 155466308229121UL;
	
	/*Setup Bluestein's method*/
	for (i = 0; i < n; ++i) {
		MUL_MOD(x0[i], x[i], Bluestein_mul[i], q);
	}
	memset((void *) (x0+n), 0, (N-n)*sizeof(FFTSHORT)); /*Pad with 0's*/
	memcpy((void *) x1, (void *) x0, N*sizeof(FFTSHORT)); /*Copy x0 into x1*/
	
	/*Cyclic convolution*/
	FFT_forward_2048_8816641(x0);
	FFT_forward_2048_17633281(x1);
	
	for (i = 0; i < N; ++i) {
		MUL_MOD(x0[i], x0[i], Bluestein_roots_fft_8816641[i], q0);
		MUL_MOD(x1[i], x1[i], Bluestein_roots_fft_17633281[i], q1);		
	}
	FFT_backward_2048_8816641(x0);
	FFT_backward_2048_17633281(x1);
	
	/*Apply the CRT*/
	for (i = 0; i < N; ++i) {
		MUL_MOD(x0[i], x0[i], Ninvq0, q0); /*Scaling for the convolution*/
		MUL_MOD(x1[i], x1[i], Ninvq1, q1); /*Scaling for the convolution*/
		x_crt[i] = h1*x0[i] % q0q1;
		x_crt[i] = q0q1 - x_crt[i];
		x_crt[i] += h0*x1[i];
		x_crt[i] = x_crt[i] % q0q1; //Will now be the integer convolution
		x_crt[i] = x_crt[i] % q; 
	}
		
	/*Complete Bluestein's trick*/
	x[0] = (FFTSHORT) x_crt[(N>>1)-1];
	for (i = 0; i < n-1; ++i) {
		MUL_MOD(x[i+1], x_crt[(N>>1)+i], Bluestein_mul[i], q);
	}		
	
}

void FFT_backward_631_44171(FFTSHORT x[631]) {
	FFTSHORT x0[2048], x1[2048];
	FFTSHORT i;
	FFTLONG x_crt[2048];
	const FFTSHORT q0 = 8816641, Ninvq0 = 8812336;	
	const FFTSHORT q1 = 17633281, Ninvq1 = 17624671;
	const FFTLONG h0 = 17633282UL, h1 = 17633281UL;
	const FFTLONG q0q1 = 155466308229121UL;
	
	/*Setup Bluestein's method*/
	for (i = 0; i < n; ++i) {
		MUL_MOD(x0[i], x[i], Bluestein_mul_inv[i], q);
	}
	memset((void *) (x0+n), 0, (N-n)*sizeof(FFTSHORT)); /*Pad with 0's*/
	memcpy((void *) x1, (void *) x0, N*sizeof(FFTSHORT)); /*Copy x0 into x1*/
		
	/*Cyclic convolution*/
	FFT_forward_2048_8816641(x0);
	FFT_forward_2048_17633281(x1);
	for (i = 0; i < N; ++i) {
		MUL_MOD(x0[i], x0[i], Bluestein_roots_inv_fft_8816641[i], q0);
		MUL_MOD(x1[i], x1[i], Bluestein_roots_inv_fft_17633281[i], q1);		
	}
	FFT_backward_2048_8816641(x0);
	FFT_backward_2048_17633281(x1);
	
	/*Apply the CRT*/
	for (i = 0; i < N; ++i) {
		MUL_MOD(x0[i], x0[i], Ninvq0, q0); /*Scaling for the convolution*/
		MUL_MOD(x1[i], x1[i], Ninvq1, q1); /*Scaling for the convolution*/
		x_crt[i] = h1*x0[i] % q0q1;
		x_crt[i] = q0q1 - x_crt[i];
		x_crt[i] += h0*x1[i];
		x_crt[i] = x_crt[i] % q0q1; //Will now be the integer convolution
		x_crt[i] = x_crt[i] % q; 
	}
			
	/*Complete Bluestein's trick*/
	x[0] = (FFTSHORT) x_crt[(N>>1)-1];	
	for (i = 0; i < n-1; ++i) {
		MUL_MOD(x[i+1], x_crt[(N>>1)+i], Bluestein_mul_inv[i], q);		
	}
				
}




/*O(n^2) cyclic convolution code for testing*/
void slow_cyclic_convolution_631_44171(FFTSHORT z[631], FFTSHORT x[631], FFTSHORT y[631]) {
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
void cyclic_convolution_631_44171(FFTSHORT z[631], FFTSHORT x[631], FFTSHORT y[631]) {

	FFT_forward_631_44171(x);
	FFT_forward_631_44171(y);
	
	FFTSHORT i;
	for (i = 0; i < n; ++i) {
		MUL_MOD(z[i], x[i], y[i], q);
	}
	FFT_backward_631_44171(z);
	/*Multiply by n^-1 mod q*/
	for (i = 0; i < n; ++i) {
		MUL_MOD(z[i], z[i], 44101UL, q);	
	}
}

