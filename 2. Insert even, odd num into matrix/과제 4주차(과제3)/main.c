#include<stdio.h>

int main()
{
	int a[5][5] = {0,};	// input data�� ó���ϱ� ���� �迭
	int in;	// ����� Input ���� ����
	int num=1;	//����� ���Ǽ� ��� n��° ǥ������ ����
	int j = 0, k = 0;	// input�� 5*5 �迭 �� ��ġ���� ����
	for (j, k; j + k < 25;) {	//j even ����, k odd ����
		printf("%d ��° : ", num++);	
		scanf("%d", &in);

		if (!(in % 2))	//even �϶�, 
		{
			a[j / 5][j % 5] = in;		//j�� ���� �ʱ�ȭ �����ʰ� ��� �������� ������ ���� ����.
			j++;
		}
		else {					//odd �϶�,
			a[4 - k / 5][4 - k % 5] = in;
			k++;
		}
	}
	printf("==========result==========\n");		//������� �ݺ���
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}