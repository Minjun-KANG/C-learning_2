#include<stdio.h>

int main()
{
	int num;
	printf("숫자를 입력해주세요 : ");
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		for (int j = 0; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}
}