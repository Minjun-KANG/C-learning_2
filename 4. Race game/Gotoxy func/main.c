#include<stdio.h>
#include<Windows.h>	// printf�� ���ϴ� ��ǥ���� ��
#include<conio.h> //Ű���� �Է� �޴°�

void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void draw_map() {
	for (int i = 1; i < 30; i += 2) {
		gotoxy(i, 1); printf("��");
		gotoxy(i, 5); printf("��");
		gotoxy(i, 9); printf("��");
	}
	
}
int main()
{
	int a_move = 3;
	int d_move = 3;
	draw_map();
	gotoxy(3, 3);
	printf("��");
	gotoxy(3, 7);
	printf("��");


	while (1)
	{
		if (kbhit()) {	//Ű���尡 ���ȴ��� �ȴ��ȴ��� �Ǵ��ϴ� �Լ�.
			char key = _getch();	//Ű���� �Է¹��� ���� key��� ����������
			if (a_move < 30 && d_move < 30) {	//�����̴� ���� ��ǥ�ϳ��� �����̽��� ��ĭ�̶�� ������.
				if (key == 'a') {
					a_move++;
					gotoxy(a_move, 3);
					printf("��");
				}
				else if (key == 'd') {
					d_move++;
					gotoxy(d_move, 7);
					printf("��");
				}
				draw_map();		// ���� ��� ����
			}
			else {
				system("cls");
				if (d_move > a_move) {
					printf("�� �¸�\n");
					break;
				}
				else {
					printf("�� �¸�\n");
					break;
				}
			}
		}
	}
}
