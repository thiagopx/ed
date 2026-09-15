#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char nome[30];
    float preco;
} Produto;

void salvar_produtos(const char *arquivo, Produto *produtos, int n)
{
    FILE *fp = fopen(arquivo, "wb");
    if (fp == NULL)
    {
        printf("Erro ao abrir arquivo para escrita.\n");
        exit(1);
    }
    fwrite(produtos, sizeof(Produto), n, fp);
    fclose(fp);
}

int carregar_produtos(const char *arquivo, Produto *produtos, int n)
{
    FILE *fp = fopen(arquivo, "rb");
    if (fp == NULL)
    {
        printf("Erro ao abrir arquivo para leitura.\n");
        return 0;
    }
    int lidos = fread(produtos, sizeof(Produto), n, fp);
    fclose(fp);
    return lidos;
}

Produto carregar_produto_por_indice(const char *arquivo, int indice)
{
    Produto p;
    FILE *fp = fopen(arquivo, "rb");
    fseek(fp, indice * sizeof(Produto), SEEK_SET);
    fread(&p, sizeof(Produto), 1, fp);
    fclose(fp);
    return p;
}

int main()
{
    Produto catalogo[3] = {
        {1, "Caderno", 12.50},
        {2, "Caneta", 3.20},
        {3, "Mochila", 89.90}
    };

    salvar_produtos("produtos.bin", catalogo, 3);
    printf("3 produtos salvos em produtos.bin (modo binario).\n\n");

    Produto lidos[3];
    int n = carregar_produtos("produtos.bin", lidos, 3);
    printf("Produtos recuperados do arquivo binario:\n");
    for (int i = 0; i < n; i++)
    {
        printf("  #%d %-10s R$ %.2f\n", lidos[i].id, lidos[i].nome, lidos[i].preco);
    }

    printf("\nAcesso direto ao produto de indice 1 (sem ler os demais):\n");
    Produto p = carregar_produto_por_indice("produtos.bin", 1);
    printf("  #%d %-10s R$ %.2f\n", p.id, p.nome, p.preco);

    return 0;
}
