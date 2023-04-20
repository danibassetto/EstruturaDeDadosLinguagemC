#include <stdio.h>

// função troca

void troca(int *x, int *y)
{
	int aux;
	
	aux = *x;
	*x = *y;
	*y = aux;	
}

main()
{
	int a, b;
	
	printf("Digite o valor de A: ");
	scanf("%d", &a);
	printf("Digite o valor de B: ");
	scanf("%d", &b);
	
	troca(&a, &b);
	
	printf("\nA = %d e B = %d", a, b);
}
