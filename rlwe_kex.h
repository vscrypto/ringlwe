/* This is free and unencumbered software released into the public domain.
 *
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 *
 * See LICENSE for complete information.
 */

#include "rlwe_includes.h"

/* Construct Alice's private / public key pair. Return all elements in the Fourier Domain 	
 * input:  none
 * output: private key s_1=s[m]...s[2*m-1] in Fourier Domain
 *         noise term s_0=s[0]...s[n-1] in Fourier Domain, not needed again
 *         public key b in Fourier Domain
 */	
void KEM1_Generate(RINGELT s[2*m], RINGELT b[m]);

/* Encapsulation routine. Returns an element in R_q x R_2
 * input:  Alice's public key b in Fourier Domain
 * output: Bob's public key u in Fourier Domain
 *         reconciliation data cr_v
 *         shared secret mu
 */
void KEM1_Encapsulate(RINGELT u[m], uint64_t cr_v[muwords], uint64_t mu[muwords], RINGELT b[m]);

/* Decapsulation routine.
 * input:  Bob's public key u in Fourier Domain
 *         Alice's private key s_1 in Fourier Domain
 *         reconciliation data cr_v
 * output: shared secret mu
 */
void KEM1_Decapsulate(uint64_t mu[muwords], RINGELT u[m], RINGELT s_1[m], uint64_t cr_v[muwords]);

/* Sample secret. Only needed externally for benchmarking. */
void sample_secret(RINGELT s[m]);

/* Round and cross-round. Only needed externally for benchmarking. */
void round_and_cross_round(uint64_t modular_rnd[muwords], uint64_t cross_rnd[muwords], const RINGELT v[m]);

/* Reconcile. Only needed externally for benchmarking. */
void rec(uint64_t r[muwords], RINGELT w[m], uint64_t b[muwords]);

/*v = e0*b, multiply and add in the ring. All done in the FFT / CRT domain, so point-wise multiplication and addition*/
#define POINTWISE_MUL(v, b, e0) \
do {\
	for (uint16_t _i = 0; _i < m; ++_i) {\
		MUL_MOD((v)[_i], (e0)[_i], (b)[_i], (q));\
	}\
} while(0)

/*v = e0+b, multiply and add in the ring. All done in the FFT / CRT domain, so point-wise multiplication and addition*/
#define POINTWISE_ADD(v, b, e0) \
do {\
	for (uint16_t _i = 0; _i < m; ++_i) {\
		ADD_MOD((v)[_i], (e0)[_i], (b)[_i], (q));\
	}\
} while(0)


/*v = e0*b+e1, multiply and add in the ring. All done in the FFT / CRT domain, so point-wise multiplication and addition*/
#define POINTWISE_MUL_ADD(v, b, e0, e1) \
do {\
	for (uint16_t _i = 0; _i < m; ++_i) {\
		MUL_MOD((v)[_i], (e0)[_i], (b)[_i], (q));\
		ADD_MOD((v)[_i], (v)[_i], (e1)[_i], (q));\
	}\
} while(0)


/*Map a length m object in the ring F_q[x]/<x^m-1> to a length m-1 object in the ring F_q[x]/<1+x+...+x^{m-1}>*/
#if MISPOWEROFTWO	
	#define MAPTOCYCLOTOMIC(v)
#else
	#define MAPTOCYCLOTOMIC(v) \
	do {\
		for (uint16_t _i = 0; _i < m-1; ++_i) {\
			SUB_MOD((v)[_i], (v)[_i], (v)[m-1], q);\
		}\
		v[m-1] = 0;\
	} while(0)
#endif
