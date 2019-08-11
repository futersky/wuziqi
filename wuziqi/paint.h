#pragma once

#include<graphics.h>

void initCheckerboard(int stx, int sty, int stepd, int sumx, int sumy);//�������ɺ���
void initCheckerboard(int stx, int sty, int stepd, int sumx, int sumy, int R, int G, int B);//�������ɺ�������ɫ���ã�

void initCheckerboard(int stx, int sty, int stepd, int sumx, int sumy) {

	COLORREF color = getlinecolor();//�洢ԭ��ɫ
	setlinecolor(COLORREF RGB(100, 100, 100));//���û�����ɫ

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
	setlinecolor(color);//�ָ�������ɫ
}

void initCheckerboard(int stx, int sty, int stepd, int sumx, int sumy, int R, int G, int B) {

	COLORREF color = getlinecolor();//�洢ԭ��ɫ
	setlinecolor(COLORREF RGB(R, G, B));//���û�����ɫ
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
	setlinecolor(color);//�ָ�������ɫ
}