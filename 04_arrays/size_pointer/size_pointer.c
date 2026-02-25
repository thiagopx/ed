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

    // v: 4 bytes * 10 = 40 bytes
    // u: 8 bytes
    printf("size(v)=%d bytes, size(u)=%d bytes\n", sizeof(v), sizeof(u));
    // try to change the v address (uncomment this)
    // v = w;
    return 0;
}