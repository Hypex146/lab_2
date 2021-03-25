#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
// 5WZ2GU2


char *get_str() {
    char buf[81] = {0};
    char *res = NULL;
    int len = 0;
    int n = 0;
    do {
        n = scanf("%80[^\n]", buf);
        if (n < 0) {
            if (!res) {
                return NULL;
            }
        } else if (n > 0) {
            int chunk_len = strlen(buf);
            int str_len = len + chunk_len;
            res = realloc(res, str_len + 1);
            memcpy(res + len, buf, chunk_len);
            len = str_len;
        } else {
            scanf("%*c");
        }
    } while (n > 0);

    if (len > 0) {
        res[len] = '\0';
    } else {
        res = calloc(1, sizeof(char));
    }

    return res;
} //done and check


int main(){
    printf("Hello, World!\n\n");

    Stack *stack;
    double *a = (double*)malloc(sizeof(double));
    double *b = (double*)malloc(sizeof(double));
    char *str;
    do{
        printf("Enter string\n");
        str = get_str();
        if (str != NULL) {
            stack = stack_init();
            int i = 0;
            while (*(str+i) != '\0'){
                char c = *(str+i);
                if (c >= '0' && c <= '9'){
                    push(stack, (int)(c - 48));
                } else{
                    pop(stack, b);
                    pop(stack, a);
                    if (c == '+') *a = *a + *b;
                    if (c == '-') *a = *a - *b;
                    if (c == '*') *a = *a * *b;
                    if (c == '/') *a = *a / *b;
                    push(stack, *a);
                }
                i++;
            }
            pop(stack, a);
            printf("ANSWER -> %lf\n\n", *a);
            clear(stack);
            free(str);
        }
    } while (str != NULL);
    printf("Bye\n");
    if (a != NULL) free(a);
    if (b != NULL) free(b);

    printf("Bye!\n");
    return 0;
}
