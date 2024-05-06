#include<iostream>
#include<cstring>
#include<string>

#include<fstream>
#include<vector>
#include<array>
#include<iomanip>
#include<Windows.h>
#include<stdio.h>
#include<ctime>
#include<algorithm>
#include<conio.h>
#include<string>
#include<cstring>

#include"head.h"

using namespace std;
void HideTheCursor() {//隐藏光标
	CONSOLE_CURSOR_INFO cciCursor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	if (GetConsoleCursorInfo(hStdOut, &cciCursor)) {
		cciCursor.bVisible = FALSE;
		SetConsoleCursorInfo(hStdOut, &cciCursor);
	}
}
//----------移动光标----------
void gotoxy(int x, int y) {//移动光标位置
	COORD pos = { x,y };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// 获取标准输出设备句柄
	SetConsoleCursorPosition(hOut, pos);//两个参数分别是指定哪个窗体，具体位置
}

void picture()
{
	system("cls");
	HideTheCursor();                            //隐藏光标

	//----------移除快速编辑模式(对于win10用户)----------
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hStdin, &mode);
	mode &= ~ENABLE_QUICK_EDIT_MODE;
	SetConsoleMode(hStdin, mode);
	cout << "鼠标左键用于绘图，鼠标右键用于停止操作" << endl;
	static int i = 0;//记录x
	static int j = 0;//记录y
	//由于static类型，所以是静态存储，直到程序结束才会销毁

	//----------循环检测----------
	while (1) {                      			//循环检测
		if (KEY_DOWN(VK_LBUTTON)) {  			//鼠标左键按下
			POINT p;
			GetCursorPos(&p);
			ScreenToClient(h, &p);               //获取鼠标在窗口上的位置
			GetCurrentConsoleFont(hOutput, FALSE, &consoleCurrentFont); //获取字体信息
			int x = p.x /= consoleCurrentFont.dwFontSize.X;
			chang[i++] = x;
			int y = p.y /= consoleCurrentFont.dwFontSize.Y;
			kuan[j++] = y;

			gotoxy(x, y);                        //移动光标置鼠标位置
			printf("@");      //在鼠标位置输出
			++count_1;
		}
		Sleep(10);
		if (KEY_DOWN(VK_RBUTTON)) {
			getnowTime();
			cout << "终止绘图" << endl;//鼠标左键按下
			system("pause");
			system("cls");
			int xx, yy;
			printnowTime();//打印绘制的时间
			for (int ii = 0; ii < count_1; ii++)
			{
				xx = chang[ii];
				yy = kuan[ii];
				gotoxy(xx, yy);
				printf("@");
				Sleep(100);

			}
			Sleep(3000);
			system("pause");
			return;


		}


	}
}

void checkpicture()
{
	system("cls");
	int xx, yy;
	printnowTime();//打印当初绘制此图的时间
	for (int ii = 0; ii < count_1; ii++)
	{
		xx = chang[ii];
		yy = kuan[ii];
		gotoxy(xx, yy);
		printf("@");
		Sleep(100);

	}
	Sleep(3000);
	system("pause");
}
void getnowTime()//获取当前时间
{
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	year = sys.wYear;
	month = sys.wMonth;
	day = sys.wDay;
	hour = sys.wHour;
	minute = sys.wMinute;
	second = sys.wSecond;
	dayofweek = sys.wDayOfWeek;


}
void printnowTime()//打印当前时间，精确到秒
{
	printf("%4d/%02d/%02d %02d:%02d:%02d 星期%1d\n", year, month, day, hour, minute, second, dayofweek);
	cout << "      绘制此图" << endl;
}

//void printnowtcTime()//体测时间
//{
//	printf("%4d/%02d/%02d %02d:%02d:%02d 星期%1d\n", yeartc, monthtc, daytc, hourtc, minutetc, secondtc, dayofweektc);
//	cout << "      绘制此图" << endl;
//}

int main()
{
	srand(time(NULL));
	system("title SCUT学生综合测评信息管理系统");//小程序的主题
	system("mode con cols=120 lines=38");//长宽
	Student aa;
	Teacher bb;


	while (1) {
		int a = chooseOption(3, printMainMenu);
		switch (a) {
		case 1:
			mainTeacher(bb);//教师主页面

			continue;

		case 2:
			mainStudent(aa);//学生主页面

			continue;

		case 0:
			exit(0);
		default:break;

		}

	}
	system("pause");

	return 0;

}