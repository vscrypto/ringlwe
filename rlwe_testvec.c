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
	int i, flag = 1, pass = 0;	

#ifdef TRANSMIT_IN_STANDARD_DOMAIN
	const char domain[] = "Standard";
#else
	const char domain[] = "FFT / CRT";
#endif

	/*Exclusively For Alice*/
	uint64_t mu_alice[muwords]; /* Alice's recovered mu */
	RINGELT b_alice[m]; /* Alice's recovered public key */

	printf("Alice's private key (%s basis) s1_alice:\n", domain);
	for (i = 0; i < m; i++) {
		printf("%04X ",(uint32_t) s1_alice_test[i]);
		if((i%8)==7) printf("\n");
	}
	printf("\n");

	printf("Alice's private error (%s basis) s0_alice:\n", domain);
	for (i = 0; i < m; i++) {
		printf("%04X ",(uint32_t) s0_alice_test[i]);
		if((i%8)==7) printf("\n");
	}
	printf("\n");

#ifdef TRANSMIT_IN_STANDARD_DOMAIN
	FFT_forward(s0_alice_test);
	FFT_forward(s1_alice_test);
#endif 

	/* KEM1_Generate */
        if (a_domain == 0) { 
		FFT_forward(a); a_domain = 1; 
	}
	POINTWISE_MUL_ADD(b_alice, a, s1_alice_test, s0_alice_test); //Combine with a to produce s_1*a+s_0 in the Fourier domain. Alice's public key.

#ifdef TRANSMIT_IN_STANDARD_DOMAIN
	FFT_backward(b_alice);
#endif 

	for(i=0;i<m;i++)
                flag &= (b_alice[i] == b_alice_test[i]);
	if(flag) {
		printf("Successful Test of KEM1_Generate!\n\n");
		pass++;
	}
	else {
		printf("Failure in Test of KEM1_Generate :-(\n");
		printf("Failed Alice's public key (%s basis) b:\n", domain);
		for (i = 0; i < m; i++) {
			printf("%04X ",(uint32_t) b_alice[i]);
			if((i%8)==7) printf("\n");
		}
		printf("\n");
	}

	printf("Bob's public key (%s basis) u:\n", domain);
	for (i = 0; i < m; i++) {
		printf("%04X ",(uint32_t) b_bob_test[i]);
		if((i%8)==7) printf("\n");
	}
	printf("\n");

	printf("Reconciliation data cr_v:\n");
	for (i = 0; i < recwords; i++) {
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

        /*If Bob's public key is in the Standard domain it will be converted to the Fourier domain by KEM1_Decapsulate*/
	KEM1_Decapsulate(mu_alice, b_bob_test, s1_alice_test, cr_v_test);

	for (i = 0; i < muwords; ++i) flag &= (mu_alice[i] == mu_test[i]);
	if (flag) {
		printf("Successful Test of KEM1_Decapsulate!\n");
		pass++;
	}
	else {
		printf("Failure in Test of KEM1_Decapsulate :-(\n");
		printf("Failed key mu:\n");
		for (i = 0; i < muwords; i++) {
			printf("%016lX ",mu_alice[i]);
			if((i%4)==3) printf("\n");
		}
		printf("\n");
	}
	
	if(pass==2) {
	        printf("\nSuccess in All Tests!\n");
	}
	else {
	        printf("\nFailure: only passed %d out of 2 tests!\n",pass);
	}
}
