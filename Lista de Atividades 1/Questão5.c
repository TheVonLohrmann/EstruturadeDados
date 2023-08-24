#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct livro
{
    char titulo[100];
    char autor[50];
    int ano;
};

void addlivro(struct livro biblioteca[], int *numlivros) {
    if (*numlivros < 10) { 
        printf("|----------------------------------------------------|\n");
        printf("|Informe o titulo do livro: ");
        scanf(" %s", biblioteca[*numlivros].titulo);

        printf("|Informe o autor do livro: ");
        scanf(" %s", biblioteca[*numlivros].autor);

        printf("|Informe o ano de publicacao do livro: ");
        scanf(" %d", &biblioteca[*numlivros].ano);
        
        (*numlivros)++;
        printf("|----------------------------------------------------|\n");
        printf("|            Livro adicionado com sucesso!           |\n");
        printf("|----------------------------------------------------|\n");
    } else {
        printf("|Biblioteca esta cheia, nao e possivel adicionar mais livros.|\n");
    }
    system("pause");
    system("cls");
}

void listalivros(struct livro biblioteca[], int numlivros){
    
    printf("|----------------------------------------------------|\n");
    printf("|                  Lista de livros                   |\n");
    printf("|----------------------------------------------------|\n");
    for (int i = 0; i < numlivros; i++)
    {
        printf("| Titulo: %s\n", biblioteca[i].titulo);
        printf("| Autor: %s\n", biblioteca[i].autor);
        printf("| Ano publicado: %d\n", biblioteca[i].ano);
        printf("|----------------------------------------------------|\n");
    }
    system("pause");
    system("cls");
}

void buscarautor(struct livro biblioteca[], int numlivros, char busca[]) {
    int encontrados = 0;
    printf("|----------------------------------------------------|\n");
    printf("| Livros do autor %s:\n", busca);
    for (int i = 0; i < numlivros; i++) {
        if (strcmp(biblioteca[i].autor, busca) == 0) {
            printf("| Titulo: %s\n", biblioteca[i].titulo);
            printf("| Ano de publicacao: %d\n", biblioteca[i].ano);
            printf("|----------------------------------------------------|\n");
            encontrados++;
        }
    }
    if (encontrados == 0) {
        printf("| Nenhum livro encontrado para o autor %s.\n|", busca);
    }
    system("pause");
    system("cls");
}



int main(){

    struct livro biblioteca[10];
    int numlivros = 0;
    int op;
    char buscar[50];

    do
    {
       printf("|-------------------------------------|\n");
       printf("|          Menu da biblioteca         |\n");
       printf("|-------------------------------------|\n");
       printf("| Adicionar livro:                [1] |\n");
       printf("| Listar livros:                  [2] |\n");
       printf("| Buscar livros por autor:        [3] |\n");
       printf("| Sair da biblioteca:             [0] |\n");
       printf("| Digite a opcao:");
       scanf(" %d", &op);

       switch (op)
       {
       case 1:
        system("cls");
        addlivro(biblioteca, &numlivros);
        break;
       case 2:
        system("cls");
        listalivros(biblioteca, numlivros);
        break;
       case 3:
        system("cls");
        printf("|-------------------------------------|\n");
        printf("| Infome o nome do autor:");
        scanf(" %s", buscar);
        buscarautor(biblioteca, numlivros, buscar);
        break;
       case 0:
        system("cls");
        printf("|-------------------------------------|\n");
        printf("|        saindo da biblioteca         |\n");
        printf("|-------------------------------------|\n");
        break;
       
       default:
       printf("|------------------------------------------|\n");
       printf("| Opcao invalida. Escolha uma opcao valida.|\n ");
       printf("|------------------------------------------|\n");
       system("pause");
       system("cls");
        break;
       }

    } while (op != 0);
    



    return 0;
}
