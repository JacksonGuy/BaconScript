#pragma once

#include <stdlib.h>
#include <string.h>

#define CAPACITYFIELD 0
#define LENGTHFIELD 1
#define STRIDEFIELD 2
#define ARRAYFIELDSIZE 3

void* _create_array(size_t capacity, size_t stride);
void _free_array(void* arr);
size_t _array_field_get(void* arr, size_t field);
void _array_field_set(void* arr, size_t field, size_t value);
void* _resize_array(void* arr, size_t size);
void* _array_push(void* arr, void* element);

#define create_array(type) _create_array(16, sizeof(type))
#define free_array(arr) _free_array(arr) 
#define resize_array(arr, size) _resize_array(arr, size);
#define array_push(arr, element) \
    do { \
        __auto_type temp = element; \
        arr = _array_push(arr, &temp); \
    } while (0)

#define array_capacity(arr) _array_field_get(arr, CAPACITYFIELD)
#define array_length(arr) _array_field_get(arr, LENGTHFIELD)
#define array_stride(arr) _array_field_get(arr, STRIDEFIELD)