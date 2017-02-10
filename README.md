A Practical Ring-LWE Key Exchange Implementation
------------------------------------------------

This software is plain C (C99 standard). Compilation has been tested using gcc on Linux. Dependencies are glibc-devel and openssl-devel, or equivalents on other platforms. A comment in the Makefile describes how to compile without openssl-devel but this is not secure, see below.

To compile everything (simulator, benchmarking, and test vectors): 
make

To run all compiled programs:
make test


This software provides an implementation of a practical and efficient Diffie-Hellman-like key exchange which is provably passively secure against quantum and classical adversaries. It is based on the ring learning with errors (ring-LWE) problem and covers a range of security levels and public key sizes. It can readily be extended to an actively secure version and an authenticated version.

The key exchange is parameterized by integers m and q, a reconciliation method, and a sampling method. 
* We present code for the case of m being a power-of-two and m being prime. When m is a power of two, the public key is an array of m integers in the range 0,..,q-1. When m is a prime, the public key is an array of m-1 integers in the range 0,..,q-1. 
* We present Peikert-style and New Hope-style reconciliation methods of approximate shared secret values.
* We present uniform, gaussian and binomial sampling methods.
We select pairs (m,q) that meet given security levels, for whichever of the reconciliation and sampling methods is chosen.

We recommend the uniform sampling variants because they run significantly faster than the gaussian sampling equivalents. 

There are two versions of gaussian sampling, both of which produce samples from the same distribution. One is the faster of the two but has a slight correlation of computation time to sampled value, whereas the other (gaussian_ct) takes constant time so has no such correlation. The uniform sampling does not have a correlation of computation time to sample value so just requires one version.

For each algorithm variant, we provide:
* an example key exchange program in rlwe_main.c, which compiles to rlwe_<m>_<q>_<sampling>
* a benchmarking program in rlwe_benchmark.c, which compiles to benchmark_<m>_<q>_<sampling>
* a check of test vectors in rlwe_testvec.c, which compiles to testvec_<m>_<q>_<sampling>

| Algorithm (rlwe_*m*_*q*) | Reconciliation | Security   |    Public key size |
| ------------------------ | -------------- | ---------- | ------------------ |
| rlwe_512_12289           | NewHope-style  | 128+ bits  |    7168 bits       |
| rlwe_1024_12289          | NewHope-style  | 256+ bits  |   14336 bits       |
| rlwe_256_15361           | Peikert-style  |  80 bits   |    3584 bits       |
| rlwe_512_25601           | Peikert-style  | 128 bits   |    7680 bits       |
| rlwe_1024_40961          | Peikert-style  | 256 bits   |   16384 bits       |
| rlwe_337_32353           | Peikert-style  |  96 bits   |    5040 bits       |
| rlwe_433_35507           | Peikert-style  | 128 bits   |    6912 bits       |
| rlwe_541_41117           | Peikert-style  | 160 bits   |    8640 bits       |
| rlwe_631_44171           | Peikert-style  | 192 bits   |   10080 bits       |
| rlwe_739_47297           | Peikert-style  | 224 bits   |   11808 bits       |
| rlwe_821_49261           | Peikert-style  | 256 bits   |   13120 bits       |

The algorithm for the Peikert-style power-of-two case is described in the paper "A Practical Key Exchange for the Internet using Lattice Cryptography" by Vikram Singh, available at http://eprint.iacr.org/2015/138, and the algorithm for the Peikert-style prime case is described in "Even More Practical Key Exchanges for the Internet using Lattice Cryptography" by Vikram Singh and Arjun Chopra, available at http://eprint.iacr.org/2015/1120. These in turn are a version of the passively secure key exchange described in the paper "Lattice Cryptography for the Internet" by Chris Peikert, available at http://eprint.iacr.org/2014/070. The New Hope-style cases are described in "Post-quantum key exchange - a new hope" by Erdem Alkim, Leo Ducas, Thomas Poeppelmann and Peter Schwabe.

Substantial parts of this code are copied from the software published by Joppe W. Bos, Craig Costello, Michael Naehrig, and Douglas Stebila at https://github.com/dstebila/rlwekex, and described in their paper "Post-quantum key exchange for the TLS protocol from the ring learning with errors problem", available at http://eprint.iacr.org/2014/599.


Cryptographically secure random number generation
-------------------------------------------------
Note that the key generation and key exchange algorithms make use of a random number generator during execution.  The sampling code is configured by default to use OpenSSL's PRNG to generate a seed and expand it using AES.  Several other options are available; see `rlwe_kex.c`.  C's `random()` can be used for testing purposes by defining the macro `RLWE_RANDOMNESS_USE_C_RANDOM_INSECURE`, but this is **not secure**.  Developers can also define the `RANDOM_VARS`, `RANDOM8`, `RANDOM32`, `RANDOM64` macros with a cryptographically secure pseudorandom number generator of their own choosing.  

License
-------
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or distribute this software, either in source code form or as a compiled binary, for any purpose, commercial or non-commercial, and by any means.

See the file LICENSE for complete information.
