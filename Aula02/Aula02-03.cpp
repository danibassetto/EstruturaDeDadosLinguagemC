#include <stdio.h>
#include <string.h>

main()
{
	char nome[30];
	int i;
	
	puts("Digite um nome: ");
	gets(nome);
	
	for(i=0; i<strlen(nome); i++)
		printf("\n%c", *(nome+i));
}
