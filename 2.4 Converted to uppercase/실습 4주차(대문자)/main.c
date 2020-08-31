#include<stdio.h>

int main()
{
	char a[100];	// 임의의 배열 설정
	int i=0;	// 배열 몇번째 칸인지 비교 변수 설정

	printf("문자입력 : ");
	scanf("%s", a);
	while (a[i] != NULL) {	// 배열이 NULL이 아닐 때 까지,
		if (96 < a[i] && a[i] < 123) {	// 소문자임을 확인한다
			a[i] -= 32;				// 대문자로 바꾼다.
			i++;			// 다음 칸으로 이동한다
		}
		else {			// 대문자인경우
			i++;		//다음 칸으로 이동한다.
		}
	}
	printf("%s\n", a);	// 결과값 확인 전용 출력문
}