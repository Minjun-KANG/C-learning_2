#include "user.h"

int main()
{
	int nun;		// 주사위 눈금
	int n;			//주사위 변
	

	printf("주사위 눈 입력 (1~6) : ");		//주사위 입력
	scanf("%d", &nun);

	while (nun < 1 || nun > 6) {		// 주사위 눈금에 대한 입력제한
		printf("\n잘못 입력하셨습니다. \n다시 입력하세요.\n");
		printf("주사위 눈 입력 (1~6) : ");
		scanf("%d", &nun);
	}
	puts("\n");		//사용자 편의성고려

	do {				//주사위 변의 길이 대한 입력 및 입력제한
		printf("변의 길이 조건 (4<n<28), (5,7,9의배수)\n");		//사용자 편의성고려
		printf("변의 길이 입력(n>=5) : ");
		scanf("%d", &n);

		if (n > 4 && n < 28) {

			if (nun == 1 && !(n % 5)) // nun 눈금에 맞게 변의길이 n의 입력제한
			{
				func5(n);
				break;
			}
			if (nun > 1 && nun < 5 && !(n % 7))
			{
				func7(nun, n);
				break;
			}
			if (nun > 4 && !(n % 9))
			{
				func9(nun, n);
				break;
			}
		}
		printf("\n잘못 입력하셨습니다. \n다시 입력하세요.\n");
	} while (1);
}
