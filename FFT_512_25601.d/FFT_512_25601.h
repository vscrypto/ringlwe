/* This is free and unencumbered software released into the public domain.
 *
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 *
 * See LICENSE for complete information.
 */
 	
#ifndef _FFT_512_25601_H_
#define	_FFT_512_25601_H_
#include <inttypes.h>	
#include <stdlib.h>
#include <string.h>	
	
#define FFTLONG uint_fast32_t
#define PRIuFFTLONG PRIuFAST32
#define FFTSHORT uint_fast16_t
#define PRIuFFTSHORT PRIuFAST16
	

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
void FFT_forward_512_25601(FFTSHORT x[512]);

/*
We use Cooley-Tukey, decimation-in-time FFT, for the inverse FFT.
Note that we will not perform the usual scambling / bit-reversal procedure here because we will the forward
fourier transform is using decimation-in-frequency.
*/
void FFT_backward_512_25601(FFTSHORT x[512]);

/*
We use Gentleman-Sande, decimation-in-frequency FFT, for the forward FFT.
We premultiply x by the 2n'th roots of unity to affect a Discrete Weighted Fourier Transform, 
so when we apply pointwise multiplication we obtain the negacyclic convolution, i.e. multiplication 
modulo x^n+1.
Note that we will not perform the usual scambling / bit-reversal procedure here because we will invert 
the fourier transform using decimation-in-time.
*/
void FFT_twisted_forward_512_25601(FFTSHORT x[512]);

/*
We use Cooley-Tukey, decimation-in-time FFT, for the inverse FFT.
We postmultiply x by the inverse of the 2n'th roots of unity * n^-1 to affect a Discrete Weighted Fourier Transform, 
so when we apply pointwise multiplication we obtain the negacyclic convolution, i.e. multiplication 
modulo x^n+1.
Note that we will not perform the usual scambling / bit-reversal procedure here because we will the forward
fourier transform is using decimation-in-frequency.
*/
void FFT_twisted_backward_512_25601(FFTSHORT x[512]);


/*O(nlogn) cyclic convolution*/
void cyclic_convolution_512_25601(FFTSHORT z[512], FFTSHORT x[512], FFTSHORT y[512]);
	

/*O(nlogn) negacyclic convolution*/
void negacyclic_convolution_512_25601(FFTSHORT z[512], FFTSHORT x[512], FFTSHORT y[512]);
	

#endif
