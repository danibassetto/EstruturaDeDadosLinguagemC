/*
Elabore um algoritmo que crie uma fun��o capaz de receber um par�metro inteiro. Retorne, no pr�prio par�metro com o dobro
 do n�mero recebido. Crie a fun��o principal e fa�a a devida chamada com os par�metros. Mostre os resultados.
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
	
	puts("Informe um n�mero: ");
	scanf("%d", &num);
	
	dobro(num, &x);
	
	printf("O dobro � %d", x);
}
