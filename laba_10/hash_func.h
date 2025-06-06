#ifndef HASH_FUNC
#define HASH_FUNC
#include <stdint.h>


uint32_t djb2_hash(const char* str, int table_size);
uint32_t fnv1a_hash(const char* str, int table_size);
uint32_t ascii_sum_hash(const char* str, int table_size);

typedef uint32_t (*hash_func)(const char* str, int table_size);

#endif