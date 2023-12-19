#ifndef SORT_H
#define SORT_H

#include <stdio.h>

void swap(int *array, int index_a, int index_b);
void down_to_leaf(int *array, size_t array_size, size_t size, size_t index);
void build_heap(int *array, size_t size);
void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);

#endif /* SORT_H */
