#include <stdio.h>

int main()
{
    int x = 5;
    printf("x = %d\n", x);

    int resultado_pos = x++;
    printf("x++ devolveu %d (valor de x antes do incremento)\n", resultado_pos);
    printf("agora x = %d\n", x);

    int resultado_pre = ++x;
    printf("++x devolveu %d (valor de x depois do incremento)\n", resultado_pre);
    printf("agora x = %d\n", x);

    int y = 10;
    printf("\ny = %d\n", y);

    int resultado_pos_y = y--;
    printf("y-- devolveu %d (valor de y antes do decremento)\n", resultado_pos_y);
    printf("agora y = %d\n", y);

    int resultado_pre_y = --y;
    printf("--y devolveu %d (valor de y depois do decremento)\n", resultado_pre_y);
    printf("agora y = %d\n", y);

    return 0;
}
