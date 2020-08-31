#include<stdio.h>

void insert_sort(int *arr, int flag);

int main()
{
	int flag;	//오름, 내림차순을 결정하는 변수
	int arr[10] = { 4,1,2,7,5,3,8,9,10,0 };	//정렬 될 배열선언
	for (int i = 0; i < 10; i++) {
		printf("%d ",arr[i]);
	}
	printf("\n1.오름차순 0.내림차순\n");	
	scanf("%d", &flag);
	printf("정렬 후\n");
	insert_sort(arr, flag);	// 정렬하는 함수호출
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
}

void insert_sort(int *arr, int flag)
{
	int i, j, remember;
	if (flag) {	//내림차순일 경우
		for (i = 1; i < 10; i++)
		{
			remember = arr[(j = i)];
			while (--j >= 0 && remember < arr[j]) {
				arr[j + 1] = arr[j];
				arr[j] = remember;
			}
		}
	}
	else {	//오름차순일경우
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