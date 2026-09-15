#include <stdio.h>

int main()
{
    int idade;
    float renda_mensal;

    printf("Digite a idade: ");
    scanf("%d", &idade);
    printf("Digite a renda mensal: ");
    scanf("%f", &renda_mensal);

    int maior_de_idade = idade >= 18;
    int renda_baixa = renda_mensal < 2000.0;

    /* Operadores logicos: && (E), || (OU), ! (negacao) */
    int elegivel = maior_de_idade && renda_baixa;
    int precisa_documento_extra = !maior_de_idade || renda_mensal > 5000.0;

    printf("\nElegivel para o beneficio: %s\n", elegivel ? "sim" : "nao");
    printf("Precisa de documento extra: %s\n", precisa_documento_extra ? "sim" : "nao");

    /* Operador condicional (ternario): teste ? valor_se_verdadeiro : valor_se_falso */
    const char *faixa = idade < 18 ? "menor de idade" : (idade < 60 ? "adulto" : "idoso");
    printf("Faixa etaria: %s\n", faixa);

    return 0;
}
