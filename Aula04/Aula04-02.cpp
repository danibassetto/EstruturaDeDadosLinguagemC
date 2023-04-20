#include <stdio.h>
#include <stdlib.h>

struct dados
{
	int info;
	struct dados *prox;
};

typedef struct dados NO;

main()
{
	NO *p, *q, *r;
	
	p = (NO *)calloc(1, sizeof(NO));
	p->info = 10;
	
	q = (NO *)calloc(1, sizeof(NO));
	q->info = 20;
	
	r = (NO *)calloc(1, sizeof(NO));
	r->info = 30;
	
	p->prox = q;
	q->prox = r;
	r->prox = NULL;
	
	while(p != NULL)
	{
		printf("%d ", p->info);
		p = p->prox;
	}
	printf("NULL");
}
