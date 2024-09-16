#include "array.h"

#include <stdio.h>
#include <string.h>

void* _create_array(size_t capacity, size_t stride) {
    size_t header_size = ARRAYFIELDSIZE * sizeof(size_t);
    size_t arr_size = capacity * stride;
    size_t* arr = (size_t*)malloc(header_size + arr_size);
    arr[CAPACITYFIELD] = capacity;
    arr[LENGTHFIELD] = 0;
    arr[STRIDEFIELD] = stride;

    return (void*)(arr + ARRAYFIELDSIZE);
}

void _free_array(void* arr) {
    free(arr - ARRAYFIELDSIZE * sizeof(size_t));
}

size_t _array_field_get(void* arr, size_t field) {
    return ((size_t*)(arr) - ARRAYFIELDSIZE)[field];
}

void _array_field_set(void* arr, size_t field, size_t value) {
    (((size_t*)arr) - ARRAYFIELDSIZE)[field] = value;
}

void* _resize_array(void* arr, size_t size) {
    void* temp = _create_array(
        size,
        array_stride(arr)
    );
    memcpy(temp, arr, array_length(arr) * array_stride(arr));
    _array_field_set(temp, LENGTHFIELD, array_length(arr));
    _free_array(arr);
    return temp;
}

void* _array_push(void* arr, void* element) {
    if (array_length(arr) >= array_capacity(arr)) {
        arr = resize_array(arr, array_capacity(arr) * 2);
    }
    memcpy(arr + array_length(arr) * array_stride(arr), element, array_stride(arr));
    _array_field_set(arr, LENGTHFIELD, array_length(arr) + 1);
    return arr;
}

void testArray() {
    // Int array
    int* arr = (int*)create_array(int);

    printf("Capacity: %d\n", array_capacity(arr));
    printf("Length: %d\n", array_length(arr));
    printf("Stride: %d\n\n", array_stride(arr));

    for (int i = 0; i < 20; i++) {
        array_push(arr, i);
    }

    for (int i = 0; i < 20; i++) {
        printf("Element %d: %d\n", i, arr[i]);
    }

    array_push(arr, 69);
    printf("Manual add: %d\n", arr[array_length(arr)-1]);

    free_array(arr);

    // String array
    char** strings = (char**)create_array(char*);
    array_push(strings, "Hello");
    array_push(strings, "World");
    printf("%s %s!\n", strings[0], strings[1]);
}