#include <stdio.h>

void sucessor(int num, int *suc)
{
	*suc = num + 1;	// trasnportando o endere�o de s, o valor ser� atribuido para ele, e n�o para vari�vel local da fun��o
}

main()
{
	int n = 10, s;
	
	sucessor(n, &s); // passando o endere�o de s, ent�o o par�metro esperado deve ser um ponteiro
	
	printf("O sucessor de %d = %d", n, s);
	
	//
}
