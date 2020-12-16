#ifndef DYNAMICARRAY_VECTOR_H
#define DYNAMICARRAY_VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **ptr;
    unsigned long len;
} vector;

void startArray(vector *v);

void appendArray(vector *v, char* elem);

char searchArray(vector *v, char *elem);

void freeArray(vector *v);

#endif
