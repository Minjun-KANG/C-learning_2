#include "User.h"
/*
== 구조체 datatype==
WHERE 사용자 위치
USER  플레이어 키설정
CAR	  자동차 상태
OB	  장애물
*/

int main()
{
	int life = 1;	//게임 승리와 패배를 가름하는 flag 변수
	random();	// user.h파일에 random() 상수값 정의.
	USER button = {0,0,0};
	WHERE position = { 7,3,{ 0,rand()%3+1} };	//CAR구조체를 가지고 있다. 자동차 길이를 랜덤으로 함
	OB boom = { 0,0 };
	for (int i = 0; i < 5; i++) {		// 0~5개의 몇개의 장애물을 출력할건지 결정
		boom.garo[i] = (rand() % 2 + 1) % 2;
	}
	boom.garo[0] = 0;
	for (int i = 1; i < 5; i++) {		// 장애물 세로길이 지정
		boom.sero[i] = rand() % 6 + 1;
	}
	

	player_set(&button); //키값 입력
	print_CAR(&boom, &position); // 자동차 위치 출력

	
	while (1)
	{
		if (kbhit()) {	//키보드가 눌렸는지 안눌렸는지 판단하는 함수.
			char key = _getch();	//키에서 입력받은 값을 key라는 변수에저장.
			if (key == button.drive) {	//전진
				if (position.garo > 58 - position.set.length*2) {	//승리 시,
					break;
				}
				(position.garo) += (position.set.speed = (int)(rand()%3+1)*2);	//차 속도를 랜덤으로 결정하기위해 사용
					life = print_CAR(&boom, &position);
					if (!life)	//패배 시,
						break;
			}
			else if (key == button.up) {	//위로 갈 시,
				if (position.sero > 2) {
					position.sero--;
					life = print_CAR(&boom, &position);
					if (!life)
						break;
				}
			}
			else if (key == button.down) {	//아래로 갈 시,
				if (position.sero < 8) {
					position.sero++;
					life = print_CAR(&boom, &position);
					if (!life)
						break;
				}
			}
		}
	}
	if (life) {	//승리 한다면 life가 1이라면,
		win();
	}
	else {
		die();
	}
}
