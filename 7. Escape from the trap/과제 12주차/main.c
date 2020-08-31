#include<stdio.h>
#include<stdlib.h>

typedef struct _man {
	unsigned int height;
	unsigned int hp;
	unsigned int escape_time;
}MAN;
typedef struct _box {
	unsigned int time;
	unsigned int height;
	unsigned int hp;

}BOX;
typedef struct _trap {
	unsigned int trap_height;
	unsigned int box_num;
	
}TRAP;

void print_man(MAN);	//출력전용
void input_box(int, BOX *);	//입력전용
void sort_box(int, BOX *);	//Random하게 들어온 Box 정보 정렬

int main()
{
	
	char flag;
	MAN man = { 0,10, 0}; //height, hp
	TRAP trap;
	BOX *box_p;
	
	printf("**** trap ****\n");
	printf("trap depth : ");
	scanf("%d", &trap.trap_height);
	printf("box num : ");
	scanf("%d", &trap.box_num);
	printf("***************\n\n");

	box_p = (BOX*)malloc(trap.box_num * sizeof(BOX));

	input_box(trap.box_num, box_p);
	sort_box(trap.box_num, box_p);

	
	while (flag = getchar() != '\n' && flag != EOF);
	int hptime = 0;
	while (1) {
		
		print_man(man);
		
		if (10 - man.hp == box_p[hptime].time) {
			
			printf("Do You eat food? [PRESS Y/N] : ");
			scanf("%c", &flag);
			if (flag == 'Y' || flag == 'y')
			{
				man.hp += box_p[hptime].hp;
			}
			else {
				man.height += box_p[hptime].height;
			}
			while (flag = getchar() != '\n' && flag != EOF);
			hptime++;
		}
		man.hp--;
		man.escape_time++;
	
		
		if (man.height >= trap.trap_height) {	// man이 함정을 뛰어넘는순간.
			system("cls");
			man.hp++;
			print_man(man);
			printf("YOU WIN!\n");
			return 1;
			system("exit");
			free(box_p);
		}
		if (!man.hp) {			//gp가 0되는순간.
			system("cls");
			print_man(man);
			printf("YOU DIE!\n");
			return 1;
			system("exit");
			free(box_p);
		}
	}
}
void sort_box(int box_range, BOX * box_p)
{
	BOX temp;
	for (int i = 0; i < box_range; i++) {	//BOX값이 랜덤으로 입력되는데, time순으로 순차적으로 변경해놓은것.
		for (int j = 0; j < box_range - i; j++) {
			if (box_p[j].time > box_p[j + 1].time) {
				temp = box_p[j];
				box_p[j] = box_p[j + 1];
				box_p[j + 1] = temp;
			}
		}
	}
}

void input_box(int box_range, BOX* box_p) {	//input 전용함수
	for (int i = 0; i < box_range; i++) {
		printf("**** Box %d ****\n", i + 1);
		printf("time : ");
		scanf("%d", &box_p[i].time);
		printf("height : ");
		scanf("%d", &box_p[i].height);
		printf("hp : ");
		scanf("%d", &box_p[i].hp);
		printf("***************\n\n\n");
	}
}


void print_man(MAN man) {		//단순 출력전용함수
	printf("***************\n");
	printf("escape time : %d\n",man.escape_time);
	printf("HP : %d\n", man.hp);
	printf("Height : %d\n", man.height);
	printf("***************\n");
}