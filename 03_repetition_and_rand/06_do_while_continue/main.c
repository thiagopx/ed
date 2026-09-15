#include <stdio.h>

int main()
{
    int numero;
    int soma = 0;
    int quantidade = 0;

    printf("Digite numeros para somar (negativos sao ignorados; digite 0 para parar):\n");

    do
    {
        printf("Numero: ");
        scanf("%d", &numero);

        if (numero < 0)
        {
            printf("  (ignorado, numero negativo)\n");
            continue;
        }

        if (numero > 0)
        {
            soma += numero;
            quantidade++;
        }
    } while (numero != 0);

    printf("\nSoma dos %d numeros positivos digitados: %d\n", quantidade, soma);

    return 0;
}
