#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stdio.h>


#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1


int slide_line(int *line, size_t size, int direction);
int merge_slid_left(int *line, int size);
int merge_slid_right(int *line, int size);

#endif
