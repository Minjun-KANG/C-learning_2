#include<stdio.h>

int main()
{
	int a[5][5];	//��İ��� ó���� �迭����
	
	for (int j = 0; j < 5; j++)		//a�迭�� ���� �Է��ϱ� ���� for��
	{
		for (int i = 0; i < 5; i++)
		{
			printf("[%d,%d] �Է� : ", j, i);
			scanf("%d", &a[j][i]);			//5*5 �迭 �� �Է�
		}
	}
	printf("===============Original===============\n");
	for (int j = 0; j < 5; j++)			//Original ��� ���� for��
	{
		for (int i = 0; i < 5; i++)
		{
			printf("%d\t", a[j][i]);
		}
		printf("\n");
	}

	printf("===============Transpose===============\n");
	for (int j = 0; j < 5; j++)			//Transpose ��� ���� for��
	{
		for (int i = 0; i < 5; i++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}