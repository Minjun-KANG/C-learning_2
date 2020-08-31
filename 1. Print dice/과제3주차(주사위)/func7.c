#include"user.h"

int func7(int nun, int n) //눈금이 5,6 입력 됬을 때 (변 9의배수)
{

	int const K = n / 7;	//자주사용하는 구문인 n/7 을 상수화시킴.
	for (int i = 0; i < n; i++) {			//n줄을 찍기위한 n번 도는 포문
		if (!(i % (n - 1))) {				//첫번째 혹은 마지막 줄일 때 정사각형중 가로줄을 출력하기 위한포문
			for (int k = 0; k < n; k++) {
				printf("■");
			}
			printf("\n");
		}
		else {			//변두리 가로줄 출력이 아니라면,
			for (int j = 0; j < n; j++) {			// 변두리 세로줄과 그안 내용을 출력하기 위한 for문
				if (!(j % (n - 1))) {	 // 첫번째혹은 마지막 줄일 때 하나출력
					printf("■");
				}
				else {		// 첫번째 혹은 마지막 세로줄이 아니라면,
					if (nun == 2) {
						for (int t = 0; t < K; t++) {
							if ((i == 1 + K + t && j == 1 + K) || (i == n - (K + 1) - K + t && j == n - (K + 1) - K)) {
								for (int l = 0; l < K; l++, j++)
								{
									printf("■");
								}

							}
						}
					}
					else if (nun == 3) {
						for (int t = 0; t < K; t++) {
							if ((i == 1 + K + t && j == 1 + K) || (i == n - (K + 1) - K + t && j == n - (K + 1) - K) || (i==3*K + t&& j==3*K) ) {
								for (int l = 0; l < K; l++, j++)
								{
									printf("■");
								}

							}
						}
					}
					else{ 
						for (int t = 0; t < K; t++) {
							if ((i == 1 + K + t || i == n - (2 * K + 1) + t) && (j == 1 + K  || j == n - (2 * K + 1))) {

								for (int l = 0; l < K; l++, j++)
								{
									printf("■");
								}

							}
						}
					}
					printf("　");		//위조건이 전부 일치하지않으면 공백출력
				}
			}
			printf("\n");		// 가로기준 한줄 출력후 줄바꿈 
		}
	}
}
