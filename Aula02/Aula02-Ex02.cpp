/*
Elabore uma fun��o que receba como par�metro duas notas (n1 e n2). A fun��o dever� retornar com a maior nota e tamb�m com a 
m�dia entre elas (um dos c�lculos dever� ser retornado via par�metro). Fa�a a fun��o principal e a devida chamada a
fun��o criada.
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
