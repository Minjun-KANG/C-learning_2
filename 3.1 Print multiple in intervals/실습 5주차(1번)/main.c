#include<stdio.h>

void sort(int, int, int);
int main()		/* �Է� �� call by value�� �Լ��� ȣ��*/
{
	int a, b, n;
	printf("A : ");		//���� A ����
	scanf("%d", &a);
	printf("B : ");		//���� B ����
	scanf("%d", &b);
	printf("N : ");		//������ ���
	scanf("%d", &n);

	printf("%d ~ %d ������ %d�� ����� ������ ��\n", a, b, n);
	sort(a, b, n);
}
void sort(int a, int b, int n) //����ϰ� �����ϴ� �Լ�
{
	int sum=0;
	for (a; a <= b; a++) {
		if (a%n) {		//��� n�� ������.
			printf("%d\n", a);
			sum += a;
		}
	}
	printf("�� : %d\n", sum);
}