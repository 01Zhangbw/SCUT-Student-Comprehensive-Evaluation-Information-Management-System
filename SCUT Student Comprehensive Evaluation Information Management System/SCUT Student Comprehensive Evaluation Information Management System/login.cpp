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
int chooseOption(int num, void (*p)(int)) {//���ڹ���ƶ���ѡ����Ӧ��ѡ��

	int a = 1;
	int key = 1;

	while (1) {

		(*p)(a);
		fflush(stdin);//���������
		key = _getch();//��ȡ����������ֻ���뻺������������ĺ���_getch
		if (key == 244 || key == 0)
			key = _getch();
		if (key == 72)
			a--;//up
		else if (key == 80)
			a++;//down
		else if (key >= 48 && key <= 57)
			return key - 48;//���ַ�ת��Ϊ���֣� 0��ASC��Ϊ48 ��
		else if (key == 27)
			return 0;//Esc
		else if (key == 13)
			return a;
		else;
		if (a == num)
			a = 0;
		if (a == -1)
			a = num - 1;
	}
}


void read(ifstream& ifs, vector<string>& vec, vector<Student>& user)//��ȡ�û��˺�����������Ϣ
{

	Student user_1;
	ifs.open("userData.txt");//��userData.txt
	string str;
	char c;
	int i = 0;
	while (ifs.get(c))//��ԭ����testData.txt����
	{

		if (c != ' ' && c != ',' && c != '.' && c != '\n')
			str += c;
		else
		{
			if (str != "") {
				vec.push_back(str);//��str��ֵѹ��vec������vector��
				i += 1;
				if (i == 1) {

					user_1.ID = (str);//��i=1�� str��ֵΪ�û���ID

				}
				if (i == 2) {

					user_1.name = (str);//��i=2�� str��ֵΪ�û�������
				}
				if (i == 3) {
					user_1.password = str;//��i=3�� str��ֵΪ�û�������
					user.push_back(user_1);//��user_1 ����Ϣѹ��user����
				}
				if (i == 3) {
					i = 0;//��ʼ�µ��û���Ϣ��ȡ
				}
				str = "";//��str�ÿ�
			}
		}
	}

	if (ifs.is_open())
		ifs.close();//���ļ��ر�

}
void user() {

	while (1) {
		int i;

		string get_1, get_2;
		for (i = 0; i < 1; i++)
		{

			system("cls");//����
			//char name[50] = { "loginMenu" };//��һ��loginMenu.txt�����¼�����ͼ����������벻��Ҫ���߳�

			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;




			cout << "                                | |                 |_   _|" << endl;
			cout << "                                | |     ___   __ _    | |  _ __" << endl;
			cout << "                                | |    / _ \ / _` |   | | | '_ \ " << endl;
			cout << "                                | |___| (_) | (_| | _ | |_| | | |" << endl;
			cout << "                                | _____\___ /\__, | |_____| | | |" << endl;
			cout << "                                               _/ |" << endl;
			cout << "                                              |___/" << endl;
			cout << endl; cout << endl; cout << endl; cout << endl;







			cout << "	                          --------------------------               " << endl;
			cout << "		                      ID:                    (please enter 10 numbers)" << endl;
			cout << "	                          --------------------------" << endl;
			cout << endl;
			cout << "                                   ---------------------------" << endl;
			cout << "		                   Password:                (please enter 6 numbers)" << endl;
			cout << "		                    -----------------------------" << endl;









			for (int lll = 0; lll < 5; lll++)cout << endl;

			cout << "	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			//inFile(name);//��ȡ

			fflush(stdin);//���������������enter�Ȱ����Ĳ���ҪӰ��
			moveCursor(42, 19);//���궨λ
			fflush(stdin);//���������
			cin >> get_1;//�����û���
			fflush(stdin);//���������
			moveCursor(45, 23);//���궨λ
			cin >> get_2;//��������

		}

		system("cls");
		vector<Student> user;
		ifstream ifs;
		vector<string> vec;
		read(ifs, vec, user);

		int ii;
		bool pass = true;
		for (int jj = 0; jj < user.size(); jj++)
		{
			if (user[jj].ID == (get_1))//�ж�������û����Ƿ���ȷ
			{
				pass = true;
				break;
			}
			else
			{
				pass = false;
				continue;
			}
		}
		if (!pass)//���������û���������������ѵ���Ϣ����ʹ���û����ٴ���������ȷ���û���
		{
			moveCursor(11, 17);
			cout << "Loading...";
			printf("Wrong ID!");//������û�������
			Sleep(1300);
		}

		for (ii = 0; ii < user.size(); ii++) {
			if (user[ii].ID == (get_1)) {//���������û�����userData.txt���ݿ��д洢����ͬ�������������ж�
				if (user[ii].password == (get_2)) {//��������������userData.txt���ݿ��д洢��������ͬ
					system("cls");//����
					cout << "Success!";//��¼�ɹ���
					Sleep(800);//ͣ��8s��ʹ�û����ý������״̬
					tmpKey = get_1;
					Student_login(user[ii]);//����ѧ����¼��Ľ���
					break;
				}
				else
				{
					moveCursor(11, 17);
					cout << "Loading...";
					printf("Wrong password!");//��ʾ�û��������������
					Sleep(1300);
				}
			}
		}

	}
}


void printStudentlogin(int a)
{
	system("cls");
	char name[50] = { "Studentlogin.txt" };//Studentlogin.txt��ȡ�Ŀ�ʼ����
	inFile(name);

	switch (a) {
	case 1:printCursor(88, 9); break;//��ʾ���
	case 2:printCursor(88, 13); break;
	case 3:
		printCursor(88, 17); break;
	default:break;
	}
}
void Student_login(Student user) {

	int a;
	while (1) {
		a = chooseOption(4, printStudentlogin);//ѡ��
		switch (a) {
		case 1:
			system("cls");
			gpa(user);//ѧ�ּ���
			continue;
		case 2:
			system("cls");
			tc(user);//���ʲ���
			continue;
		case 3:
			system("cls");
			covid(user);//�������
			continue;
		default:
			break;
		}
		break;
	}

}
