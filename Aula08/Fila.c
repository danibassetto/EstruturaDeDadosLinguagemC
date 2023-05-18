#include <stdio.h>
#include <stdlib.h>

#define tam 10

void Cria_Fila(int *Inicio, int *Fim)
{
	*Inicio = 0;
	*Fim = 0;
}

int Ins_Fila(int *Fila, int *Inicio, int *Fim, int val)
{
	if((*Fim + 1) % tam == *Inicio)
		return 0; // Fila cheia
	else
	{
		*Fim = (*Fim + 1) % tam;
		Fila[*Fim] = val;
		return 1;
	}
}

int Rem_Fila(int *Fila, int *Inicio, int *Fim, int *val)
{
	if(*Inicio == *Fim)
		return 0; // Fila vazia
	else
	{
		*Inicio = (*Inicio + 1) % tam;
		*val = Fila[*Inicio];
		return 1;
	}
}

void Imprime(int *Fila, int Inicio, int Fim)
{
	int i = Inicio;
	
	do
	{
		i = (i + 1) % tam;
		printf("[%d]", Fila[i]);
	} while (i != Fim);
	printf("\n");
}

int Tamanho(int Inicio, int Fim)
{
	int i = Inicio, cont = 0;
	
	do
	{
		i = (i + 1) % tam;
		cont++;
	} while (i != Fim);
	
	return cont;
}

void Esvaziar(int *Fila, int *Inicio, int *Fim)
{
	int v;
	
	while(Rem_Fila(Fila, Inicio, Fim, &v))
	{
		printf("Removeu...%d\n", v);
		if(*Inicio != *Fim)
			Imprime(Fila, *Inicio, *Fim);
	}
}

main()
{
	int Fila[tam], Inicio, Fim, val, op;
	
	Cria_Fila(&Inicio, &Fim);
	
	do
	{
		system("cls");
		puts("1 - Inserir na Fila");
		puts("2 - Remover da Fila");
		puts("3 - Imprimir a Fila");
		puts("4 - Tamanho da Fila");
		puts("5 - Esvaziar a Fila");
		puts("0 - Sair do programa");
		
		printf("\nDigite a opcao: ");
		scanf("%d", &op);
		
		switch(op)
		{
			case 1: printf("\nDigite o valor a inserir: ");
					scanf("%d", &val);
					if(Ins_Fila(Fila, &Inicio, &Fim, val))
						printf("\nInsercao realizada com sucesso!\n");
					else
						printf("\nFila cheia!\n");
					system("Pause");
					break;
			case 2: if(Rem_Fila(Fila, &Inicio, &Fim, &val))
						printf("\nRemovido valor: %d\n", val);
					else
						printf("\nFila vazia!\n");
					system("Pause");
					break;
			case 3: if(Inicio == Fim)
						printf("\nFila vazia!\n");
					else
					{
						printf("\nFila:\n");
						Imprime(Fila, Inicio, Fim);
					}
					system("Pause");
					break;
			case 4: if(Inicio == Fim)
						printf("\nFila vazia!");
					else
					{
						val = Tamanho(Inicio, Fim);
						printf("\nTamanho da fila: %d\n", val);
					}
					system("Pause");
					break;
			case 5: if(Inicio == Fim)
						printf("\nFila vazia!");
					else
						Esvaziar(Fila, &Inicio, &Fim);
					system("Pause");
					break;
		}
	} while (op != 0);
}
