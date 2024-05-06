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
//教师端注册
void teacher_register() {//用户注册

	int i;
	Teacher user;

	for (i = 0; i < 3; i++) {

		system("cls");
		char name[50] = { "registerMenu.txt" };//name的数组来存储后缀维持txt的文件名
		inFile(name);//读取registerMenu.txt里面的开始页面
		fflush(stdin);//清除缓冲区
		moveCursor(40, 14);//定位
		cin >> user.teachID;//输入使用者的ID
		fflush(stdin);//清除缓冲区
		moveCursor(41, 16);//定位
		cin >> user.teachname;//输入使用者的名字
		moveCursor(45, 18);//定位
		cin >> user.teachpassword;//输入使用者的密码

		vector<Teacher> user1;
		ifstream ifs;
		vector<string> vec;
		read_teacher(ifs, vec, user1);//读取先前txt的信息

		int boo = 0;//相当于bool变量，用于判断是否先前已注册
		int ii;
		for (ii = 0; ii < user1.size(); ii++) {
			if (user1[ii].teachID == (user.teachID)) {//用户名相同，即先前有其他用户已注册
				boo = 1;
				break;
			}
		}

		if (!boo) {
			moveCursor(40, 21);
			cout << "Success!";

			char name[20] = "teacherData.txt";
			ofstream outfile(name, std::ios::app);//创建ofstream的对象


			if (!outfile.is_open()) {
				cout << "canIDt open";
				exit(0);
			}
			outfile << user.teachID << " ";//读入文件 ID
			outfile << user.teachname << " ";//读入文件 用户名
			outfile << user.teachpassword << endl;//读入文件 密码

			outfile.close();
			Sleep(1800);
			return;
		}
		else {
			moveCursor(13, 16);
			cout << "Failed! Please register again!" << endl;//请重新注册！
			moveCursor(13, 18);
			if (boo == 1)
				std::cout << "You have registered. Please log in!";//已注册，请登录！
			Sleep(2100);
		}
	}
}

//向txt文件写教师信息
void write_teacher(Teacher user) {

	char name[20] = "teacherData.txt";
	ofstream outfile(name);

	if (!outfile.is_open()) {
		printf("canIDt open %s\n", name);
		exit(0);
	}
	outfile << user.teachID << " ";
	outfile << user.teachname << " ";
	outfile << user.teachpassword << endl;
	outfile.close();

}
//将教师注册的信息读入txt
void read_teacher(ifstream& ifs, vector<string>& vec, vector<Teacher>& user)
{

	Teacher user_1;
	ifs.open("teacherData.txt");//打开userData.txt
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

					user_1.teachID = (str);//当i=1， str赋值为用户的ID

				}
				if (i == 2) {

					user_1.teachname = (str);//当i=2， str赋值为用户的名字
				}
				if (i == 3) {
					user_1.teachpassword = str;//当i=3， str赋值为用户的密码
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

//教师登录的页面
void user_teacher() {

	while (1) {
		int i;

		string get_1, get_2;
		for (i = 0; i < 1; i++)
		{

			system("cls");//清屏


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
		vector<Teacher> user;
		ifstream ifs;
		vector<string> vec;
		read_teacher(ifs, vec, user);

		int ii;
		bool pass = true;
		for (int jj = 0; jj < user.size(); jj++)
		{
			if (user[jj].teachID == (get_1))//判断输入的用户名是否正确
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
			if (user[ii].teachID == (get_1)) {//如果输入的用户名与userData.txt数据库中存储的相同，则进入密码的判断
				if (user[ii].teachpassword == (get_2)) {//如果输入的密码与userData.txt数据库中存储的密码相同
					system("cls");//清屏
					cout << "Success!";//登录成功！
					Sleep(800);//停留8s，使用户更好进入答题状态

					Teacher_login(user[ii], stu);//进入教师登录后的界面
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
//打印教师端的主菜单
void printTeacherMainMenu(int a) {

	system("cls");
	char name[50] = { "teacherMenu.txt" };//teacherMenu.txt存取的开始界面
	inFile(name);//将txt中的图片打印到screen上

	switch (a) {
	case 1:printCursor(80, 9); break;//显示光标
	case 2:printCursor(80, 14); break;
	default:break;
	}
}
//打印教师注册页面
void printTeacherlogin(int a)
{
	system("cls");
	char name[50] = { "Teacherlogin.txt" };//teacherlogin.txt存取的开始界面
	inFile(name);

	switch (a) {
	case 1:
		printCursor(80, 9);
		break;//显示光标
	case 2:
		printCursor(80, 11);
		break;
	case 3:
		printCursor(80, 13);
		break;
	case 4:
		printCursor(80, 15);
		break;
	case 5:
		printCursor(80, 17);
		break;
	case 6:
		printCursor(80, 19);
		break;

	default:break;
	}
}

void Teacher_login(Teacher user, Student stu[])
{
	int a;

	while (1) {
		a = chooseOption(7, printTeacherlogin);//选择
		switch (a) {
		case 1:
			system("cls");
			Input(stu);//录入学生成绩
			continue;
		case 2:
			system("cls");
			Modify(stu);//修改学生的成绩
			continue;
		case 3:
			system("cls");
			Insert(stu);//添加学生的成绩
			continue;
		case 4:
			system("cls");
			Delete(stu);//删除学生的成绩
			continue;
		case 5:
			system("cls");
			Output(stu);//输出所有学生的全部成绩（按照学号升序输出）
			continue;
		case 6:
			system("cls");
			Sort(stu);//学生成绩的排序（按照GPA降序输出）
			continue;

		default:
			break;
		}
		break;
	}

}

//将学生的信息写入score.txt文件
void Write(Student stu[], int n)
{

	fstream ioFile;

	ioFile.open("score.txt", ios::out | ios::binary);//二进制文件

	if (!ioFile)
	{
		cout << "the file cannot be open" << endl;
		exit(1);

	}

	int count = n;
	ioFile << count << endl << endl;

	for (int j = 0; j < n; j++)
	{
		ioFile << stu[j].ID << "\t"//学号
			<< stu[j].name << "\t"//名字
			<< stu[j].highmaths << "\t"//数分
			<< stu[j].english << "\t"//大英
			<< stu[j].linear << "\t"//线代
			<< stu[j].cpp << "\t"//C++
			<< stu[j].gailv << "\t"//概率论
			<< stu[j].ddca << "\t"//数字逻辑
			<< stu[j].pe << "\t"//体育（体测）
			<< stu[j].history << "\t"//近代史
			<< stu[j].policy << "\t"//思修
			<< stu[j].totalscore << endl;//GPA


	}
	ioFile.close();


}

//将txt文件的内容读出
int Read(Student stu[])
{
	fstream ioFile;
	ioFile.open("score.txt", ios::in | ios::binary);


	if (!ioFile)
	{
		cout << "the file cannot open" << endl;
		exit(1);
	}


	int count;
	ioFile.seekg(0);

	ioFile >> count;

	for (int j = 0; j < count; j++)
	{
		ioFile >> stu[j].ID//学号
			>> stu[j].name//姓名
			>> stu[j].highmaths//数分
			>> stu[j].english//大英
			>> stu[j].linear//线代
			>> stu[j].cpp//C++
			>> stu[j].gailv//概率论
			>> stu[j].ddca//数字逻辑
			>> stu[j].pe//大学体育
			>> stu[j].history//近现代史
			>> stu[j].policy//思修
			>> stu[j].totalscore;//学分绩点


	}
	ioFile.close();

	return count;


}

//输入学生的成绩
void Input(Student stu[])
{
	system("cls");
	int  i = 0;
	bool flag;
	char sign = '0';
	cout << "=========>>\t请输入学生成绩\t<<==========" << endl;
	while (sign != 'n' && sign != 'N')
	{
	loop:

		cout << "学号：";
		cin >> stu[i].ID;
		int c = 0;
		while (c < i)//检测是否重复输入
		{
			c++;
			if (stu[i].ID == stu[i - c].ID)
			{
				cout << "您输入的学号存在！请重新输入 " << endl;
				goto loop;
			}
		}

		cout << "姓名：";
		cin >> stu[i].name;
		do//确保输入的均为0-100的分数
		{
			flag = false;
			cout << "工科数学分析成绩：";

			cin >> stu[i].highmaths;
			if (stu[i].highmaths > 100 || stu[i].highmaths < 0)
			{
				cout << "对不起，请输入1-100之间的数字" << endl;

			}
			if (stu[i].highmaths <= 100 && stu[i].highmaths >= 0)
			{
				flag = true;

			}


		} while (flag == false);

		do
		{
			flag = false;
			cout << "大学英语成绩：";
			cin >> stu[i].english;
			if (stu[i].english > 100 || stu[i].english < 0)
			{
				cout << "对不起，请输入1-100之间的数字" << endl;

			}
			if (stu[i].english <= 100 && stu[i].english >= 0)
			{
				flag = true;

			}
		} while (flag == false);

		do
		{
			flag = false;
			cout << "线性代数成绩：";
			cin >> stu[i].linear;
			if (stu[i].linear > 100 || stu[i].linear < 0)
			{
				cout << "对不起，请输入1-100之间的数字" << endl;

			}
			if (stu[i].linear <= 100 && stu[i].linear >= 0)
			{
				flag = true;

			}
		} while (flag == false);

		do
		{
			flag = false;
			cout << "C++程序设计成绩：";
			cin >> stu[i].cpp;
			if (stu[i].cpp > 100 || stu[i].cpp < 0)
			{
				cout << "对不起，请输入1-100之间的数字" << endl;

			}
			if (stu[i].cpp <= 100 && stu[i].cpp >= 0)
			{
				flag = true;

			}
		} while (flag == false);


		do
		{
			flag = false;
			cout << "概率论与数理统计成绩：";
			cin >> stu[i].gailv;
			if (stu[i].gailv > 100 || stu[i].gailv < 0)
			{
				cout << "对不起，请输入1-100之间的数字" << endl;

			}
			if (stu[i].gailv <= 100 && stu[i].gailv >= 0)
			{
				flag = true;

			}
		} while (flag == false);


		do
		{
			flag = false;
			cout << "数字逻辑成绩： ";
			cin >> stu[i].ddca;
			if (stu[i].ddca > 100 || stu[i].ddca < 0)
			{
				cout << "对不起，请输入1-100之间的数字" << endl;

			}
			if (stu[i].ddca <= 100 && stu[i].ddca >= 0)
			{
				flag = true;

			}
		} while (flag == false);


		do
		{
			flag = false;
			cout << "大学体育成绩：";
			cin >> stu[i].pe;
			if (stu[i].pe > 100 || stu[i].pe < 0)
			{
				cout << "对不起，请输入1-100之间的数字" << endl;

			}
			if (stu[i].pe <= 100 && stu[i].pe >= 0)
			{
				flag = true;

			}
		} while (flag == false);


		do
		{
			flag = false;
			cout << "近现代史纲要成绩：";
			cin >> stu[i].history;
			if (stu[i].history > 100 || stu[i].history < 0)
			{
				cout << "对不起，请输入1-100之间的数字" << endl;

			}
			if (stu[i].history <= 100 && stu[i].history >= 0)
			{
				flag = true;

			}
		} while (flag == false);

		do
		{
			flag = false;
			cout << "思想道德与法治成绩： ";
			cin >> stu[i].policy;
			if (stu[i].policy > 100 || stu[i].policy < 0)
			{
				cout << "对不起，请输入1-100之间的数字" << endl;

			}
			if (stu[i].policy <= 100 && stu[i].policy >= 0)
			{
				flag = true;

			}
		} while (flag == false);
		//计算学分绩点
		stu[i].totalscore = (stu[i].highmaths * stu[i].highmaths_rate
			+ stu[i].cpp * stu[i].cpp_rate + stu[i].english * stu[i].english_rate
			+ stu[i].linear * stu[i].linear_rate
			+ stu[i].gailv * stu[i].gailv_rate + stu[i].ddca * stu[i].ddca_rate
			+ stu[i].pe * stu[i].pe_rate + stu[i].history * stu[i].history_rate
			+ stu[i].policy * stu[i].policy_rate) / (stu[i].highmaths_rate
				+ stu[i].cpp_rate + stu[i].english_rate + stu[i].linear_rate
				+ stu[i].gailv_rate + stu[i].ddca_rate + stu[i].pe_rate
				+ stu[i].history_rate + stu[i].policy_rate);

		cout << "GPA: " << stu[i].totalscore << endl;

		cout << "=========>>提示： 是否继续写入写入学生成绩 ？ （Y / N）";//询问是否继续
		cin >> sign;
		++i;

	}
	Write(stu, i);//写入txt

}


//screen输出所有学生的GPA//所有学生的GPA//该系统并未使用该函数
void Statistic(Student stu[])
{
	system("cls");
	int n = Read(stu);
	cout << endl;
	cout << "==========>>\t\t输出学生统计数据\t\t<<============" << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << "\t" << "学号\t" << "姓名\t" << "GPA\t";
	cout << endl;
	cout << "------------------------------------------------------" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "\t" << stu[i].ID << "\t" << stu[i].name << "\t" << stu[i].totalscore << endl;

	}
	cout << "------------------------------------------------------" << endl;
	system("pause");

}

void SortFun(Student stu[])//以GPA排序
{
	int i;
	int j;
	int k;
	double s;
	string tmp;
	int n = Read(stu);//读取scoore.txt中的学生总数
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			if (stu[j].totalscore < stu[j + 1].totalscore)
			{//交换
				tmp = stu[j + 1].ID;
				stu[j + 1].ID = stu[j].ID;
				stu[j].ID = tmp;

				tmp = stu[j + 1].name;
				stu[j + 1].name = stu[j].name;
				stu[j].name = tmp;

				tmp = stu[j + 1].password;
				stu[j + 1].password = stu[j].password;
				stu[j].password = tmp;

				s = stu[j + 1].highmaths;
				stu[j + 1].highmaths = stu[j].highmaths;
				stu[j].highmaths = s;

				s = stu[j + 1].english;
				stu[j + 1].english = stu[j].english;
				stu[j].english = s;

				s = stu[j + 1].linear;
				stu[j + 1].linear = stu[j].linear;
				stu[j].linear = s;

				s = stu[j + 1].cpp;
				stu[j + 1].cpp = stu[j].cpp;
				stu[j].cpp = s;

				s = stu[j + 1].gailv;
				stu[j + 1].gailv = stu[j].gailv;
				stu[j].gailv = s;

				s = stu[j + 1].ddca;
				stu[j + 1].ddca = stu[j].ddca;
				stu[j].ddca = s;

				s = stu[j + 1].pe;
				stu[j + 1].pe = stu[j].pe;
				stu[j].pe = s;

				s = stu[j + 1].history;
				stu[j + 1].history = stu[j].history;
				stu[j].history = s;

				s = stu[j + 1].policy;
				stu[j + 1].policy = stu[j].policy;
				stu[j].policy = s;

				s = stu[j + 1].totalscore;
				stu[j + 1].totalscore = stu[j].totalscore;
				stu[j].totalscore = s;



			}
		}
	}
	Write(stu, n);//重新写入score.txt
	for (int i = 0; i < n; i++)
	{
		stu[i].order = i + 1;//确定各个成员的排序序号

	}
}

//查找学生成绩//Teachet&Student
void Lookup(Student stu[])
{
	system("cls");
	int n = Read(stu);
	string s;
	int i = 0;
	cout << endl;
	cout << "==========================>>\t\t各科成绩查询\t\t<<=========================" << endl << endl;
	cout << "=========================>>\t\t查询\t\t<<==============================" << endl;
	system("pause");
	Sleep(1500);
	//cout << "请输入要查找学生的学号";
	//cin >> s;
	while ((stu[i].ID != tmpKey) && i < n)//看是否有该学生
	{
		i++;

	}
	if (i == n)
	{
		cout << "==========>>\t\t对不起，无法找到该学生\t\t<<============" << endl;

	}
	else
	{
		cout << endl << endl << endl;
		cout << "学号\t" << stu[i].ID << endl << endl;
		cout << "姓名\t" << stu[i].name << endl << endl;
		cout << "工科数学分析\t" << stu[i].highmaths << endl << endl;
		cout << "大学英语\t" << stu[i].english << endl << endl;
		cout << "线性代数\t" << stu[i].linear << endl << endl;
		cout << "C++程序设计\t" << stu[i].cpp << endl << endl;
		cout << "概率论数理统计\t" << stu[i].gailv << endl << endl;
		cout << "数字逻辑\t" << stu[i].ddca << endl << endl;
		cout << "大学体育\t" << stu[i].pe << endl << endl;
		cout << "近现代史\t" << stu[i].history << endl << endl;
		cout << "思想道德与法治\t" << stu[i].policy << endl << endl;

	}

	system("pause");
}
//查找学生GPA//Teachet&Student
void Lookup_GPA(Student stu[])
{
	system("cls");
	SortFun(stu);
	int n = Read(stu);
	string str;
	int ii = 0;

	cout << endl;
	//cout << "============>>\t\t查找学生成绩\t\t<<============" << endl;
	//cout << "请输入要查找学生的学号";
	//cin >> str;
	cout << "==========================>>\t\t各科成绩查询\t\t<<=========================" << endl;
	cout << endl;
	cout << "=========================>>\t\tGPA查询\t\t<<==============================" << endl;
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
		cout << endl << endl << endl;
		cout << "学号\t" << stu[ii].ID << endl << endl;
		cout << "姓名\t" << stu[ii].name << endl << endl;
		cout << "GPA\t" << stu[ii].totalscore << endl << endl;
		cout << "排名\t" << stu[ii].order << " / " << n << endl << endl;

	}

	system("pause");
}

//修改学生成绩//Teacher
void Modify(Student stu[])
{
	system("cls");
	int n = Read(stu);
	string s;
	bool flag;
	int i = 0;
	cout << endl;
	cout << "===========>>\t\t修改学生成绩\t\t<<=============" << endl;
	cout << "请输入要修改成绩学生的学号： ";
	cin >> s;
	while (stu[i].ID != s && i < n)
	{
		i++;

	}
	if (i == n)
	{
		cout << "================>>\t\t对不起，无法找到该学生\t\t<<===================";
		cout << endl;
	}
	else
	{
		cout << "------------------------------------------------------------------------------------" << endl;
		cout << "学号" << "\t" << "姓名" << "\t"
			<< "数分" << "\t" << "大英" << "\t" << "线代" << "\t"
			<< "C++" << "\t" << "概率论" << "\t" << "数电" << "\t"
			<< "体育" << "\t" << "近代史\t" << "思修" << "\t"
			<< "GPA" << "\t" << endl;
		cout << "------------------------------------------------------------------------------------" << endl;
		cout << stu[i].ID << "\t" << stu[i].name << "\t"
			<< stu[i].highmaths << "\t" << stu[i].english << "\t" << stu[i].linear << "\t"
			<< stu[i].cpp << "\t" << stu[i].gailv << "\t" << stu[i].ddca << "\t"
			<< stu[i].pe << "\t" << stu[i].history << "\t" << stu[i].policy
			<< "\t" << stu[i].totalscore << endl;
		cout << endl << "请重新输入该学生成绩： " << endl;
		do
		{
			flag = false;
			cout << "工科数学分析成绩：";

			cin >> stu[i].highmaths;
			if (stu[i].highmaths > 100 || stu[i].highmaths < 0)
			{
				cout << "对不起，请输入1-100之间的数字" << endl;

			}
			if (stu[i].highmaths <= 100 && stu[i].highmaths >= 0)
			{
				flag = true;

			}


		} while (flag == false);

		do
		{
			flag = false;
			cout << "大学英语成绩：";
			cin >> stu[i].english;
			if (stu[i].english > 100 || stu[i].english < 0)
			{
				cout << "对不起，请输入1-100之间的数字" << endl;

			}
			if (stu[i].english <= 100 && stu[i].english >= 0)
			{
				flag = true;

			}
		} while (flag == false);

		do
		{
			flag = false;
			cout << "线性代数成绩：";
			cin >> stu[i].linear;
			if (stu[i].linear > 100 || stu[i].linear < 0)
			{
				cout << "对不起，请输入1-100之间的数字" << endl;

			}
			if (stu[i].linear <= 100 && stu[i].linear >= 0)
			{
				flag = true;

			}
		} while (flag == false);

		do
		{
			flag = false;
			cout << "C++程序设计成绩：";
			cin >> stu[i].cpp;
			if (stu[i].cpp > 100 || stu[i].cpp < 0)
			{
				cout << "对不起，请输入1-100之间的数字" << endl;

			}
			if (stu[i].cpp <= 100 && stu[i].cpp >= 0)
			{
				flag = true;

			}
		} while (flag == false);


		do
		{
			flag = false;
			cout << "概率论与数理统计成绩：";
			cin >> stu[i].gailv;
			if (stu[i].gailv > 100 || stu[i].gailv < 0)
			{
				cout << "对不起，请输入1-100之间的数字" << endl;

			}
			if (stu[i].gailv <= 100 && stu[i].gailv >= 0)
			{
				flag = true;

			}
		} while (flag == false);


		do
		{
			flag = false;
			cout << "数字逻辑成绩： ";
			cin >> stu[i].ddca;
			if (stu[i].ddca > 100 || stu[i].ddca < 0)
			{
				cout << "对不起，请输入1-100之间的数字" << endl;

			}
			if (stu[i].ddca <= 100 && stu[i].ddca >= 0)
			{
				flag = true;

			}
		} while (flag == false);


		do
		{
			flag = false;
			cout << "大学体育成绩：";
			cin >> stu[i].pe;
			if (stu[i].pe > 100 || stu[i].pe < 0)
			{
				cout << "对不起，请输入1-100之间的数字" << endl;

			}
			if (stu[i].pe <= 100 && stu[i].pe >= 0)
			{
				flag = true;

			}
		} while (flag == false);


		do
		{
			flag = false;
			cout << "近现代史纲要成绩：";
			cin >> stu[i].history;
			if (stu[i].history > 100 || stu[i].history < 0)
			{
				cout << "对不起，请输入1-100之间的数字" << endl;

			}
			if (stu[i].history <= 100 && stu[i].history >= 0)
			{
				flag = true;

			}
		} while (flag == false);

		do
		{
			flag = false;
			cout << "思想道德与法治成绩： ";
			cin >> stu[i].policy;
			if (stu[i].policy > 100 || stu[i].policy < 0)
			{
				cout << "对不起，请输入1-100之间的数字" << endl;

			}
			if (stu[i].policy <= 100 && stu[i].policy >= 0)
			{
				flag = true;

			}
		} while (flag == false);

		stu[i].totalscore = (stu[i].highmaths * stu[i].highmaths_rate
			+ stu[i].cpp * stu[i].cpp_rate + stu[i].english * stu[i].english_rate
			+ stu[i].linear * stu[i].linear_rate
			+ stu[i].gailv * stu[i].gailv_rate + stu[i].ddca * stu[i].ddca_rate
			+ stu[i].pe * stu[i].pe_rate + stu[i].history * stu[i].history_rate
			+ stu[i].policy * stu[i].policy_rate) / (stu[i].highmaths_rate
				+ stu[i].cpp_rate + stu[i].english_rate + stu[i].linear_rate
				+ stu[i].gailv_rate + stu[i].ddca_rate + stu[i].pe_rate
				+ stu[i].history_rate + stu[i].policy_rate);

		cout << "GPA: " << stu[i].totalscore << endl;
		char key;
		cout << "=========>>\t\t是否保存数据\t\t(y / n)";//询问是否保存修改后的信息
		cin >> key;
		if (key != 'n' && key != 'N')
		{
			Write(stu, n);//重新写入

		}




	}

}

//交换两个字符串//均为string类型
void strSwap(string& a, string& b)///交换两个字符串
{
	string tmpa = a;
	a = b;
	b = tmpa;

}

//删除学生的成绩//Teacher
void Delete(Student stu[])
{
	system("cls");
	int n = Read(stu);
	string s;
	int i = 0;
	int j;
	cout << endl;
	cout << "===========>>\t\t删除学生成绩\t\t<<==================" << endl;
	cout << "请输入要删除的学生的学号： ";
	cin >> s;
	while (stu[i].ID != s && i < n)
	{
		i++;

	}
	if (i == n)
	{
		cout << "==============>>\t\t对不起，无法找到该学生\t\t<<===============";
		cout << endl;
	}
	else
	{
		for (j = i; j < n - 1; j++)
		{
			strSwap(stu[j].name, stu[j + 1].name);
			strSwap(stu[j].ID, stu[j + 1].ID);
			strSwap(stu[j].password, stu[j + 1].password);

			stu[j].highmaths = stu[j + 1].highmaths;
			stu[j].english = stu[j + 1].english;
			stu[j].linear = stu[j + 1].linear;
			stu[j].cpp = stu[j + 1].cpp;
			stu[j].gailv = stu[j + 1].gailv;
			stu[j].ddca = stu[j + 1].ddca;
			stu[j].pe = stu[j + 1].pe;
			stu[j].history = stu[j + 1].history;
			stu[j].policy = stu[j + 1].policy;
			stu[j].totalscore = stu[j + 1].totalscore;

		}
		cout << "==============>>\t\t提示：已成功删除！ " << endl;

	}
	Write(stu, n - 1);//写入txt，注意此处是n-1，即为已删除选中人的信息


}

//插入（使得班级的人数增加）//Teacher
void Insert(Student stu[])
{

	system("cls");
	int n = Read(stu);//直接定位到第n个同学，实现后面的插入
	int i = 0;
	bool flag;

	char s = '0';
	cout << endl;
	cout << "=======================>>\t\t增加学生成绩\t\t<<=====================" << endl;
	while (s != 'n' && s != 'N')
	{
	loop:

		cout << "学号：";
		cin >> stu[n].ID;
		int c = 0;
		while (c < n)
		{
			c++;
			if (stu[n].ID == stu[n - c].ID)
			{
				cout << "您输入的学号存在！请重新输入 " << endl;
				goto loop;
			}
		}
		cout << "姓名：";
		cin >> stu[n].name;
		do
		{
			flag = false;
			cout << "工科数学分析成绩： ";

			cin >> stu[n].highmaths;
			if (stu[n].highmaths > 100 || stu[n].highmaths < 0)
			{
				cout << "对不起，请输入1-100之间的数字" << endl;

			}
			if (stu[n].highmaths <= 100 && stu[n].highmaths >= 0)
			{
				flag = true;

			}


		} while (flag == false);

		do
		{
			flag = false;
			cout << "大学英语成绩： ";
			cin >> stu[n].english;
			if (stu[n].english > 100 || stu[n].english < 0)
			{
				cout << "对不起，请输入1-100之间的数字" << endl;

			}
			if (stu[n].english <= 100 && stu[n].english >= 0)
			{
				flag = true;

			}
		} while (flag == false);

		do
		{
			flag = false;
			cout << "线性代数成绩： ";
			cin >> stu[n].linear;
			if (stu[n].linear > 100 || stu[n].linear < 0)
			{
				cout << "对不起，请输入1-100之间的数字" << endl;

			}
			if (stu[n].linear <= 100 && stu[n].linear >= 0)
			{
				flag = true;

			}
		} while (flag == false);

		do
		{
			flag = false;
			cout << "C++程序设计成绩： ";
			cin >> stu[n].cpp;
			if (stu[n].cpp > 100 || stu[n].cpp < 0)
			{
				cout << "对不起，请输入1-100之间的数字" << endl;

			}
			if (stu[n].linear <= 100 && stu[n].linear >= 0)
			{
				flag = true;

			}
		} while (flag == false);


		do
		{
			flag = false;
			cout << "概率论与数理统计成绩： ";
			cin >> stu[n].gailv;
			if (stu[n].gailv > 100 || stu[n].gailv < 0)
			{
				cout << "对不起，请输入1-100之间的数字" << endl;

			}
			if (stu[n].gailv <= 100 && stu[n].gailv >= 0)
			{
				flag = true;

			}
		} while (flag == false);


		do
		{
			flag = false;
			cout << "数字逻辑成绩： ";
			cin >> stu[n].ddca;
			if (stu[n].ddca > 100 || stu[n].ddca < 0)
			{
				cout << "对不起，请输入1-100之间的数字" << endl;

			}
			if (stu[n].ddca <= 100 && stu[n].ddca >= 0)
			{
				flag = true;

			}
		} while (flag == false);


		do
		{
			flag = false;
			cout << "大学体育成绩： ";
			cin >> stu[n].pe;
			if (stu[n].pe > 100 || stu[n].pe < 0)
			{
				cout << "对不起，请输入1-100之间的数字" << endl;

			}
			if (stu[n].pe <= 100 && stu[n].pe >= 0)
			{
				flag = true;

			}
		} while (flag == false);


		do
		{
			flag = false;
			cout << "近现代史纲要成绩： ";
			cin >> stu[n].history;
			if (stu[n].history > 100 || stu[n].history < 0)
			{
				cout << "对不起，请输入1-100之间的数字" << endl;

			}
			if (stu[n].history <= 100 && stu[n].history >= 0)
			{
				flag = true;

			}
		} while (flag == false);

		do
		{
			flag = false;
			cout << "思想道德与法治成绩： ";
			cin >> stu[n].policy;
			if (stu[n].policy > 100 || stu[n].policy < 0)
			{
				cout << "对不起，请输入1-100之间的数字" << endl;

			}
			if (stu[n].policy <= 100 && stu[n].policy >= 0)
			{
				flag = true;

			}
		} while (flag == false);

		stu[n].totalscore = (stu[n].highmaths * stu[n].highmaths_rate
			+ stu[n].cpp * stu[n].cpp_rate + stu[n].english * stu[n].english_rate
			+ stu[n].linear * stu[n].linear_rate
			+ stu[n].gailv * stu[n].gailv_rate + stu[n].ddca * stu[n].ddca_rate
			+ stu[n].pe * stu[n].pe_rate + stu[n].history * stu[n].history_rate
			+ stu[n].policy * stu[n].policy_rate) / (stu[n].highmaths_rate
				+ stu[n].cpp_rate + stu[n].english_rate + stu[n].linear_rate
				+ stu[n].gailv_rate + stu[n].ddca_rate + stu[n].pe_rate
				+ stu[n].history_rate + stu[n].policy_rate);
		//计算GPA

		cout << "GPA: " << stu[n].totalscore << endl;
		n++;
		cout << "=========>>\t\t是否继续插入（y/n）";
		cin >> s;
	}

	Write(stu, n);//写入信息

}
//排序
void Sort(Student stu[])//以GPA 排序
{
	system("cls");
	int i;
	int j;
	int k;
	double s;
	string tmp;

	cout << endl << "==========>>\t\t降序排列\t\t<<===========" << endl;
	int n = Read(stu);
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			if (stu[j].totalscore < stu[j + 1].totalscore)
			{
				tmp = stu[j + 1].ID;
				stu[j + 1].ID = stu[j].ID;
				stu[j].ID = tmp;

				tmp = stu[j + 1].name;
				stu[j + 1].name = stu[j].name;
				stu[j].name = tmp;

				tmp = stu[j + 1].password;
				stu[j + 1].password = stu[j].password;
				stu[j].password = tmp;

				s = stu[j + 1].highmaths;
				stu[j + 1].highmaths = stu[j].highmaths;
				stu[j].highmaths = s;

				s = stu[j + 1].english;
				stu[j + 1].english = stu[j].english;
				stu[j].english = s;

				s = stu[j + 1].linear;
				stu[j + 1].linear = stu[j].linear;
				stu[j].linear = s;

				s = stu[j + 1].cpp;
				stu[j + 1].cpp = stu[j].cpp;
				stu[j].cpp = s;

				s = stu[j + 1].gailv;
				stu[j + 1].gailv = stu[j].gailv;
				stu[j].gailv = s;

				s = stu[j + 1].ddca;
				stu[j + 1].ddca = stu[j].ddca;
				stu[j].ddca = s;

				s = stu[j + 1].pe;
				stu[j + 1].pe = stu[j].pe;
				stu[j].pe = s;

				s = stu[j + 1].history;
				stu[j + 1].history = stu[j].history;
				stu[j].history = s;

				s = stu[j + 1].policy;
				stu[j + 1].policy = stu[j].policy;
				stu[j].policy = s;

				s = stu[j + 1].totalscore;
				stu[j + 1].totalscore = stu[j].totalscore;
				stu[j].totalscore = s;



			}
		}
	}
	cout << "-------------------------------------------------------------------------------------------" << endl;
	cout << "学号" << "\t" << "姓名" << "\t"
		<< "数分" << "\t" << "大英" << "\t" << "线代" << "\t"
		<< "C++" << "\t" << "概率论" << "\t" << "数电" << "\t"
		<< "体育" << "\t" << "近代史\t" << "思修" << "\t"
		<< "GPA" << endl;
	cout << "---------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < n; i++)
	{
		stu[i].order = i + 1;
		cout << stu[i].ID << "\t" << stu[i].name << "\t"
			<< stu[i].highmaths << "\t" << stu[i].english << "\t" << stu[i].linear << "\t"
			<< stu[i].cpp << "\t" << stu[i].gailv << "\t" << stu[i].ddca << "\t"
			<< stu[i].pe << "\t" << stu[i].history << "\t" << stu[i].policy
			<< "\t" << stu[i].totalscore << endl;
	}
	Write(stu, n);
	system("pause");
}

void zongce(Student stu[])//综测
{
	system("cls");
	SortFun(stu);
	int n = Read(stu);//txt已有用户的数量
	string str;
	int i = 0;
	double percent;
	cout << endl;
	cout << "==========================>>\t\t综测评优查询\t\t<<=========================" << endl << endl;
	cout << "=========================>>\t\t查询\t\t<<==============================" << endl << endl;
	system("pause");
	Sleep(1500);
	while ((stu[i].ID != tmpKey) && i < n)
	{
		i++;

	}
	if (i == n)
	{
		cout << "==========>>\t\t对不起，无法找到该学生\t\t<<============" << endl;

	}
	//奖学金前提是各科60+以及体测75+
	else
	{
		cout << endl << endl << endl;
		cout << "学号\t" << stu[i].ID << endl << endl;
		cout << "姓名\t" << stu[i].name << endl << endl;
		cout << "GPA\t" << stu[i].totalscore << endl << endl;
		Sleep(1500);
		if (stu[i].highmaths >= 60 && stu[i].english >= 60 && stu[i].linear >= 60 && stu[i].cpp >= 60
			&& stu[i].gailv >= 60 && stu[i].ddca >= 60 && stu[i].pe >= 60 && stu[i].history >= 60
			&& stu[i].policy >= 60)
		{
			cout << "成绩方面：   ";
			cout << "该同学没有挂科记录，各科均通过！ " << endl << endl;

			Sleep(1500);
			if (stu[i].pe >= 75)
			{
				cout << "体测方面： ";
				cout << "体测高于75分，有获得奖学金的资格！  " << endl << endl;
				Sleep(1500);


				percent = stu[i].order / n;
				if (stu[i].order == 1)
				{
					cout << "恭喜你获得国家奖学金！ " << endl << endl;
					Sleep(2000);



				}
				else
				{
					if (percent > 0 && percent <= 0.1)//除了国奖的排名前0 - 10%
					{
						cout << "恭喜你获得校一等奖学金!  " << endl << endl;
						Sleep(2000);


					}
					else if (percent > 0.1 && percent <= 0.2)//10 - 20%
					{
						cout << "恭喜你获得校二等奖学金!  " << endl << endl;
						Sleep(2000);


					}
					else if (percent > 0.2 && percent <= 0.3)//20% - 30%
					{
						cout << "恭喜你获得校三等奖学金！ " << endl << endl;
						Sleep(2000);


					}
					else
					{
						cout << "未获得奖学金，再接再厉！  " << endl << endl;
						Sleep(2000);


					}


				}
			}
			else
			{
				cout << "尽管成绩达标，但是体测不合格，无法获得奖学金！  " << endl << endl;
			}
		}
		else
		{
			cout << "存在挂科记录，不可获得奖学金！ " << endl << endl;
		}


	}
	system("pause");
}



//输出学生的成绩(按照学号排序)
void Output(Student stu[])
{
	system("cls");
	int i;
	int j;
	int k;
	double s;
	string tmp;

	cout << endl << "==========>>\t\t学号排序\t\t<<===========" << endl;
	int n = Read(stu);
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			if (convert(stu[j].ID) > convert(stu[j + 1].ID))
			{
				tmp = stu[j + 1].ID;
				stu[j + 1].ID = stu[j].ID;
				stu[j].ID = tmp;

				tmp = stu[j + 1].name;
				stu[j + 1].name = stu[j].name;
				stu[j].name = tmp;

				tmp = stu[j + 1].password;
				stu[j + 1].password = stu[j].password;
				stu[j].password = tmp;

				s = stu[j + 1].highmaths;
				stu[j + 1].highmaths = stu[j].highmaths;
				stu[j].highmaths = s;

				s = stu[j + 1].english;
				stu[j + 1].english = stu[j].english;
				stu[j].english = s;

				s = stu[j + 1].linear;
				stu[j + 1].linear = stu[j].linear;
				stu[j].linear = s;

				s = stu[j + 1].cpp;
				stu[j + 1].cpp = stu[j].cpp;
				stu[j].cpp = s;

				s = stu[j + 1].gailv;
				stu[j + 1].gailv = stu[j].gailv;
				stu[j].gailv = s;

				s = stu[j + 1].ddca;
				stu[j + 1].ddca = stu[j].ddca;
				stu[j].ddca = s;

				s = stu[j + 1].pe;
				stu[j + 1].pe = stu[j].pe;
				stu[j].pe = s;

				s = stu[j + 1].history;
				stu[j + 1].history = stu[j].history;
				stu[j].history = s;

				s = stu[j + 1].policy;
				stu[j + 1].policy = stu[j].policy;
				stu[j].policy = s;

				s = stu[j + 1].totalscore;
				stu[j + 1].totalscore = stu[j].totalscore;
				stu[j].totalscore = s;



			}
		}
	}
	cout << "-------------------------------------------------------------------------------------------" << endl;
	cout << "学号" << "\t" << "姓名" << "\t"
		<< "数分" << "\t" << "大英" << "\t" << "线代" << "\t"
		<< "C++" << "\t" << "概率论" << "\t" << "数电" << "\t"
		<< "体育" << "\t" << "近代史\t" << "思修" << "\t"
		<< "GPA" << endl;
	cout << "---------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < n; i++)
	{

		cout << stu[i].ID << "\t" << stu[i].name << "\t"
			<< stu[i].highmaths << "\t" << stu[i].english << "\t" << stu[i].linear << "\t"
			<< stu[i].cpp << "\t" << stu[i].gailv << "\t" << stu[i].ddca << "\t"
			<< stu[i].pe << "\t" << stu[i].history << "\t" << stu[i].policy
			<< "\t" << stu[i].totalscore << endl;
	}
	Write(stu, n);
	system("pause");

}


