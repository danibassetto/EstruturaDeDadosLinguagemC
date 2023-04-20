/*
Elabore um algoritmo que crie uma função capaz de receber um parâmetro inteiro. Retorne, no próprio parâmetro com o dobro
 do número recebido. Crie a função principal e faça a devida chamada com os parâmetros. Mostre os resultados.
*/
#include <locale.h>
#include <stdio.h>

void dobro(int num, int *x)
{
	*x = num * 2;
}

main()
{
	setlocale(LC_ALL, "");
	int x, num;
	
	puts("Informe um número: ");
	scanf("%d", &num);
	
	dobro(num, &x);
	
	printf("O dobro é %d", x);
}
