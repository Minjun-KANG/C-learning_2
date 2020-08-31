#include<stdio.h>
#include<stdlib.h>

int main()
{
	int ARRAY_SIZE;
	do
	{
		printf("배열 갯수 입력 [1~10]: ");
		scanf("%d", &ARRAY_SIZE);
	} while (ARRAY_SIZE < 1 || ARRAY_SIZE>10);
	

	char *cp_num, *cp_char, *cp_sum;
	cp_num = (char *)calloc(ARRAY_SIZE * sizeof(char) + 1, sizeof(char));	
	cp_char = (char *)calloc(ARRAY_SIZE * sizeof(char) + 1, sizeof(char));
	cp_sum = (char *)calloc(2*ARRAY_SIZE * sizeof(char) + 4, sizeof(char));
	//malloc이 아니라 calloc으로 한이유는 초기값을 0으로 주어 출력할 때 편하기 위함이다.
	if (!cp_num || !cp_char || !cp_sum) {	//memory공간이 부족하여 NULL 을 RETURN 할 때,
		printf("메모리 부족\n");
		return 1;
	}
	
	for (int i = 0; i < ARRAY_SIZE; i++) {	//값 대입
		//itoa(i, &cp_num[i], 10);	변환 대상, 값을 넣을 배열, 10진수 //이걸 사용한 이유는 접근을 잘못했다.
		cp_num[i] = i + 48;
		cp_char[i] = i + 65;
	}
	int i = 0, k = 0, l = 0;
	while (i < ARRAY_SIZE*2) {	//i가 SIZE*2 보다 작을 때 
		for (int j = 0; j <= k; j++) {	//for 문 2개는 전부 문장을 만들기 위함.
			cp_sum[i] = cp_num[j + l];
			i++;
		}
		for (int j = 0; j <= k; j++) {
			cp_sum[i] = cp_char[j + l];
			i++;
		}
		k++;
		l = 2 * k - 1;
		if (i == 12)l++;		// l에 대한 수식을 2k-1로 정의했는데, i가 12일때 6이필요하지만 수식을 생각못해 조건문 추가.
	}
	printf("Array A : %s\n", cp_num);	//출력
	printf("Array B : %s\n", cp_char);
	printf("Array C : %s\n", cp_sum);
	free(cp_num);	//할당받은 메모리 해제
	free(cp_char);
	free(cp_sum);
}