/* This is free and unencumbered software released into the public domain.
 *
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 *
 * See LICENSE for complete information.
 */

#ifndef _PARAMS_H_
#define _PARAMS_H_

#if MAIN
#define EXTERN
#else
#define EXTERN extern
#endif

#include "rlwe_includes.h"

/*Parameters*/
EXTERN const RINGELT m;
EXTERN const RINGELT q;

EXTERN const RINGELT muwords, recwords;

#ifdef UNIFORM
EXTERN const RINGELT B, BB, LOG2B, BMASK;
/*[-B..B] modulo q*/
EXTERN const RINGELT small_coeff_table[11];
#endif

#ifdef NHRECONCILE
EXTERN const RINGELT rdim, rsize;
#else
EXTERN const RINGELT qmod4;
/*Quadrants defining I_0, I'_1, I'_0, I_1*/
EXTERN const RINGELT q_1_4, q_2_4, q_3_4;
/*Define intervals for rec routine*/
EXTERN const RINGELT r0_u, r0_l, r1_u, r1_l;
#endif

/*Public parameter a. Note that this is held in the FFT / CRT basis.*/
EXTERN const RINGELT a[433];

#endif //_PARAMS_H
