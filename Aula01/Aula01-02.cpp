#include <stdio.h>

void dobro(int *a)
{
	*a = 2 * (*a);
}

main()
{
	int a; 
	
	printf("Digite um numero: ");
	scanf("%d", &a);
	
	dobro(&a);
	printf("Dobro = %d", a);
}
