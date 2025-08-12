// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
int main() {
    int *t;
    int n = 7 ;
    t =malloc(n * sizeof(int));
    int m=4;
    printf("%d\n",t);
    t =realloc(t,(n+m)*sizeof(int));
    printf("%d",t);
    free(t);
    t= NULL;
    
}
