#include"user.h"	//�������, ���, �Լ�������Ÿ���� �־�� ������� ����.

int main() {

	int arr[8][10];		// 10���� ���� �迭�� ����ϴµ� �ʿ��� �迭
	int score[8];		//�迭�� �� ĭ���� ������ �ű�� ���� ����

	make_array(arr);				//�迭 �����Լ�	 call by reference
	print_array(arr, 1);			//�迭 ����Լ�	 call by reference + value, 1�̶� ���ڴ� ù��° ������ ��Ÿ��.
	score_array(arr, score, 1);		//�迭�� �����ű�� �Լ�	call by reference + value 1�̶� ���ڴ� ù��° ������ ��Ÿ��.
	select_array(arr, score, 1);	//n���� �迭�� n/2�� �迭�� Ư���� Ȯ���� ���� �߷����� �Լ�	 call by reference + value
	print_array(arr, 2);
	score_array(arr, score, 2);
	select_array(arr, score, 2);
	print_array(arr, 3);
	cross_array(arr);				// n���� �迭�� select_array fuction�� ���� �����Ǿ�
									// n=2 ���� �迭�� ������ �� 50%Ȯ���� 2�� �� �� 1�Ͽ� ���ο� �迭�� �����,
}									// 5% Ȯ���� ���ο� ���� �߰��Ͽ� score=7�� �ǵ����ϴ� �Լ�.