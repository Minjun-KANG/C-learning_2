#include<stdio.h>

void devide(int *n);
int main()
{
	int n;
	int *p = &n;			// call by reference로 구성하기 위함.
	printf("N : ");
	scanf("%d", p);
	devide(p);		//call by reference
}
void devide(int *n)
{
	if (*n % 2) {
		printf("흰 돌이 %d개 많습니다\n", *n / 2 + 1);		//수식을 위와 같게 정의함.
	}
	else {
		printf("검은 돌이 %d개 많습니다\n", *n / 2);
	}
}