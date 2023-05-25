#include <stdio.h>
#include <stdlib.h>

struct no_arvore
{
	struct no_arvore *esq;
	int info; 
	struct no_arvore *dir; 
};

typedef struct no_arvore ARVORE;

ARVORE *CAPB (int N)
{
	ARVORE *r;
	if (N==0)
	   r=NULL;
	else
	{
		r = (ARVORE *) calloc (1, sizeof(ARVORE));
		printf("\nDigite um valor => ");
		scanf("%i",&r->info);
		r->esq = CAPB(N/2);
		r->dir = CAPB(N - N/2 - 1);
	}
	return r;
}

void Pre_Order(ARVORE *Raiz)
{
	if (Raiz != NULL)
	{
		printf("%d ",Raiz->info);
		Pre_Order(Raiz->esq);
		Pre_Order(Raiz->dir);
	}
}

void In_Order(ARVORE *Raiz)
{
	if (Raiz != NULL)
	{
		In_Order(Raiz->esq);
		printf("%d ", Raiz->info);
		In_Order(Raiz->dir);
	}
}

void Pos_Order(ARVORE *Raiz)
{
	if (Raiz!=NULL)
	{
		Pos_Order(Raiz->esq);
		Pos_Order(Raiz->dir);
		printf("%d ", Raiz->info);
	}
}

void Folhas(ARVORE *Raiz)
{
	if (Raiz != NULL)
	{
		Folhas(Raiz->esq);
		if (Raiz->esq == NULL && Raiz->dir==NULL)
		    printf("%d ", Raiz->info);
		Folhas(Raiz->dir);
	}
}

void Filhos(ARVORE *Raiz, int val)
{
	if (Raiz != NULL)
	{
		Filhos(Raiz->esq, val);
		if (Raiz->info==val) //achei o pai
		    if (Raiz->esq == NULL && Raiz->dir==NULL)
		        printf("\nNao possui filhos!");
		    else
		    {
		    	printf("%d ", Raiz->esq->info);
		    	if (Raiz->dir!=NULL)
		    	   printf("%d ", Raiz->dir->info);
			}
		Filhos(Raiz->dir, val);
	}
}

void Descendentes(ARVORE *Raiz, int val)
{
	if (Raiz != NULL)
	{
		Descendentes(Raiz->esq, val);
		if (Raiz->info==val) //achei o pai
		    if (Raiz->esq == NULL && Raiz->dir==NULL)
		        printf("\nNao possui descendentes!");
		    else
		    {
		    	printf("\nDescendentes de: %d\n", val);
		    	In_Order(Raiz->esq);
		    	In_Order(Raiz->dir);
			}
		Descendentes(Raiz->dir, val);
	}
}

void Pai(ARVORE *Raiz, int val)
{
	if (Raiz != NULL)
	{
		Pai(Raiz->esq, val);
		if ((Raiz->esq != NULL) &&
		   (Raiz->esq->info == val))
		      printf("O pai de %d = %d", val, Raiz->info);
		if ((Raiz->dir!=NULL) &&
		     (Raiz->dir->info==val))
		      printf("O pai de %d = %d", val, Raiz->info);
		   
		Pai(Raiz->dir, val);
	}
}

main()
{
	ARVORE *Raiz;
	int op, n, val;
	
	Raiz = NULL; // Arvore Vazia
	do
	{
		system("cls");
		puts("1 - Cria Arvore Balanceada");
		puts("2 - Percursos");
		puts("3 - Folhas");
		puts("4 - Filhos (Descendentes diretos)");
		
		puts("5 - Descendentes de um No");
		
		puts("6 - Pai de um No");
		
		puts("0 - Sair do programa");
		
		printf("\nDigite a opcao: ");
		scanf("%d", &op);
		
		switch(op)
		{
			case 1: printf("\nDigite a qtd. de nos:");
			        scanf("%d", &n);
					Raiz = CAPB(n);
					break;
					
			case 2: printf("\nPRE: ");
			  		Pre_Order(Raiz);
			  		printf("\nIN : ");
			  		In_Order(Raiz);
			  		printf("\nPOS: ");
			  		Pos_Order(Raiz);
			  		printf("\n");
			  		system("Pause");
			  		break;
			  		
			case 3: printf("\nFolhas:\n");	
					Folhas(Raiz);
					printf("\n");
					system("Pause");
					break;
					
			case 4: printf("\nDigite o no que quer ver os filhos:");
			        scanf("%d", &val);
			        Filhos(Raiz, val);
			        printf("\n");
			        system("Pause");
			        
			case 5: printf("\nDigite o no que quer ver os descendentes:");
			        scanf("%d", &val);
			        Descendentes(Raiz, val);
			        printf("\n");
			        system("Pause");
			        
			case 6: printf("\nDigite o no que quer ver o Pai:");
			        scanf("%d", &val);
			        Pai(Raiz, val);
			        printf("\n");
			        system("Pause");
			        
		}
				
	}while (op!=0);
	
}
