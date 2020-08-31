#include<stdio.h>
#include<Windows.h>	// printf를 원하는 좌표에서 함
#include<conio.h> //키보드 입력 받는거
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


typedef struct user_set	//USER key setting 구조체
{
	char drive;
	char up;
	char down;

}USER;


typedef struct obstacle	//장애물 위치 구조체
{
	int sero[6];
	int garo[6];
}OB;

typedef struct car_set	// 자동차 정보 구조체	// 다이렉트로 사용하지 않고, WHERE data type에서 사용.
{
	int speed;
	int length;
}CAR;

typedef struct user_position	//자동차 위치 구조체, 자동차 정보구조체를 가지고 있음.
{
	int sero;
	int garo;
	CAR set;
	
}WHERE;
