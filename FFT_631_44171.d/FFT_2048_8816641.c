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
	n = 2048, q = 8816641	*/


#include "FFT_2048_8816641.h"

/*Set n and q*/
static const FFTSHORT n = 2048;
static const FFTSHORT q = 8816641;


#include "FFT_2048_8816641_constants.c"

	

#define ADD_MOD(x, a, b, q) \
do {\
	x = (a) + (b);\
	x -= (x >= (q)) ? (q) : 0;\
} while (0)	


#define ADD(x, a, b) \
do {\
	x = (a) + (b);\
} while (0)	


#define MOD(x, q) \
do {\
	x = x % (q);\
} while (0)	


#define SUB_MOD(x, a, b, q) \
do {\
	x = (a) + ((q) - (b));\
	x -= (x >= (q)) ? (q) : 0;\
} while (0)




/*Needed for indexing in the FFT*/
#define SUB_MODn(x, a, b) \
do {\
	x = (a) + (n-(b));\
	x -= (x >= n) ? n : 0;\
} while (0)


		
#define MUL_MOD(x, a, b, q) \
do {\
	FFTLONG x64 = (FFTLONG) (a)*(b);\
	x64 = x64 % (q);\
	x = (FFTSHORT) x64;\
} while(0)


/*
We use Gentleman-Sande, decimation-in-frequency FFT, for the forward FFT.
Note that we will not perform the usual scambling / bit-reversal procedure here because we will invert 
the fourier transform using decimation-in-time.
*/
void FFT_forward_2048_8816641(FFTSHORT x[2048]) {
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
void FFT_backward_2048_8816641(FFTSHORT x[2048]) {
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


/*O(nlogn) cyclic convolution*/
void cyclic_convolution_2048_8816641(FFTSHORT z[2048], FFTSHORT x[2048], FFTSHORT y[2048]) {

	FFT_forward_2048_8816641(x);
	FFT_forward_2048_8816641(y);
	
	FFTSHORT i;
	for (i = 0; i < n; ++i) {
		MUL_MOD(z[i], x[i], y[i], q);
	}
	FFT_backward_2048_8816641(z);
	/*Multiply by n^-1 mod q*/
	for (i = 0; i < n; ++i) {
		MUL_MOD(z[i], z[i], 8812336UL, q);	
	}
}

