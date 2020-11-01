#include <stdio.h>

int main(void)
{
	int a = 0 , b = 0, c = 0, d = 0;
	int *pa, *pb, *pc, *pd;

	// faz os ponteiros apontarem para as variaveis int
	pa = &a;
	pb = &b;
	pc = &c;
	pd = &d;

	printf("Estado das variaveis int:\na = %d\nb = %d\nc = %d\nd = %d\n", a, b, c, d);

	*pa = *pa + 1;
	printf("Estado das variaveis int:\na = %d\nb = %d\nc = %d\nd = %d\n", a, b, c, d);

	*pb = *pb + 2;
	printf("Estado das variaveis int:\na = %d\nb = %d\nc = %d\nd = %d\n", a, b, c, d);

	*pc = *pc + 3;
	printf("Estado das variaveis int:\na = %d\nb = %d\nc = %d\nd = %d\n", a, b, c, d);

	*pd = *pd + 4; 
	printf("Estado das variaveis int:\na = %d\nb = %d\nc = %d\nd = %d\n", a, b, c, d);

	return 0;
}
