/* This is free and unencumbered software released into the public domain.
 *
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 *
 * See LICENSE for complete information.
 */
 	
#ifndef _FFT_337_32353_H
#define	_FFT_337_32353_H
	
#include <inttypes.h>	
#include <stdlib.h>
#include <string.h>	
	
#define FFTLONG uint_fast64_t
#define PRIuFFTLONG PRIuFAST64
#define FFTSHORT uint_fast32_t
#define PRIuFFTSHORT PRIuFAST32

#include "FFT_1024_8816641.h"

#include "FFT_1024_17633281.h"
	

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


void FFT_forward_337_32353(FFTSHORT x[337]);	
void FFT_backward_337_32353(FFTSHORT x[337]);
	

/*O(nlogn) cyclic convolution*/
void cyclic_convolution_337_32353(FFTSHORT z[337], FFTSHORT x[337], FFTSHORT y[337]);
	

#endif
