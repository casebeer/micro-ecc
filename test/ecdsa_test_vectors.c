/* Copyright 2020, Kenneth MacKay. Licensed under the BSD 2-clause license. */

#include "uECC.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test_vectors/test_vector.h"

Test secp256k1_tests[] = {
    {
        "ebb2c082fd7727890a28ac82f6bdf97bad8de9f5d7c9028692de1a255cad3e0f",
        "779dd197a5df977ed2cf6cb31d82d43328b790dc6b3b7d4437a427bd5847dfcde94b724a555b6d017bb7607c3e3281daf5b1699d6ef4124975c9237b917d426f",
        "49a0d7b786ec9cde0d0721d72804befd06571c974b191efb42ecf322ba9ddd9a",
        "4b688df40bcedbe641ddb16ff0a1842d9c67ea1c3bf63f3e0471baa664531d1a",
        "241097efbf8b63bf145c8961dbdf10c310efbb3b2676bbc0f8b08505c9e2f795",
        "021006b7838609339e8b415a7f9acb1b661828131aef1ecbc7955dfb01f3ca0e"
    },
};


// test cases from https://github.com/kmackay/micro-ecc/issues/196
Test secp256r1_bug196_tests[] = {
    {
        // private key set to 0 to trigger verify-only test mode
        "0000000000000000000000000000000000000000000000000000000000000000",
        "495d1499b6626ea994af768ff960acfac3af290f8c9816a158a7ee71be895e792a168aaeb797ea665786966356715bcb44cc51d792f4bcd6320c370a73871f69", // public_key
        "0000000000000000000000000000000000000000000000000000000000000000", // k
        "ef798cff4c935dca6cc19338f48ffd6185a7eb461216985fc3d72552f5b91836", // message
        "495d1499b6626ea994af768ff960acfac3af290f8c9816a158a7ee71be895e79", // R
        "06783594bfe892d4c1daa797f9b49d4c29b9f5131f9a203c717c0224329b18f9", // S
    },
    {
        "0000000000000000000000000000000000000000000000000000000000000000", // private_key
        "7cf27b188d034f7e8a52380304b51ac3c08969e277f21b35a60b48fc4766997807775510db8ed040293d9ac69f7430dbba7dade63ce982299e04b79d227873d1", // public_key
        "0000000000000000000000000000000000000000000000000000000000000000", // k
        "797601b76d29603d167fa1062cc27b00bb0e39493bf3b7bbafa610c2b24f4a20", // hash
        "56cd9cf152bccc3a64e41e2b2bf91ed0661e0821b14b50abe93c05ea889afed3", // r
        "f93452957106bab410617e306d876bb58fa7d7b5a515ac6b6181d8d638651fc7", // s
    },
};

extern int uECC_sign_with_k(const uint8_t *private_key,
                            const uint8_t *message_hash,
                            unsigned hash_size,
                            const uint8_t *k,
                            uint8_t *signature,
                            uECC_Curve curve);


void vli_print(uint8_t *vli, unsigned int size) {
    for(unsigned i=0; i<size; ++i) {
        //printf("%02X ", (unsigned)vli[i]);
        printf("%02x", (unsigned)vli[i]);
    }
    printf("\n");
}

int max(int a, int b) {
  return (a >= b) ? a : b;
}


void strtobytes(const char* str, uint8_t* bytes, int count) {
  int slen = strlen(str);
  const char *strpos = str;
  int offset = max(count - slen / 2, 0);
  int c;

  //printf("%s\n", str);

  for (c = 0; c < count; c++) {
    bytes[c] = 0;
  }

  // odd # of chars, special case the first nibble
  if (slen % 2 && offset > 0 && strpos + 1 < str + slen) {
    sscanf(strpos, "%1hhx", &bytes[offset - 1]);
    strpos++;
  }

  for (c = offset; c < count && strpos < str + slen; ++c) {
    if (sscanf(strpos, "%2hhx", &bytes[c]) != 1) {
      printf("Failed to read string to bytes %d, %d in string:\n", c, (int)(strpos - str));
      printf("  %s", str);
      exit(1);
    }
    strpos += 2;
  }
}

int global_passes = 0;
int global_failures = 0;

int run(Test* tests, int num_tests, uECC_Curve curve) {
    uint8_t private[32] = {0};
    uint8_t public[64] = {0};
    uint8_t k[32] = {0};
    uint8_t hash[32] = {0};
    uint8_t r[32] = {0};
    uint8_t s[32] = {0};
    uint8_t zeroes[64] = {0};

    uint8_t signature[64] = {0};

    int result;
    int should_verify;
    int i;
    int private_key_size;
    int public_key_size;
    int all_success = 1;
    int fail = 0;
    int passes = 0;
    int failures = 0;

    private_key_size = uECC_curve_private_key_size(curve);
    public_key_size = uECC_curve_public_key_size(curve);

    for (i = 0; i < num_tests; ++i) {
        fail = 0;
        strtobytes(tests[i].private_key, private, private_key_size);
        strtobytes(tests[i].public_key, public, public_key_size);
        strtobytes(tests[i].k, k, private_key_size);
        strtobytes(tests[i].hash, hash, private_key_size);
        strtobytes(tests[i].r, r, private_key_size);
        strtobytes(tests[i].s, s, private_key_size);

        /* only generate a signature if we have a private key */
        if (memcmp(private, zeroes, private_key_size) != 0) {
            result = uECC_sign_with_k(private, hash, private_key_size, k, signature, curve);
            if (!result) {
                fail = 1;
                all_success = 0;
                printf("  Sign failed for test %d\n", i);
            }
            if (result) {
                should_verify = 1;
                if (memcmp(signature, r, private_key_size) != 0) {
                    fail = 1;
                    all_success = 0;
                    printf("  Got incorrect r for test %d\n", i);
                    printf("    Expected:   ");
                    vli_print(r, private_key_size);
                    printf("    Calculated: ");
                    vli_print(signature, private_key_size);
                }
                if (memcmp(signature + private_key_size, s, private_key_size) != 0) {
                    fail = 1;
                    all_success = 0;
                    printf("  Got incorrect s for test %d\n", i);
                    printf("    Expected:   ");
                    vli_print(s, private_key_size);
                    printf("    Calculated: ");
                    vli_print(signature + private_key_size, private_key_size);
                }
            }
        } else {
            /* else this is a validate-only test */
            /* combine r||s to get verifyable signature */
            memcpy(signature, r, private_key_size);
            memcpy(signature + private_key_size, s, private_key_size);
            should_verify = 1;
        }

        if (should_verify) {
            result = uECC_verify(public, hash, private_key_size, signature, curve);
            if (!result) {
                fail = 1;
                all_success = 0;
                printf("  Verify failed for test %d\n", i);
            }
        }

        if (fail) {
            failures++;
        } else {
            passes++;
            //printf("  Pass for test %d\n", i);
        }

    }

    printf("  Pass: %d Fail: %d\n", passes, failures);
    global_passes += passes;
    global_failures += failures;
    return all_success;
}

#define RUN_TESTS(curve, test_vectors) \
    printf(#curve "(" #test_vectors "):\n"); \
    if (run(test_vectors, sizeof(test_vectors) / sizeof(test_vectors[0]), uECC_##curve()) ) { \
        printf("  All passed\n"); \
    } else { \
        printf("  Failed\n"); \
        failed_tests++; \
    }

int main() {
    int failed_tests = 0;

    printf("ECDSA Test Vectors\n");
#if uECC_SUPPORTS_secp256k1
    RUN_TESTS(secp256k1, secp256k1_tests)
#endif
#if uECC_SUPPORTS_secp256r1
#include "test_vectors/nist_fips_186_secp256r1_tvs.h"
#include "test_vectors/rfc6979.h"
    RUN_TESTS(secp256r1, secp256r1_bug196_tests)
    RUN_TESTS(secp256r1, nist_fips_186_secp256r1_tvs)
    RUN_TESTS(secp256r1, rfc6979_p256_tvs)
#endif
#if uECC_SUPPORTS_secp224r1
#include "test_vectors/nist_fips_186_secp224r1_tvs.h"
#include "test_vectors/rfc6979.h"
    RUN_TESTS(secp224r1, nist_fips_186_secp224r1_tvs)
    RUN_TESTS(secp224r1, rfc6979_p224_tvs)
#endif
#if uECC_SUPPORTS_secp192r1
#include "test_vectors/nist_fips_186_secp192r1_tvs.h"
#include "test_vectors/rfc6979.h"
    RUN_TESTS(secp192r1, nist_fips_186_secp192r1_tvs)
    RUN_TESTS(secp192r1, rfc6979_p192_tvs)
#endif
    printf("TOTAL Pass: %d Fail: %d\n", global_passes, global_failures);
    return global_failures;
}
