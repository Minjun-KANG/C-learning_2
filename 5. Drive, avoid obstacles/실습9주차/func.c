#include"User.h"

void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


void draw_map() {		//맵 출력함수
	for (int i = 1; i < 60; i += 2) {
		gotoxy(i, 1); printf("■");
		gotoxy(i, 9); printf("■");
	}

}
//speed가 3이 max니깐, 장애물 최소 간격은 4가 되어야 한다. +=4 씩증가하는 for문을 구성하고,
//rand값으로 1/2확률을 계산해서, 장애물을 생성할건지 말건지를 판단하고 boom변수에 따른 장애물 길이를 생성.
//이때 장애물 넓이는 무조건 1로 가정한다.

void draw_ob(OB *boom) {		//장애물 출력
	for (int k=0, i = 1; i < 60; i +=10 ,k++) {
		if (boom->garo[k]) {
			boom->garo[k] = i;
			for (int j = 0; j < boom->sero[k]; j++) {
				gotoxy(i, j+2); printf("■");
			}
		}
	}

}

int print_CAR(OB *boom, WHERE *position)	//자동차 위치 출력함수.
{

	system("cls");
	draw_map();
	draw_ob(boom);

	print_car2(position);
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < position->set.length*2; j += 2) {
			if (((position->garo + j >= boom->garo[i]) && (position->garo + j <= boom->garo[i])) && position->sero - 2 < boom->sero[i]) {//-2만하기
				return 0;
				break;
			}
		}
	}
}
void print_car2(WHERE *position)
{
	//position.set.length == 1
	gotoxy(position->garo, position->sero);
	if (position->set.length == 1) {
		printf("□");
	}
	else if (position->set.length == 2) {
		
		printf("□□");
	}
	else {
		printf("□□□");
	}
}

int player_set(USER *button)	//플레이어 세팅에 관한 함수.
{
	printf("플레이어 세팅\n");
	printf("플레이어 입력 Dirve key : ");
	scanf("%c", &button->drive);
	CLEAR_BUF();
	printf("플레이어 입력 Up key : ");
	scanf("%c", &button->up);
	CLEAR_BUF();
	printf("플레이어 입력 Down key : ");
	scanf("%c", &button->down);
	
	system("cls");
}

void CLEAR_BUF()	//scanf 함수 사용시, 버퍼 정리함수.
{
	char buffer=0;
	while (buffer = getchar() != '\n' && buffer != EOF);
}

void win()	//승리 시
{
	system("cls");
	printf("WIN!\n");
}
void die()	//패배 시
{
	system("cls");
	printf("DIE!\n");
	
}

