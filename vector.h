#ifndef LAB2_VECTOR_H
#define LAB2_VECTOR_H
typedef struct _VECTOR{
    int len;
    double *val;
}Vector;
Vector *vector_init();
int vector_insert(Vector *vector, double val, int index);
int vector_write(Vector *vector);
int vector_clear(Vector *vector);
int vector_remove(Vector *vector, int index, double *val);
#endif //LAB2_VECTOR_H
