#include<stdio.h>

int main()
{
	char a[11] = { 'D','F','I','C','A','G','H','B','J','E' };	// 규칙없이 나열된 char형 배열 선언
	char swap;			// 정렬시 필요한 swap전용 변수
	printf("정렬 전 : ");	// 사용자 편의성 고려 정리 전 출력
	for (int i = 0; i < 10; i++) {
		printf("%c ", a[i]);
	}
	printf("\n");	// 사용자 편의성 고려
	for (int i = 0; i < 10; i++) {		
		for (int j = 0; j < 9 - i; j++) {	// 안에 j를 변수로 하는 포문을 전부 돌면 가장 큰 값이 배열 맨뒤로감.
			if (a[j] > a[j + 1]) {
				swap = a[j];
				a[j] = a[j + 1];
				a[j + 1] = swap;
			}
		}
	}
	printf("정렬 후 : ");			//사용자 편의성 고려 정리 후 출력전용
	for (int i = 0; i < 10; i++) {
		printf("%c ", a[i]);
	}
	printf("\n");
}