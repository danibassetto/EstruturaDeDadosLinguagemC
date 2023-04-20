#include <stdio.h>
#include <stdlib.h>

struct dados
{
	struct dados *esq;
	int info;
	struct dados *dir;
};

typedef struct dados NO;

void Cria_LDE(NO **Inicio, NO **Fim)
{
	*Inicio = NULL;
	*Fim = NULL;
}

void Ins_Inicio(NO **Inicio, NO **Fim, int val)
{
	NO *p;
	
	p = (NO *)calloc(1, sizeof(NO));
	p->info = val;
	
	p->esq = NULL;
	p->dir = *Inicio;
	
	if(*Inicio == NULL)
		*Fim = p;
	else
		(*Inicio)->esq = p;
		
	*Inicio = p;
}

void Ins_Fim(NO **Inicio, NO **Fim, int val)
{
	NO *p;
	
	p = (NO *)calloc(1, sizeof(NO));
	
	p->info = val;
	
	p->dir = NULL;
	p->esq = *Fim;
	
	if(*Inicio == NULL)
		*Inicio = p;
	else
		(*Fim)->dir = p;
	*Fim = p;
}


void Imprime(NO *Inicio)
{
	NO *p;
	
	p = Inicio;
	printf("\nNULL");
	
	while(p != NULL)
	{
		printf("<--%d-->", p->info);
		p = p->dir;
	}
	printf("NULL\n\n");
}

void Rem_Inicio(NO **Inicio, NO **Fim)
{
	NO *p;
	
	p = *Inicio;
	
	if(*Inicio == *Fim) // um elemento
	{
		*Inicio = NULL;
		*Fim = NULL;
	}
	else
	{
		*Inicio = p->dir;
		(*Inicio)->esq = NULL;
	}
	free(p);
}

void Rem_Fim(NO **Inicio, NO **Fim)
{
	NO *p;
	
	p = *Fim;
	if(*Inicio == *Fim)
	{
		*Inicio = NULL;
		*Fim = NULL;
	}
	else
	{
		*Fim = p->esq;
		(*Fim)->dir = NULL;
	}
	free(p);
}

NO * Consulta(NO *Inicio, int val)
{
	NO *p = Inicio;

	while (p!=NULL && p->info!= val)
	   p=p->dir;

	return p;
}

void Ins_Depois(NO *r, int val)
{
	NO *p, *q;

	p = (NO *)calloc(1, sizeof(NO));
	p->info = val;

	q = r->dir;
	p->dir = q;
	p->esq = r;

	r->dir = p;
	q->esq = p;
}

void Rem_Meio(NO *r)
{
	NO *p,*q;

	q = r->esq;
	p = r->dir;

	q->dir = p;
	p->esq = q;

	free(r);
}

void Ins_Ordenado(NO **Inicio, NO **Fim, int val)
{
    NO *p, *q;

    p = (NO *)calloc(1, sizeof(NO));
    p->info = val;

    if (*Inicio == NULL || val <= (*Inicio)->info) // se é menor ou igual ao primeiro elemento, insere no início
        Ins_Inicio(Inicio, Fim, val);
	else if (val >= (*Fim)->info) //  se é maior ou igual ao último elemento, insere no fim
        Ins_Fim(Inicio, Fim, val);
    else // senão percorre a lista para encontrar a posição correta para inserir o novo elemento
	{
        q = *Inicio;
        while (q != NULL && q->info < val) {
            q = q->dir;
        }
        p->esq = q->esq;
        p->dir = q;
        q->esq->dir = p;
        q->esq = p;
    }
}

main()
{
	NO *Inicio, *Fim, *r;
	int val, op;
	
	Cria_LDE(&Inicio, &Fim);
	
	do
	{
		system("cls");
		puts("1 - Inserir no Inicio");
		puts("2 - Inserir no Fim");
		puts("3 - Imprimir a Lista");
		puts("4 - Remover no Inicio");
		puts("5 - Remover no Fim");
		puts("6 - Consultar valor");
		puts("7 - Adicionar depois de um valor");
		puts("8 - Remover um valor");
		puts("9 - Inserir de forma ordenada");
		puts("0 - Sair do programa");
		printf("\nDigite a opcao: ");
		
		scanf("%d", &op);
		
		switch(op)
		{
			case 1: printf("\nDigite o valor: ");
					scanf("%d", &val);
					Ins_Inicio(&Inicio, &Fim, val);
					break;
					
			case 2: printf("\nDigite o valor: ");
					scanf("%d", &val);
					Ins_Fim(&Inicio, &Fim, val);
					break;
					
			case 3: if(Inicio == NULL)
						printf("A lista esta vazia!");
					else
					{
						printf("\nLista:\n");
						Imprime(Inicio);
					}
					system("Pause");
					break;
					
			case 4: if(Inicio == NULL)
						printf("\nLista vazia!");
					else
						Rem_Inicio(&Inicio, &Fim);
					break;
					
			case 5: if(Inicio == NULL)
						printf("\nLista vazia!");
					else
						Rem_Fim(&Inicio, &Fim);
					break;
					
			case 6: printf("\nDigite o valor a procurar: ");
					scanf("%d", &val);
					
					r = Consulta(Inicio, val);
					
					if(r == NULL)
						printf("\nValor nao existe\n!");
					else
						printf("\nValor = %d\n", r->info);
					system("Pause");
					break;
					
			case 7: printf("\nDigite o valor a procurar:");
			        scanf("%d", &val);

			        r = Consulta(Inicio, val);

			        if (r==NULL)
			             printf("\nValor nao existe!\n");
			        else
			        {
			        	printf("\nDigite o valor a inserir:");
			        	scanf("%d", &val);
			        	if (r==Fim)
			        		Ins_Fim(&Inicio, &Fim, val);
			        	else
				        	Ins_Depois(r,val);
					}
			        break;
			        
			case 8: printf("\nDigite o valor a remover:");
			        scanf("%d", &val);

			        r = Consulta(Inicio, val);

			        if (r==NULL)
			             printf("\nValor nao existe!\n");
			        else
			        {
			        	if (r==Inicio)
			        		Rem_Inicio(&Inicio, &Fim);
			        	else
			        		if (r==Fim)
			        		    Rem_Fim(&Inicio,&Fim);
			        		else
			        			Rem_Meio(r);
			        }
			        break;
			        
			case 9: printf("\nDigite o valor: ");
    				scanf("%d", &val);
    				Ins_Ordenado(&Inicio, &Fim, val);
    				break;
		}
	}while(op != 0);
}
