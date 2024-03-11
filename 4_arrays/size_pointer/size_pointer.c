#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int v[10];
    int w[10];
    int *u;

    u = v;
    *u = 4;
    printf("v[0]=%d\n", v[0]);

    u = &v[3];
    *u = 11;
    printf("v[3]=%d\n", v[3]);

    // v: 4 bits * 10 = 40 bits
    // u: 1 byte = 8 bits
    printf("size(v)=%d, size(u)=%d\n", sizeof(v), sizeof(u));
    // try to change the v address (uncomment this)
    // v = w;
    return 0;
}