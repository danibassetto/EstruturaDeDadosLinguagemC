/*
Elabore uma função que receba como parâmetro uma string de no máximo 20 caracteres e um caractere. Retorne com a primeira
ocorrência do caractere no string. Caso o caractere não exista na string, retorne com -1
*/

#include <stdio.h>
#include <string.h>

int busca(char *s, char C)
{
	int i, p = -1;
	
	for(i = 0; i < strlen(s); i++) 
		if(*(s+i) == C) 
		{ //if (s[i] == C)
			p = i;
			break;
		}
	return p;
}

main()
{
	char str[20], car;
	int pos;
	
	puts("Digite uma palavra: ");
	gets(str);
	
	fflush(stdin); //limpando buffer do teclado
	puts("Digite um caractere:");
	scanf("%c", &car);
	
	pos = busca(str, car);
	
	if(pos == -1)
		puts("Caractere não existe!");
	else
		printf("Caractere %c na posicao: %d", car, pos);
}
