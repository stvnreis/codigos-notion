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

void pre_ordem(noArvore **no)
{
	if((*no) != NULL)
	{
		printf("%d ", (*no)->valor);
		pre_ordem(&(*no)->esquerda);
		pre_ordem(&(*no)->direita);
	}
}

int main()
{
	noArvore *raiz;
	iniciar(&raiz);
	
	inserir(&raiz, 2);
	inserir(&raiz, 1);
	inserir(&raiz, 3);
	
	pre_ordem(&raiz);
	return 0;
}
