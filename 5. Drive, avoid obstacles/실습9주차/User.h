#include<stdio.h>
#include<Windows.h>	// printf�� ���ϴ� ��ǥ���� ��
#include<conio.h> //Ű���� �Է� �޴°�
#include<stdlib.h>//random
#include<time.h>

#define random() srand((unsigned int)time(NULL))

void print_car2(position);
int print_CAR(boom, position);
int player_set(button);
void gotoxy(int x, int y);
void draw_map();
void draw_ob(boom);
void CLEAR_BUF();
void win();
void die();


typedef struct user_set	//USER key setting ����ü
{
	char drive;
	char up;
	char down;

}USER;


typedef struct obstacle	//��ֹ� ��ġ ����ü
{
	int sero[6];
	int garo[6];
}OB;

typedef struct car_set	// �ڵ��� ���� ����ü	// ���̷�Ʈ�� ������� �ʰ�, WHERE data type���� ���.
{
	int speed;
	int length;
}CAR;

typedef struct user_position	//�ڵ��� ��ġ ����ü, �ڵ��� ��������ü�� ������ ����.
{
	int sero;
	int garo;
	CAR set;
	
}WHERE;
