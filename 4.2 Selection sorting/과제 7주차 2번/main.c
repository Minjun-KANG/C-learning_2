#include<stdio.h>

void selection_sort(int *arr, int flag);

int main()
{
	int flag;
	int arr[10] = { 4,1,2,7,5,3,8,9,10,0 };
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n1.오름차순 0.내림차순\n");
	scanf("%d", &flag);
	printf("정렬 후\n");
	selection_sort(arr, flag);
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
}

void selection_sort(int *arr, int flag)
{
	int indexMin, temp;
	int operations = 0;
	if (flag) {
		for (int i = 0; i < 9; i++)
		{
			indexMin = i;
			for (int j = i + 1; j < 10; j++)
			{
				if (arr[j] < arr[indexMin])
				{
					indexMin = j;
				}
				operations++;
			}
			temp = arr[indexMin];
			arr[indexMin] = arr[i];
			arr[i] = temp;
		}
	}
	else {
		for (int i = 0; i < 9; i++)
		{
			indexMin = i;
			for (int j = i + 1; j < 10; j++)
			{
				if (arr[j] > arr[indexMin])
				{
					indexMin = j;
					
				}
				operations++;
			}
			temp = arr[indexMin];
			arr[indexMin] = arr[i];
			arr[i] = temp;
		}

	}
	printf("연산 횟수 : %d\n", operations);	//연산횟수 출력
}