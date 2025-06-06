#include <stdint.h>

//DJB2
uint32_t djb2_hash(const char* str, int table_size) {
    uint32_t hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash % table_size;
}

//FNV-1a
uint32_t fnv1a_hash(const char* str, int table_size) {
    uint32_t hash = 2166136261u; // FNV_offset_basis
    while (*str) {
        hash ^= *str++;
        hash *= 16777619u; // FNV_prime
    }
    return hash % table_size;
}

//ASCII SUM
uint32_t ascii_sum_hash(const char* str, int table_size) {
    uint32_t hash = 0;
    while (*str) {
        hash += *str++;
    }
    return hash % table_size;
}