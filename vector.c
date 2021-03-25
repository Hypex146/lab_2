#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "vector.h"

Vector *vector_init(){
    Vector *vector = (Vector*)malloc(sizeof(Vector));
    vector->len = 0;
    vector->val = NULL;
    return vector;
}


int vector_insert(Vector *vector, double val, int index){
    if (index >= 0){
        vector->len++;
        if (index == 0){ // add in start
            double *new_vector = (double*)malloc(vector->len*sizeof(double));
            memcpy(new_vector+1, vector->val, (vector->len-1)*sizeof(double));
            new_vector[0] = val;
            free(vector->val);
            vector->val = new_vector;
        } else if (index >= vector->len - 1){ // add in end
            vector->val = (double*)realloc(vector->val, vector->len*sizeof(double));
            vector->val[vector->len-1] = val;
        } else{ // add in other position
            double *new_vector = (double*)malloc(vector->len*sizeof(double));
            memcpy(new_vector, vector->val, index*sizeof(double));
            new_vector[index] = val;
            memcpy(new_vector+index+1, vector->val+index, (vector->len-index-1)*sizeof(double ));
            free(vector->val);
            vector->val = new_vector;
        }
        return 0;
    } else return -1;
}


int vector_remove(Vector *vector, int index, double *val){
    if (index >= 0){
        *val = vector->val[index];
        if (vector->len > 0) vector->len--;
        if (vector->len > 0){
            if (index == 0){ // del first element
                double *new_vector = (double*)malloc(vector->len*sizeof(double));
                memcpy(new_vector, vector->val+1, vector->len*sizeof(double));
                free(vector->val);
                vector->val = new_vector;
            } else if (index >= vector->len){ // del last element
                vector->val = (double*)realloc(vector->val, vector->len*sizeof(double));
            } else{ // del middle element
                double *new_vector = (double*)malloc(vector->len*sizeof(double));
                memcpy(new_vector, vector->val, index*sizeof(double));
                memcpy(new_vector+index, vector->val+index+1, (vector->len-index)*sizeof(double));
                free(vector->val);
                vector->val = new_vector;
            }
        } else if (vector->len == 0){
            free(vector->val);
            vector->val = NULL;
        }
        return 0;
    } else return -1;
}


int vector_clear(Vector *vector){
    free(vector->val);
    free(vector);
    printf("Clearing\n");
    return 0;
}


int vector_write(Vector *vector){
    printf("Vector:\n");
    for (int i=0; i<vector->len; i++){
        printf("%lf ", *(vector->val+i));
    }
    printf("\n");
    return 0;
}
