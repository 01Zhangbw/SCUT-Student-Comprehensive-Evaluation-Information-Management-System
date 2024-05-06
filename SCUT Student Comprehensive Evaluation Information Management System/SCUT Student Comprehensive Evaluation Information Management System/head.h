#pragma once
#ifndef HEAD_H
#define HEAD_H
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
#include<array>
#include<ctime>
#include<time.h>



using namespace std;

class Student
{
public:

	Student(const string & = "  ", const string& name = "  ", const string& password = "  ",
		double = 0.0, double = 0.0, double = 0.0,
		double = 0.0, double = 0.0, double = 0.0,
		double = 0.0, double = 0.0, double = 0.0, double = 0.0,
		double highmaths_rate = 7.0, double english_rate = 3.0,
		double linear_rate = 3.0, double cpp_rate = 3.5, double gailv_rate = 3.0,
		double ddca_rate = 2.5, double pe_rate = 1.0, double history_rate = 2.5,
		double policy_rate = 2.5, double totalrate = 0.0, int order = 1, string content = "  ");//默认构造函数.
	//各科的学分默认值，且不改变
	//set函数
	void setname(const string&);
	void setpassword(const string&);
	void setID(const string&);

	void setmaths(double);
	void seteng(double);
	void setlin(double);
	void setcpp(double);
	void setgll(double);
	void setddca(double);
	void setpe(double);
	void sethis(double);
	void setpol(double);
	void settotalscore(double);

	//数据成员
	string ID;//用户名

	string name;//姓名

	string password;//密码

	double highmaths;//数分
	double highmaths_rate;//数分学分

	double english;//大学英语
	double english_rate;//大学英语学分

	double linear;////线性代数
	double linear_rate;//线性代数学分

	double cpp;//C++
	double cpp_rate;//C++学分

	double gailv;//概率论
	double gailv_rate;//概率论学分

	double ddca;//数字逻辑
	double ddca_rate;//数字逻辑学分

	double pe;//大学体育
	double pe_rate;//大学体育学分

	double history;//近现代史
	double history_rate;//近现代史学分

	double policy;//思想道德与法治
	double policy_rate;//思修道德与法治学分


	double totalscore;//学分绩点
	double totalrate;//总学分

	//排名
	int order;
	//输入的心得内容
	string content;



};
extern Student stu[100];//全局变量声明extern，在同名的cpp中会进行初始化

extern string tmpKey;//全局变量，存取学生账号这一信息

class Teacher
{
public:
	Teacher(const string& a = " ", const string& b = " ", const string& c = " ");//默认构造函数

	string teachID;//用户名

	string teachname;//姓名

	string teachpassword;//密码
};


class Info {//疫情答题的题目信息
public:
	string rightAnswer;//正确选项
	string optionsA;//选项A
	string optionsB;//选项B
	string optionsC;//选项C
	string optionsD;//选项D
	string statement;//题目描述
	int rightTime;//答对的次数

};





//疫情防控
void rankings();//疫情测试的信息查询
void write_user(Student user);
void printCursor(int x, int y);
void _register();//学生注册
int chooseOption(int num, void (*p)(int));//选择
void read(ifstream& ifs, vector<string>& vec, vector<Student>& user);//读
void user();//学生登录

void gpa(Student user);//GPA板块
void moveCursor(int x, int y);//移动光标
void inFile(char name[15]);//从txt中一行一行读取，并打印到屏幕上，用于输出txt里面保存的图案，避免代码冗长
void printMainMenu(int a);//打印主菜单

void covid(Student user);//疫情板块
int main();//main
void printGPAMenu(int a);//打印GPA菜单


void exam(Student user);//疫情考试

void readTest(ifstream& ifs, vector<string>& vec, vector<Info>& info);//读取测试的信息
void Student_login(Student user);//学生登录之后的页面
vector<int> random(int n);//随机数出题
void printCovidMenu(int a);//打印疫情页面
void printStudentlogin(int);//打印学生登录之后的页面
void printtcMenu(int a);//打印体测页面
void tc(Student user);//体测版面


//Teacher
void Teacher_login(Teacher user, Student stu[]);//教师登录
void printTeacherlogin(int a);//打印教师登录后的页面
void user_teacher();//教师登录
void read_teacher(ifstream& ifs, vector<string>& vec, vector<Teacher>& user);//将txt文件读到screen
void write_teacher(Teacher user); //写用户信息到txt文件
void teacher_register();//教师注册

void printMainMenu(int a);//打印主菜单

void Write(Student stu[], int count);//写入score.txt
int Read(Student stu[]);//读score.txt信息，int是用来返回txt保存的用户的数量
void Input(Student stu[]);//输入学生信息
void Statistic(Student stu[]);//统计GPA，并未使用该函数
void Lookup(Student stu[]);//查询成绩
void Sort(Student stu[]);//排序并写入
void Output(Student stu[]);//以学号升序输出
void Insert(Student stu[]);//插入学生信息
void Delete(Student stu[]);//删除学生信息
void strSwap(string& a, string& b);//交换两个字符串
void Modify(Student stu[]);//修改学生信息
void Lookup_GPA(Student stu[]);//查询GPA
long long convert(string s);//string转化为long long
void SortFun(Student stu[]);//GPA排序
void zongce(Student stu[]);//综测
void Lookup_tc(Student stu[]);//查询体测


void printMenu2(int a);

void printStudentMenu(int a);
void printTeacherMenu(int a);
void printMainMenu(int a);
void mainTeacher(Teacher user);
void mainStudent(Student stu);

void picture();
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)  //用来检测按键的点击事件
//保存鼠标位置
extern int chang[1000];//x
extern int kuan[1000];//y

extern POINT p;
extern HANDLE hOutput;
extern HWND h;
extern CONSOLE_FONT_INFO consoleCurrentFont;
//当地时间
extern int year;
extern int month;
extern int day;
extern int hour;
extern int minute;
extern int second;
extern int dayofweek;
//----------移动光标----------
void gotoxy(int x, int y);

//----------隐藏光标----------
void HideTheCursor();

void getnowTime();//获取当地时间
void printnowTime();//打印当地时间

void checkpicture();//疫情心声动画

//tc

void DailyOutput();//体测心得社区呈现
void DailyInput();//体测心得社区写入
void Advice(Student stu[]);//建议

extern int count_1;//作图的坐标总数
//体测心得的时间
extern int yeartc;
extern int monthtc;
extern int daytc;
extern int hourtc;
extern int minutetc;
extern int secondtc;
extern int dayofweektc;

//void getnowtcTime();//获取体测心得时间


#endif