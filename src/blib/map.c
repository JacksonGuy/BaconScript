#include "map.h"

/*
 * This should probably be replaced in the future
 */
unsigned long hash(unsigned char* str) {
    unsigned long hash = 5381;
    int c;

    while (c = *str++) {
        hash = ((hash << 5) + hash) + c;
    }

    return hash;
}

hmap* hm_create() {
    hmap* hm = (hmap*)malloc(sizeof(hmap));
    if (hm == NULL) return NULL;

    hm->length = 0;
    hm->capacity = 16;
    hm->entries = (hash_entry*)create_array(hmap);
    if (hm->entries == NULL) {
        free(hm);
        return NULL;
    }
    return hm;
}

void hm_free(hmap* hm) {
    free_array(hm->entries);
    free(hm);
}

void* hm_get(hmap* hm, const char* key) {
    // Get hash
    unsigned long key_hash = hash(key);
    size_t index = (size_t)(key_hash & (hm->capacity - 1));
}