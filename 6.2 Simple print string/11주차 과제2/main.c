#include<stdio.h>
#include<stdlib.h>

int main()
{
	char *cp;
	char buffer;
	int array_size;
	printf("할당하려는 크기 : ");
	scanf("%d", &array_size);
	while (buffer = getchar() != '\n' && buffer != EOF);

	cp = (char*)calloc(array_size+1, sizeof(char));
	printf("출력히려는 문장 : ");
	scanf("%[^\n]s", cp);

	printf("출력확인 : %s\n",cp);
	free(cp);
}