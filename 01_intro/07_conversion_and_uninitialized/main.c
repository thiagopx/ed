#include <stdio.h>

int main()
{
    /* ---- Parte 1: conversao de tipo ---- */
    int total_pontos = 17;
    int quantidade_provas = 5;

    /* Divisao entre dois inteiros trunca o resultado */
    float media_errada = total_pontos / quantidade_provas;
    printf("Media (sem conversao): %.2f\n", media_errada);

    /* Convertendo um operando para float antes da divisao (cast explicito) */
    float media_certa = (float) total_pontos / quantidade_provas;
    printf("Media (com conversao explicita): %.2f\n", media_certa);

    /* ---- Parte 2: variavel com valor indefinido ---- */
    int nao_inicializada;
    printf("\nValor de uma variavel nao inicializada: %d\n", nao_inicializada);
    printf("(Esse numero nao tem significado - e o que sobrou na memoria antes de ser usada. Nunca leia uma variavel antes de dar um valor a ela.)\n");

    return 0;
}
