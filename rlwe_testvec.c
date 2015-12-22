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

#include "rlwe_testvec.h"

int main(int argc, char *argv[]) 
{

	/*Exclusively For Alice*/
	uint64_t mu_alice[muwords]; /* Alice's recovered mu */

	int i, flag = 1;	

	printf("Alice's private key (FFT / CRT basis) s1_alice:\n");
	for (i = 0; i < m; i++) {
		printf("%04X ",(uint32_t) s1_alice_test[i]);
		if((i%8)==7) printf("\n");
	}
	printf("\n");

	printf("Bob's public key (FFT / CRT basis) u:\n");
	for (i = 0; i < m; i++) {
		printf("%04X ",(uint32_t) b_bob_test[i]);
		if((i%8)==7) printf("\n");
	}
	printf("\n");

	printf("Reconciliation data cr_v:\n");
	for (i = 0; i < muwords; i++) {
		printf("%016lX ",cr_v_test[i]);
		if((i%4)==3) printf("\n");
	}
	printf("\n");

	printf("Shared key mu:\n");
	for (i = 0; i < muwords; i++) {
		printf("%016lX ",mu_test[i]);
		if((i%4)==3) printf("\n");
	}
	printf("\n");


	KEM1_Decapsulate(mu_alice, b_bob_test, s1_alice_test, cr_v_test);


	for (i = 0; i < muwords; ++i) flag &= (mu_alice[i] == mu_test[i]);
	if (flag) {
		printf("Successful Test!\n");
	}
	else {
		printf("Failure in Test :-(\n");
		printf("Failed key mu:\n");
		for (i = 0; i < muwords; i++) {
		  printf("%016lX ",mu_alice[i]);
		  if((i%4)==3) printf("\n");
		}
		printf("\n");
	}

}


