#include<stdio.h>
#include<stdlib.h>//random, malloc
#include<time.h>//random
void print(int *ip, int array_size);
void change_star(int *ip, int array_size);
int select_num(int *ip, int array_size);

int main()
{
	srand((unsigned int)time(NULL));
	int array_size;
	printf("n*n���� ����ã���Դϴ�.\nn���� �Է����ּ��� : ");
	scanf("%d", &array_size);

	int *ip;		// ���ڹ迭 �����Ҵ�
	ip = (int *)malloc(array_size*array_size * sizeof(int));

	for (int i = 0; i < array_size*array_size; i++)		//���� ���� �������� �־���.
	{
		ip[i] = rand() % 2;
	}
	printf("\n\n");
	print(ip, array_size);
	printf("=== ��ȯ �� ===\n\n\n");
	change_star(ip, array_size);	// 0�� 1�� �̷���� �迭�� 1�� *�� �ٲٴ� �۾��� ��ħ.
	select_num(ip, array_size);		//�ֺ��� ���ڰ����� ����� count
	print(ip, array_size);
	free(ip);
}
void print(int *ip, int array_size)	//������� �Լ�.
{
	int a = 1;
	for (int i = 0; i < array_size*array_size; i++)
	{
		
		if (ip[i] < 10)	//���� �ƴ϶��, ASCII code �̿�
		{
			printf("%d ", ip[i]);
		}
		else {
			printf("%c ", ip[i]);
		}
		if (i == a * array_size - 1) {
			a++;
			printf("\n");
		}
	}
	printf("\n\n");
}

void change_star(int *ip, int array_size)	//1�̸� ���ιٲٴ� �Լ�
{
	for (int i = 0; i < array_size*array_size; i++)
	{
		if (ip[i])
		{
			ip[i] = '*';
		}
	}
}
int select_num(int *ip, int n)	//���ڰ� �ƴѰ�� �ֺ� cnt++ ���ִ� �Լ�.
{

	int **ip2;
	int cnt = 0;

	ip2 = (int *)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		ip2[i] = malloc(sizeof(int) * n);
	}

	for (int k = 0, i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ip2[i][j] = ip[k];
			k++;
		}
	}
	for (int k = 0, i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!(ip2[i][j]))	//���� �ƴ϶��,
			{
				cnt = 0;
				int flag[4] = { 1,1,1,1 }; //[0]x_left, [1]x_right, [2]y_up, [3]y_down
				//flag�� �ξ�, �𼭸����� ���������� ���� �˻�
				if (i - 1 < 0)
				{
					flag[2] = 0;
				}

				if (i + 1 >= n)
				{
					flag[0] = 0;
				}

				if (j - 1 < 0)
				{
					flag[3] = 0;
				}

				if (j + 1 >= n)
				{
					flag[1] = 0;
				}

				// �ֺ� 8�� ��θ� �˻��ϰ�, cnt++�� �Ѵ�
				if (flag[2] && (ip2[i - 1][j] == '*'))
					cnt++;

				if (flag[0] && (ip2[i + 1][j] == '*'))
					cnt++;

				if (flag[3] && (ip2[i][j - 1] == '*'))
					cnt++;

				if (flag[1] && (ip2[i][j + 1] == '*'))
					cnt++;

				if (flag[0] && flag[3] && (ip2[i + 1][j - 1] == '*'))
					cnt++;

				if (flag[2] && flag[1] && (ip2[i - 1][j + 1] == '*'))
					cnt++;

				if (flag[2] && flag[3] && (ip2[i - 1][j - 1] == '*'))
					cnt++;

				if (flag[0] && flag[1] && (ip2[i + 1][j + 1] == '*'))
					cnt++;

				//ip[k]�� �ٷ� ���� �־��ش�.
				ip[k] = cnt;
			}
			k++;
		}
	}
	free(ip2);	// �������迭�� ���� ���ϰ� ����ߴ� ip2�� �����Ѵ�.
}
