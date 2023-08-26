#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char Titulo[100];
	char Diretor[50];
	char Genero[50];
	char Duracao[10];
	int Classe;
}Filme;

void ImpriFilme(Filme F){
	printf("|--------------------------------|\n");
	printf("|Titulo: %s\n", F.Titulo);
    printf("|Diretor: %s\n", F.Diretor);
    printf("|Genero: %s\n", F.Genero);
    printf("|Duracao: %s\n", F.Duracao);
    printf("|Classificacao: + %d\n", F.Classe);
	printf("|--------------------------------|");

}

Filme setFilme(char Titulo[100], char Diretor[50], char Genero[50], char Duracao[10], int Classe){
	Filme F;
	strcpy(F.Titulo, Titulo);
	strcpy(F.Diretor, Diretor);
	strcpy(F.Genero, Genero);
	strcpy(F.Duracao, Duracao);
	F.Classe = Classe;
	return F;
}

int main(){
	Filme Odyssey;
	Odyssey = setFilme("Odyssey Aurora", "lucas", "terror", "2 horas", 18);
	ImpriFilme(Odyssey);
    

	return 0;
}