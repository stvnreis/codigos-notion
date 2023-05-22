#include <stdio.h>
#include <stdlib.h>

typedef struct noArvore
{
	int valor;
	struct noArvore *esquerda;
	struct noArvore *direita;
}noArvore;

void iniciar(noArvore **no)
{
	(*no)=NULL;
}

int inserir(noArvore **no, int valor)
{
	if((*no) == NULL)
	{
		(*no) = malloc(sizeof(noArvore));
		(*no)->valor = valor;
		(*no)->esquerda = NULL;
		(*no)->direita = NULL;
	
		return 1;
	}
	else if((*no)->valor > valor)
	{
		return inserir(&(*no)->esquerda, valor);
	}
	else if((*no)->valor < valor)
	{
		return inserir(&(*no)->direita, valor);
	}
	else 
	{
		return 0;
	}
}

int maior_elemento(noArvore **no)
{
	if((*no)->direita == NULL && (*no)->esquerda == NULL)
	{
		int valor = (*no)->valor;
		free((*no));
		(*no) = NULL;
		return valor;
	}
	else 
		maior_elemento(&(*no)->direita);
}

int remover(noArvore **no, int valor)
{
	if((*no) == NULL)
		return 0;
	if((*no)->valor > valor)
		return remover(&(*no)->esquerda, valor);
	else if((*no)->valor < valor)
		return remover(&(*no)->direita, valor);
	else if((*no)->valor == valor)
	{
		if((*no)->direita == NULL && (*no)->esquerda == NULL)
		{
			free((*no));
			(*no) = NULL;
		}
		else if((*no)->direita == NULL && (*no)->esquerda != NULL)
		{
			(*no) = (*no)->esquerda;
			free((*no)->esquerda);
		}
		else if((*no)->direita != NULL && (*no)->esquerda == NULL)
		{
			(*no) = (*no)->direita;
			free((*no)->direita);
		}
		else 
		{
			(*no)->valor = maior_elemento(&(*no)->esquerda);
		}

		return 1;
	}
}

int pesquisar(noArvore **no, int valor)
{
	if((*no) == NULL)
		return 0;
	else
	{
		if((*no)->valor == valor)
			return 1;
		else if((*no)->valor > valor)
			return pesquisar(&(*no)->esquerda, valor);
		else 
			return pesquisar(&(*no)->direita, valor);
	}
}

void ler_chaves(noArvore **no, int tamanho)
{
	int i, valor;
	
	for(i=0; i<tamanho; i++)
	{
		scanf("%d", &valor);
		inserir(&(*no), valor);
	}
}

void pre_ordem(noArvore **no)
{
	if((*no) != NULL)
	{
		printf("%d ", (*no)->valor);
		pre_ordem(&(*no)->esquerda);
		pre_ordem(&(*no)->direita);
	}
}

void print_arvore(noArvore **no, int ordem)
{
	//system("cls");
	if(ordem == 1)
	{
		printf("Arvore em pre-ordem:\n");
		pre_ordem(&(*no));
	}
	else if(ordem == 2)
	{
		
	}
	else if(ordem == 3)
	{
		
	}
	else
	{
		printf("Ordem nao encontrada!\n");
	}
}

int escolher_ordem()
{
	int ordem;
	
	printf("ESCOLHA A ORDEM QUE DESEJA IMPRIMIR A ARVORE\n");
	printf("PRE-ORDEM 	(1)\n");
	printf("ORDEM 		(2)\n");
	printf("POS-ORDEM 	(3)\n");
	
	scanf("%d", &ordem);
	
	return ordem;
}

int escolher_tamanho()
{
	int tamanho;
	system("cls");
	printf("QUANTOS ELEMENTOS DEVE TER A ARVORE?\n");
	scanf("%d", &tamanho);
	
	return tamanho;
}


int main()
{
	noArvore *raiz;
	iniciar(&raiz);
	
	int ordem = escolher_ordem();
	int n = escolher_tamanho();
	
	ler_chaves(&raiz, n);
	int valor;

	printf("Digite um valor a ser removido\n");
	scanf("%d", &valor);

	remover(&raiz, valor);
	print_arvore(&raiz, ordem);

	return 0;
}