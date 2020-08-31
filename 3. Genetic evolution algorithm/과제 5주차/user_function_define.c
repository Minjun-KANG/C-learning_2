#include"user.h"

void make_array(int(*arr)[10]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 10; j++) {
			*(*(arr + i) + j) = (int)(random() * 100);
		}
	}
}


void print_array(int(*arr)[10], int st)	//���
{
	printf("==================== �迭 ���� ====================\n\n");
	for (int i = 0; i < 8 / st; i++) {
		printf("    �迭[%d] ���� : ", i);
		for (int j = 0; j < 10; j++) {
			printf("%2d ", *(*(arr + i) + j));
		}
		printf("\n");
	}
	printf("\n===================================================\n\n\n");
}

void copy_array(int(*arr)[10], int j, int k)	// �����Լ��� select_array���� ����Ѵ�.
{
	int swap_arr[10];
	for (int i = 0; i < 10; i++) {
		swap_arr[i] = *(arr[j] + i);
		*(arr[k] + i) = swap_arr[i];
	}
}

void cross_array(int(*arr)[10])	//������ 2���� ������ �� �̿��ϴ� �Լ�
{
	int last_arr[10];
	int n;
	float new_value;
	int score[1];
	while (score[0] % 7) {
		for (int i = 0; i < 10; i++) {
			n = (int)(random() * 100) % 10;
			new_value = random();

			if (5 <= n)
				last_arr[i] = *(arr[0] + i);
			else {
				last_arr[i] = *(arr[1] + i);
			}
			if (new_value <= 0.05)
			{
				last_arr[i] = (int)(random() * 100) % 100 + 1;
			}
		}
		print_array(last_arr, 8);
		score_array(last_arr, score, 8);
	}
	printf("���α׷��� �����մϴ�.\n\n");
}

void score_array(int(*arr)[10], int *score, int st)		//���� �ű�� �Լ�
{
	for (int j = 0; j < 8 / st; j++) {
		score[j] = 0;
	}
	for (int j = 0; j < 8 / st; j++) {
		for (int i = 0; i < 9; i++) {
			if (*(arr[j] + i) < *(arr[j] + i + 1))
			{
				score[j]++;
			}
		}
	}

	printf("================== �迭 ȹ������ ==================\n\n");
	for (int i = 0; i < 8 / st; i++) {
		printf("\t\t�迭[%d] ���� : %d\n", i, score[i]);
	}
	printf("\n===================================================\n\n");

}

void select_array(int(*arr)[10], int *score, int st)		//Ư���� Ȯ���� n���� �迭���� n/2 ���� �迭�� ����� �Լ�
{
	int sum = 0;
	float n[4];
	float a[8] = { 0, };
	float big;
	int t[4];
	for (int i = 0; i < 8 / st; i++) {	//sum����� 
		sum += score[i];
	}

	for (int i = 0; i < 8 / st; i++) {		//�� �迭�����
		if (!i) {
			a[i] = (float)score[i] / sum;
			big = (float)score[i] / sum;
		}
		else {
			a[i] = (float)score[i] / sum + a[i - 1];
			if (big < (float)score[i] / sum) {
				big = (float)score[i] / sum;
			}
		}
	}

	for (int i = 0; i < 4 / st; i++) {
		n[i] = random();
	}
	for (int j = 0; j < 4 / st; j++) {
		for (int i = 0; i < 4 / st - 1 - j; i++) {
			if (n[i + 1] < n[i]) {
				float swap = n[i];
				n[i] = n[i + 1];
				n[i + 1] = swap;
			}
		}
	}
	for (int i = 0; i < 4 / st - 1; i++) {
		if (n[i + 1] - n[i] < big) {
			n[i + 1] = random();
			i = 0;
		}
	}
	for (int i = 0; i < 4 / st; i++) {
		for (int j = 0; j < 8 / st; j++) {
			if ((t[0] != j && t[1] != j && t[2] != j && t[3] != j)) {
				if (!i && a[j] > n[i]) {		//j=0 �϶�
					copy_array(arr, j, i);
					t[i] = j;
					break;
				}
				else if (j != 7 / st && a[j + 1] > n[i] && a[j] <= n[i]) {	//j�� 1~6�϶�
					copy_array(arr, j, i);
					t[i] = j;
					break;
				}
				else if (j == 7 / st && a[j - 1] < n[i]) {
					copy_array(arr, j, i);		//j=7 �϶�
					t[i] = j;
					break;
				}
			}
		}
	}
}
