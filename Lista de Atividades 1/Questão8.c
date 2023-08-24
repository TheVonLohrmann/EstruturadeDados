#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct produto
{
    char nome[50];
    float preco;
    int quantestoque;
};

void comprarproduto(struct produto *produtos, int quantidadecompra){

    if (quantidadecompra <= produtos->quantestoque)
    {
        produtos->quantestoque-=quantidadecompra;
        printf("|----------------------------------------|\n");
        printf("| Compra realizada com sucesso.\n");
        printf("|----------------------------------------|\n");
    }else{
        printf("|----------------------------------------|\n");
        printf("| Quantidade insuficiente em estoque.\n");
        printf("|----------------------------------------|\n");
    }
  
}

float calculartotal(struct produto produtos, int quantidadecompra){
    return produtos.preco * quantidadecompra;
}

int main(){

    struct produto item;
    int quantidadecompra;
    strcpy(item.nome, "Iphone");
    item.preco = 14000.00;
    item.quantestoque = 30;

    printf("|----------------------------------------|\n");
    printf("|       Bem-vindo a loja de celular      |\n");
    printf("|----------------------------------------|\n");
    printf("| Produto: %s\n", item.nome);
    printf("| Preco: %.2f\n", item.preco);
    printf("| Quantidade em estoque: %d\n", item.quantestoque);
    printf("|----------------------------------------|\n");
    printf("| Quantidade desejada: ");
    scanf("%d", &quantidadecompra);
    comprarproduto(&item, quantidadecompra);
    float totalcompra = calculartotal(item, quantidadecompra);
    printf("|----------------------------------------|\n");
    printf("| Total da compra: %.2f\n", totalcompra);
    printf("|----------------------------------------|\n");
    return 0;
}