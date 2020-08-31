#include<stdio.h>
#include<Windows.h>	// printf를 원하는 좌표에서 함
#include<conio.h> //키보드 입력 받는거

void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void draw_map() {
	for (int i = 1; i < 30; i += 2) {
		gotoxy(i, 1); printf("■");
		gotoxy(i, 5); printf("□");
		gotoxy(i, 9); printf("■");
	}
	
}
int main()
{
	int a_move = 3;
	int d_move = 3;
	draw_map();
	gotoxy(3, 3);
	printf("★");
	gotoxy(3, 7);
	printf("☆");


	while (1)
	{
		if (kbhit()) {	//키보드가 눌렸는지 안눌렸는지 판단하는 함수.
			char key = _getch();	//키에서 입력받은 값을 key라는 변수에저장
			if (a_move < 30 && d_move < 30) {	//움직이는 조건 좌표하나가 스페이스바 한칸이라고 생각함.
				if (key == 'a') {
					a_move++;
					gotoxy(a_move, 3);
					printf("★");
				}
				else if (key == 'd') {
					d_move++;
					gotoxy(d_move, 7);
					printf("☆");
				}
				draw_map();		// 맵을 계속 갱신
			}
			else {
				system("cls");
				if (d_move > a_move) {
					printf("☆ 승리\n");
					break;
				}
				else {
					printf("★ 승리\n");
					break;
				}
			}
		}
	}
}
