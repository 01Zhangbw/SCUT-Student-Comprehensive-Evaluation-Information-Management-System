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


	system("cls");//����
	char name[50] = { "examMenu.txt" };//��examMenu.txt��ȡ���ԵĲ˵�ҳ��
	inFile(name);
	switch (a) {
		//��ʾ���
	case 1:printCursor(80, 25); break;
	case 2:printCursor(80, 31); break;
	default:break;
	}

}
void moveCursor(int x, int y) {//��궨λ
	//(��,��)
	COORD coord = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void printCursor(int x, int y) {//��ʾ���
	moveCursor(x - 60, y);
	cout << "-->>";
	moveCursor(x, y);
	cout << "<<--";
	moveCursor(x + 4, y);

}

void inFile(char name[15]) {//����txt�ļ�������ʾ������̨
	system("cls");

	ifstream readfile(name);

	if (!readfile.is_open()) {//�޷����ļ����쳣����
		printf("cannot open %s\n", name);
		exit(0);
	}

	const int LINE_LENGTH = 200;
	char str[LINE_LENGTH];
	while (readfile.getline(str, LINE_LENGTH))//��LINE_LENGTH�ĳ��ȵ�txt��һ�����ݸ�ֵ��str
	{
		cout << str << endl;//���
	}
	readfile.close();

}

void printStudentMenu(int a)//��ȡѧ��ҳ��
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

void printTeacherMenu(int a)//��ȡ��ʦҳ��
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
void printMainMenu(int a)//��ȡ���˵�
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
void mainTeacher(Teacher user)//��ȡ��ʦ��ҳ��
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
void mainStudent(Student stu)//��ȡѧ����ҳ��
{

	while (1) {
		int a = chooseOption(3, printStudentMenu);
		switch (a) {
		case 1:
			user();//�û���¼
			continue;
		case 2:
			_register();//�û�ע��
			continue;
		default:
			break;
		}
		break;
	}
}