C = gcc

# if OpenSSL available use this line
CFLAGS = -O3 -std=gnu99 -lm -lcrypto -DRLWE_RANDOMNESS_USE_OPENSSL_AES
# otherwise use this line
#CFLAGS = -O3 -std=gnu99 -lm -DRLWE_RANDOMNESS_USE_C_RANDOM_INSECURE
# this parameter is for improved performance so can be optionally added to CFLAGS: -march=native

global_header_files =\
	rlwe_includes.h\
	rlwe_kex.h

rlwe_benchmark.c_files =\
	rlwe_benchmark.c\
	rlwe_kex.c

rlwe_main_files =\
	rlwe_main.c\
	rlwe_kex.c

rlwe_testvec.c_files =\
	rlwe_testvec.c\
	rlwe_kex.c

rlwe_testvec_header_files =\
	rlwe_testvec.h

random_files =\
	rlwe_rand_c.c\
	rlwe_rand_openssl_aes.c\
	rlwe_rand_openssl_rand.c\
	rlwe_rand_openssl_rc4.c

rlwe_params_337_32353_header_files =\
	rlwe_params_337_32353.h

rlwe_params_337_32353_c_files =\
	rlwe_params_337_32353.c

FFT_337_32353_header_files =\
	FFT_337_32353.d/FFT_1024_8816641.h\
	FFT_337_32353.d/FFT_1024_17633281.h\
	FFT_337_32353.d/FFT_337_32353.h

FFT_337_32353_c_files =\
	FFT_337_32353.d/FFT_1024_8816641.c\
	FFT_337_32353.d/FFT_1024_17633281.c\
	FFT_337_32353.d/FFT_337_32353.c

rlwe_params_433_35507_header_files =\
	rlwe_params_433_35507.h

rlwe_params_433_35507_c_files =\
	rlwe_params_433_35507.c

FFT_433_35507_header_files =\
	FFT_433_35507.d/FFT_1024_8816641.h\
	FFT_433_35507.d/FFT_1024_17633281.h\
	FFT_433_35507.d/FFT_433_35507.h

FFT_433_35507_c_files =\
	FFT_433_35507.d/FFT_1024_8816641.c\
	FFT_433_35507.d/FFT_1024_17633281.c\
	FFT_433_35507.d/FFT_433_35507.c

rlwe_params_541_41117_header_files =\
	rlwe_params_541_41117.h

rlwe_params_541_41117_c_files =\
	rlwe_params_541_41117.c

FFT_541_41117_header_files =\
	FFT_541_41117.d/FFT_2048_8816641.h\
	FFT_541_41117.d/FFT_2048_17633281.h\
	FFT_541_41117.d/FFT_541_41117.h

FFT_541_41117_c_files =\
	FFT_541_41117.d/FFT_2048_8816641.c\
	FFT_541_41117.d/FFT_2048_17633281.c\
	FFT_541_41117.d/FFT_541_41117.c

rlwe_params_631_44171_header_files =\
	rlwe_params_631_44171.h

rlwe_params_631_44171_c_files =\
	rlwe_params_631_44171.c

FFT_631_44171_header_files =\
	FFT_631_44171.d/FFT_2048_8816641.h\
	FFT_631_44171.d/FFT_2048_17633281.h\
	FFT_631_44171.d/FFT_631_44171.h

FFT_631_44171_c_files =\
	FFT_631_44171.d/FFT_2048_8816641.c\
	FFT_631_44171.d/FFT_2048_17633281.c\
	FFT_631_44171.d/FFT_631_44171.c

rlwe_params_739_47297_header_files =\
	rlwe_params_739_47297.h

rlwe_params_739_47297_c_files =\
	rlwe_params_739_47297.c

FFT_739_47297_header_files =\
	FFT_739_47297.d/FFT_2048_8816641.h\
	FFT_739_47297.d/FFT_2048_17633281.h\
	FFT_739_47297.d/FFT_739_47297.h

FFT_739_47297_c_files =\
	FFT_739_47297.d/FFT_2048_8816641.c\
	FFT_739_47297.d/FFT_2048_17633281.c\
	FFT_739_47297.d/FFT_739_47297.c

rlwe_params_821_49261_header_files =\
	rlwe_params_821_49261.h

rlwe_params_821_49261_c_files =\
	rlwe_params_821_49261.c

FFT_821_49261_header_files =\
	FFT_821_49261.d/FFT_2048_8816641.h\
	FFT_821_49261.d/FFT_2048_17633281.h\
	FFT_821_49261.d/FFT_821_49261.h

FFT_821_49261_c_files =\
	FFT_821_49261.d/FFT_2048_8816641.c\
	FFT_821_49261.d/FFT_2048_17633281.c\
	FFT_821_49261.d/FFT_821_49261.c

rlwe_params_256_15361_header_files =\
	rlwe_params_256_15361.h

rlwe_params_256_15361_c_files =\
	rlwe_params_256_15361.c

FFT_256_15361_header_files =\
	FFT_256_15361.d/FFT_256_15361.h

FFT_256_15361_c_files =\
	FFT_256_15361.d/FFT_256_15361.c

rlwe_params_512_25601_header_files =\
	rlwe_params_512_25601.h

rlwe_params_512_25601_c_files =\
	rlwe_params_512_25601.c

FFT_512_25601_header_files =\
	FFT_512_25601.d/FFT_512_25601.h

FFT_512_25601_c_files =\
	FFT_512_25601.d/FFT_512_25601.c

rlwe_params_1024_40961_header_files =\
	rlwe_params_1024_40961.h

rlwe_params_1024_40961_c_files =\
	rlwe_params_1024_40961.c

FFT_1024_40961_header_files =\
	FFT_1024_40961.d/FFT_1024_40961.h

FFT_1024_40961_c_files =\
	FFT_1024_40961.d/FFT_1024_40961.c

all: rlwe_all benchmark_all testvec_all 

test: rlwe.log_all benchmark.log_all testvec.log_all 


benchmark_337_32353_uniform: $(global_header_files) $(rlwe_benchmark.c_files) $(random_files) $(rlwe_params_337_32353_header_files) $(rlwe_params_337_32353_c_files) $(FFT_337_32353_header_files) $(FFT_337_32353_c_files)
	$(C) $(CFLAGS) -DUNIFORM -DM337 -DQ32353 -o benchmark_337_32353_uniform $(rlwe_benchmark.c_files) $(rlwe_params_337_32353_c_files) $(FFT_337_32353_c_files)

benchmark_337_32353_gaussian: $(global_header_files) $(rlwe_benchmark.c_files) $(random_files) $(rlwe_params_337_32353_header_files) $(rlwe_params_337_32353_c_files) $(FFT_337_32353_header_files) $(FFT_337_32353_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN -DM337 -DQ32353 -o benchmark_337_32353_gaussian $(rlwe_benchmark.c_files) $(rlwe_params_337_32353_c_files) $(FFT_337_32353_c_files)

benchmark_337_32353_gaussian_ct: $(global_header_files) $(rlwe_benchmark.c_files) $(random_files) $(rlwe_params_337_32353_header_files) $(rlwe_params_337_32353_c_files) $(FFT_337_32353_header_files) $(FFT_337_32353_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN_CT -DM337 -DQ32353 -o benchmark_337_32353_gaussian_ct $(rlwe_benchmark.c_files) $(rlwe_params_337_32353_c_files) $(FFT_337_32353_c_files)

benchmark_433_35507_uniform: $(global_header_files) $(rlwe_benchmark.c_files) $(random_files) $(rlwe_params_433_35507_header_files) $(rlwe_params_433_35507_c_files) $(FFT_433_35507_header_files) $(FFT_433_35507_c_files)
	$(C) $(CFLAGS) -DUNIFORM -DM433 -DQ35507 -o benchmark_433_35507_uniform $(rlwe_benchmark.c_files) $(rlwe_params_433_35507_c_files) $(FFT_433_35507_c_files)

benchmark_433_35507_gaussian: $(global_header_files) $(rlwe_benchmark.c_files) $(random_files) $(rlwe_params_433_35507_header_files) $(rlwe_params_433_35507_c_files) $(FFT_433_35507_header_files) $(FFT_433_35507_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN -DM433 -DQ35507 -o benchmark_433_35507_gaussian $(rlwe_benchmark.c_files) $(rlwe_params_433_35507_c_files) $(FFT_433_35507_c_files)

benchmark_433_35507_gaussian_ct: $(global_header_files) $(rlwe_benchmark.c_files) $(random_files) $(rlwe_params_433_35507_header_files) $(rlwe_params_433_35507_c_files) $(FFT_433_35507_header_files) $(FFT_433_35507_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN_CT -DM433 -DQ35507 -o benchmark_433_35507_gaussian_ct $(rlwe_benchmark.c_files) $(rlwe_params_433_35507_c_files) $(FFT_433_35507_c_files)

benchmark_541_41117_uniform: $(global_header_files) $(rlwe_benchmark.c_files) $(random_files) $(rlwe_params_541_41117_header_files) $(rlwe_params_541_41117_c_files) $(FFT_541_41117_header_files) $(FFT_541_41117_c_files)
	$(C) $(CFLAGS) -DUNIFORM -DM541 -DQ41117 -o benchmark_541_41117_uniform $(rlwe_benchmark.c_files) $(rlwe_params_541_41117_c_files) $(FFT_541_41117_c_files)

benchmark_541_41117_gaussian: $(global_header_files) $(rlwe_benchmark.c_files) $(random_files) $(rlwe_params_541_41117_header_files) $(rlwe_params_541_41117_c_files) $(FFT_541_41117_header_files) $(FFT_541_41117_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN -DM541 -DQ41117 -o benchmark_541_41117_gaussian $(rlwe_benchmark.c_files) $(rlwe_params_541_41117_c_files) $(FFT_541_41117_c_files)

benchmark_541_41117_gaussian_ct: $(global_header_files) $(rlwe_benchmark.c_files) $(random_files) $(rlwe_params_541_41117_header_files) $(rlwe_params_541_41117_c_files) $(FFT_541_41117_header_files) $(FFT_541_41117_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN_CT -DM541 -DQ41117 -o benchmark_541_41117_gaussian_ct $(rlwe_benchmark.c_files) $(rlwe_params_541_41117_c_files) $(FFT_541_41117_c_files)

benchmark_631_44171_uniform: $(global_header_files) $(rlwe_benchmark.c_files) $(random_files) $(rlwe_params_631_44171_header_files) $(rlwe_params_631_44171_c_files) $(FFT_631_44171_header_files) $(FFT_631_44171_c_files)
	$(C) $(CFLAGS) -DUNIFORM -DM631 -DQ44171 -o benchmark_631_44171_uniform $(rlwe_benchmark.c_files) $(rlwe_params_631_44171_c_files) $(FFT_631_44171_c_files)

benchmark_631_44171_gaussian: $(global_header_files) $(rlwe_benchmark.c_files) $(random_files) $(rlwe_params_631_44171_header_files) $(rlwe_params_631_44171_c_files) $(FFT_631_44171_header_files) $(FFT_631_44171_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN -DM631 -DQ44171 -o benchmark_631_44171_gaussian $(rlwe_benchmark.c_files) $(rlwe_params_631_44171_c_files) $(FFT_631_44171_c_files)

benchmark_631_44171_gaussian_ct: $(global_header_files) $(rlwe_benchmark.c_files) $(random_files) $(rlwe_params_631_44171_header_files) $(rlwe_params_631_44171_c_files) $(FFT_631_44171_header_files) $(FFT_631_44171_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN_CT -DM631 -DQ44171 -o benchmark_631_44171_gaussian_ct $(rlwe_benchmark.c_files) $(rlwe_params_631_44171_c_files) $(FFT_631_44171_c_files)

benchmark_739_47297_uniform: $(global_header_files) $(rlwe_benchmark.c_files) $(random_files) $(rlwe_params_739_47297_header_files) $(rlwe_params_739_47297_c_files) $(FFT_739_47297_header_files) $(FFT_739_47297_c_files)
	$(C) $(CFLAGS) -DUNIFORM -DM739 -DQ47297 -o benchmark_739_47297_uniform $(rlwe_benchmark.c_files) $(rlwe_params_739_47297_c_files) $(FFT_739_47297_c_files)

benchmark_739_47297_gaussian: $(global_header_files) $(rlwe_benchmark.c_files) $(random_files) $(rlwe_params_739_47297_header_files) $(rlwe_params_739_47297_c_files) $(FFT_739_47297_header_files) $(FFT_739_47297_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN -DM739 -DQ47297 -o benchmark_739_47297_gaussian $(rlwe_benchmark.c_files) $(rlwe_params_739_47297_c_files) $(FFT_739_47297_c_files)

benchmark_739_47297_gaussian_ct: $(global_header_files) $(rlwe_benchmark.c_files) $(random_files) $(rlwe_params_739_47297_header_files) $(rlwe_params_739_47297_c_files) $(FFT_739_47297_header_files) $(FFT_739_47297_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN_CT -DM739 -DQ47297 -o benchmark_739_47297_gaussian_ct $(rlwe_benchmark.c_files) $(rlwe_params_739_47297_c_files) $(FFT_739_47297_c_files)

benchmark_821_49261_uniform: $(global_header_files) $(rlwe_benchmark.c_files) $(random_files) $(rlwe_params_821_49261_header_files) $(rlwe_params_821_49261_c_files) $(FFT_821_49261_header_files) $(FFT_821_49261_c_files)
	$(C) $(CFLAGS) -DUNIFORM -DM821 -DQ49261 -o benchmark_821_49261_uniform $(rlwe_benchmark.c_files) $(rlwe_params_821_49261_c_files) $(FFT_821_49261_c_files)

benchmark_821_49261_gaussian: $(global_header_files) $(rlwe_benchmark.c_files) $(random_files) $(rlwe_params_821_49261_header_files) $(rlwe_params_821_49261_c_files) $(FFT_821_49261_header_files) $(FFT_821_49261_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN -DM821 -DQ49261 -o benchmark_821_49261_gaussian $(rlwe_benchmark.c_files) $(rlwe_params_821_49261_c_files) $(FFT_821_49261_c_files)

benchmark_821_49261_gaussian_ct: $(global_header_files) $(rlwe_benchmark.c_files) $(random_files) $(rlwe_params_821_49261_header_files) $(rlwe_params_821_49261_c_files) $(FFT_821_49261_header_files) $(FFT_821_49261_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN_CT -DM821 -DQ49261 -o benchmark_821_49261_gaussian_ct $(rlwe_benchmark.c_files) $(rlwe_params_821_49261_c_files) $(FFT_821_49261_c_files)

benchmark_256_15361_uniform: $(global_header_files) $(rlwe_benchmark.c_files) $(random_files) $(rlwe_params_256_15361_header_files) $(rlwe_params_256_15361_c_files) $(FFT_256_15361_header_files) $(FFT_256_15361_c_files)
	$(C) $(CFLAGS) -DUNIFORM -DM256 -DQ15361 -o benchmark_256_15361_uniform $(rlwe_benchmark.c_files) $(rlwe_params_256_15361_c_files) $(FFT_256_15361_c_files)

benchmark_256_15361_gaussian: $(global_header_files) $(rlwe_benchmark.c_files) $(random_files) $(rlwe_params_256_15361_header_files) $(rlwe_params_256_15361_c_files) $(FFT_256_15361_header_files) $(FFT_256_15361_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN -DM256 -DQ15361 -o benchmark_256_15361_gaussian $(rlwe_benchmark.c_files) $(rlwe_params_256_15361_c_files) $(FFT_256_15361_c_files)

benchmark_256_15361_gaussian_ct: $(global_header_files) $(rlwe_benchmark.c_files) $(random_files) $(rlwe_params_256_15361_header_files) $(rlwe_params_256_15361_c_files) $(FFT_256_15361_header_files) $(FFT_256_15361_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN_CT -DM256 -DQ15361 -o benchmark_256_15361_gaussian_ct $(rlwe_benchmark.c_files) $(rlwe_params_256_15361_c_files) $(FFT_256_15361_c_files)

benchmark_512_25601_uniform: $(global_header_files) $(rlwe_benchmark.c_files) $(random_files) $(rlwe_params_512_25601_header_files) $(rlwe_params_512_25601_c_files) $(FFT_512_25601_header_files) $(FFT_512_25601_c_files)
	$(C) $(CFLAGS) -DUNIFORM -DM512 -DQ25601 -o benchmark_512_25601_uniform $(rlwe_benchmark.c_files) $(rlwe_params_512_25601_c_files) $(FFT_512_25601_c_files)

benchmark_512_25601_gaussian: $(global_header_files) $(rlwe_benchmark.c_files) $(random_files) $(rlwe_params_512_25601_header_files) $(rlwe_params_512_25601_c_files) $(FFT_512_25601_header_files) $(FFT_512_25601_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN -DM512 -DQ25601 -o benchmark_512_25601_gaussian $(rlwe_benchmark.c_files) $(rlwe_params_512_25601_c_files) $(FFT_512_25601_c_files)

benchmark_512_25601_gaussian_ct: $(global_header_files) $(rlwe_benchmark.c_files) $(random_files) $(rlwe_params_512_25601_header_files) $(rlwe_params_512_25601_c_files) $(FFT_512_25601_header_files) $(FFT_512_25601_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN_CT -DM512 -DQ25601 -o benchmark_512_25601_gaussian_ct $(rlwe_benchmark.c_files) $(rlwe_params_512_25601_c_files) $(FFT_512_25601_c_files)

benchmark_1024_40961_uniform: $(global_header_files) $(rlwe_benchmark.c_files) $(random_files) $(rlwe_params_1024_40961_header_files) $(rlwe_params_1024_40961_c_files) $(FFT_1024_40961_header_files) $(FFT_1024_40961_c_files)
	$(C) $(CFLAGS) -DUNIFORM -DM1024 -DQ40961 -o benchmark_1024_40961_uniform $(rlwe_benchmark.c_files) $(rlwe_params_1024_40961_c_files) $(FFT_1024_40961_c_files)

benchmark_1024_40961_gaussian: $(global_header_files) $(rlwe_benchmark.c_files) $(random_files) $(rlwe_params_1024_40961_header_files) $(rlwe_params_1024_40961_c_files) $(FFT_1024_40961_header_files) $(FFT_1024_40961_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN -DM1024 -DQ40961 -o benchmark_1024_40961_gaussian $(rlwe_benchmark.c_files) $(rlwe_params_1024_40961_c_files) $(FFT_1024_40961_c_files)

benchmark_1024_40961_gaussian_ct: $(global_header_files) $(rlwe_benchmark.c_files) $(random_files) $(rlwe_params_1024_40961_header_files) $(rlwe_params_1024_40961_c_files) $(FFT_1024_40961_header_files) $(FFT_1024_40961_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN_CT -DM1024 -DQ40961 -o benchmark_1024_40961_gaussian_ct $(rlwe_benchmark.c_files) $(rlwe_params_1024_40961_c_files) $(FFT_1024_40961_c_files)

rlwe_337_32353_uniform: $(global_header_files) $(rlwe_main_files) $(random_files) $(rlwe_params_337_32353_header_files) $(rlwe_params_337_32353_c_files) $(FFT_337_32353_header_files) $(FFT_337_32353_c_files)
	$(C) $(CFLAGS) -DUNIFORM -DM337 -DQ32353 -o rlwe_337_32353_uniform $(rlwe_main_files) $(rlwe_params_337_32353_c_files) $(FFT_337_32353_c_files)

rlwe_337_32353_gaussian: $(global_header_files) $(rlwe_main_files) $(random_files) $(rlwe_params_337_32353_header_files) $(rlwe_params_337_32353_c_files) $(FFT_337_32353_header_files) $(FFT_337_32353_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN -DM337 -DQ32353 -o rlwe_337_32353_gaussian $(rlwe_main_files) $(rlwe_params_337_32353_c_files) $(FFT_337_32353_c_files)

rlwe_337_32353_gaussian_ct: $(global_header_files) $(rlwe_main_files) $(random_files) $(rlwe_params_337_32353_header_files) $(rlwe_params_337_32353_c_files) $(FFT_337_32353_header_files) $(FFT_337_32353_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN_CT -DM337 -DQ32353 -o rlwe_337_32353_gaussian_ct $(rlwe_main_files) $(rlwe_params_337_32353_c_files) $(FFT_337_32353_c_files)

rlwe_433_35507_uniform: $(global_header_files) $(rlwe_main_files) $(random_files) $(rlwe_params_433_35507_header_files) $(rlwe_params_433_35507_c_files) $(FFT_433_35507_header_files) $(FFT_433_35507_c_files)
	$(C) $(CFLAGS) -DUNIFORM -DM433 -DQ35507 -o rlwe_433_35507_uniform $(rlwe_main_files) $(rlwe_params_433_35507_c_files) $(FFT_433_35507_c_files)

rlwe_433_35507_gaussian: $(global_header_files) $(rlwe_main_files) $(random_files) $(rlwe_params_433_35507_header_files) $(rlwe_params_433_35507_c_files) $(FFT_433_35507_header_files) $(FFT_433_35507_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN -DM433 -DQ35507 -o rlwe_433_35507_gaussian $(rlwe_main_files) $(rlwe_params_433_35507_c_files) $(FFT_433_35507_c_files)

rlwe_433_35507_gaussian_ct: $(global_header_files) $(rlwe_main_files) $(random_files) $(rlwe_params_433_35507_header_files) $(rlwe_params_433_35507_c_files) $(FFT_433_35507_header_files) $(FFT_433_35507_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN_CT -DM433 -DQ35507 -o rlwe_433_35507_gaussian_ct $(rlwe_main_files) $(rlwe_params_433_35507_c_files) $(FFT_433_35507_c_files)

rlwe_541_41117_uniform: $(global_header_files) $(rlwe_main_files) $(random_files) $(rlwe_params_541_41117_header_files) $(rlwe_params_541_41117_c_files) $(FFT_541_41117_header_files) $(FFT_541_41117_c_files)
	$(C) $(CFLAGS) -DUNIFORM -DM541 -DQ41117 -o rlwe_541_41117_uniform $(rlwe_main_files) $(rlwe_params_541_41117_c_files) $(FFT_541_41117_c_files)

rlwe_541_41117_gaussian: $(global_header_files) $(rlwe_main_files) $(random_files) $(rlwe_params_541_41117_header_files) $(rlwe_params_541_41117_c_files) $(FFT_541_41117_header_files) $(FFT_541_41117_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN -DM541 -DQ41117 -o rlwe_541_41117_gaussian $(rlwe_main_files) $(rlwe_params_541_41117_c_files) $(FFT_541_41117_c_files)

rlwe_541_41117_gaussian_ct: $(global_header_files) $(rlwe_main_files) $(random_files) $(rlwe_params_541_41117_header_files) $(rlwe_params_541_41117_c_files) $(FFT_541_41117_header_files) $(FFT_541_41117_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN_CT -DM541 -DQ41117 -o rlwe_541_41117_gaussian_ct $(rlwe_main_files) $(rlwe_params_541_41117_c_files) $(FFT_541_41117_c_files)

rlwe_631_44171_uniform: $(global_header_files) $(rlwe_main_files) $(random_files) $(rlwe_params_631_44171_header_files) $(rlwe_params_631_44171_c_files) $(FFT_631_44171_header_files) $(FFT_631_44171_c_files)
	$(C) $(CFLAGS) -DUNIFORM -DM631 -DQ44171 -o rlwe_631_44171_uniform $(rlwe_main_files) $(rlwe_params_631_44171_c_files) $(FFT_631_44171_c_files)

rlwe_631_44171_gaussian: $(global_header_files) $(rlwe_main_files) $(random_files) $(rlwe_params_631_44171_header_files) $(rlwe_params_631_44171_c_files) $(FFT_631_44171_header_files) $(FFT_631_44171_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN -DM631 -DQ44171 -o rlwe_631_44171_gaussian $(rlwe_main_files) $(rlwe_params_631_44171_c_files) $(FFT_631_44171_c_files)

rlwe_631_44171_gaussian_ct: $(global_header_files) $(rlwe_main_files) $(random_files) $(rlwe_params_631_44171_header_files) $(rlwe_params_631_44171_c_files) $(FFT_631_44171_header_files) $(FFT_631_44171_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN_CT -DM631 -DQ44171 -o rlwe_631_44171_gaussian_ct $(rlwe_main_files) $(rlwe_params_631_44171_c_files) $(FFT_631_44171_c_files)

rlwe_739_47297_uniform: $(global_header_files) $(rlwe_main_files) $(random_files) $(rlwe_params_739_47297_header_files) $(rlwe_params_739_47297_c_files) $(FFT_739_47297_header_files) $(FFT_739_47297_c_files)
	$(C) $(CFLAGS) -DUNIFORM -DM739 -DQ47297 -o rlwe_739_47297_uniform $(rlwe_main_files) $(rlwe_params_739_47297_c_files) $(FFT_739_47297_c_files)

rlwe_739_47297_gaussian: $(global_header_files) $(rlwe_main_files) $(random_files) $(rlwe_params_739_47297_header_files) $(rlwe_params_739_47297_c_files) $(FFT_739_47297_header_files) $(FFT_739_47297_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN -DM739 -DQ47297 -o rlwe_739_47297_gaussian $(rlwe_main_files) $(rlwe_params_739_47297_c_files) $(FFT_739_47297_c_files)

rlwe_739_47297_gaussian_ct: $(global_header_files) $(rlwe_main_files) $(random_files) $(rlwe_params_739_47297_header_files) $(rlwe_params_739_47297_c_files) $(FFT_739_47297_header_files) $(FFT_739_47297_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN_CT -DM739 -DQ47297 -o rlwe_739_47297_gaussian_ct $(rlwe_main_files) $(rlwe_params_739_47297_c_files) $(FFT_739_47297_c_files)

rlwe_821_49261_uniform: $(global_header_files) $(rlwe_main_files) $(random_files) $(rlwe_params_821_49261_header_files) $(rlwe_params_821_49261_c_files) $(FFT_821_49261_header_files) $(FFT_821_49261_c_files)
	$(C) $(CFLAGS) -DUNIFORM -DM821 -DQ49261 -o rlwe_821_49261_uniform $(rlwe_main_files) $(rlwe_params_821_49261_c_files) $(FFT_821_49261_c_files)

rlwe_821_49261_gaussian: $(global_header_files) $(rlwe_main_files) $(random_files) $(rlwe_params_821_49261_header_files) $(rlwe_params_821_49261_c_files) $(FFT_821_49261_header_files) $(FFT_821_49261_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN -DM821 -DQ49261 -o rlwe_821_49261_gaussian $(rlwe_main_files) $(rlwe_params_821_49261_c_files) $(FFT_821_49261_c_files)

rlwe_821_49261_gaussian_ct: $(global_header_files) $(rlwe_main_files) $(random_files) $(rlwe_params_821_49261_header_files) $(rlwe_params_821_49261_c_files) $(FFT_821_49261_header_files) $(FFT_821_49261_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN_CT -DM821 -DQ49261 -o rlwe_821_49261_gaussian_ct $(rlwe_main_files) $(rlwe_params_821_49261_c_files) $(FFT_821_49261_c_files)

rlwe_256_15361_uniform: $(global_header_files) $(rlwe_main_files) $(random_files) $(rlwe_params_256_15361_header_files) $(rlwe_params_256_15361_c_files) $(FFT_256_15361_header_files) $(FFT_256_15361_c_files)
	$(C) $(CFLAGS) -DUNIFORM -DM256 -DQ15361 -o rlwe_256_15361_uniform $(rlwe_main_files) $(rlwe_params_256_15361_c_files) $(FFT_256_15361_c_files)

rlwe_256_15361_gaussian: $(global_header_files) $(rlwe_main_files) $(random_files) $(rlwe_params_256_15361_header_files) $(rlwe_params_256_15361_c_files) $(FFT_256_15361_header_files) $(FFT_256_15361_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN -DM256 -DQ15361 -o rlwe_256_15361_gaussian $(rlwe_main_files) $(rlwe_params_256_15361_c_files) $(FFT_256_15361_c_files)

rlwe_256_15361_gaussian_ct: $(global_header_files) $(rlwe_main_files) $(random_files) $(rlwe_params_256_15361_header_files) $(rlwe_params_256_15361_c_files) $(FFT_256_15361_header_files) $(FFT_256_15361_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN_CT -DM256 -DQ15361 -o rlwe_256_15361_gaussian_ct $(rlwe_main_files) $(rlwe_params_256_15361_c_files) $(FFT_256_15361_c_files)

rlwe_512_25601_uniform: $(global_header_files) $(rlwe_main_files) $(random_files) $(rlwe_params_512_25601_header_files) $(rlwe_params_512_25601_c_files) $(FFT_512_25601_header_files) $(FFT_512_25601_c_files)
	$(C) $(CFLAGS) -DUNIFORM -DM512 -DQ25601 -o rlwe_512_25601_uniform $(rlwe_main_files) $(rlwe_params_512_25601_c_files) $(FFT_512_25601_c_files)

rlwe_512_25601_gaussian: $(global_header_files) $(rlwe_main_files) $(random_files) $(rlwe_params_512_25601_header_files) $(rlwe_params_512_25601_c_files) $(FFT_512_25601_header_files) $(FFT_512_25601_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN -DM512 -DQ25601 -o rlwe_512_25601_gaussian $(rlwe_main_files) $(rlwe_params_512_25601_c_files) $(FFT_512_25601_c_files)

rlwe_512_25601_gaussian_ct: $(global_header_files) $(rlwe_main_files) $(random_files) $(rlwe_params_512_25601_header_files) $(rlwe_params_512_25601_c_files) $(FFT_512_25601_header_files) $(FFT_512_25601_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN_CT -DM512 -DQ25601 -o rlwe_512_25601_gaussian_ct $(rlwe_main_files) $(rlwe_params_512_25601_c_files) $(FFT_512_25601_c_files)

rlwe_1024_40961_uniform: $(global_header_files) $(rlwe_main_files) $(random_files) $(rlwe_params_1024_40961_header_files) $(rlwe_params_1024_40961_c_files) $(FFT_1024_40961_header_files) $(FFT_1024_40961_c_files)
	$(C) $(CFLAGS) -DUNIFORM -DM1024 -DQ40961 -o rlwe_1024_40961_uniform $(rlwe_main_files) $(rlwe_params_1024_40961_c_files) $(FFT_1024_40961_c_files)

rlwe_1024_40961_gaussian: $(global_header_files) $(rlwe_main_files) $(random_files) $(rlwe_params_1024_40961_header_files) $(rlwe_params_1024_40961_c_files) $(FFT_1024_40961_header_files) $(FFT_1024_40961_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN -DM1024 -DQ40961 -o rlwe_1024_40961_gaussian $(rlwe_main_files) $(rlwe_params_1024_40961_c_files) $(FFT_1024_40961_c_files)

rlwe_1024_40961_gaussian_ct: $(global_header_files) $(rlwe_main_files) $(random_files) $(rlwe_params_1024_40961_header_files) $(rlwe_params_1024_40961_c_files) $(FFT_1024_40961_header_files) $(FFT_1024_40961_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN_CT -DM1024 -DQ40961 -o rlwe_1024_40961_gaussian_ct $(rlwe_main_files) $(rlwe_params_1024_40961_c_files) $(FFT_1024_40961_c_files)

testvec_337_32353_uniform: $(global_header_files) $(rlwe_testvec_header_files) $(rlwe_testvec.c_files) $(random_files) $(rlwe_params_337_32353_header_files) $(rlwe_params_337_32353_c_files) $(FFT_337_32353_header_files) $(FFT_337_32353_c_files)
	$(C) $(CFLAGS) -DUNIFORM -DM337 -DQ32353 -o testvec_337_32353_uniform $(rlwe_testvec.c_files) $(rlwe_params_337_32353_c_files) $(FFT_337_32353_c_files)

testvec_337_32353_gaussian: $(global_header_files) $(rlwe_testvec_header_files) $(rlwe_testvec.c_files) $(random_files) $(rlwe_params_337_32353_header_files) $(rlwe_params_337_32353_c_files) $(FFT_337_32353_header_files) $(FFT_337_32353_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN -DM337 -DQ32353 -o testvec_337_32353_gaussian $(rlwe_testvec.c_files) $(rlwe_params_337_32353_c_files) $(FFT_337_32353_c_files)

testvec_337_32353_gaussian_ct: $(global_header_files) $(rlwe_testvec_header_files) $(rlwe_testvec.c_files) $(random_files) $(rlwe_params_337_32353_header_files) $(rlwe_params_337_32353_c_files) $(FFT_337_32353_header_files) $(FFT_337_32353_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN_CT -DM337 -DQ32353 -o testvec_337_32353_gaussian_ct $(rlwe_testvec.c_files) $(rlwe_params_337_32353_c_files) $(FFT_337_32353_c_files)

testvec_433_35507_uniform: $(global_header_files) $(rlwe_testvec_header_files) $(rlwe_testvec.c_files) $(random_files) $(rlwe_params_433_35507_header_files) $(rlwe_params_433_35507_c_files) $(FFT_433_35507_header_files) $(FFT_433_35507_c_files)
	$(C) $(CFLAGS) -DUNIFORM -DM433 -DQ35507 -o testvec_433_35507_uniform $(rlwe_testvec.c_files) $(rlwe_params_433_35507_c_files) $(FFT_433_35507_c_files)

testvec_433_35507_gaussian: $(global_header_files) $(rlwe_testvec_header_files) $(rlwe_testvec.c_files) $(random_files) $(rlwe_params_433_35507_header_files) $(rlwe_params_433_35507_c_files) $(FFT_433_35507_header_files) $(FFT_433_35507_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN -DM433 -DQ35507 -o testvec_433_35507_gaussian $(rlwe_testvec.c_files) $(rlwe_params_433_35507_c_files) $(FFT_433_35507_c_files)

testvec_433_35507_gaussian_ct: $(global_header_files) $(rlwe_testvec_header_files) $(rlwe_testvec.c_files) $(random_files) $(rlwe_params_433_35507_header_files) $(rlwe_params_433_35507_c_files) $(FFT_433_35507_header_files) $(FFT_433_35507_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN_CT -DM433 -DQ35507 -o testvec_433_35507_gaussian_ct $(rlwe_testvec.c_files) $(rlwe_params_433_35507_c_files) $(FFT_433_35507_c_files)

testvec_541_41117_uniform: $(global_header_files) $(rlwe_testvec_header_files) $(rlwe_testvec.c_files) $(random_files) $(rlwe_params_541_41117_header_files) $(rlwe_params_541_41117_c_files) $(FFT_541_41117_header_files) $(FFT_541_41117_c_files)
	$(C) $(CFLAGS) -DUNIFORM -DM541 -DQ41117 -o testvec_541_41117_uniform $(rlwe_testvec.c_files) $(rlwe_params_541_41117_c_files) $(FFT_541_41117_c_files)

testvec_541_41117_gaussian: $(global_header_files) $(rlwe_testvec_header_files) $(rlwe_testvec.c_files) $(random_files) $(rlwe_params_541_41117_header_files) $(rlwe_params_541_41117_c_files) $(FFT_541_41117_header_files) $(FFT_541_41117_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN -DM541 -DQ41117 -o testvec_541_41117_gaussian $(rlwe_testvec.c_files) $(rlwe_params_541_41117_c_files) $(FFT_541_41117_c_files)

testvec_541_41117_gaussian_ct: $(global_header_files) $(rlwe_testvec_header_files) $(rlwe_testvec.c_files) $(random_files) $(rlwe_params_541_41117_header_files) $(rlwe_params_541_41117_c_files) $(FFT_541_41117_header_files) $(FFT_541_41117_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN_CT -DM541 -DQ41117 -o testvec_541_41117_gaussian_ct $(rlwe_testvec.c_files) $(rlwe_params_541_41117_c_files) $(FFT_541_41117_c_files)

testvec_631_44171_uniform: $(global_header_files) $(rlwe_testvec_header_files) $(rlwe_testvec.c_files) $(random_files) $(rlwe_params_631_44171_header_files) $(rlwe_params_631_44171_c_files) $(FFT_631_44171_header_files) $(FFT_631_44171_c_files)
	$(C) $(CFLAGS) -DUNIFORM -DM631 -DQ44171 -o testvec_631_44171_uniform $(rlwe_testvec.c_files) $(rlwe_params_631_44171_c_files) $(FFT_631_44171_c_files)

testvec_631_44171_gaussian: $(global_header_files) $(rlwe_testvec_header_files) $(rlwe_testvec.c_files) $(random_files) $(rlwe_params_631_44171_header_files) $(rlwe_params_631_44171_c_files) $(FFT_631_44171_header_files) $(FFT_631_44171_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN -DM631 -DQ44171 -o testvec_631_44171_gaussian $(rlwe_testvec.c_files) $(rlwe_params_631_44171_c_files) $(FFT_631_44171_c_files)

testvec_631_44171_gaussian_ct: $(global_header_files) $(rlwe_testvec_header_files) $(rlwe_testvec.c_files) $(random_files) $(rlwe_params_631_44171_header_files) $(rlwe_params_631_44171_c_files) $(FFT_631_44171_header_files) $(FFT_631_44171_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN_CT -DM631 -DQ44171 -o testvec_631_44171_gaussian_ct $(rlwe_testvec.c_files) $(rlwe_params_631_44171_c_files) $(FFT_631_44171_c_files)

testvec_739_47297_uniform: $(global_header_files) $(rlwe_testvec_header_files) $(rlwe_testvec.c_files) $(random_files) $(rlwe_params_739_47297_header_files) $(rlwe_params_739_47297_c_files) $(FFT_739_47297_header_files) $(FFT_739_47297_c_files)
	$(C) $(CFLAGS) -DUNIFORM -DM739 -DQ47297 -o testvec_739_47297_uniform $(rlwe_testvec.c_files) $(rlwe_params_739_47297_c_files) $(FFT_739_47297_c_files)

testvec_739_47297_gaussian: $(global_header_files) $(rlwe_testvec_header_files) $(rlwe_testvec.c_files) $(random_files) $(rlwe_params_739_47297_header_files) $(rlwe_params_739_47297_c_files) $(FFT_739_47297_header_files) $(FFT_739_47297_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN -DM739 -DQ47297 -o testvec_739_47297_gaussian $(rlwe_testvec.c_files) $(rlwe_params_739_47297_c_files) $(FFT_739_47297_c_files)

testvec_739_47297_gaussian_ct: $(global_header_files) $(rlwe_testvec_header_files) $(rlwe_testvec.c_files) $(random_files) $(rlwe_params_739_47297_header_files) $(rlwe_params_739_47297_c_files) $(FFT_739_47297_header_files) $(FFT_739_47297_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN_CT -DM739 -DQ47297 -o testvec_739_47297_gaussian_ct $(rlwe_testvec.c_files) $(rlwe_params_739_47297_c_files) $(FFT_739_47297_c_files)

testvec_821_49261_uniform: $(global_header_files) $(rlwe_testvec_header_files) $(rlwe_testvec.c_files) $(random_files) $(rlwe_params_821_49261_header_files) $(rlwe_params_821_49261_c_files) $(FFT_821_49261_header_files) $(FFT_821_49261_c_files)
	$(C) $(CFLAGS) -DUNIFORM -DM821 -DQ49261 -o testvec_821_49261_uniform $(rlwe_testvec.c_files) $(rlwe_params_821_49261_c_files) $(FFT_821_49261_c_files)

testvec_821_49261_gaussian: $(global_header_files) $(rlwe_testvec_header_files) $(rlwe_testvec.c_files) $(random_files) $(rlwe_params_821_49261_header_files) $(rlwe_params_821_49261_c_files) $(FFT_821_49261_header_files) $(FFT_821_49261_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN -DM821 -DQ49261 -o testvec_821_49261_gaussian $(rlwe_testvec.c_files) $(rlwe_params_821_49261_c_files) $(FFT_821_49261_c_files)

testvec_821_49261_gaussian_ct: $(global_header_files) $(rlwe_testvec_header_files) $(rlwe_testvec.c_files) $(random_files) $(rlwe_params_821_49261_header_files) $(rlwe_params_821_49261_c_files) $(FFT_821_49261_header_files) $(FFT_821_49261_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN_CT -DM821 -DQ49261 -o testvec_821_49261_gaussian_ct $(rlwe_testvec.c_files) $(rlwe_params_821_49261_c_files) $(FFT_821_49261_c_files)

testvec_256_15361_uniform: $(global_header_files) $(rlwe_testvec_header_files) $(rlwe_testvec.c_files) $(random_files) $(rlwe_params_256_15361_header_files) $(rlwe_params_256_15361_c_files) $(FFT_256_15361_header_files) $(FFT_256_15361_c_files)
	$(C) $(CFLAGS) -DUNIFORM -DM256 -DQ15361 -o testvec_256_15361_uniform $(rlwe_testvec.c_files) $(rlwe_params_256_15361_c_files) $(FFT_256_15361_c_files)

testvec_256_15361_gaussian: $(global_header_files) $(rlwe_testvec_header_files) $(rlwe_testvec.c_files) $(random_files) $(rlwe_params_256_15361_header_files) $(rlwe_params_256_15361_c_files) $(FFT_256_15361_header_files) $(FFT_256_15361_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN -DM256 -DQ15361 -o testvec_256_15361_gaussian $(rlwe_testvec.c_files) $(rlwe_params_256_15361_c_files) $(FFT_256_15361_c_files)

testvec_256_15361_gaussian_ct: $(global_header_files) $(rlwe_testvec_header_files) $(rlwe_testvec.c_files) $(random_files) $(rlwe_params_256_15361_header_files) $(rlwe_params_256_15361_c_files) $(FFT_256_15361_header_files) $(FFT_256_15361_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN_CT -DM256 -DQ15361 -o testvec_256_15361_gaussian_ct $(rlwe_testvec.c_files) $(rlwe_params_256_15361_c_files) $(FFT_256_15361_c_files)

testvec_512_25601_uniform: $(global_header_files) $(rlwe_testvec_header_files) $(rlwe_testvec.c_files) $(random_files) $(rlwe_params_512_25601_header_files) $(rlwe_params_512_25601_c_files) $(FFT_512_25601_header_files) $(FFT_512_25601_c_files)
	$(C) $(CFLAGS) -DUNIFORM -DM512 -DQ25601 -o testvec_512_25601_uniform $(rlwe_testvec.c_files) $(rlwe_params_512_25601_c_files) $(FFT_512_25601_c_files)

testvec_512_25601_gaussian: $(global_header_files) $(rlwe_testvec_header_files) $(rlwe_testvec.c_files) $(random_files) $(rlwe_params_512_25601_header_files) $(rlwe_params_512_25601_c_files) $(FFT_512_25601_header_files) $(FFT_512_25601_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN -DM512 -DQ25601 -o testvec_512_25601_gaussian $(rlwe_testvec.c_files) $(rlwe_params_512_25601_c_files) $(FFT_512_25601_c_files)

testvec_512_25601_gaussian_ct: $(global_header_files) $(rlwe_testvec_header_files) $(rlwe_testvec.c_files) $(random_files) $(rlwe_params_512_25601_header_files) $(rlwe_params_512_25601_c_files) $(FFT_512_25601_header_files) $(FFT_512_25601_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN_CT -DM512 -DQ25601 -o testvec_512_25601_gaussian_ct $(rlwe_testvec.c_files) $(rlwe_params_512_25601_c_files) $(FFT_512_25601_c_files)

testvec_1024_40961_uniform: $(global_header_files) $(rlwe_testvec_header_files) $(rlwe_testvec.c_files) $(random_files) $(rlwe_params_1024_40961_header_files) $(rlwe_params_1024_40961_c_files) $(FFT_1024_40961_header_files) $(FFT_1024_40961_c_files)
	$(C) $(CFLAGS) -DUNIFORM -DM1024 -DQ40961 -o testvec_1024_40961_uniform $(rlwe_testvec.c_files) $(rlwe_params_1024_40961_c_files) $(FFT_1024_40961_c_files)

testvec_1024_40961_gaussian: $(global_header_files) $(rlwe_testvec_header_files) $(rlwe_testvec.c_files) $(random_files) $(rlwe_params_1024_40961_header_files) $(rlwe_params_1024_40961_c_files) $(FFT_1024_40961_header_files) $(FFT_1024_40961_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN -DM1024 -DQ40961 -o testvec_1024_40961_gaussian $(rlwe_testvec.c_files) $(rlwe_params_1024_40961_c_files) $(FFT_1024_40961_c_files)

testvec_1024_40961_gaussian_ct: $(global_header_files) $(rlwe_testvec_header_files) $(rlwe_testvec.c_files) $(random_files) $(rlwe_params_1024_40961_header_files) $(rlwe_params_1024_40961_c_files) $(FFT_1024_40961_header_files) $(FFT_1024_40961_c_files)
	$(C) $(CFLAGS) -DGAUSSIAN_CT -DM1024 -DQ40961 -o testvec_1024_40961_gaussian_ct $(rlwe_testvec.c_files) $(rlwe_params_1024_40961_c_files) $(FFT_1024_40961_c_files)

%.log: %
	./$< > $@

%.log: %
	./$< > $@

benchmark_all: benchmark_337_32353_uniform benchmark_337_32353_gaussian benchmark_337_32353_gaussian_ct benchmark_433_35507_uniform benchmark_433_35507_gaussian benchmark_433_35507_gaussian_ct benchmark_541_41117_uniform benchmark_541_41117_gaussian benchmark_541_41117_gaussian_ct benchmark_631_44171_uniform benchmark_631_44171_gaussian benchmark_631_44171_gaussian_ct benchmark_739_47297_uniform benchmark_739_47297_gaussian benchmark_739_47297_gaussian_ct benchmark_821_49261_uniform benchmark_821_49261_gaussian benchmark_821_49261_gaussian_ct benchmark_256_15361_uniform benchmark_256_15361_gaussian benchmark_256_15361_gaussian_ct benchmark_512_25601_uniform benchmark_512_25601_gaussian benchmark_512_25601_gaussian_ct benchmark_1024_40961_uniform benchmark_1024_40961_gaussian benchmark_1024_40961_gaussian_ct 

benchmark.log_all: benchmark_337_32353_uniform.log benchmark_337_32353_gaussian.log benchmark_337_32353_gaussian_ct.log benchmark_433_35507_uniform.log benchmark_433_35507_gaussian.log benchmark_433_35507_gaussian_ct.log benchmark_541_41117_uniform.log benchmark_541_41117_gaussian.log benchmark_541_41117_gaussian_ct.log benchmark_631_44171_uniform.log benchmark_631_44171_gaussian.log benchmark_631_44171_gaussian_ct.log benchmark_739_47297_uniform.log benchmark_739_47297_gaussian.log benchmark_739_47297_gaussian_ct.log benchmark_821_49261_uniform.log benchmark_821_49261_gaussian.log benchmark_821_49261_gaussian_ct.log benchmark_256_15361_uniform.log benchmark_256_15361_gaussian.log benchmark_256_15361_gaussian_ct.log benchmark_512_25601_uniform.log benchmark_512_25601_gaussian.log benchmark_512_25601_gaussian_ct.log benchmark_1024_40961_uniform.log benchmark_1024_40961_gaussian.log benchmark_1024_40961_gaussian_ct.log 

rlwe_all: rlwe_337_32353_uniform rlwe_337_32353_gaussian rlwe_337_32353_gaussian_ct rlwe_433_35507_uniform rlwe_433_35507_gaussian rlwe_433_35507_gaussian_ct rlwe_541_41117_uniform rlwe_541_41117_gaussian rlwe_541_41117_gaussian_ct rlwe_631_44171_uniform rlwe_631_44171_gaussian rlwe_631_44171_gaussian_ct rlwe_739_47297_uniform rlwe_739_47297_gaussian rlwe_739_47297_gaussian_ct rlwe_821_49261_uniform rlwe_821_49261_gaussian rlwe_821_49261_gaussian_ct rlwe_256_15361_uniform rlwe_256_15361_gaussian rlwe_256_15361_gaussian_ct rlwe_512_25601_uniform rlwe_512_25601_gaussian rlwe_512_25601_gaussian_ct rlwe_1024_40961_uniform rlwe_1024_40961_gaussian rlwe_1024_40961_gaussian_ct 

rlwe.log_all: rlwe_337_32353_uniform.log rlwe_337_32353_gaussian.log rlwe_337_32353_gaussian_ct.log rlwe_433_35507_uniform.log rlwe_433_35507_gaussian.log rlwe_433_35507_gaussian_ct.log rlwe_541_41117_uniform.log rlwe_541_41117_gaussian.log rlwe_541_41117_gaussian_ct.log rlwe_631_44171_uniform.log rlwe_631_44171_gaussian.log rlwe_631_44171_gaussian_ct.log rlwe_739_47297_uniform.log rlwe_739_47297_gaussian.log rlwe_739_47297_gaussian_ct.log rlwe_821_49261_uniform.log rlwe_821_49261_gaussian.log rlwe_821_49261_gaussian_ct.log rlwe_256_15361_uniform.log rlwe_256_15361_gaussian.log rlwe_256_15361_gaussian_ct.log rlwe_512_25601_uniform.log rlwe_512_25601_gaussian.log rlwe_512_25601_gaussian_ct.log rlwe_1024_40961_uniform.log rlwe_1024_40961_gaussian.log rlwe_1024_40961_gaussian_ct.log 

testvec_all: testvec_337_32353_uniform testvec_337_32353_gaussian testvec_337_32353_gaussian_ct testvec_433_35507_uniform testvec_433_35507_gaussian testvec_433_35507_gaussian_ct testvec_541_41117_uniform testvec_541_41117_gaussian testvec_541_41117_gaussian_ct testvec_631_44171_uniform testvec_631_44171_gaussian testvec_631_44171_gaussian_ct testvec_739_47297_uniform testvec_739_47297_gaussian testvec_739_47297_gaussian_ct testvec_821_49261_uniform testvec_821_49261_gaussian testvec_821_49261_gaussian_ct testvec_256_15361_uniform testvec_256_15361_gaussian testvec_256_15361_gaussian_ct testvec_512_25601_uniform testvec_512_25601_gaussian testvec_512_25601_gaussian_ct testvec_1024_40961_uniform testvec_1024_40961_gaussian testvec_1024_40961_gaussian_ct 

testvec.log_all: testvec_337_32353_uniform.log testvec_337_32353_gaussian.log testvec_337_32353_gaussian_ct.log testvec_433_35507_uniform.log testvec_433_35507_gaussian.log testvec_433_35507_gaussian_ct.log testvec_541_41117_uniform.log testvec_541_41117_gaussian.log testvec_541_41117_gaussian_ct.log testvec_631_44171_uniform.log testvec_631_44171_gaussian.log testvec_631_44171_gaussian_ct.log testvec_739_47297_uniform.log testvec_739_47297_gaussian.log testvec_739_47297_gaussian_ct.log testvec_821_49261_uniform.log testvec_821_49261_gaussian.log testvec_821_49261_gaussian_ct.log testvec_256_15361_uniform.log testvec_256_15361_gaussian.log testvec_256_15361_gaussian_ct.log testvec_512_25601_uniform.log testvec_512_25601_gaussian.log testvec_512_25601_gaussian_ct.log testvec_1024_40961_uniform.log testvec_1024_40961_gaussian.log testvec_1024_40961_gaussian_ct.log 

clean:
	rm -rf benchmark_337_32353_uniform benchmark_337_32353_uniform.log benchmark_337_32353_gaussian benchmark_337_32353_gaussian.log benchmark_337_32353_gaussian_ct benchmark_337_32353_gaussian_ct.log benchmark_433_35507_uniform benchmark_433_35507_uniform.log benchmark_433_35507_gaussian benchmark_433_35507_gaussian.log benchmark_433_35507_gaussian_ct benchmark_433_35507_gaussian_ct.log benchmark_541_41117_uniform benchmark_541_41117_uniform.log benchmark_541_41117_gaussian benchmark_541_41117_gaussian.log benchmark_541_41117_gaussian_ct benchmark_541_41117_gaussian_ct.log benchmark_631_44171_uniform benchmark_631_44171_uniform.log benchmark_631_44171_gaussian benchmark_631_44171_gaussian.log benchmark_631_44171_gaussian_ct benchmark_631_44171_gaussian_ct.log benchmark_739_47297_uniform benchmark_739_47297_uniform.log benchmark_739_47297_gaussian benchmark_739_47297_gaussian.log benchmark_739_47297_gaussian_ct benchmark_739_47297_gaussian_ct.log benchmark_821_49261_uniform benchmark_821_49261_uniform.log benchmark_821_49261_gaussian benchmark_821_49261_gaussian.log benchmark_821_49261_gaussian_ct benchmark_821_49261_gaussian_ct.log benchmark_256_15361_uniform benchmark_256_15361_uniform.log benchmark_256_15361_gaussian benchmark_256_15361_gaussian.log benchmark_256_15361_gaussian_ct benchmark_256_15361_gaussian_ct.log benchmark_512_25601_uniform benchmark_512_25601_uniform.log benchmark_512_25601_gaussian benchmark_512_25601_gaussian.log benchmark_512_25601_gaussian_ct benchmark_512_25601_gaussian_ct.log benchmark_1024_40961_uniform benchmark_1024_40961_uniform.log benchmark_1024_40961_gaussian benchmark_1024_40961_gaussian.log benchmark_1024_40961_gaussian_ct benchmark_1024_40961_gaussian_ct.log rlwe_337_32353_uniform rlwe_337_32353_uniform.log rlwe_337_32353_gaussian rlwe_337_32353_gaussian.log rlwe_337_32353_gaussian_ct rlwe_337_32353_gaussian_ct.log rlwe_433_35507_uniform rlwe_433_35507_uniform.log rlwe_433_35507_gaussian rlwe_433_35507_gaussian.log rlwe_433_35507_gaussian_ct rlwe_433_35507_gaussian_ct.log rlwe_541_41117_uniform rlwe_541_41117_uniform.log rlwe_541_41117_gaussian rlwe_541_41117_gaussian.log rlwe_541_41117_gaussian_ct rlwe_541_41117_gaussian_ct.log rlwe_631_44171_uniform rlwe_631_44171_uniform.log rlwe_631_44171_gaussian rlwe_631_44171_gaussian.log rlwe_631_44171_gaussian_ct rlwe_631_44171_gaussian_ct.log rlwe_739_47297_uniform rlwe_739_47297_uniform.log rlwe_739_47297_gaussian rlwe_739_47297_gaussian.log rlwe_739_47297_gaussian_ct rlwe_739_47297_gaussian_ct.log rlwe_821_49261_uniform rlwe_821_49261_uniform.log rlwe_821_49261_gaussian rlwe_821_49261_gaussian.log rlwe_821_49261_gaussian_ct rlwe_821_49261_gaussian_ct.log rlwe_256_15361_uniform rlwe_256_15361_uniform.log rlwe_256_15361_gaussian rlwe_256_15361_gaussian.log rlwe_256_15361_gaussian_ct rlwe_256_15361_gaussian_ct.log rlwe_512_25601_uniform rlwe_512_25601_uniform.log rlwe_512_25601_gaussian rlwe_512_25601_gaussian.log rlwe_512_25601_gaussian_ct rlwe_512_25601_gaussian_ct.log rlwe_1024_40961_uniform rlwe_1024_40961_uniform.log rlwe_1024_40961_gaussian rlwe_1024_40961_gaussian.log rlwe_1024_40961_gaussian_ct rlwe_1024_40961_gaussian_ct.log testvec_337_32353_uniform testvec_337_32353_uniform.log testvec_337_32353_gaussian testvec_337_32353_gaussian.log testvec_337_32353_gaussian_ct testvec_337_32353_gaussian_ct.log testvec_433_35507_uniform testvec_433_35507_uniform.log testvec_433_35507_gaussian testvec_433_35507_gaussian.log testvec_433_35507_gaussian_ct testvec_433_35507_gaussian_ct.log testvec_541_41117_uniform testvec_541_41117_uniform.log testvec_541_41117_gaussian testvec_541_41117_gaussian.log testvec_541_41117_gaussian_ct testvec_541_41117_gaussian_ct.log testvec_631_44171_uniform testvec_631_44171_uniform.log testvec_631_44171_gaussian testvec_631_44171_gaussian.log testvec_631_44171_gaussian_ct testvec_631_44171_gaussian_ct.log testvec_739_47297_uniform testvec_739_47297_uniform.log testvec_739_47297_gaussian testvec_739_47297_gaussian.log testvec_739_47297_gaussian_ct testvec_739_47297_gaussian_ct.log testvec_821_49261_uniform testvec_821_49261_uniform.log testvec_821_49261_gaussian testvec_821_49261_gaussian.log testvec_821_49261_gaussian_ct testvec_821_49261_gaussian_ct.log testvec_256_15361_uniform testvec_256_15361_uniform.log testvec_256_15361_gaussian testvec_256_15361_gaussian.log testvec_256_15361_gaussian_ct testvec_256_15361_gaussian_ct.log testvec_512_25601_uniform testvec_512_25601_uniform.log testvec_512_25601_gaussian testvec_512_25601_gaussian.log testvec_512_25601_gaussian_ct testvec_512_25601_gaussian_ct.log testvec_1024_40961_uniform testvec_1024_40961_uniform.log testvec_1024_40961_gaussian testvec_1024_40961_gaussian.log testvec_1024_40961_gaussian_ct testvec_1024_40961_gaussian_ct.log  *~



