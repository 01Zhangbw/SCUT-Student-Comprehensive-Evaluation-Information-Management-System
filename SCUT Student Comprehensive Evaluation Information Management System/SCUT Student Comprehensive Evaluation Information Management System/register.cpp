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
void _register() {//�û�ע��

	int i;
	Student user;

	for (i = 0; i < 3; i++) {

		system("cls");
		char name[50] = { "registerMenu.txt" };//name���������洢��׺ά��txt���ļ���
		inFile(name);//��ȡregisterMenu.txt����Ŀ�ʼҳ��
		fflush(stdin);//���������
		moveCursor(40, 14);//��λ
		cin >> user.ID;//����ʹ���ߵ�ID
		fflush(stdin);//���������
		moveCursor(41, 16);//��λ
		cin >> user.name;//����ʹ���ߵ�����
		moveCursor(45, 18);//��λ
		cin >> user.password;//����ʹ���ߵ�����

		vector<Student> user1;
		ifstream ifs;
		vector<string> vec;
		read(ifs, vec, user1);//��ȡ��ǰtxt����Ϣ

		int boo = 0;//�൱��bool�����������ж��Ƿ���ǰ��ע��
		int ii;
		for (ii = 0; ii < user1.size(); ii++) {
			if (user1[ii].ID == (user.ID)) {//�û�����ͬ������ǰ�������û���ע��
				boo = 1;
				break;
			}
		}

		if (!boo) {
			moveCursor(40, 21);
			cout << "Success!";

			char name[15] = "userData.txt";
			ofstream outfile(name, std::ios::app);//����ofstream�Ķ���


			if (!outfile.is_open()) {
				cout << "canIDt open";
				exit(0);
			}
			outfile << user.ID << " ";//�����ļ� ID
			outfile << user.name << " ";//�����ļ� �û���
			outfile << user.password << endl;//�����ļ� ����

			outfile.close();
			Sleep(1800);
			return;
		}
		else {
			moveCursor(13, 16);
			cout << "Failed! Please register again!" << endl;//������ע�ᣡ
			moveCursor(13, 18);
			if (boo == 1)
				std::cout << "You have registered. Please log in!";//��ע�ᣬ���¼��
			Sleep(2100);
		}
	}
}

void write_user(Student user) {//д�û���Ϣ

	char name[15] = "user.txt";
	ofstream outfile(name);

	if (!outfile.is_open()) {
		printf("canIDt open %s\n", name);
		exit(0);
	}
	outfile << user.ID << " ";
	outfile << user.name << " ";
	outfile << user.password << endl;
	outfile.close();

}