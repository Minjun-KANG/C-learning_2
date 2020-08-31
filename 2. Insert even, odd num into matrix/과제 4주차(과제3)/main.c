#include<stdio.h>

int main()
{
	int a[5][5] = {0,};	// input data를 처리하기 위한 배열
	int in;	// 사용자 Input 전용 변수
	int num=1;	//사용자 편의성 고려 n번째 표시전용 변수
	int j = 0, k = 0;	// input값 5*5 배열 中 위치선정 변수
	for (j, k; j + k < 25;) {	//j even 전용, k odd 전용
		printf("%d 번째 : ", num++);	
		scanf("%d", &in);

		if (!(in % 2))	//even 일때, 
		{
			a[j / 5][j % 5] = in;		//j의 값을 초기화 하지않고 몫과 나머지를 나누어 값을 대입.
			j++;
		}
		else {					//odd 일때,
			a[4 - k / 5][4 - k % 5] = in;
			k++;
		}
	}
	printf("==========result==========\n");		//출력전용 반복문
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}