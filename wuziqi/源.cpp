#include<graphics.h>
#include<conio.h>

void initCheckerboard(int stx, int sty, int stepd, int sumx, int sumy);//棋盘生成函数
void initCheckerboard(int stx, int sty, int stepd, int sumx, int sumy, int R, int G, int B);//棋盘生成函数（颜色设置）

int main() {

	initgraph(480 , 480);
	initCheckerboard(30, 30, 30, 15, 15);//棋盘生成函数-参数-（初始x，初始y，步进，总量x，总量y）

	_getch();				// 按任意键继续
	closegraph();			// 关闭绘图窗口

}

void initCheckerboard(int stx, int sty, int stepd, int sumx, int sumy) {

	COLORREF color = getlinecolor();//存储原颜色
	setlinecolor(COLORREF RGB(100, 100, 100));//设置画线颜色
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
	setlinecolor(color);//恢复画线颜色
}

void initCheckerboard(int stx, int sty, int stepd, int sumx, int sumy, int R, int G, int B) {

	COLORREF color = getlinecolor();//存储原颜色
	setlinecolor(COLORREF RGB(R, G, B));//设置画线颜色
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
	setlinecolor(color);//恢复画线颜色
}