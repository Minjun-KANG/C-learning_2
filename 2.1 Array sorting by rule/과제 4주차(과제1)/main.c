#include<stdio.h>

int main()
{
	char a[11] = { '0','1','2','3','4','5','6','7','8','9' }; //숫자배열선언
	char b[11] = { 'A','B','C','D','E','F','G','H','I','J' }; //문자배열선언
	char c[21] = { 0, };	// 1차정리 배열
	char d[21] = { 0, };	// 2차정리 배열
	int i = 0, k = 0, l = 0;	// 동작 시 필요한 변수
	while (i < 20) {	//i가 20보다 작을 때 
		for (int j = 0; j <= k; j++) {	//for 문 2개는 전부 0A12BC345DEF6789GHIJ 를 만들기 위함.(1차정리)
			c[i] = a[j + l];
			i++;
		}
		for (int j = 0; j <= k; j++) {
			c[i] = b[j + l];
			i++;
		}
		k++;
		l = 2 * k - 1;
		if (i == 12)l++;		// l에 대한 수식을 2k-1로 정의했는데, i가 12일때 6이필요하지만 수식을 생각못해 조건문 추가.
	}

	i = 0;
	int plus = 0;	//짝수칸전용 
	int minus = 19;	//홀수칸전용
	while (i < 20) //01B35E68GIJH97FD4C2A			위에서 정리된 수식을 조건에 맞게 집어 넣는 반복문
	{
		if (!(i % 2)) {			// 짝수번째 칸일 때, 
			d[plus] = c[i];
			plus++;
		}
		else {
			d[minus] = c[i];
			minus--;
		}
		i++;
	}
	printf("%s\n", d);		//사용자편의성 고려 출력문.
}