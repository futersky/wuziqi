#include<graphics.h>
#include<conio.h>

#include"paint.h"


int main() {

	initgraph(480 , 480);
	initCheckerboard(30, 30, 30, 15, 15);//�������ɺ���-����-����ʼx����ʼy������������x������y��

	while (1 == 1)
	{
		mousecheck();
	};

	//deleteCheck(60, 30, 12);
	_getch();				// �����������
	closegraph();			// �رջ�ͼ����

}