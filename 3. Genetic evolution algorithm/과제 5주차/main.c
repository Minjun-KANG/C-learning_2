#include"user.h"	//헤더파일, 상수, 함수프로토타입을 넣어논 헤더파일 정의.

int main() {

	int arr[8][10];		// 10개의 정수 배열을 출력하는데 필요한 배열
	int score[8];		//배열의 각 칸마다 점수를 매기기 위한 변수

	make_array(arr);				//배열 생성함수	 call by reference
	print_array(arr, 1);			//배열 출력함수	 call by reference + value, 1이란 숫자는 첫번째 정리를 나타냄.
	score_array(arr, score, 1);		//배열에 점수매기는 함수	call by reference + value 1이란 숫자는 첫번째 정리를 나타냄.
	select_array(arr, score, 1);	//n개의 배열을 n/2개 배열로 특정한 확률을 통해 추려내는 함수	 call by reference + value
	print_array(arr, 2);
	score_array(arr, score, 2);
	select_array(arr, score, 2);
	print_array(arr, 3);
	cross_array(arr);				// n개의 배열이 select_array fuction에 의해 정리되어
									// n=2 개의 배열이 남았을 때 50%확률로 2개 중 택 1하여 새로운 배열을 만들고,
}									// 5% 확률로 새로운 값을 추가하여 score=7이 되도록하는 함수.