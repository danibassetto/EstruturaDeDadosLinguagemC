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
		
	for(i = p.topo; i >= 0; i--)
	    printf("[ %d ]\n", p.info[i]);
}

int Converter(PILHA p, int v)
{
	int bin = 0, x;
	
	while(v > 0)
	{
		Push(&p, v%2); // empilhando os restos da divisão por 2
		v /= 2;
	}
	
	while(!Vazia(&p))
	{
		Pop(&p, &x); // enquanto a pilha não estiver vazia, ele remove os itens
		bin = bin * 10 + x; // concatena
	}
	return bin;
}

void Remover(PILHA *p, PILHA *a, int v)
{
	int x;
	
	while(!Vazia(p) && (p->info[p->topo] != v))
	{
		Pop(p, &x);
		Push(a, x);
	}
	
	if(Vazia(p))
		printf("\nValor nao encontrado!\n");
	else
	{
		Pop(p, &x);
		printf("\nValor removido!");
	}
	
	while(!Vazia(a))
	{
		Pop(a, &x);
        Push(p, x);
	}
}

void Ordenar(PILHA *p, PILHA *a, int v)
{
    int x;

    // enquanto a pilha não estiver vazia e o valor a ser inserido for maior que o topo da pilha
    while (!Vazia(p) && v > p->info[p->topo])
    {
        Pop(p, &x); // desempilha o elemento
        Push(a, x); // empilha na pilha auxiliar
    }

    Push(p, v); // insere o novo elemento na pilha

    // enquanto a pilha auxiliar não estiver vazia (processo de empilhamento na pilha original)
    while (!Vazia(a))
    {
        Pop(a, &x); // desempilha o elemento da pilha auxiliar
        Push(p, x); // empilha na pilha original
    }
}


main()
{
	PILHA s, aux;
	int op, val, binario;

	Inicializa(&s);
	
	do
	{
		system("cls"); // a cada execução, limpa o console
		puts("1 - Inserir na Pilha");
		puts("2 - Remover da Pilha");
		puts("3 - Imprimir a Pilha");
		puts("4 - Converter decimal para binario");
		puts("5 - Remover um valor da Pilha");
		puts("6 - Inserir na Pilha de forma ordenada");
		puts("0 - Sair do programa");
		
		printf("\nDigite a opcao: ");
		scanf("%d", &op);
		
		switch(op)
		{
			case 1: printf("\nDigite o valor: ");
					scanf("%d", &val);
					if(Push(&s, val))
						printf("\nInsercao realizada com sucesso!\n");
					else
						printf("\nPilha cheia!\n");
					system("Pause");
					break;
			case 2: if(Pop(&s, &val))
						printf("\nValor removido: %d\n", val);
					else
						printf("\nPilha vazia!\n");
					system("Pause");
					break;
			case 3: if (Vazia(&s))
			            printf("\nPilha Vazia!\n");
			        else
			        {
			        	printf("Pilha:\n");
			        	Imprime(s);
					}
					system("Pause");
					break;
			case 4: printf("\nDigite um valor em decimal: ");
					scanf("%d", &val);
					
					Inicializa(&s);
					binario = Converter(s, val);
					
					printf("\n%d em binario = %d\n", val, binario);
					system("Pause");
					break;
			case 5: printf("\nDigite o valor a remover: ");
					scanf("%d", &val);
					
					Inicializa(&aux);
					Remover(&s, &aux, val);

					system("Pause");
					break;
			case 6: printf("\nDigite o valor a inserir: ");
    				scanf("%d", &val);
    				
					Inicializa(&aux);
    				Ordenar(&s, &aux, val);

    				system("Pause");
    				break;
				
			default:printf("Opcao invalida!\n");
					system("Pause");
					break;
		}
	} while(op != 0);
}
