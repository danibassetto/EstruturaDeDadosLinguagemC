#include <stdio.h>

main()
{
	int a, *p;
	
	a = 10;
	
	p = &a;  // p é um ponteiro que armazena endereço de memória de a
	
	printf("\nA = %d", a);
	printf("\nEndereço de a = %x", &a);
	
	*p = 20;  // ao trocar o conteudo de p, troquei o de a, pois p era o endereço de A
	
	printf("\nP = %x", p);
	printf("\nConteudo de p = %d", *p);
	
	/*
	p = a; ERRO
	p = &a; VERDADEIRO
	*p = 20; VERDADEIRO
	*p = &a; ERRO
	
	a = p; ERRO (a é valor e p endereço)
	a = *p; VERDADEIRO (a recebe conteúdo de p, os dois são valores)
	
	*/
}
