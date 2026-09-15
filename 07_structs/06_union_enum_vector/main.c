#include <stdio.h>

typedef struct
{
    float x;
    float y;
} Point2D;

typedef enum
{
    TIPO_INTEIRO,
    TIPO_REAL
} TipoValor;

typedef union
{
    int como_inteiro;
    float como_real;
} Valor;

int main()
{
    Point2D poligono[4] = {
        {0.0, 0.0},
        {4.0, 0.0},
        {4.0, 3.0},
        {0.0, 3.0}
    };

    printf("Vertices do poligono:\n");
    for (int i = 0; i < 4; i++)
    {
        printf("  p%d = (%.1f, %.1f)\n", i, poligono[i].x, poligono[i].y);
    }

    TipoValor tipo = TIPO_REAL;
    Valor v;
    v.como_real = 3.14f;

    printf("\n");
    if (tipo == TIPO_INTEIRO)
    {
        printf("Valor inteiro: %d\n", v.como_inteiro);
    }
    else
    {
        printf("Valor real: %.2f\n", v.como_real);
    }
    printf("Tamanho da union Valor: %lu bytes\n", sizeof(Valor));

    return 0;
}
