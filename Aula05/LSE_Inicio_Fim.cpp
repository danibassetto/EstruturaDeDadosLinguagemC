#include <stdio.h>
#include <stdlib.h>

struct dados
{
	int info;
	struct dados *prox;
};

typedef struct dados NO;

void Cria_LSE(NO **Inicio, NO **Fim )
{
	*Inicio = NULL;
	*Fim = NULL;
}

void Ins_Inicio(NO **Inicio, NO **Fim, int val)
{
	NO *p;
	
	p = (NO*)calloc(1, sizeof(NO));
	p->info = val;
	p->prox = *Inicio;
	if (*Inicio == NULL)
	    *Fim = p;
	    
	*Inicio = p;
}

void Ins_Fim(NO **Inicio, NO **Fim, int val)
{
	NO *p;
	p = (NO*)calloc(1,sizeof(NO));
	p->info = val;
	p->prox = NULL;
	if (*Inicio == NULL)
	    *Inicio = p;
	else
	   (*Fim)->prox = p;
	   
	*Fim = p;	
}

void Imprime(NO *Inicio)
{
	NO *p = Inicio;
	
	printf("\nInicio-->");
	while (p != NULL)
	{
		printf("%d-->", p->info);
		p = p->prox;
	}
	printf("NULL\n");
}

void Rem_Inicio(NO **Inicio, NO **Fim)
{
	NO *p = *Inicio;
	
	if (p == *Fim) //so existe um n�
	{
		*Inicio = NULL;
		*Fim = NULL;
	}
	else
		*Inicio = p->prox;
		
	free(p);
}

void Rem_Fim(NO **Inicio, NO **Fim)
{
	NO *p = *Fim, *q;
	
	if (p == *Inicio) // so tem um n�
	{
		*Inicio = NULL;
		*Fim = NULL;
	}
	else
	{
		q = *Inicio;
		while (q->prox != p)
		    q = q->prox;
		    
		q->prox = NULL;
		*Fim = q;
	}
	free(p);
}

void Trans_Fim(NO **Inicio, NO **Fim)
{
	NO *p;
	
	p = *Inicio;
	*Inicio = p->prox;
	p->prox = NULL;
	
	(*Fim)->prox = p;
	
	*Fim=p;
}

void Trans_Inicio(NO **Inicio, NO **Fim)
{
	NO *p, * q;
	
	p = *Fim;
	q = *Inicio;
	while (q -> prox != p)
	    q = q->prox;
	    
	p->prox =* Inicio;
	*Inicio = p;
	q->prox = NULL;
	*Fim = q;		
}

void Resta_Um(NO **Inicio, NO **Fim, int N)
{
    NO *p = *Inicio, *q;

    while (*Inicio != *Fim) // enquanto n�o h� apenas um n�
    {
        for (int i = 0; i < N - 1; i++) // looping para "procurar" o N
        {
            q = p; // armazena o n� anterior
            p = p->prox;
            if (p == NULL) // se estiver no final, volta para o inicio
                p = *Inicio;
        }
        if (p == *Fim)
        {
            Rem_Fim(Inicio, Fim); // se for o fim, reaproveitamos a fun��o Rem_Fim
            p = *Inicio;
        }
        else if (p == *Inicio)
        {
            Rem_Inicio(Inicio, Fim); // se for o inicio, reaproveitamos a fun��o Rem_Inicio
            p = *Inicio;
        }
        else // sen�o.. se for no meio
        {
            q->prox = p->prox; 
            free(p);
            p = q->prox;
        }
        Imprime(*Inicio); // Imprime cada remo��o
    }
}

main()
{
	NO *Inicio, *Fim;
	int op, val;
	
	
	Cria_LSE(&Inicio, &Fim);
	
	do
	{
		system("cls");
		puts("1 - Inserir no Inicio");
		puts("2 - Inserir no Fim");
		puts("3 - Imprimir a Lista");
		puts("4 - Remover no Inicio");
		puts("5 - Remover no Fim");
		puts("6 - Transferir Inicio para o Fim");
		puts("7 - Transferir Fim para o Inicio");
		puts("8 - Resta UM");
		puts("0 - Sair do programa");
		
		printf("\nDigite a opcao: ");
		scanf("%d", &op);
		
		switch(op)
		{
			case 1: printf("\nDigite o valor: ");
			        scanf("%d", &val);
			        Ins_Inicio(&Inicio,&Fim, val);
			        break;
			        
			case 2: printf("\nDigite o valor: ");
			        scanf("%d", &val);
			        Ins_Fim(&Inicio,&Fim, val);
			        break;
			
			case 3: if (Inicio == NULL)
						printf("\nLista Vazia!");
					else
						Imprime(Inicio);
						
					system("Pause");
					break;
					
			case 4: if (Inicio == NULL)
						printf("\nLista Vazia!");
					else
						Rem_Inicio(&Inicio, &Fim);
						
					system("Pause");
					break;
					
			case 5: if (Inicio == NULL)
						printf("\nLista Vazia!");
					else
						Rem_Fim(&Inicio, &Fim);
						
					system("Pause");
					break;
					
			case 6: if (Inicio == NULL)
						printf("\nLista Vazia!");
					else
					    if(Inicio==Fim)//so 1 no
					       printf("\nO primeiro ja eh o ultimo");
					    else
					       Trans_Fim(&Inicio, &Fim);
					system("Pause");
					break;
						
			case 7: if (Inicio == NULL)
						printf("\nLista Vazia!");
					else
					    if(Inicio == Fim)//so 1 no
					       printf("\nO ultimo ja eh o primeiro");
					    else
					       Trans_Inicio(&Inicio, &Fim);
					system("Pause");
					break;
					
			case 8: if (Inicio == NULL)
						printf("\nLista Vazia!");
					else
					    if(Inicio == Fim)//so 1 no
					       printf("\nA lista ja esta com um no!");
					       
					    else
				    	{
				    		printf("\nDigite o valor da contagem:");
				    		scanf("%d", &val);
				    		Resta_Um(&Inicio, &Fim, val);
					    }
					system("Pause");
					break;
		}
	} while (op!=0);
}
