#include<stdio.h>

void devide(int *n);
int main()
{
	int n;
	int *p = &n;			// call by reference�� �����ϱ� ����.
	printf("N : ");
	scanf("%d", p);
	devide(p);		//call by reference
}
void devide(int *n)
{
	if (*n % 2) {
		printf("�� ���� %d�� �����ϴ�\n", *n / 2 + 1);		//������ ���� ���� ������.
	}
	else {
		printf("���� ���� %d�� �����ϴ�\n", *n / 2);
	}
}