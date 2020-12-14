#ifndef DYNAMICARRAY_VECTOR_H
#define DYNAMICARRAY_VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **ptr;               //TODO adapt type here
    unsigned long len;
} vector;

void startArray(vector *v);

void appendArray(vector *v, char* elem);

void prependArray(vector *v, char* elem);

void removeArray(vector *v, int index);

char searchArray(vector *v, char *elem);

void printArray(vector v);

void freeArray(vector *v);

#endif
