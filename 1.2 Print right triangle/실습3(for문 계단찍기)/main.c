#include<stdio.h>

int main()
{
	int num;
	printf("���ڸ� �Է����ּ��� : ");
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		for (int j = 0; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}
}