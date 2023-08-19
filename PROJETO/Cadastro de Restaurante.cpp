#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef struct tipo_restaurante{
	char nome[30];
	char endereco[50];
	char tipo[30];
	int nota;
	struct tipo_restaurante *proximo;
} TRestaurante;

void inserir(TRestaurante **cabeca);
void listar(TRestaurante *cabeca);
void listar_nota(TRestaurante *cabeca);
void listar_tipo(TRestaurante *cabeca);

int main()
{
	setlocale(LC_ALL,"Portuguese");
	
	TRestaurante *cabeca = NULL;
	TRestaurante *noatual = NULL;
	
	int op;
	int nota;
	int tipo_comida[50];
	
	printf("\n\t\t>----------------------------------------------------------------------<");
	printf("\n\t\t\t\t\tCadastro de restaurante");
	printf("\n\t\t>----------------------------------------------------------------------<");
		
	do{
		printf("\n\n|Escolha uma das opções abaixo        |");
		printf("\n|[1] - Inserir um restaurante           |");
		printf("\n|[2] - Listar os restaurantes           |");
		printf("\n|[3] - Listar os restaurantes por nota  |");
		printf("\n|[4] - Listar os restaurantes pelo tipo |");
		printf("\n|[5] - Sair                             |");
		printf("\nOpção escolhida: ");
		scanf("%d", &op);
		switch(op)
		{
			case 1: inserir(&cabeca); break;
			case 2: listar(cabeca); break;
			case 3: listar_nota(cabeca); break;
			case 4: listar_tipo(cabeca); break;
			case 5: break;
			default: printf("\nOpção inválida!");
		}
		fflush(stdin);
	}while(op != 5);
	
	noatual = cabeca;
	while (noatual != NULL)
	{
		cabeca = noatual->proximo;
		free(noatual);
		noatual = cabeca;	
	}		
}

void inserir (TRestaurante **cabeca)
{
	setlocale(LC_ALL,"Portuguese");
	
	TRestaurante *noatual;
	
	noatual = (TRestaurante*)malloc(sizeof(TRestaurante));
	
	printf("\nDigite o nome do restaurante: ");
    fflush(stdin);
    fgets(noatual->nome, 30, stdin);
    printf("\nDigite o endereço do restaurante: ");
    fflush(stdin);
	fgets(noatual->endereco, 50, stdin);
	printf("\nDigite o tipo de comida: ");
    fflush(stdin);
	fgets(noatual->tipo, 30, stdin);
	
	do{
		printf("\n***Nota do restaurante (0 a 5)");
		printf("\n|0 - Horrível              |");
		printf("\n|1 - Ruim                  |");
		printf("\n|2 - Razoável              |");
		printf("\n|3 - Bom                   |");  
		printf("\n|4 - Muito bom             |");
		printf("\n|5 - Excelente/ Espetacular|");
		printf("\nDigite a nota do restaurante: ");
		scanf("%d", &noatual->nota);
	}while((noatual->nota>5) || (noatual->nota<0));
	
	noatual->proximo = *cabeca;
	*cabeca = noatual;
	
	
}

void listar(TRestaurante *cabeca)
{ 	
	TRestaurante *noatual;
	noatual = cabeca;
	
	printf("\n\t\t>----------------------------------------------------------------------<");
	printf("\n\t\t\t\t\tFicha dos restaurantes");
	while( noatual != NULL)
	{
		printf("\n\nt\t\t\t\tNome do restaurante: %s",noatual->nome);
		printf("t\t\t\t\tEndereço do Restaurante: %s", noatual->endereco);
		printf("t\t\t\t\tTipo de comida: %s", noatual->tipo);
		printf("t\t\t\t\tNota: %d", noatual->nota);
		noatual = noatual->proximo;
	}
	printf("\n\t\t>----------------------------------------------------------------------<");
}

void  listar_nota(TRestaurante *cabeca)
{
	TRestaurante *noatual;
	noatual = cabeca;
	
	int i;
	printf("Digite a nota para filtrar os restaurantes: ");
	scanf("%d", &i);
	
	for(i=5; i>=0; i--)
	{
		while(noatual != NULL)
		{
			if(noatual->nota == i)
			{
				printf("\n\t\t>----------------------------------------------------------------------<");
				printf("\n\t\t\t\t\tFicha dos restaurantes por nota");
				printf("\n\nt\t\t\t\tNome do restaurante: %s",noatual->nome);
				printf("t\t\t\t\tEndereço do Restaurante: %s", noatual->endereco);
				printf("t\t\t\t\tTipo de comida: %s", noatual->tipo);
				printf("t\t\t\t\tNota: %d", noatual->nota);
				printf("\n\t\t>----------------------------------------------------------------------<");
			}
			noatual = noatual->proximo;
		}
		noatual = cabeca;
	}
}

void listar_tipo(TRestaurante *cabeca)
{
	TRestaurante *noatual;
	char tipo_comida[50];
	
	printf("Tipo de culinária: ");
	fflush(stdin);
	fgets(tipo_comida, 50, stdin);
	noatual = cabeca;
	
	while(noatual != NULL)
	{
		if(strcmp(noatual->tipo, tipo_comida)==0)
		{
			printf("\n\t\t>----------------------------------------------------------------------<");
			printf("\n\t\t\t\t\tFicha dos restaurantes por tipo de comida");
			printf("\n\nt\t\t\t\tNome do restaurante: %s",noatual->nome);
			printf("t\t\t\t\tEndereço do Restaurante: %s", noatual->endereco);
			printf("t\t\t\t\tTipo de comida: %s", noatual->tipo);
			printf("t\t\t\t\tNota: %d", noatual->nota);
			printf("\n\t\t>----------------------------------------------------------------------<");
		}
		noatual = noatual->proximo;
	}
}








