#include<graphics.h>
#include<conio.h>

void initCheckerboard(int stx, int sty, int stepd, int sumx, int sumy);

int main() {

	initgraph(480 , 480);
	initCheckerboard(30, 30, 30, 15, 15);//�������ɺ���-����-����ʼx����ʼy������������x������y��

	_getch();				// �����������
	closegraph();			// �رջ�ͼ����

}

void initCheckerboard(int stx, int sty, int stepd, int sumx, int sumy) {

	int x = stx;
	int y = sty;
	int step = 0;

	int result_endx;
	int result_endy;

	result_endx = stx + stepd * (sumx - 1);
	result_endy = sty + stepd * (sumy - 1);

	for (y = sty; step < sumy; y = y + stepd) {
		line(x, y, result_endx, y);
		step++;
	}

	step = 0;
	y = sty;

	for (x = stx; step < sumx; x = x + stepd) {
		line(x, y, x, result_endy);
		step++;
	}

}