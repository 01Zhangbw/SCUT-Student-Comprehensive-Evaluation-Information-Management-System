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
		double policy_rate = 2.5, double totalrate = 0.0, int order = 1, string content = "  ");//Ĭ�Ϲ��캯��.
	//���Ƶ�ѧ��Ĭ��ֵ���Ҳ��ı�
	//set����
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

	//���ݳ�Ա
	string ID;//�û���

	string name;//����

	string password;//����

	double highmaths;//����
	double highmaths_rate;//����ѧ��

	double english;//��ѧӢ��
	double english_rate;//��ѧӢ��ѧ��

	double linear;////���Դ���
	double linear_rate;//���Դ���ѧ��

	double cpp;//C++
	double cpp_rate;//C++ѧ��

	double gailv;//������
	double gailv_rate;//������ѧ��

	double ddca;//�����߼�
	double ddca_rate;//�����߼�ѧ��

	double pe;//��ѧ����
	double pe_rate;//��ѧ����ѧ��

	double history;//���ִ�ʷ
	double history_rate;//���ִ�ʷѧ��

	double policy;//˼������뷨��
	double policy_rate;//˼�޵����뷨��ѧ��


	double totalscore;//ѧ�ּ���
	double totalrate;//��ѧ��

	//����
	int order;
	//������ĵ�����
	string content;



};
extern Student stu[100];//ȫ�ֱ�������extern����ͬ����cpp�л���г�ʼ��

extern string tmpKey;//ȫ�ֱ�������ȡѧ���˺���һ��Ϣ

class Teacher
{
public:
	Teacher(const string& a = " ", const string& b = " ", const string& c = " ");//Ĭ�Ϲ��캯��

	string teachID;//�û���

	string teachname;//����

	string teachpassword;//����
};


class Info {//����������Ŀ��Ϣ
public:
	string rightAnswer;//��ȷѡ��
	string optionsA;//ѡ��A
	string optionsB;//ѡ��B
	string optionsC;//ѡ��C
	string optionsD;//ѡ��D
	string statement;//��Ŀ����
	int rightTime;//��ԵĴ���

};





//�������
void rankings();//������Ե���Ϣ��ѯ
void write_user(Student user);
void printCursor(int x, int y);
void _register();//ѧ��ע��
int chooseOption(int num, void (*p)(int));//ѡ��
void read(ifstream& ifs, vector<string>& vec, vector<Student>& user);//��
void user();//ѧ����¼

void gpa(Student user);//GPA���
void moveCursor(int x, int y);//�ƶ����
void inFile(char name[15]);//��txt��һ��һ�ж�ȡ������ӡ����Ļ�ϣ��������txt���汣���ͼ������������߳�
void printMainMenu(int a);//��ӡ���˵�

void covid(Student user);//������
int main();//main
void printGPAMenu(int a);//��ӡGPA�˵�


void exam(Student user);//���鿼��

void readTest(ifstream& ifs, vector<string>& vec, vector<Info>& info);//��ȡ���Ե���Ϣ
void Student_login(Student user);//ѧ����¼֮���ҳ��
vector<int> random(int n);//���������
void printCovidMenu(int a);//��ӡ����ҳ��
void printStudentlogin(int);//��ӡѧ����¼֮���ҳ��
void printtcMenu(int a);//��ӡ���ҳ��
void tc(Student user);//������


//Teacher
void Teacher_login(Teacher user, Student stu[]);//��ʦ��¼
void printTeacherlogin(int a);//��ӡ��ʦ��¼���ҳ��
void user_teacher();//��ʦ��¼
void read_teacher(ifstream& ifs, vector<string>& vec, vector<Teacher>& user);//��txt�ļ�����screen
void write_teacher(Teacher user); //д�û���Ϣ��txt�ļ�
void teacher_register();//��ʦע��

void printMainMenu(int a);//��ӡ���˵�

void Write(Student stu[], int count);//д��score.txt
int Read(Student stu[]);//��score.txt��Ϣ��int����������txt������û�������
void Input(Student stu[]);//����ѧ����Ϣ
void Statistic(Student stu[]);//ͳ��GPA����δʹ�øú���
void Lookup(Student stu[]);//��ѯ�ɼ�
void Sort(Student stu[]);//����д��
void Output(Student stu[]);//��ѧ���������
void Insert(Student stu[]);//����ѧ����Ϣ
void Delete(Student stu[]);//ɾ��ѧ����Ϣ
void strSwap(string& a, string& b);//���������ַ���
void Modify(Student stu[]);//�޸�ѧ����Ϣ
void Lookup_GPA(Student stu[]);//��ѯGPA
long long convert(string s);//stringת��Ϊlong long
void SortFun(Student stu[]);//GPA����
void zongce(Student stu[]);//�۲�
void Lookup_tc(Student stu[]);//��ѯ���


void printMenu2(int a);

void printStudentMenu(int a);
void printTeacherMenu(int a);
void printMainMenu(int a);
void mainTeacher(Teacher user);
void mainStudent(Student stu);

void picture();
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)  //������ⰴ���ĵ���¼�
//�������λ��
extern int chang[1000];//x
extern int kuan[1000];//y

extern POINT p;
extern HANDLE hOutput;
extern HWND h;
extern CONSOLE_FONT_INFO consoleCurrentFont;
//����ʱ��
extern int year;
extern int month;
extern int day;
extern int hour;
extern int minute;
extern int second;
extern int dayofweek;
//----------�ƶ����----------
void gotoxy(int x, int y);

//----------���ع��----------
void HideTheCursor();

void getnowTime();//��ȡ����ʱ��
void printnowTime();//��ӡ����ʱ��

void checkpicture();//������������

//tc

void DailyOutput();//����ĵ���������
void DailyInput();//����ĵ�����д��
void Advice(Student stu[]);//����

extern int count_1;//��ͼ����������
//����ĵõ�ʱ��
extern int yeartc;
extern int monthtc;
extern int daytc;
extern int hourtc;
extern int minutetc;
extern int secondtc;
extern int dayofweektc;

//void getnowtcTime();//��ȡ����ĵ�ʱ��


#endif