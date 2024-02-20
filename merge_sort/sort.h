#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>


void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void recursive_merge(int *array, int *tmp, int start, int end);
void merge(int *array, int *tmp, int start, int mid, int end);

#endif /* SORT_H */
