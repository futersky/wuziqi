#include<graphics.h>
#include<conio.h>

#include"paint.h"


int main() {

	initgraph(480 , 480);
	initCheckerboard(30, 30, 30, 15, 15);//�������ɺ���-����-����ʼx����ʼy������������x������y��

	_getch();				// �����������
	closegraph();			// �رջ�ͼ����

}