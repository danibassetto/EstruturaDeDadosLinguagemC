#include <stdio.h>
#include <stdlib.h>

struct no_arvore
{
    struct no_arvore *esq;
    int info;
    struct no_arvore *dir;
};

typedef struct no_arvore ARVORE;

void Insere(ARVORE **Raiz, int val)
{
    if (*Raiz == NULL)
    {
        (*Raiz) = (ARVORE *)calloc(1, sizeof(ARVORE));
        (*Raiz)->info = val;
        (*Raiz)->esq = NULL;
        (*Raiz)->dir = NULL;
    }
    else if (val < (*Raiz)->info)
        Insere(&(*Raiz)->esq, val);
    else
        Insere(&(*Raiz)->dir, val);
}

void Pre_Order(ARVORE *Raiz)
{
    if (Raiz != NULL)
    {
        printf("%d ", Raiz->info);
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
    if (Raiz != NULL)
    {
        Pos_Order(Raiz->esq);
        Pos_Order(Raiz->dir);
        printf("%d ", Raiz->info);
    }
}

ARVORE *Busca(ARVORE *Raiz, int val)
{
    if (Raiz==NULL)
	   return NULL;
	else
	   if (Raiz->info==val)
	      return Raiz;
	   else
	      if (Raiz->info > val)
		 	return Busca (Raiz->esq,val);
	      else
		 	return Busca (Raiz->dir,val);
}

ARVORE *Encontra_Menor(ARVORE *Raiz)
{
    if (Raiz == NULL || Raiz->esq == NULL)
        return Raiz;
    return Encontra_Menor(Raiz->esq);
}

ARVORE *Remove_No(ARVORE *Raiz, int val)
{
    if (Raiz == NULL)
        return NULL;
    else if (val < Raiz->info)
        Raiz->esq = Remove_No(Raiz->esq, val);
    else if (val > Raiz->info)
        Raiz->dir = Remove_No(Raiz->dir, val);
    else
    {
        if (Raiz->esq == NULL && Raiz->dir == NULL) // folha
        {
            free(Raiz);
            Raiz = NULL;
        }
        else if (Raiz->esq == NULL) // 1 filho a direita
        {
            ARVORE *aux = Raiz;
            Raiz = Raiz->dir;
            free(aux);
        }
        else if (Raiz->dir == NULL) //  1 filho a esquerda
        {
            ARVORE *aux = Raiz;
            Raiz = Raiz->esq;
            free(aux);
        }
        else // 2 filhos
        {
            ARVORE *aux = Encontra_Menor(Raiz->dir);
            Raiz->info = aux->info;
            Raiz->dir = Remove_No(Raiz->dir, aux->info);
        }
    }
    return Raiz;
}

main()
{
    ARVORE *Raiz, *r;
    int op, val;

    Raiz = NULL;

    do
    {
        system("cls");
        puts("1 - Inserir Valor");
        puts("2 - Percursos");
        puts("3 - Buscar um valor");
        puts("4 - Remover um no");
        puts("0 - Sair do Programa");

        printf("\nDigite a opcao: ");
        scanf("%d", &op);

        switch (op)
        {
	        case 1:
	            printf("\nDigite o valor: ");
	            scanf("%d", &val);
	            Insere(&Raiz, val);
	            break;

	        case 2:
	            if (Raiz == NULL)
	                printf("\nArvore vazia!");
	            else
	            {
	                printf("\nPRE: ");
	                Pre_Order(Raiz);
	                printf("\nIN : ");
	                In_Order(Raiz);
	                printf("\nPOS: ");
	                Pos_Order(Raiz);
	                printf("\n");
	            }
	            system("Pause");
	            break;

	        case 3:
	            printf("\nDigite o valor a buscar:");
	            scanf("%d", &val);

	            r = Busca(Raiz, val);

	            if (r == NULL)
	                printf("\nValor nao encontrado!");
	            else
	                printf("\nValor = %d", r->info);

	            printf("\n");
	            system("Pause");
	            break;

	        case 4:
	            printf("\nDigite o valor a ser removido: ");
	            scanf("%d", &val);
	            Raiz = Remove_No(Raiz, val);
	            break;
        }

    } while (op != 0);
}

