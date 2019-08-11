#include<graphics.h>
#include<conio.h>

#include"paint.h"


int main() {

	initgraph(480 , 480);
	initCheckerboard(30, 30, 30, 15, 15);//棋盘生成函数-参数-（初始x，初始y，步进，总量x，总量y）

	while (1 == 1)
	{
		mousecheck();
	};

	//deleteCheck(60, 30, 12);
	_getch();				// 按任意键继续
	closegraph();			// 关闭绘图窗口

}