#include<stdio.h>
#include<stdlib.h>

int main()
{
	int ARRAY_SIZE;
	do
	{
		printf("�迭 ���� �Է� [1~10]: ");
		scanf("%d", &ARRAY_SIZE);
	} while (ARRAY_SIZE < 1 || ARRAY_SIZE>10);
	

	char *cp_num, *cp_char, *cp_sum;
	cp_num = (char *)calloc(ARRAY_SIZE * sizeof(char) + 1, sizeof(char));	
	cp_char = (char *)calloc(ARRAY_SIZE * sizeof(char) + 1, sizeof(char));
	cp_sum = (char *)calloc(2*ARRAY_SIZE * sizeof(char) + 4, sizeof(char));
	//malloc�� �ƴ϶� calloc���� �������� �ʱⰪ�� 0���� �־� ����� �� ���ϱ� �����̴�.
	if (!cp_num || !cp_char || !cp_sum) {	//memory������ �����Ͽ� NULL �� RETURN �� ��,
		printf("�޸� ����\n");
		return 1;
	}
	
	for (int i = 0; i < ARRAY_SIZE; i++) {	//�� ����
		//itoa(i, &cp_num[i], 10);	��ȯ ���, ���� ���� �迭, 10���� //�̰� ����� ������ ������ �߸��ߴ�.
		cp_num[i] = i + 48;
		cp_char[i] = i + 65;
	}
	int i = 0, k = 0, l = 0;
	while (i < ARRAY_SIZE*2) {	//i�� SIZE*2 ���� ���� �� 
		for (int j = 0; j <= k; j++) {	//for �� 2���� ���� ������ ����� ����.
			cp_sum[i] = cp_num[j + l];
			i++;
		}
		for (int j = 0; j <= k; j++) {
			cp_sum[i] = cp_char[j + l];
			i++;
		}
		k++;
		l = 2 * k - 1;
		if (i == 12)l++;		// l�� ���� ������ 2k-1�� �����ߴµ�, i�� 12�϶� 6���ʿ������� ������ �������� ���ǹ� �߰�.
	}
	printf("Array A : %s\n", cp_num);	//���
	printf("Array B : %s\n", cp_char);
	printf("Array C : %s\n", cp_sum);
	free(cp_num);	//�Ҵ���� �޸� ����
	free(cp_char);
	free(cp_sum);
}