#include <stdio.h>
#include <locale.h>

main()
{
	setlocale(LC_ALL, "");
	char nome[30];	
	
	puts("Digite um nome:");
	gets(nome);
	
	printf("%c", nome[0]);
	printf("\n%c", *nome);	
	// todo nome de vetor, todo nome de string na verdade é um endereço físico de memória
}
