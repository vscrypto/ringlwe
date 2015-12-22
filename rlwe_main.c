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

#define TRIALS 1000

int main(int argc, char *argv[]) 
{

	/*Exclusively For Alice*/
	RINGELT s_alice[2*m]; /* Alice's Private Key */
	uint64_t mu_alice[muwords]; /* Alice's recovered mu */

	/*Exclusively For Bob*/
	uint64_t mu_bob[muwords]; /* Bob's version of mu */

	/*Information that gets shared by Alice and Bob*/
	RINGELT b_alice[m]; /* Alice's Public Key */
	RINGELT u[m]; /* Bob's Ring Element from Encapsulation */
	uint64_t cr_v[muwords]; /* Cross Rounding of v */

	KEM1_Generate(s_alice, b_alice);

	KEM1_Encapsulate(u, cr_v, mu_bob, b_alice);

	KEM1_Decapsulate(mu_alice, u, s_alice + m, cr_v);

	int i, flag = 1;	
	for (i = 0; i < muwords; ++i) flag &= (mu_alice[i] == mu_bob[i]);
	if (flag) {
		printf("Successful Key Agreement!\n");
	}
	else {
		printf("Failure in Key Agreement :-(\n");
		for (i = 0; i < muwords; ++i) {
			printf("%"PRIu64"\t", mu_alice[i]);
		}
		printf("\n");
		for (i = 0; i < muwords; ++i) {
			printf("%"PRIu64"\t", mu_bob[i]);
		}
		printf("\n");

		exit(-1);
	}

	printf("Alice's version of mu\n");
	for (i = 0; i < muwords; ++i) {
		printf("%lu ", mu_alice[i]);
	}
	printf("\n\n");

	printf("Bob's version of mu\n");
	for (i = 0; i < muwords; ++i) {
		printf("%lu ", mu_bob[i]);
	}

	printf("\n\n");

	printf("Running %d trials\n", TRIALS);
	int ii;
	for (ii = 0; ii < TRIALS; ++ii) {
		memset(s_alice, 0, 2*m*sizeof(RINGELT));
		memset(b_alice, 0, m*sizeof(RINGELT));
		memset(u, 0, m*sizeof(RINGELT));
		memset(mu_alice, 0, muwords*sizeof(uint64_t));
		memset(mu_bob, 0, muwords*sizeof(uint64_t));
		memset(cr_v, 0, muwords*sizeof(uint64_t));

		KEM1_Generate(s_alice, b_alice);
		KEM1_Encapsulate(u, cr_v, mu_bob, b_alice);
		KEM1_Decapsulate(mu_alice, u, s_alice + m, cr_v);


		flag = 1;	
		for (i = 0; i < muwords; ++i) flag &= (mu_alice[i] == mu_bob[i]);
		if (!flag) {
			printf("Failure in Key Agreement on trial %d\n", ii);
			exit(-1);
		}
	}
	printf("%d trials completed successfully\n", TRIALS);

}


