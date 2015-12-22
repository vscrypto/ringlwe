/* This is free and unencumbered software released into the public domain.
 *
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 *
 * See LICENSE for complete information.
 */
 	
#ifndef _FFT_2048_8816641_H
#define	_FFT_2048_8816641_H
#include <inttypes.h>	
#include <stdlib.h>	
#include <string.h>	
	
#ifndef	FFTLONG	
	#define FFTLONG uint_fast64_t
	#define PRIuFFTLONG PRIuFAST64
#endif
#ifndef FFTSHORT
	#define FFTSHORT uint_fast32_t
	#define PRIuFFTSHORT PRIuFAST32
#endif	

/*
We use Gentleman-Sande, decimation-in-frequency FFT, for the forward FFT.
Note that we will not perform the usual scambling / bit-reversal procedure here because we will invert 
the fourier transform using decimation-in-time.
*/
void FFT_forward_2048_8816641(FFTSHORT x[2048]);

/*
We use Cooley-Tukey, decimation-in-time FFT, for the inverse FFT.
Note that we will not perform the usual scambling / bit-reversal procedure here because we will the forward
fourier transform is using decimation-in-frequency.
*/
void FFT_backward_2048_8816641(FFTSHORT x[2048]);

/*O(nlogn) cyclic convolution*/
void cyclic_convolution_2048_8816641(FFTSHORT z[2048], FFTSHORT x[2048], FFTSHORT y[2048]);
	

#endif
