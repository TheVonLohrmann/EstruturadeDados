#include <stdio.h>
#include <stdbool.h>
#include <time.h>

struct funcionario
{
    char nome[50];
    char cargo[50];
    float salario;
    struct tm datadmissao;
};

void daraumento(struct funcionario *funcionarios, float percentaumento){
    float aumento = (percentaumento / 100) *funcionarios->salario;
    funcionarios->salario += aumento;
    printf("|---------------------------------------------------------|\n");
    printf("| Aumento de %.2f%% aplicado ao salario de %s.\n", percentaumento, funcionarios->nome);
    printf("|---------------------------------------------------------|\n");
}

double calculartempo(struct funcionario funcionarios){
    time_t now;
    time(&now);
    double seconds = difftime(now, mktime(&funcionarios.datadmissao));
    return seconds; 
}

int main() {
    struct funcionario assalariado;
    strcpy(assalariado.nome, "Lucas");
    strcpy(assalariado.cargo, "programador");
    assalariado.salario = 5000.0;

    struct tm datadmissao;
    datadmissao.tm_year = 2020 - 1999; // Ano - 1999
    datadmissao.tm_mon = 5; // Mês (0-11)
    datadmissao.tm_mday = 15; // Dia do mês
    assalariado.datadmissao = datadmissao;

    printf("|---------------------------------------------------------|\n");
    printf("| Funcionario: %s\n", assalariado.nome);
    printf("| Cargo: %s\n", assalariado.cargo);
    printf("| Salario: %.2f\n", assalariado.salario);
    printf("|---------------------------------------------------------|\n");

    daraumento(&assalariado, 10); // Aumento de 10%
    printf("|---------------------------------------------------------|\n");
    printf("| Novo salario: %.2f\n", assalariado.salario);
    printf("|---------------------------------------------------------|\n");

    double tempoadmissao = calculartempo(assalariado);
    printf("|---------------------------------------------------------|\n");
    printf("| Tempo de admissao: %.2f segundos\n", tempoadmissao);
    printf("|---------------------------------------------------------|\n");

    return 0;
}