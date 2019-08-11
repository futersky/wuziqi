#pragma once

#include<graphics.h>

void initCheckerboard(int stx, int sty, int stepd, int sumx, int sumy);//�������ɺ���
void initCheckerboard(int stx, int sty, int stepd, int sumx, int sumy, int R, int G, int B);//�������ɺ�������ɫ���ã�

void paintCheck(int x, int y, char color);//��������
void paintCheck(int x, int y, char color, int r);//�������� �趨�뾶
void deleteCheck(int x, int y, int r);//ɾ������

int judgeWin();//�ж�ʤ��

int qipan[15][15] = { 0 };
int a[3] = { 0,0,-1 };//1��ʾx���꣬2��ʾy���꣬3��ʾ��ɫ1��-1��
int k = 1;
int aa = 1, b;
int newx, newy, newcheck_color;
int judge = 0;

void initCheckerboard(int stx, int sty, int stepd, int sumx, int sumy) {

	setbkcolor(COLORREF RGB(138, 109, 53));//������ɫ
	cleardevice();
	COLORREF color = getlinecolor();//�洢ԭ��ɫ
	setlinecolor(BLACK);//���û�����ɫ

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
	moveto(stx, sty);//����Ĭ�������Ϊstx,sty
}

void initCheckerboard(int stx, int sty, int stepd, int sumx, int sumy, int R, int G, int B) {

	setbkcolor(COLORREF RGB(138, 109, 53));//������ɫ
	cleardevice();
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
	moveto(stx, sty);//����Ĭ�������Ϊstx,sty
}

void paintCheck(int x, int y, char color) {

	COLORREF save_color = getfillcolor();//�洢ԭ��ɫ
	if (color == 1) {
		setfillcolor(BLACK);
	}
	else {
		setfillcolor(WHITE);
	}
	solidcircle(x, y, 12);//����
	setfillcolor(save_color);//��ԭ��ɫ

}

void paintCheck(int x, int y, char color,int r) {

	COLORREF save_color = getfillcolor();//�洢ԭ��ɫ
	if (color == 1) {
		setfillcolor(BLACK);
	}
	else {
		setfillcolor(WHITE);
	}
	
	solidcircle(x, y, r);//����
	setfillcolor(save_color);//��ԭ��ɫ

}

void mousecheck()
{
	MOUSEMSG m;
	m = GetMouseMsg();

	if (m.mkLButton == true and k == 1)
	{


		if ((((int)m.x - 15) / 30 + 1) <= 15 and (((int)m.x - 15) / 30 + 1) >= 0)
		{
			a[0] = (((int)m.x - 15) / 30 + 1);
			aa = m.x;
		}
		else { goto h1; };
		if ((((int)m.y - 15) / 30 + 1) <= 15 and (((int)m.y - 15) / 30 + 1) >= 0)

		{
			a[1] = (((int)m.y - 15) / 30 + 1);
			b = m.y;
		}
		else { goto h1; };
		if (qipan[a[0]][a[1]] == 0) { ; }
		else { goto h1; };

		qipan[a[0]][a[1]] = a[2];
		a[2] = a[2] * (-1);//����ɫ

		k = -1;

		newx = a[0];//���������λ��
		newy = a[1];
		newcheck_color = a[2];

		paintCheck(a[0] * 30, a[1] * 30, a[2]);

		judge = judgeWin();
		if (judge == -1) {
			char s[] = "White Win";
			outtextxy(0, 0, s);
		}
		else if (judge == 1) {
			char s[] = "Black Win";
			outtextxy(0, 0, s);
		}

		while (k == -1)
		{
			MOUSEMSG mm;
			mm = GetMouseMsg();
			if (mm.uMsg == WM_LBUTTONUP)
			{
				k = 1;
			};
		};

		FlushMouseMsgBuffer();

	h1:;
	};

}
//new code

void deleteCheck(int x, int y, int r) {

	COLORREF save_line_color = getlinecolor();//��ȡ������ɫ
	clearcircle(x, y, r);
	int result_x1, result_y1, result_x2, result_y2;
	setlinecolor(BLACK);//����

	result_x1 = x - r;
	result_y1 = y - r;
	result_x2 = x + r;
	result_y2 = y + r;
	
	int a[10][10] = { 0 };
	a[1][1] = 6;

	if (x == 30) result_x1 = x;
	if (y == 30) result_y1 = y;
	if (x == 450) result_x2 = x;
	if (y == 450) result_y2 = y;

	line(result_x1, y, result_x2, y);
	line(x, result_y1, x, result_y2);

	setlinecolor(save_line_color);//��ԭ��ɫ

}

int judgeWin() {
	int startx, endx, starty, endy;
	int number = 0;
	startx = newx - 4;
	starty = newy - 4;
	endx = newx + 4;
	endy = newy + 4;

	if (newx - 4 <= 0) {
		startx = 1;
	}
	if (newx + 4 >= 16) {
		endx = 15;
		
	}
	if (newy - 4 <= 0) {
		starty = 1;
	}
	if (newy + 4 >= 16) {
		endy = 15;
	}
	//����
	for (int i = startx; i <= endx; i++) {
		if (qipan[i][newy] == newcheck_color*-1) {
			number++;
		}
		else {
			number = 0;
		}
		if (number >= 5) {
			return newcheck_color;
		}
	}
	number = 0;
	//����
	for (int i = starty; i <= endy; i++) {
		if (qipan[newx][i] == newcheck_color*-1) {
			number++;
		}
		else {
			number = 0;
		}
		if (number >= 5) {
			return newcheck_color;
		}
	}
	number = 0;
	//[\]
	if ((newx - startx) < (newy - starty)) {
		starty = newy - newx + startx;
	}
	else if ((newx - startx) > (newy - starty)) {
		startx = newx - newy + starty;
	}

	if ((newx - endx) > (newy - endy)) {
		endy = newy - newx + endx;
	}
	else if ((newx - endx) < (newy - endy)) {
		endx = newx - newy + endy;
	}

	if ((endx - startx) <= (endy - starty)) {
		for (int i = startx; i <= endx; i++) {
			if (qipan[i][starty + i - startx] == newcheck_color * -1) {
				number++;
			}
			else {
				number = 0;
			}
			if (number >= 5) {
				return newcheck_color;
			}
		}
	}
	else {
		for (int i = starty; i <= endy; i++) {
			if (qipan[startx + i - 1][i] == newcheck_color * -1) {
				number++;
			}
			else {
				number = 0;
			}
			if (number >= 5) {
				return newcheck_color;
			}
		}
	}

	number = 0;

	startx = newx - 4;
	starty = newy - 4;
	endx = newx + 4;
	endy = newy + 4;

	if (newx - 4 <= 0) {
		startx = 1;
	}
	if (newx + 4 >= 16) {
		endx = 15;

	}
	if (newy - 4 <= 0) {
		starty = 1;
	}
	if (newy + 4 >= 16) {
		endy = 15;
	}

	//[/]
	if ((newx - startx) < (endy - newy)) {
		endy = newy + newx - startx;
	}
	else if ((newx - startx) > (endy - newy)) {
		startx = newx + newy - endy;
	}

	if ((newx - endx) > (starty - newy)) {
		starty = newy + newx - endx;
	}
	else if ((newx - endx) < (starty - newy)) {
		endx = newx + newy - starty;
	}

	if ((endx - startx) <= (endy - starty)) {
		for (int i = startx; i <= endx; i++) {
			if (qipan[i][endy - i + startx] == newcheck_color * -1) {
				number++;
			}
			else {
				number = 0;
			}
			if (number >= 5) {
				return newcheck_color;
			}
		}
	}
	else {
		for (int i = starty; i <= endy; i++) {
			if (qipan[startx + i - 1][i] == newcheck_color * -1) {
				number++;
			}
			else {
				number = 0;
			}
			if (number >= 5) {
				return newcheck_color;
			}
		}
	}
	number = 0;
	return 0;
}