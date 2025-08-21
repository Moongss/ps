#include <stdio.h>

int main(void)
{
	long A, B, V;
	scanf("%d %d %d", &A, &B, &V);
	if ((V - A) % (A - B) == 0)
		printf("%d", 1 + (V - A) / (A - B));
	else
		printf("%d", 2 + (V - A) / (A - B));
}