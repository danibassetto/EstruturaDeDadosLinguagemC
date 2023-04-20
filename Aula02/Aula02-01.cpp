// algoritmo incrementa a

#include <stdio.h>

void incrementa(int *a)
{
	(*a)++;
}

main()
{
	int a = 10;
	
	incrementa(&a);
	printf("A = %d", a);
}
