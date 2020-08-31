#include<stdio.h>

void insert_sort(int *arr, int flag);

int main()
{
	int flag;	//����, ���������� �����ϴ� ����
	int arr[10] = { 4,1,2,7,5,3,8,9,10,0 };	//���� �� �迭����
	for (int i = 0; i < 10; i++) {
		printf("%d ",arr[i]);
	}
	printf("\n1.�������� 0.��������\n");	
	scanf("%d", &flag);
	printf("���� ��\n");
	insert_sort(arr, flag);	// �����ϴ� �Լ�ȣ��
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
}

void insert_sort(int *arr, int flag)
{
	int i, j, remember;
	if (flag) {	//���������� ���
		for (i = 1; i < 10; i++)
		{
			remember = arr[(j = i)];
			while (--j >= 0 && remember < arr[j]) {
				arr[j + 1] = arr[j];
				arr[j] = remember;
			}
		}
	}
	else {	//���������ϰ��
		for (i = 1; i < 10; i++)
		{
			remember = arr[(j = i)];
			while (--j >= 0 && remember > arr[j]) {
				arr[j + 1] = arr[j];
				arr[j] = remember;
			}
		}
	}

}