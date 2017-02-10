/* This is free and unencumbered software released into the public domain.
 *
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 *
 * See LICENSE for complete information.
 */

#ifndef _RLWE_INCLUDES_H_
#define _RLWE_INCLUDES_H_

#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>


#if defined M512 && defined Q12289
	#include "FFT_512_12289.d/FFT_512_12289.h"
	#define RINGELT FFTSHORT
	#define PRIuRINGELT PRIuFFTSHORT
	#include "rlwe_params_512_12289.h"
	
	/*Use the twisted Fourier Transform in the Power of 2 case for multiplication
	in the ring F_q[x] / <x^m+1>*/
	
	#define FFT_forward FFT_twisted_forward_512_12289
	#define FFT_backward(_x)\
	do {\
		FFT_twisted_backward_512_12289(_x);\
		for (uint16_t _i = 0; _i < m; ++_i) {\
			MUL_MOD((_x)[_i], (_x)[_i], 12265, (q));\
		}\
	} while(0)
			
	#define HAVEVALIDMQ 1
	#define MISPOWEROFTWO 1
#endif

#if defined M1024 && defined Q12289
	#include "FFT_1024_12289.d/FFT_1024_12289.h"
	#define RINGELT FFTSHORT
	#define PRIuRINGELT PRIuFFTSHORT
	#include "rlwe_params_1024_12289.h"
	
	/*Use the twisted Fourier Transform in the Power of 2 case for multiplication
	in the ring F_q[x] / <x^m+1>*/
	
	#define FFT_forward FFT_twisted_forward_1024_12289
	#define FFT_backward(_x)\
	do {\
		FFT_twisted_backward_1024_12289(_x);\
		for (uint16_t _i = 0; _i < m; ++_i) {\
			MUL_MOD((_x)[_i], (_x)[_i], 12277, (q));\
		}\
	} while(0)
			
	#define HAVEVALIDMQ 1
	#define MISPOWEROFTWO 1
#endif

#if defined M256 && defined Q15361
	#include "FFT_256_15361.d/FFT_256_15361.h"
	#define RINGELT FFTSHORT
	#define PRIuRINGELT PRIuFFTSHORT
	#include "rlwe_params_256_15361.h"
	
	/*Use the twisted Fourier Transform in the Power of 2 case for multiplication
	in the ring F_q[x] / <x^m+1>*/
	
	#define FFT_forward FFT_twisted_forward_256_15361
	#define FFT_backward(_x)\
	do {\
		FFT_twisted_backward_256_15361(_x);\
		for (uint16_t _i = 0; _i < m; ++_i) {\
			MUL_MOD((_x)[_i], (_x)[_i], 15301, (q));\
		}\
	} while(0)
			
	#define HAVEVALIDMQ 1
	#define MISPOWEROFTWO 1
#endif

#if defined M337 && defined Q32353
	#include "FFT_337_32353.d/FFT_337_32353.h"
	#define RINGELT FFTSHORT
	#define PRIuRINGELT PRIuFFTSHORT
	#include "rlwe_params_337_32353.h"
	
	#define FFT_forward FFT_forward_337_32353
	#define FFT_backward(_x)\
	do {\
		FFT_backward_337_32353(_x);\
		for (uint16_t _i = 0; _i < m; ++_i) {\
			MUL_MOD((_x)[_i], (_x)[_i], 32257, (q));\
		}\
	} while(0)
			
	#define HAVEVALIDMQ 1
	#define MISPOWEROFTWO 0
#endif

#if defined M433 && defined Q35507
	#include "FFT_433_35507.d/FFT_433_35507.h"
	#define RINGELT FFTSHORT
	#define PRIuRINGELT PRIuFFTSHORT
	#include "rlwe_params_433_35507.h"
	
	#define FFT_forward FFT_forward_433_35507
	#define FFT_backward(_x)\
	do {\
		FFT_backward_433_35507(_x);\
		for (uint16_t _i = 0; _i < m; ++_i) {\
			MUL_MOD((_x)[_i], (_x)[_i], 35425, (q));\
		}\
	} while(0)
			
	#define HAVEVALIDMQ 1
	#define MISPOWEROFTWO 0
#endif

#if defined M512 && defined Q25601
	#include "FFT_512_25601.d/FFT_512_25601.h"
	#define RINGELT FFTSHORT
	#define PRIuRINGELT PRIuFFTSHORT
	#include "rlwe_params_512_25601.h"
	
	/*Use the twisted Fourier Transform in the Power of 2 case for multiplication
	in the ring F_q[x] / <x^m+1>*/
	
	#define FFT_forward FFT_twisted_forward_512_25601
	#define FFT_backward(_x)\
	do {\
		FFT_twisted_backward_512_25601(_x);\
		for (uint16_t _i = 0; _i < m; ++_i) {\
			MUL_MOD((_x)[_i], (_x)[_i], 25551, (q));\
		}\
	} while(0)
			
	#define HAVEVALIDMQ 1
	#define MISPOWEROFTWO 1
#endif

#if defined M541 && defined Q41117
	#include "FFT_541_41117.d/FFT_541_41117.h"
	#define RINGELT FFTSHORT
	#define PRIuRINGELT PRIuFFTSHORT
	#include "rlwe_params_541_41117.h"
	
	#define FFT_forward FFT_forward_541_41117
	#define FFT_backward(_x)\
	do {\
		FFT_backward_541_41117(_x);\
		for (uint16_t _i = 0; _i < m; ++_i) {\
			MUL_MOD((_x)[_i], (_x)[_i], 41041, (q));\
		}\
	} while(0)
			
	#define HAVEVALIDMQ 1
	#define MISPOWEROFTWO 0
#endif

#if defined M631 && defined Q44171
	#include "FFT_631_44171.d/FFT_631_44171.h"
	#define RINGELT FFTSHORT
	#define PRIuRINGELT PRIuFFTSHORT
	#include "rlwe_params_631_44171.h"
	
	#define FFT_forward FFT_forward_631_44171
	#define FFT_backward(_x)\
	do {\
		FFT_backward_631_44171(_x);\
		for (uint16_t _i = 0; _i < m; ++_i) {\
			MUL_MOD((_x)[_i], (_x)[_i], 44101, (q));\
		}\
	} while(0)
			
	#define HAVEVALIDMQ 1
	#define MISPOWEROFTWO 0
#endif

#if defined M739 && defined Q47297
	#include "FFT_739_47297.d/FFT_739_47297.h"
	#define RINGELT FFTSHORT
	#define PRIuRINGELT PRIuFFTSHORT
	#include "rlwe_params_739_47297.h"
	
	#define FFT_forward FFT_forward_739_47297
	#define FFT_backward(_x)\
	do {\
		FFT_backward_739_47297(_x);\
		for (uint16_t _i = 0; _i < m; ++_i) {\
			MUL_MOD((_x)[_i], (_x)[_i], 47233, (q));\
		}\
	} while(0)
			
	#define HAVEVALIDMQ 1
	#define MISPOWEROFTWO 0
#endif

#if defined M821 && defined Q49261
	#include "FFT_821_49261.d/FFT_821_49261.h"
	#define RINGELT FFTSHORT
	#define PRIuRINGELT PRIuFFTSHORT
	#include "rlwe_params_821_49261.h"
	
	#define FFT_forward FFT_forward_821_49261
	#define FFT_backward(_x)\
	do {\
		FFT_backward_821_49261(_x);\
		for (uint16_t _i = 0; _i < m; ++_i) {\
			MUL_MOD((_x)[_i], (_x)[_i], 49201, (q));\
		}\
	} while(0)
			
	#define HAVEVALIDMQ 1
	#define MISPOWEROFTWO 0
#endif

#if defined M1024 && defined Q40961
	#include "FFT_1024_40961.d/FFT_1024_40961.h"
	#define RINGELT FFTSHORT
	#define PRIuRINGELT PRIuFFTSHORT
	#include "rlwe_params_1024_40961.h"
	
	/*Use the twisted Fourier Transform in the Power of 2 case for multiplication
	in the ring F_q[x] / <x^m+1>*/
	
	#define FFT_forward FFT_twisted_forward_1024_40961
	#define FFT_backward(_x)\
	do {\
		FFT_twisted_backward_1024_40961(_x);\
		for (uint16_t _i = 0; _i < m; ++_i) {\
			MUL_MOD((_x)[_i], (_x)[_i], 40921, (q));\
		}\
	} while(0)
			
	#define HAVEVALIDMQ 1
	#define MISPOWEROFTWO 1
#endif

#ifndef HAVEVALIDMQ
	#error "Not compiling with valid values of m and q"
#endif


#endif
