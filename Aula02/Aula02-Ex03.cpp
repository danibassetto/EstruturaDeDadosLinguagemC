/*
Elabore um algoritmo que crie uma fun��o capaz de receber um par�metro inteiro. Retorne, em outros dois par�metros com o 
sucessor e o antecessor do n�mero recebido. Crie a fun��o principal e fa�a a devida chamada com os par�metros. Mostre os 
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
