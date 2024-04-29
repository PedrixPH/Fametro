#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct estacionamento
{
	char placa[10];
	char modelo[65];
	char cor[20];
	struct estacionamento *prox;
} celula;

celula *topo = NULL;

void print();
void push(const char placa[], const char modelo[], const char cor[]);
void pop();

celula *top = NULL;

int main()
{
	setlocale(LC_ALL,"Portuguese");
	int opcao;
	char placa[8], modelo[65], cor[25];
	do
	{
		printf("\nMENU DO ESTACIONAMENTO:\n1. Adicionar carro \n2. Remover carro \n3. Exibir todos os carros estacionados \n0. Sair");
		printf("\nEscolha uma opção de 0 a 3: ");
		scanf("%d", &opcao);
		switch (opcao)
		{
			case 1:
				printf("\nDigite a placa do carro (EX: ABC1234): ");
				scanf("%s", &placa);
				printf("\nDigite o modelo do carro: ");
				scanf("%s", &modelo);
				printf("\nDigite a cor do carro: ");
				scanf("%s", &cor);
				push(placa, modelo, cor);
				break;
			case 2:
				pop();
				break;
			case 3:
				print();
				break;
		}
	}while (opcao != 0);
}



void push (const char placa[], const char modelo[], const char cor[])
{
	printf("\n===============");
	printf("\nESTACIONANDO...");
	printf("\n===============");
	celula *novo = malloc(sizeof(celula));
	strcpy(novo->placa, placa);
	strcpy(novo->modelo, modelo);
	strcpy(novo->cor, cor);
	novo->prox = top;
	top = novo;
	printf("\n-> O carro %s, de cor %s e placa %s foi estacionado com sucesso.", novo->modelo, novo->cor, novo->placa);
	printf("\n");
}



void pop()
{
	printf("\n===============");
	printf("\nREMOVENDO CARRO");
	printf("\n===============");
	if (top == NULL)
	{
		printf("\n\nO estacionamento esta vazio.");
	}
	else{
		celula *temp;
		temp = top;
		top = top->prox;
		printf("\n-> O carro %s, de cor %s e placa %s foi retirado do estacionamento com sucesso.", temp->modelo, temp->cor, temp->placa);
		free(temp);
	}
	printf("\n");
}



void print()
{
	celula *temp;
	temp = top;
	printf("\n===================");
	printf("\nCARROS ESTACIONADOS");
	printf("\n===================");
	while (temp != NULL)
	{
		printf("\nPlaca: %s, Modelo: %s, Cor: %s", temp->placa, temp->modelo, temp->cor);
		temp = temp->prox;
	}
	printf("\n");
}

