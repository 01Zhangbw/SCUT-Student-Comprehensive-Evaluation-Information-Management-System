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
//���

void printtcMenu(int a)
{
	system("cls");
	char name[50] = { "tcMenu.txt" };//Studentlogin.txt��ȡ�Ŀ�ʼ����
	inFile(name);

	switch (a)
	{
	case 1:
		printCursor(80, 9);
		break;//��ʾ���
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

//�����
void tc(Student user)
{
	int a;
	while (1)
	{
		a = chooseOption(5, printtcMenu);
		switch (a)
		{
		case 1:

			Lookup_tc(stu);//��ѯ���ɼ�

			continue;
		case 2:

			Advice(stu);//��Ӧ�����Ľ���
			continue;

		case 3:

			DailyInput();//�������ݵ�д��
			continue;

		case 4:
			system("cls");
			DailyOutput();//�������ݵĳ���
			continue;

		default:
			break;

		}
		break;
	}
}


void Advice(Student stu[])//��⽨��
{
	system("cls");
	int n = Read(stu);

	int ii = 0;
	while ((stu[ii].ID != tmpKey) && ii < n)//�����˺Ŷ�Ӧѧ��
	{
		ii++;

	}
	if (ii == n)
	{
		cout << "==========>>\t\t�Բ����޷��ҵ���ѧ��\t\t<<============" << endl;

	}
	else//�Ѿ��鵽��Ӧѧ��
	{
		if (stu[ii].pe >= 90 && stu[ii].pe <= 100)
		{
			cout << "\n\n\n\n";
			cout << "������ɼ��ǳ������ɼ����ڶ������������˴󹦷�ģ��������֣�" << endl;
		}
		else if (stu[ii].pe >= 80 && stu[ii].pe < 90)
		{
			cout << "\n\n\n\n";
			cout << "�������������������80�֣��ɼ���������������л��Ǻܳ����ģ�û����90�ֵ�ԭ�򣬺ܴ�̶�������"
				<< "����������ϲ�����꣬��Ҳ�ǽ�����ߵ���Ŀ֮һ\nϣ����������ⷽ������ͻ�ƣ�" << endl;
		}
		else if (stu[ii].pe >= 70 && stu[ii].pe < 80)
		{
			cout << "\n\n\n\n";
			cout << "���������70�֣����Դﵽ���ŵķ��롣���ǲ�Ҫ��˶�����������������ж������ǲ����ģ�\nϣ������Զಹ������"
				<< "���ڽ��Ĳ����н���" << endl;
		}
		else if (stu[ii].pe >= 60 && stu[ii].pe <= 70)
		{
			cout << "\n\n\n\n";
			cout << "���������ֻ����ʮ���ˣ�����ƽ�������������й�ϵ����������ĳɼ����ɼ���߿ռ仹�ܴ�ϣ�������ÿ������ܲ����Լ���"
				<< "���ɼ�������ߡ����ɺõĶ���ϰ��Ҳ�����������ģ�" << endl;
		}
		else if (stu[ii].pe < 60)
		{
			cout << "\n\n\n\n";
			cout << "���������������ʮ���ˣ�����ƽ�������������й�ϵ�����Ǳ���ģ�\nϣ�������ÿ�����ܲ��������������Լ���"
				<< "���ɼ�������ߡ����ɺõĶ���ϰ��Ҳ�����������ģ�" << endl;

		}

	}
	system("pause");
}



void Lookup_tc(Student stu[])//��ѯ���ɼ�
{
	system("cls");
	int n = Read(stu);
	string str;
	int ii = 0;

	cout << endl;
	cout << "==========================>>\t\t���ɼ���ѯ\t\t<<=========================" << endl << endl;
	cout << "=========================>>\t\t��ѯ\t\t<<==============================" << endl << endl;
	system("pause");
	Sleep(1500);
	while ((stu[ii].ID != tmpKey) && ii < n)
	{
		ii++;

	}
	if (ii == n)
	{
		cout << "==========>>\t\t�Բ����޷��ҵ���ѧ��\t\t<<============" << endl;

	}
	else
	{
		cout << "ѧ��\t" << stu[ii].ID << endl << endl;
		cout << "����\t" << stu[ii].name << endl << endl;
		cout << "���ɼ�\t" << stu[ii].pe << endl << endl;

	}

	system("pause");
}

void DailyInput()//����ĵ�д��
{
	system("cls");//����
	string str;
	string contents;
	cout << "�������ĵ������ �� " << endl;
	cin >> contents;
	fstream outFile("Daily.txt", ios::app);
	if (!outFile)
	{
		cout << "the File cannot open " << endl;
		exit(1);
	}
	outFile << endl;
	outFile << "ѧ�ţ�" << tmpKey << "      " << "ʱ�䣺";
	SYSTEMTIME sys;       // ����һ�� SYSTEMTIME �ṹ�� sys
	GetLocalTime(&sys);   // GetLocalTime��һ��Windows API ������������ȡ���صĵ�ǰϵͳ���ں�ʱ�䡣
	//��ȡ��ʱ��ʱ��
	outFile << sys.wYear << "/" << sys.wMonth << "/" << sys.wDay << "      " << setfill('0') << setw(2) << sys.wHour
		<< ":" << std::setfill('0') << std::setw(2) << sys.wMinute << ":" << std::setfill('0') << std::setw(2) << sys.wSecond << endl;
	outFile << endl;
	outFile << "�ĵ���᣺";
	outFile << contents;//�ĵõ�����
	outFile << endl << endl;

}

void DailyOutput() {//���Daily.txt������
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
