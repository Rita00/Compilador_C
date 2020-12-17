#include "vector.h"

void startArray(vector *v) {
    v->ptr = NULL;
    v->len = 0;
}

void appendArray(vector *v, char* elem) {
    char **new = (char**)calloc(v->len + 1, sizeof(char*));
    memcpy(new, v->ptr, v->len * sizeof(char*));
    new[v->len] = strdup(elem);
    if(v->ptr != NULL)
        free(v->ptr);
    v->ptr = new;                                       
    v->len++;                                           
}

char searchArray(vector *v, char *elem) {
    for (int i = 0; i < v->len; i++) {
        if (strcmp(v->ptr[i], elem) == 0)
            return 1;
    }
    return 0;
}

void freeArray(vector *v) {
    for (int i = 0; i < v->len; i++) {
        free(v->ptr[i]);
    }
    if(v->ptr != NULL)
        free(v->ptr);
    v->ptr = NULL;
    v->len = 0;
}