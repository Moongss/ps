#include <stdio.h>
#include <stdlib.h>

typedef struct  s_set{
	int order;
	int age;
	char name[101];
}				t_set;

int mycmp(t_set *a, t_set *b) 
{
	int age;
	
	age = a->age - b->age;
	return age != 0 ? age : a->order - b->order;
}

int main(void)
{
	t_set* set;

	int num;

	scanf("%d", &num);
	set = (t_set*)malloc(num * sizeof(t_set));
	for (int i = 0; i < num; i++)
	{
		scanf("%d %s", &set[i].age, set[i].name);
		set[i].order = i;
	}
	qsort(set, num, sizeof(t_set), mycmp);
	for (int i = 0; i < num; i++)
		printf("%d %s\n", set[i].age, set[i].name);
	return (0);
}

