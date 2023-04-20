/*
Elabore um algoritmo que crie uma função capaz de receber um parâmetro inteiro. Retorne, em outros dois parâmetros com o 
sucessor e o antecessor do número recebido. Crie a função principal e faça a devida chamada com os parâmetros. Mostre os 
resultados.
*/

#include <stdio.h>

void ant_suc(int n, int *x, int *y)
{
	*x = n-1;
	*y = n+1;
}

main()
{
	int num, a, s;
	
	puts("Digite um numero: ");
	scanf("%d", &num);
	
	ant_suc(num, &a, &s);	
	printf("\nAntecessor de %d = %d", num, a);
	printf("\nSucessor de %d = %d", num, s);
}
