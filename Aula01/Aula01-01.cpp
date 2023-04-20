#include <stdio.h>

main()
{
	int a, *p;
	
	a = 10;
	
	p = &a;  // p � um ponteiro que armazena endere�o de mem�ria de a
	
	printf("\nA = %d", a);
	printf("\nEndere�o de a = %x", &a);
	
	*p = 20;  // ao trocar o conteudo de p, troquei o de a, pois p era o endere�o de A
	
	printf("\nP = %x", p);
	printf("\nConteudo de p = %d", *p);
	
	/*
	p = a; ERRO
	p = &a; VERDADEIRO
	*p = 20; VERDADEIRO
	*p = &a; ERRO
	
	a = p; ERRO (a � valor e p endere�o)
	a = *p; VERDADEIRO (a recebe conte�do de p, os dois s�o valores)
	
	*/
}
