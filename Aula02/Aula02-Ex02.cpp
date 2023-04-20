/*
Elabore uma função que receba como parâmetro duas notas (n1 e n2). A função deverá retornar com a maior nota e também com a 
média entre elas (um dos cálculos deverá ser retornado via parâmetro). Faça a função principal e a devida chamada a
função criada.
*/

#include <stdio.h>

void media_e_maior(double *media, double *maior, double *n1, double *n2)
{
	*media = (*n1 + *n2) / 2;

	if(*n1 > *n2)
		*maior = *n1;
	else
		*maior = *n2;
}

main()
{
	double n1, n2, media, maior;
	
	puts("Informe sua primeira nota:");
	scanf("%d", &n1);
	
	puts("Informe sua segunda nota:");
	scanf("%d", &n2);
	
	media_e_maior(&media, &maior, &n1, &n2);
	
	printf("Maior nota: %d", maior);
	printf("\nMedia = %d", media);
}
