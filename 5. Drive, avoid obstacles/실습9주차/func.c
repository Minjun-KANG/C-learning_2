#include"User.h"

void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


void draw_map() {		//�� ����Լ�
	for (int i = 1; i < 60; i += 2) {
		gotoxy(i, 1); printf("��");
		gotoxy(i, 9); printf("��");
	}

}
//speed�� 3�� max�ϱ�, ��ֹ� �ּ� ������ 4�� �Ǿ�� �Ѵ�. +=4 �������ϴ� for���� �����ϰ�,
//rand������ 1/2Ȯ���� ����ؼ�, ��ֹ��� �����Ұ��� �������� �Ǵ��ϰ� boom������ ���� ��ֹ� ���̸� ����.
//�̶� ��ֹ� ���̴� ������ 1�� �����Ѵ�.

void draw_ob(OB *boom) {		//��ֹ� ���
	for (int k=0, i = 1; i < 60; i +=10 ,k++) {
		if (boom->garo[k]) {
			boom->garo[k] = i;
			for (int j = 0; j < boom->sero[k]; j++) {
				gotoxy(i, j+2); printf("��");
			}
		}
	}

}

int print_CAR(OB *boom, WHERE *position)	//�ڵ��� ��ġ ����Լ�.
{

	system("cls");
	draw_map();
	draw_ob(boom);

	print_car2(position);
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < position->set.length*2; j += 2) {
			if (((position->garo + j >= boom->garo[i]) && (position->garo + j <= boom->garo[i])) && position->sero - 2 < boom->sero[i]) {//-2���ϱ�
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
		printf("��");
	}
	else if (position->set.length == 2) {
		
		printf("���");
	}
	else {
		printf("����");
	}
}

int player_set(USER *button)	//�÷��̾� ���ÿ� ���� �Լ�.
{
	printf("�÷��̾� ����\n");
	printf("�÷��̾� �Է� Dirve key : ");
	scanf("%c", &button->drive);
	CLEAR_BUF();
	printf("�÷��̾� �Է� Up key : ");
	scanf("%c", &button->up);
	CLEAR_BUF();
	printf("�÷��̾� �Է� Down key : ");
	scanf("%c", &button->down);
	
	system("cls");
}

void CLEAR_BUF()	//scanf �Լ� ����, ���� �����Լ�.
{
	char buffer=0;
	while (buffer = getchar() != '\n' && buffer != EOF);
}

void win()	//�¸� ��
{
	system("cls");
	printf("WIN!\n");
}
void die()	//�й� ��
{
	system("cls");
	printf("DIE!\n");
	
}

