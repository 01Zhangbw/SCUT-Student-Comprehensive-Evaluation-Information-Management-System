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
int chooseOption(int num, void (*p)(int)) {//用于光标移动与选择相应的选项

	int a = 1;
	int key = 1;

	while (1) {

		(*p)(a);
		fflush(stdin);//清除缓冲区
		key = _getch();//获取按键，但是只进入缓冲区而不输出的函数_getch
		if (key == 244 || key == 0)
			key = _getch();
		if (key == 72)
			a--;//up
		else if (key == 80)
			a++;//down
		else if (key >= 48 && key <= 57)
			return key - 48;//由字符转化为数字（ 0的ASCⅡ为48 ）
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


void read(ifstream& ifs, vector<string>& vec, vector<Student>& user)//读取用户账号名字密码信息
{

	Student user_1;
	ifs.open("userData.txt");//打开userData.txt
	string str;
	char c;
	int i = 0;
	while (ifs.get(c))//其原理与testData.txt类似
	{

		if (c != ' ' && c != ',' && c != '.' && c != '\n')
			str += c;
		else
		{
			if (str != "") {
				vec.push_back(str);//将str的值压入vec容器（vector）
				i += 1;
				if (i == 1) {

					user_1.ID = (str);//当i=1， str赋值为用户的ID

				}
				if (i == 2) {

					user_1.name = (str);//当i=2， str赋值为用户的名字
				}
				if (i == 3) {
					user_1.password = str;//当i=3， str赋值为用户的密码
					user.push_back(user_1);//将user_1 的信息压入user容器
				}
				if (i == 3) {
					i = 0;//开始新的用户信息读取
				}
				str = "";//将str置空
			}
		}
	}

	if (ifs.is_open())
		ifs.close();//将文件关闭

}
void user() {

	while (1) {
		int i;

		string get_1, get_2;
		for (i = 0; i < 1; i++)
		{

			system("cls");//清屏
			//char name[50] = { "loginMenu" };//用一个loginMenu.txt保存登录界面的图案，避免代码不必要的冗长

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
			//inFile(name);//读取

			fflush(stdin);//清除缓冲区，避免enter等按键的不必要影响
			moveCursor(42, 19);//坐标定位
			fflush(stdin);//清除缓冲区
			cin >> get_1;//输入用户名
			fflush(stdin);//清除缓冲区
			moveCursor(45, 23);//坐标定位
			cin >> get_2;//输入密码

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
			if (user[jj].ID == (get_1))//判断输入的用户名是否正确
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
		if (!pass)//如果输入的用户名错误，则输出提醒的信息，并使得用户能再次输入其正确的用户名
		{
			moveCursor(11, 17);
			cout << "Loading...";
			printf("Wrong ID!");//输入的用户名错误
			Sleep(1300);
		}

		for (ii = 0; ii < user.size(); ii++) {
			if (user[ii].ID == (get_1)) {//如果输入的用户名与userData.txt数据库中存储的相同，则进入密码的判断
				if (user[ii].password == (get_2)) {//如果输入的密码与userData.txt数据库中存储的密码相同
					system("cls");//清屏
					cout << "Success!";//登录成功！
					Sleep(800);//停留8s，使用户更好进入答题状态
					tmpKey = get_1;
					Student_login(user[ii]);//进入学生登录后的界面
					break;
				}
				else
				{
					moveCursor(11, 17);
					cout << "Loading...";
					printf("Wrong password!");//提示用户输入的密码有误
					Sleep(1300);
				}
			}
		}

	}
}


void printStudentlogin(int a)
{
	system("cls");
	char name[50] = { "Studentlogin.txt" };//Studentlogin.txt存取的开始界面
	inFile(name);

	switch (a) {
	case 1:printCursor(88, 9); break;//显示光标
	case 2:printCursor(88, 13); break;
	case 3:
		printCursor(88, 17); break;
	default:break;
	}
}
void Student_login(Student user) {

	int a;
	while (1) {
		a = chooseOption(4, printStudentlogin);//选择
		switch (a) {
		case 1:
			system("cls");
			gpa(user);//学分绩点
			continue;
		case 2:
			system("cls");
			tc(user);//体质测试
			continue;
		case 3:
			system("cls");
			covid(user);//疫情答题
			continue;
		default:
			break;
		}
		break;
	}

}
