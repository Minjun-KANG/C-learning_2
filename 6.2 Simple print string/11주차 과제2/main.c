#include<stdio.h>
#include<stdlib.h>

int main()
{
	char *cp;
	char buffer;
	int array_size;
	printf("�Ҵ��Ϸ��� ũ�� : ");
	scanf("%d", &array_size);
	while (buffer = getchar() != '\n' && buffer != EOF);

	cp = (char*)calloc(array_size+1, sizeof(char));
	printf("��������� ���� : ");
	scanf("%[^\n]s", cp);

	printf("���Ȯ�� : %s\n",cp);
	free(cp);
}