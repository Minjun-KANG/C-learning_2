#include "User.h"
/*
== ����ü datatype==
WHERE ����� ��ġ
USER  �÷��̾� Ű����
CAR	  �ڵ��� ����
OB	  ��ֹ�
*/

int main()
{
	int life = 1;	//���� �¸��� �й踦 �����ϴ� flag ����
	random();	// user.h���Ͽ� random() ����� ����.
	USER button = {0,0,0};
	WHERE position = { 7,3,{ 0,rand()%3+1} };	//CAR����ü�� ������ �ִ�. �ڵ��� ���̸� �������� ��
	OB boom = { 0,0 };
	for (int i = 0; i < 5; i++) {		// 0~5���� ��� ��ֹ��� ����Ұ��� ����
		boom.garo[i] = (rand() % 2 + 1) % 2;
	}
	boom.garo[0] = 0;
	for (int i = 1; i < 5; i++) {		// ��ֹ� ���α��� ����
		boom.sero[i] = rand() % 6 + 1;
	}
	

	player_set(&button); //Ű�� �Է�
	print_CAR(&boom, &position); // �ڵ��� ��ġ ���

	
	while (1)
	{
		if (kbhit()) {	//Ű���尡 ���ȴ��� �ȴ��ȴ��� �Ǵ��ϴ� �Լ�.
			char key = _getch();	//Ű���� �Է¹��� ���� key��� ����������.
			if (key == button.drive) {	//����
				if (position.garo > 58 - position.set.length*2) {	//�¸� ��,
					break;
				}
				(position.garo) += (position.set.speed = (int)(rand()%3+1)*2);	//�� �ӵ��� �������� �����ϱ����� ���
					life = print_CAR(&boom, &position);
					if (!life)	//�й� ��,
						break;
			}
			else if (key == button.up) {	//���� �� ��,
				if (position.sero > 2) {
					position.sero--;
					life = print_CAR(&boom, &position);
					if (!life)
						break;
				}
			}
			else if (key == button.down) {	//�Ʒ��� �� ��,
				if (position.sero < 8) {
					position.sero++;
					life = print_CAR(&boom, &position);
					if (!life)
						break;
				}
			}
		}
	}
	if (life) {	//�¸� �Ѵٸ� life�� 1�̶��,
		win();
	}
	else {
		die();
	}
}
