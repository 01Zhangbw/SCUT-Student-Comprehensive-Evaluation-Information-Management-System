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
void HideTheCursor() {//���ع��
	CONSOLE_CURSOR_INFO cciCursor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	if (GetConsoleCursorInfo(hStdOut, &cciCursor)) {
		cciCursor.bVisible = FALSE;
		SetConsoleCursorInfo(hStdOut, &cciCursor);
	}
}
//----------�ƶ����----------
void gotoxy(int x, int y) {//�ƶ����λ��
	COORD pos = { x,y };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// ��ȡ��׼����豸���
	SetConsoleCursorPosition(hOut, pos);//���������ֱ���ָ���ĸ����壬����λ��
}

void picture()
{
	system("cls");
	HideTheCursor();                            //���ع��

	//----------�Ƴ����ٱ༭ģʽ(����win10�û�)----------
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hStdin, &mode);
	mode &= ~ENABLE_QUICK_EDIT_MODE;
	SetConsoleMode(hStdin, mode);
	cout << "���������ڻ�ͼ������Ҽ�����ֹͣ����" << endl;
	static int i = 0;//��¼x
	static int j = 0;//��¼y
	//����static���ͣ������Ǿ�̬�洢��ֱ����������Ż�����

	//----------ѭ�����----------
	while (1) {                      			//ѭ�����
		if (KEY_DOWN(VK_LBUTTON)) {  			//����������
			POINT p;
			GetCursorPos(&p);
			ScreenToClient(h, &p);               //��ȡ����ڴ����ϵ�λ��
			GetCurrentConsoleFont(hOutput, FALSE, &consoleCurrentFont); //��ȡ������Ϣ
			int x = p.x /= consoleCurrentFont.dwFontSize.X;
			chang[i++] = x;
			int y = p.y /= consoleCurrentFont.dwFontSize.Y;
			kuan[j++] = y;

			gotoxy(x, y);                        //�ƶ���������λ��
			printf("@");      //�����λ�����
			++count_1;
		}
		Sleep(10);
		if (KEY_DOWN(VK_RBUTTON)) {
			getnowTime();
			cout << "��ֹ��ͼ" << endl;//����������
			system("pause");
			system("cls");
			int xx, yy;
			printnowTime();//��ӡ���Ƶ�ʱ��
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
	printnowTime();//��ӡ�������ƴ�ͼ��ʱ��
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
void getnowTime()//��ȡ��ǰʱ��
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
void printnowTime()//��ӡ��ǰʱ�䣬��ȷ����
{
	printf("%4d/%02d/%02d %02d:%02d:%02d ����%1d\n", year, month, day, hour, minute, second, dayofweek);
	cout << "      ���ƴ�ͼ" << endl;
}

//void printnowtcTime()//���ʱ��
//{
//	printf("%4d/%02d/%02d %02d:%02d:%02d ����%1d\n", yeartc, monthtc, daytc, hourtc, minutetc, secondtc, dayofweektc);
//	cout << "      ���ƴ�ͼ" << endl;
//}

int main()
{
	srand(time(NULL));
	system("title SCUTѧ���ۺϲ�����Ϣ����ϵͳ");//С���������
	system("mode con cols=120 lines=38");//����
	Student aa;
	Teacher bb;


	while (1) {
		int a = chooseOption(3, printMainMenu);
		switch (a) {
		case 1:
			mainTeacher(bb);//��ʦ��ҳ��

			continue;

		case 2:
			mainStudent(aa);//ѧ����ҳ��

			continue;

		case 0:
			exit(0);
		default:break;

		}

	}
	system("pause");

	return 0;

}