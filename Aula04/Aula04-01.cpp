#include <stdio.h>

void sucessor(int num, int *suc)
{
	*suc = num + 1;	// trasnportando o endereço de s, o valor será atribuido para ele, e não para variável local da função
}

main()
{
	int n = 10, s;
	
	sucessor(n, &s); // passando o endereço de s, então o parâmetro esperado deve ser um ponteiro
	
	printf("O sucessor de %d = %d", n, s);
	
	//
}
