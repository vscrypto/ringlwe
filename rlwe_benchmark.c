/* This is free and unencumbered software released into the public domain.
 *
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 *
 * See LICENSE for complete information.
 */

#define MAIN 1

#include <sys/time.h>
#include "rlwe_kex.h"

#define ITERATIONS 10000


#if defined(__i386__)

static __inline__ unsigned long long rdtsc(void)
{
	unsigned long long int x;
	__asm__ volatile (".byte 0x0f, 0x31" : "=A" (x));
	return x;
}
#elif defined(__x86_64__)

static __inline__ unsigned long long rdtsc(void)
{
	unsigned hi, lo;
	__asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
	return ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
}
#endif

#define START_TIMER \
	gettimeofday(&timeval_start, NULL); \
	cycles_start = rdtsc();
	
#define END_TIMER \
	cycles_end = rdtsc(); \
	gettimeofday(&timeval_end, NULL);

#define PRINT_TIMER_AVG(op_name, it) \
	printf("%-30s %15d %15d %15" PRIu64 "\n", (op_name), (it), \
		(uint32_t) ((timeval_end.tv_usec+1000000*timeval_end.tv_sec) - (timeval_start.tv_usec+1000000*timeval_start.tv_sec)) / (it), \
		(cycles_end - cycles_start) / (it));

#define TIME_OPERATION(op, op_name, it) \
	START_TIMER \
	for (int i = 0; i < (it); i++) { \
		op; \
	} \
	END_TIMER \
	PRINT_TIMER_AVG(op_name, it)





int main(int argc, char *argv[]) 
{
	/*For timing*/
	uint64_t cycles_start, cycles_end;
	struct timeval timeval_start, timeval_end;

	/*Exclusively For Alice*/
	RINGELT s_alice[2*m]; /* Alice's Private Key */
	uint64_t mu_alice[muwords]; /* Alice's recovered mu */

	/*Exclusively For Bob*/
	uint64_t mu_bob[muwords]; /* Bob's version of mu */

	/*Information that gets shared by Alice and Bob*/
	RINGELT b_alice[m]; /* Alice's Public Key */
	RINGELT u[m]; /* Bob's Ring Element from Encapsulation */
	uint64_t cr_v[recwords]; /* Cross Rounding of v */

	printf("Benchmarking : m = %"PRIuRINGELT", q = %"PRIuRINGELT"\n", m, q);
	
	
#ifdef UNIFORM
	printf("Uniform sampling\n");
#endif
#ifdef GAUSSIAN
	printf("Gaussian sampling\n");
#endif
#ifdef GAUSSIAN_CT
	printf("Gaussian Constant Time sampling \n");
#endif
#ifdef BINOMIAL
	printf("Binomial sampling\n");
#endif
	printf("%-30s %15s %15s %15s\n", "Operation", "Iterations", "usec (avg)", "cycles (avg)");
	printf("------------------------------------------------------------------------------\n");
#if defined UNIFORM
	TIME_OPERATION(sample_secret(s_alice), "Sample Uniform", ITERATIONS / 50);
#elif defined GAUSSIAN
	TIME_OPERATION(sample_secret(s_alice), "Sample Gaussian", ITERATIONS / 50);
#elif defined GAUSSIAN_CT
	TIME_OPERATION(sample_secret(s_alice), "Sample Gaussian Constant Time", ITERATIONS / 50);	
#elif defined BINOMIAL
	TIME_OPERATION(sample_secret(s_alice), "Sample Binomial", ITERATIONS / 50);	
#endif

	TIME_OPERATION(FFT_forward(s_alice), "FFT Forward", ITERATIONS / 50);

	TIME_OPERATION(FFT_backward(s_alice), "FFT Backward", ITERATIONS / 50);


	KEM1_Generate(s_alice, b_alice);

	TIME_OPERATION(help_rec(mu_alice, cr_v, u), "HelpRec and Rec", ITERATIONS);
	
	TIME_OPERATION(rec(mu_bob, u, cr_v), "Rec", ITERATIONS);
	
	TIME_OPERATION(KEM1_Generate(s_alice, b_alice), "KEM1.Generate", ITERATIONS / 50);

	TIME_OPERATION(KEM1_Encapsulate(u, cr_v, mu_bob, b_alice), "KEM1.Encapsulate", ITERATIONS / 50);

	TIME_OPERATION(KEM1_Decapsulate(mu_alice, u, s_alice + m, cr_v), "KEM1.Decapsulate", ITERATIONS / 50);
	printf("------------------------------------------------------------------------------\n\n\n");

}


