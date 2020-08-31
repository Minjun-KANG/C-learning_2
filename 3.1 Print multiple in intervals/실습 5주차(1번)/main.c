#include<stdio.h>

void sort(int, int, int);
int main()		/* 입력 및 call by value로 함수를 호출*/
{
	int a, b, n;
	printf("A : ");		//구간 A 부터
	scanf("%d", &a);
	printf("B : ");		//구간 B 까지
	scanf("%d", &b);
	printf("N : ");		//제외할 배수
	scanf("%d", &n);

	printf("%d ~ %d 까지의 %d의 배수를 제외한 수\n", a, b, n);
	sort(a, b, n);
}
void sort(int a, int b, int n) //출력하고 종료하는 함수
{
	int sum=0;
	for (a; a <= b; a++) {
		if (a%n) {		//배수 n을 제외한.
			printf("%d\n", a);
			sum += a;
		}
	}
	printf("합 : %d\n", sum);
}