#include <stdio.h>

int main(){
    printf("short\t\t%lu\n", sizeof(short));
    printf("int\t\t%lu\n", sizeof(int));
    printf("long\t\t%lu\n", sizeof(long));
    printf("longlong\t%lu\n", sizeof(long long));
    printf("double\t\t%lu\n", sizeof(double));
    return 0;
}
