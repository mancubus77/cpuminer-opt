#ifndef __SHA256D_4WAY_H__
#define __SHA256D_4WAY_H__ 1

#include <stdint.h>
#include "algo-gate-api.h"

#if defined(__AVX512F__) && defined(__AVX512VL__) && defined(__AVX512DQ__) && defined(__AVX512BW__)
  #define SHA256D_16WAY 1
#elif defined(__AVX2__)
  #define SHA256D_8WAY 1
#else
  #define SHA256D_4WAY 1
#endif

bool register_sha256d_algo( algo_gate_t* gate );

#if defined(SHA256D_16WAY)

int scanhash_sha256d_16way( struct work *work, uint32_t max_nonce,
                           uint64_t *hashes_done, struct thr_info *mythr );
#endif

#if defined(SHA256D_8WAY)

int scanhash_sha256d_8way( struct work *work, uint32_t max_nonce,
                           uint64_t *hashes_done, struct thr_info *mythr );
#endif

#if defined(SHA256D_4WAY)

int scanhash_sha256d_4way( struct work *work, uint32_t max_nonce,
                           uint64_t *hashes_done, struct thr_info *mythr );
#endif


/*
#if defined(__SHA__)

int scanhash_sha256d( struct work *work, uint32_t max_nonce,
                      uint64_t *hashes_done, struct thr_info *mythr );

#endif
*/

#endif

