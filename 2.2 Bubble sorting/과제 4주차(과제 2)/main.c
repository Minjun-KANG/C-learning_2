#include<stdio.h>

int main()
{
	char a[11] = { 'D','F','I','C','A','G','H','B','J','E' };	// ��Ģ���� ������ char�� �迭 ����
	char swap;			// ���Ľ� �ʿ��� swap���� ����
	printf("���� �� : ");	// ����� ���Ǽ� ��� ���� �� ���
	for (int i = 0; i < 10; i++) {
		printf("%c ", a[i]);
	}
	printf("\n");	// ����� ���Ǽ� ���
	for (int i = 0; i < 10; i++) {		
		for (int j = 0; j < 9 - i; j++) {	// �ȿ� j�� ������ �ϴ� ������ ���� ���� ���� ū ���� �迭 �ǵڷΰ�.
			if (a[j] > a[j + 1]) {
				swap = a[j];
				a[j] = a[j + 1];
				a[j + 1] = swap;
			}
		}
	}
	printf("���� �� : ");			//����� ���Ǽ� ��� ���� �� �������
	for (int i = 0; i < 10; i++) {
		printf("%c ", a[i]);
	}
	printf("\n");
}