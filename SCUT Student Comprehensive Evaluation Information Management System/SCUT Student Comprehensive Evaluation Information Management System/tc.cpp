#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<fstream>

#include<array>
#include<iomanip>
#include<Windows.h>
#include<stdio.h>

#include<algorithm>
#include<conio.h>
#include<string>
#include<cstring>
#define _CRT_SECURE_NO_WARNINGS
#include"head.h"
using namespace std;
//体测

void printtcMenu(int a)
{
	system("cls");
	char name[50] = { "tcMenu.txt" };//Studentlogin.txt存取的开始界面
	inFile(name);

	switch (a)
	{
	case 1:
		printCursor(80, 9);
		break;//显示光标
	case 2:
		printCursor(80, 13);
		break;
	case 3:
		printCursor(80, 17);
		break;
	case 4:
		printCursor(80, 21);
		break;


	default:
		break;
	}

}

//体测板块
void tc(Student user)
{
	int a;
	while (1)
	{
		a = chooseOption(5, printtcMenu);
		switch (a)
		{
		case 1:

			Lookup_tc(stu);//查询体测成绩

			continue;
		case 2:

			Advice(stu);//对应给出的建议
			continue;

		case 3:

			DailyInput();//社区内容的写入
			continue;

		case 4:
			system("cls");
			DailyOutput();//社区内容的呈现
			continue;

		default:
			break;

		}
		break;
	}
}


void Advice(Student stu[])//体测建议
{
	system("cls");
	int n = Read(stu);

	int ii = 0;
	while ((stu[ii].ID != tmpKey) && ii < n)//查找账号对应学生
	{
		ii++;

	}
	if (ii == n)
	{
		cout << "==========>>\t\t对不起，无法找到该学生\t\t<<============" << endl;

	}
	else//已经查到对应学生
	{
		if (stu[ii].pe >= 90 && stu[ii].pe <= 100)
		{
			cout << "\n\n\n\n";
			cout << "你的体测成绩非常不错，可见你在锻炼方面是下了大功夫的，继续保持！" << endl;
		}
		else if (stu[ii].pe >= 80 && stu[ii].pe < 90)
		{
			cout << "\n\n\n\n";
			cout << "你的体测分数还不错，高于80分，可见锻炼在你的生活中还是很常见的！没有上90分的原因，很大程度上在于"
				<< "你的引体向上不够达标，这也是较难提高的项目之一\n希望你可以在这方面有所突破！" << endl;
		}
		else if (stu[ii].pe >= 70 && stu[ii].pe < 80)
		{
			cout << "\n\n\n\n";
			cout << "你的体测高于70分，可以达到评优的范畴。但是不要因此而骄傲，在你的生活中锻炼还是不够的，\n希望你可以多补齐弱项"
				<< "，在今后的测试中进步" << endl;
		}
		else if (stu[ii].pe >= 60 && stu[ii].pe <= 70)
		{
			cout << "\n\n\n\n";
			cout << "你的体测分数只是六十分了，和你平常不经常锻炼有关系。仅仅及格的成绩，可见提高空间还很大。希望你可以每天多跑跑步让自己的"
				<< "体测成绩有所提高。养成好的锻炼习惯也是受益终生的！" << endl;
		}
		else if (stu[ii].pe < 60)
		{
			cout << "\n\n\n\n";
			cout << "你的体测分数低于六十分了，和你平常不经常锻炼有关系。但是别灰心，\n希望你可以每天跑跑步，跳跳绳。让自己的"
				<< "体测成绩有所提高。养成好的锻炼习惯也是受益终生的！" << endl;

		}

	}
	system("pause");
}



void Lookup_tc(Student stu[])//查询体测成绩
{
	system("cls");
	int n = Read(stu);
	string str;
	int ii = 0;

	cout << endl;
	cout << "==========================>>\t\t体测成绩查询\t\t<<=========================" << endl << endl;
	cout << "=========================>>\t\t查询\t\t<<==============================" << endl << endl;
	system("pause");
	Sleep(1500);
	while ((stu[ii].ID != tmpKey) && ii < n)
	{
		ii++;

	}
	if (ii == n)
	{
		cout << "==========>>\t\t对不起，无法找到该学生\t\t<<============" << endl;

	}
	else
	{
		cout << "学号\t" << stu[ii].ID << endl << endl;
		cout << "姓名\t" << stu[ii].name << endl << endl;
		cout << "体测成绩\t" << stu[ii].pe << endl << endl;

	}

	system("pause");
}

void DailyInput()//体测心得写入
{
	system("cls");//清屏
	string str;
	string contents;
	cout << "你的体测心得体会是 ： " << endl;
	cin >> contents;
	fstream outFile("Daily.txt", ios::app);
	if (!outFile)
	{
		cout << "the File cannot open " << endl;
		exit(1);
	}
	outFile << endl;
	outFile << "学号：" << tmpKey << "      " << "时间：";
	SYSTEMTIME sys;       // 定义一个 SYSTEMTIME 结构体 sys
	GetLocalTime(&sys);   // GetLocalTime是一个Windows API 函数，用来获取当地的当前系统日期和时间。
	//存取此时的时间
	outFile << sys.wYear << "/" << sys.wMonth << "/" << sys.wDay << "      " << setfill('0') << setw(2) << sys.wHour
		<< ":" << std::setfill('0') << std::setw(2) << sys.wMinute << ":" << std::setfill('0') << std::setw(2) << sys.wSecond << endl;
	outFile << endl;
	outFile << "心得体会：";
	outFile << contents;//心得的内容
	outFile << endl << endl;

}

void DailyOutput() {//输出Daily.txt的内容
	system("cls");

	char name[50] = { "Daily.txt" };
	ifstream ReadFile(name);


	const int LINE_LENGTH = 1000;
	char str[LINE_LENGTH];
	while (ReadFile.getline(str, LINE_LENGTH))
	{
		cout << str << endl;
	}
	ReadFile.close();
	system("pause");
}
