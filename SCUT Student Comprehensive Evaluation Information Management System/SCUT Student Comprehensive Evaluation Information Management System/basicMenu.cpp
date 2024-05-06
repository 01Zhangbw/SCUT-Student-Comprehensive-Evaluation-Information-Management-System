#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<fstream>
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


void printMenu2(int a) {


	system("cls");//清屏
	char name[50] = { "examMenu.txt" };//用examMenu.txt存取考试的菜单页面
	inFile(name);
	switch (a) {
		//显示光标
	case 1:printCursor(80, 25); break;
	case 2:printCursor(80, 31); break;
	default:break;
	}

}
void moveCursor(int x, int y) {//光标定位
	//(列,行)
	COORD coord = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void printCursor(int x, int y) {//显示光标
	moveCursor(x - 60, y);
	cout << "-->>";
	moveCursor(x, y);
	cout << "<<--";
	moveCursor(x + 4, y);

}

void inFile(char name[15]) {//讲将txt文件内容显示到控制台
	system("cls");

	ifstream readfile(name);

	if (!readfile.is_open()) {//无法打开文件的异常处理
		printf("cannot open %s\n", name);
		exit(0);
	}

	const int LINE_LENGTH = 200;
	char str[LINE_LENGTH];
	while (readfile.getline(str, LINE_LENGTH))//将LINE_LENGTH的长度的txt的一行内容赋值给str
	{
		cout << str << endl;//输出
	}
	readfile.close();

}

void printStudentMenu(int a)//读取学生页面
{
	system("cls");
	char name[50] = "StudentMenu.txt";
	inFile(name);
	switch (a)
	{
	case 1:
		printCursor(80, 11);
		break;
	case 2:
		printCursor(80, 18);
		break;
	default:
		break;


	}
}

void printTeacherMenu(int a)//读取教师页面
{
	system("cls");
	char name[50] = "teacherMenu.txt";
	inFile(name);
	switch (a)
	{
	case 1:
		printCursor(80, 10);
		break;
	case 2:
		printCursor(80, 14);
		break;
	default:
		break;


	}

}
void printMainMenu(int a)//读取主菜单
{
	system("cls");
	char name[50] = "MainMenu.txt";
	inFile(name);
	switch (a)
	{
	case 1:
		printCursor(80, 8);
		break;
	case 2:
		printCursor(80, 13);
		break;
	default:
		break;


	}
}
void mainTeacher(Teacher user)//读取教师主页面
{
	int a;

	while (1)
	{
		a = chooseOption(3, printTeacherMenu);
		switch (a)
		{
		case 1:
			user_teacher();
			continue;
		case 2:
			teacher_register();
			continue;
		default:
			break;

		}
		break;

	}
}
void mainStudent(Student stu)//读取学生主页面
{

	while (1) {
		int a = chooseOption(3, printStudentMenu);
		switch (a) {
		case 1:
			user();//用户登录
			continue;
		case 2:
			_register();//用户注册
			continue;
		default:
			break;
		}
		break;
	}
}