#include <stdio.h>
#include <stdlib.h>

#define tam 10

typedef struct
{
	int topo;
	int info[tam];
}PILHA;

void Inicializa(PILHA *p)
{
	p->topo = -1; // -1 para iniciar a partir do 0
}

int Cheia(PILHA *p)
{
	return (p->topo == tam-1); // se vai de 0 a 9 temos 10 elementos já, então tem que checar se topo é 9
}

int Vazia(PILHA *p)
{
	return (p->topo == -1); // -1 se o topo for -1
}

int Push(PILHA *p, int v)
{
	if(Cheia(p))
		return 0;
	p->info[++p->topo] = v; // adicionando
	return 1;
}

int Pop(PILHA *p, int *v)
{
	if(Vazia(p))
		return 0; // pilha vazia = não tem o que remover

	*v = p->info[p->topo--]; // v se torna o elemento anterior
	return 1;
}

void Imprime(PILHA p)
{
	int i;
	for(i =p.topo; i >= 0; i--)
		printf("[ %d ]\n", p.info[i]);
}

main()
{
	PILHA s;
	int op, val;
	
	do
	{
		system("cls"); // a cada execução, limpa o console
		puts("1 - Inserir na Pilha");
		puts("2 - Remover da Pilha");
		puts("3 - Imprimir a Pilha");
		puts("0 - Sair do programa");
		
		printf("\nDigite a opcao: ");
		scanf("%d", &op);
		
		switch(op)
		{
			case 1: printf("\nDigite o valor: ");
					scanf("%d", &val);
					if(Push(&s, val))
						printf("\nInsercao realizada com sucesso!");
					else
						printf("\nPilha cheia!");
					system("Pause");
					break;
			case 2: if(Pop(&s, &val))
						printf("\nValor removido: %d\n", val);
					else
						printf("\nPilha vazia!");
					system("Pause");
					break;
			case 3: if(Vazia(&s))
						printf("\nPilha vazia!");
					else
					{
						printf("Pilha: \n");
						Imprime(s);
					}
					system("Pause");
					break;
			default: printf("Opcao invalida!");
					 system("Pause");
					 break;
		}
	} while(op != 0);
}
