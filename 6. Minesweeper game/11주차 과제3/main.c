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
	printf("n*n개의 지뢰찾기입니다.\nn개를 입력해주세요 : ");
	scanf("%d", &array_size);

	int *ip;		// 지뢰배열 동적할당
	ip = (int *)malloc(array_size*array_size * sizeof(int));

	for (int i = 0; i < array_size*array_size; i++)		//지뢰 값을 랜덤으로 넣어줌.
	{
		ip[i] = rand() % 2;
	}
	printf("\n\n");
	print(ip, array_size);
	printf("=== 변환 후 ===\n\n\n");
	change_star(ip, array_size);	// 0과 1로 이루어진 배열을 1은 *로 바꾸는 작업을 거침.
	select_num(ip, array_size);		//주변에 지뢰갯수가 몇개인지 count
	print(ip, array_size);
	free(ip);
}
void print(int *ip, int array_size)	//출력전용 함수.
{
	int a = 1;
	for (int i = 0; i < array_size*array_size; i++)
	{
		
		if (ip[i] < 10)	//별이 아니라면, ASCII code 이용
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

void change_star(int *ip, int array_size)	//1이면 별로바꾸는 함수
{
	for (int i = 0; i < array_size*array_size; i++)
	{
		if (ip[i])
		{
			ip[i] = '*';
		}
	}
}
int select_num(int *ip, int n)	//지뢰가 아닌경우 주변 cnt++ 해주는 함수.
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
			if (!(ip2[i][j]))	//별이 아니라면,
			{
				cnt = 0;
				int flag[4] = { 1,1,1,1 }; //[0]x_left, [1]x_right, [2]y_up, [3]y_down
				//flag를 두어, 모서리인지 맨윗줄인지 등을 검사
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

				// 주변 8개 모두를 검사하고, cnt++을 한다
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

				//ip[k]에 바로 값을 넣어준다.
				ip[k] = cnt;
			}
			k++;
		}
	}
	free(ip2);	// 이차원배열로 보기 편하게 사용했던 ip2는 해제한다.
}
