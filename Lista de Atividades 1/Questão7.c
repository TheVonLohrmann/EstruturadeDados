#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct contabancaria
{
    char nome[50];
    int numeroconta;
    float saldo;
};

void depositar(struct contabancaria *conta, float valor){
    conta->saldo += valor;
    printf("|--------------------------------------------------------|\n");
    printf("| Deposito realizado com sucesso. Novo saldo: %.2f\n", conta->saldo);
    printf("|--------------------------------------------------------|\n");
    system("pause");
    system("cls");
}

bool sacar(struct contabancaria *conta, float valor){
    if (valor <= conta->saldo) {
        conta->saldo -= valor;
        printf("|--------------------------------------------------------|\n");
        printf("| Saque realizado com sucesso. Novo saldo: %.2f\n", conta->saldo);
        printf("|--------------------------------------------------------|\n");
        system("pause");
        system("cls");
        return true;
    } else {
        printf("|--------------------------------------------------------|\n");
        printf("| Saldo insuficiente para realizar o saque.\n");
        printf("|--------------------------------------------------------|\n");
        system("pause");
        system("cls");
        return false;
    }
}

float versaldo(struct contabancaria conta){
    return conta.saldo;
}

int main(){

    struct contabancaria minhaconta;
    int Dp, Sc;
    int op;

    do
    {
    printf("|----------------------------------------------------|\n");
    printf("|              Banco estrutura de dados              |\n");
    printf("|----------------------------------------------------|\n");
    printf("| Cadastrar conta:                             [1]   |\n");
    printf("| Verificar saldo:                             [2]   |\n");
    printf("| Depositar:                                   [3]   |\n");
    printf("| Sacar:                                       [4]   |\n");
    printf("| Sair do banco:                               [0]   |\n");
    printf("|----------------------------------------------------|\n");
    printf("| Digite a opcao: ");
    scanf(" %d", &op);

    switch (op)
    {
    case 1:
        system("cls");
        printf("|--------------------------------------------------|\n"); 
        printf("| Informe o nome do titular: ");
        scanf(" %s", minhaconta.nome);

        printf("| Informe o numero da conta: ");
        scanf(" %d", &minhaconta.numeroconta);

        printf("| Informe o saldo da conta: ");
        scanf(" %f", &minhaconta.saldo);
        printf("|--------------------------------------------------|\n");
        system("cls");
        break;
    case 2:
        system("cls");
        float saldoatual = versaldo(minhaconta);
        printf("|--------------------------------------------------|\n");
        printf("| Saldo atual: %.2f\n", saldoatual);
        printf("|--------------------------------------------------|\n");
        system("pause");
        system("cls");
        break;
    case 3:
        system("cls");
        printf("|--------------------------------------------------|\n");
        printf("| Quanto deseja depositar: ");
        scanf(" %d", &Dp);
        depositar(&minhaconta, Dp);
        break;
    case 4:
        system("cls");
        printf("|--------------------------------------------------|\n");
        printf("| Quanto deseja sacar: ");
        scanf(" %d", &Sc);
        sacar(&minhaconta, Sc);
        break;
    case 0:
        system("cls");
        printf("|-------------------------------------|\n");
        printf("|           saindo do banco           |\n");
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