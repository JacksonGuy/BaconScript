#pragma once

#include "array.h"

typedef struct {
    const char* key;
    void* value;
} hash_entry;

typedef struct {
    hash_entry* entries;
    size_t capacity;
    size_t length;
} hmap;

unsigned long hash(unsigned char* str);
hmap* hm_create();
void hm_free(hmap* hm);
void* hm_get(hmap* hm, const char* key);
void hm_set(hmap* hm, const char* key, void* value);