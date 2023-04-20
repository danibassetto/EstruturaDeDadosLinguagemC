#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define tam 10

struct dados 
{
	char desc[30];
	int codigo;
	float preco;
};

typedef struct dados PRODUTO;

void Ins_Fim(PRODUTO *A, int *f) 
{
	printf("\nCodigo: ");
    scanf("%d",&A[*f].codigo);
    printf("\nDescricao: ");
    fflush(stdin);
    gets(A[*f].desc);
    printf("\nPreco: ");
    scanf("%f", &A[*f].preco);
    (*f)++;
}

void Listagem (PRODUTO *A, int f)
{
	int i;
	puts("*** Listagem dos Produtos ***");
	for (i=0; i<f; i++)
	    printf("%d %s %.2f\n", A[i].codigo,
		       A[i].desc, A[i].preco);
}

void Insere_k(PRODUTO *A, int k, int *f)
{
	int i;
	for(i = *f; i > k; i--)
	{
		A[i] = A[i - 1];
	}
	
	printf("\nCodigo: ");
    scanf("%d",&A[k].codigo);
    printf("\nDescricao: ");
    fflush(stdin);
    gets(A[k].desc);
    printf("\nPreco: ");
    scanf("%f", &A[k].preco);
    (*f)++;
}

main()
{
	
	PRODUTO L[tam];
	int fim = 0, op, k;

	do
	{
	 system("cls"); 
	 puts("1 - Inserir produtos no fim da lista");
	 puts("2 - Listar produtos");
	 puts("3 - Inserir um produto na posicao K");
	 
	 puts("0 - Sair do programa"); 
	 
	 puts("\nDigite a opcao:");
	 scanf("%d", &op); 
	 
	 system("cls");
		puts("1 - Inserir produtos no fim da lista");
		puts("2 - Listar produtos");

		puts("0 - Sair do programa");

		printf("\nDigite a opcao:");
		scanf("%d", &op);

		switch(op)
		{
			case 1: if (fim==tam)
			            puts("Lista Cheia!");
			        else
			        	Ins_Fim(L,&fim);

				    getch(); 
			        break;

			case 2: if (fim==0)
			            puts("Lista Vazia!");
			        else
			            Listagem(L, fim);

			        getch();
			        break;
			case 3: printf("\nDigite a posicao k: ");
					scanf("%d", &k);
					if (k<fim)
					   Insere_k(L, k, &fim);
					else
					   puts("Posicao invalida!");

					getch();
					break;
		}
	} while (op != 0);
}
