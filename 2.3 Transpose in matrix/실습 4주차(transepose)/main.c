#include<stdio.h>

int main()
{
	int a[5][5];	//행렬값을 처리할 배열선언
	
	for (int j = 0; j < 5; j++)		//a배열에 값을 입력하기 위한 for문
	{
		for (int i = 0; i < 5; i++)
		{
			printf("[%d,%d] 입력 : ", j, i);
			scanf("%d", &a[j][i]);			//5*5 배열 값 입력
		}
	}
	printf("===============Original===============\n");
	for (int j = 0; j < 5; j++)			//Original 출력 전용 for문
	{
		for (int i = 0; i < 5; i++)
		{
			printf("%d\t", a[j][i]);
		}
		printf("\n");
	}

	printf("===============Transpose===============\n");
	for (int j = 0; j < 5; j++)			//Transpose 출력 전용 for문
	{
		for (int i = 0; i < 5; i++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}