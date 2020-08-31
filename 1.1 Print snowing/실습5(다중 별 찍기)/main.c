#include<stdio.h>

int main()
{
	int size;
	printf("크기를 입력하세요 : ");
	scanf("%d", &size);

	for (int k = 0, i = 0; i < size; i++) {
		for (int j = 0; j < 10; j++) {
			if (k % 2 == 0)
			{
				printf("*");
				k++;
			}
			else {
				printf(" ");
				k++;
			}
		}
		k++;
		printf("\n");
	}
}

#include<stdio.h>

