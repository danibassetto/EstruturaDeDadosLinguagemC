/*
Fazer um programa em C, usando o conceito de fun��es e par�metros que, crie um vetor com N idades.
Ap�s isso, fa�a as fun��es:
a) Ler as N idades
b) Mostrar as N idades
c) Calcular e retornar com a m�dia entre as idades
d) Calcular e retornar  a maior idade
*/

#include <stdio.h>
#include <stdlib.h>

void leitura(int *vet, int tam)
{
	int i;
	puts("Digite as idades:");
	for(i = 0; i < tam; i++)
	{
		scanf("%d", &vet[i]); // (vet + i)
	}
}

void mostrar(int *vet, int tam)
{
	int i;
	puts("Idades:");
	for(i = 0; i < tam; i++)
	{
		printf("%d", vet[i]); // *(vet+i)
	}
	
}

main()
{
	int *v, n;
	
	puts("Digite a qtd de elementos:");
	scanf("%d", &n);
	
	v = (int *) calloc(n, sizeof(int));
	
	leitura(v, n);
	
	mostrar(v, n);
}
