#include <stdio.h>

struct dados
{
	char nome[30];
	int idade;
	float altura;
};

typedef struct dados PESSOA;

main()
{
	PESSOA a, *p;
	
	puts("Digite o nome: ");
	gets(a.nome);
	puts("Digite a idade: ");
	scanf("%d", &a.idade);
	puts("Digite a altura: ");
	scanf("%f", &a.altura);
	
	p = &a;
	
	printf("\nNome: %s, Idade: %d, Altura: %f", a.nome, a.idade, a.altura);
	
	printf("\nNome: %s, Idade: %d, Altura: %f", p->nome, p->idade, p->altura);
}
