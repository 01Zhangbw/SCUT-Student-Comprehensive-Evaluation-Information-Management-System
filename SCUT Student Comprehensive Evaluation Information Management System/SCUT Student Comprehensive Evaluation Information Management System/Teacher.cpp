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
//��ʦ��ע��
void teacher_register() {//�û�ע��

	int i;
	Teacher user;

	for (i = 0; i < 3; i++) {

		system("cls");
		char name[50] = { "registerMenu.txt" };//name���������洢��׺ά��txt���ļ���
		inFile(name);//��ȡregisterMenu.txt����Ŀ�ʼҳ��
		fflush(stdin);//���������
		moveCursor(40, 14);//��λ
		cin >> user.teachID;//����ʹ���ߵ�ID
		fflush(stdin);//���������
		moveCursor(41, 16);//��λ
		cin >> user.teachname;//����ʹ���ߵ�����
		moveCursor(45, 18);//��λ
		cin >> user.teachpassword;//����ʹ���ߵ�����

		vector<Teacher> user1;
		ifstream ifs;
		vector<string> vec;
		read_teacher(ifs, vec, user1);//��ȡ��ǰtxt����Ϣ

		int boo = 0;//�൱��bool�����������ж��Ƿ���ǰ��ע��
		int ii;
		for (ii = 0; ii < user1.size(); ii++) {
			if (user1[ii].teachID == (user.teachID)) {//�û�����ͬ������ǰ�������û���ע��
				boo = 1;
				break;
			}
		}

		if (!boo) {
			moveCursor(40, 21);
			cout << "Success!";

			char name[20] = "teacherData.txt";
			ofstream outfile(name, std::ios::app);//����ofstream�Ķ���


			if (!outfile.is_open()) {
				cout << "canIDt open";
				exit(0);
			}
			outfile << user.teachID << " ";//�����ļ� ID
			outfile << user.teachname << " ";//�����ļ� �û���
			outfile << user.teachpassword << endl;//�����ļ� ����

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

//��txt�ļ�д��ʦ��Ϣ
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
//����ʦע�����Ϣ����txt
void read_teacher(ifstream& ifs, vector<string>& vec, vector<Teacher>& user)
{

	Teacher user_1;
	ifs.open("teacherData.txt");//��userData.txt
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

					user_1.teachID = (str);//��i=1�� str��ֵΪ�û���ID

				}
				if (i == 2) {

					user_1.teachname = (str);//��i=2�� str��ֵΪ�û�������
				}
				if (i == 3) {
					user_1.teachpassword = str;//��i=3�� str��ֵΪ�û�������
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

//��ʦ��¼��ҳ��
void user_teacher() {

	while (1) {
		int i;

		string get_1, get_2;
		for (i = 0; i < 1; i++)
		{

			system("cls");//����


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
		vector<Teacher> user;
		ifstream ifs;
		vector<string> vec;
		read_teacher(ifs, vec, user);

		int ii;
		bool pass = true;
		for (int jj = 0; jj < user.size(); jj++)
		{
			if (user[jj].teachID == (get_1))//�ж�������û����Ƿ���ȷ
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
			if (user[ii].teachID == (get_1)) {//���������û�����userData.txt���ݿ��д洢����ͬ�������������ж�
				if (user[ii].teachpassword == (get_2)) {//��������������userData.txt���ݿ��д洢��������ͬ
					system("cls");//����
					cout << "Success!";//��¼�ɹ���
					Sleep(800);//ͣ��8s��ʹ�û����ý������״̬

					Teacher_login(user[ii], stu);//�����ʦ��¼��Ľ���
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
//��ӡ��ʦ�˵����˵�
void printTeacherMainMenu(int a) {

	system("cls");
	char name[50] = { "teacherMenu.txt" };//teacherMenu.txt��ȡ�Ŀ�ʼ����
	inFile(name);//��txt�е�ͼƬ��ӡ��screen��

	switch (a) {
	case 1:printCursor(80, 9); break;//��ʾ���
	case 2:printCursor(80, 14); break;
	default:break;
	}
}
//��ӡ��ʦע��ҳ��
void printTeacherlogin(int a)
{
	system("cls");
	char name[50] = { "Teacherlogin.txt" };//teacherlogin.txt��ȡ�Ŀ�ʼ����
	inFile(name);

	switch (a) {
	case 1:
		printCursor(80, 9);
		break;//��ʾ���
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
		a = chooseOption(7, printTeacherlogin);//ѡ��
		switch (a) {
		case 1:
			system("cls");
			Input(stu);//¼��ѧ���ɼ�
			continue;
		case 2:
			system("cls");
			Modify(stu);//�޸�ѧ���ĳɼ�
			continue;
		case 3:
			system("cls");
			Insert(stu);//���ѧ���ĳɼ�
			continue;
		case 4:
			system("cls");
			Delete(stu);//ɾ��ѧ���ĳɼ�
			continue;
		case 5:
			system("cls");
			Output(stu);//�������ѧ����ȫ���ɼ�������ѧ�����������
			continue;
		case 6:
			system("cls");
			Sort(stu);//ѧ���ɼ������򣨰���GPA���������
			continue;

		default:
			break;
		}
		break;
	}

}

//��ѧ������Ϣд��score.txt�ļ�
void Write(Student stu[], int n)
{

	fstream ioFile;

	ioFile.open("score.txt", ios::out | ios::binary);//�������ļ�

	if (!ioFile)
	{
		cout << "the file cannot be open" << endl;
		exit(1);

	}

	int count = n;
	ioFile << count << endl << endl;

	for (int j = 0; j < n; j++)
	{
		ioFile << stu[j].ID << "\t"//ѧ��
			<< stu[j].name << "\t"//����
			<< stu[j].highmaths << "\t"//����
			<< stu[j].english << "\t"//��Ӣ
			<< stu[j].linear << "\t"//�ߴ�
			<< stu[j].cpp << "\t"//C++
			<< stu[j].gailv << "\t"//������
			<< stu[j].ddca << "\t"//�����߼�
			<< stu[j].pe << "\t"//��������⣩
			<< stu[j].history << "\t"//����ʷ
			<< stu[j].policy << "\t"//˼��
			<< stu[j].totalscore << endl;//GPA


	}
	ioFile.close();


}

//��txt�ļ������ݶ���
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
		ioFile >> stu[j].ID//ѧ��
			>> stu[j].name//����
			>> stu[j].highmaths//����
			>> stu[j].english//��Ӣ
			>> stu[j].linear//�ߴ�
			>> stu[j].cpp//C++
			>> stu[j].gailv//������
			>> stu[j].ddca//�����߼�
			>> stu[j].pe//��ѧ����
			>> stu[j].history//���ִ�ʷ
			>> stu[j].policy//˼��
			>> stu[j].totalscore;//ѧ�ּ���


	}
	ioFile.close();

	return count;


}

//����ѧ���ĳɼ�
void Input(Student stu[])
{
	system("cls");
	int  i = 0;
	bool flag;
	char sign = '0';
	cout << "=========>>\t������ѧ���ɼ�\t<<==========" << endl;
	while (sign != 'n' && sign != 'N')
	{
	loop:

		cout << "ѧ�ţ�";
		cin >> stu[i].ID;
		int c = 0;
		while (c < i)//����Ƿ��ظ�����
		{
			c++;
			if (stu[i].ID == stu[i - c].ID)
			{
				cout << "�������ѧ�Ŵ��ڣ����������� " << endl;
				goto loop;
			}
		}

		cout << "������";
		cin >> stu[i].name;
		do//ȷ������ľ�Ϊ0-100�ķ���
		{
			flag = false;
			cout << "������ѧ�����ɼ���";

			cin >> stu[i].highmaths;
			if (stu[i].highmaths > 100 || stu[i].highmaths < 0)
			{
				cout << "�Բ���������1-100֮�������" << endl;

			}
			if (stu[i].highmaths <= 100 && stu[i].highmaths >= 0)
			{
				flag = true;

			}


		} while (flag == false);

		do
		{
			flag = false;
			cout << "��ѧӢ��ɼ���";
			cin >> stu[i].english;
			if (stu[i].english > 100 || stu[i].english < 0)
			{
				cout << "�Բ���������1-100֮�������" << endl;

			}
			if (stu[i].english <= 100 && stu[i].english >= 0)
			{
				flag = true;

			}
		} while (flag == false);

		do
		{
			flag = false;
			cout << "���Դ����ɼ���";
			cin >> stu[i].linear;
			if (stu[i].linear > 100 || stu[i].linear < 0)
			{
				cout << "�Բ���������1-100֮�������" << endl;

			}
			if (stu[i].linear <= 100 && stu[i].linear >= 0)
			{
				flag = true;

			}
		} while (flag == false);

		do
		{
			flag = false;
			cout << "C++������Ƴɼ���";
			cin >> stu[i].cpp;
			if (stu[i].cpp > 100 || stu[i].cpp < 0)
			{
				cout << "�Բ���������1-100֮�������" << endl;

			}
			if (stu[i].cpp <= 100 && stu[i].cpp >= 0)
			{
				flag = true;

			}
		} while (flag == false);


		do
		{
			flag = false;
			cout << "������������ͳ�Ƴɼ���";
			cin >> stu[i].gailv;
			if (stu[i].gailv > 100 || stu[i].gailv < 0)
			{
				cout << "�Բ���������1-100֮�������" << endl;

			}
			if (stu[i].gailv <= 100 && stu[i].gailv >= 0)
			{
				flag = true;

			}
		} while (flag == false);


		do
		{
			flag = false;
			cout << "�����߼��ɼ��� ";
			cin >> stu[i].ddca;
			if (stu[i].ddca > 100 || stu[i].ddca < 0)
			{
				cout << "�Բ���������1-100֮�������" << endl;

			}
			if (stu[i].ddca <= 100 && stu[i].ddca >= 0)
			{
				flag = true;

			}
		} while (flag == false);


		do
		{
			flag = false;
			cout << "��ѧ�����ɼ���";
			cin >> stu[i].pe;
			if (stu[i].pe > 100 || stu[i].pe < 0)
			{
				cout << "�Բ���������1-100֮�������" << endl;

			}
			if (stu[i].pe <= 100 && stu[i].pe >= 0)
			{
				flag = true;

			}
		} while (flag == false);


		do
		{
			flag = false;
			cout << "���ִ�ʷ��Ҫ�ɼ���";
			cin >> stu[i].history;
			if (stu[i].history > 100 || stu[i].history < 0)
			{
				cout << "�Բ���������1-100֮�������" << endl;

			}
			if (stu[i].history <= 100 && stu[i].history >= 0)
			{
				flag = true;

			}
		} while (flag == false);

		do
		{
			flag = false;
			cout << "˼������뷨�γɼ��� ";
			cin >> stu[i].policy;
			if (stu[i].policy > 100 || stu[i].policy < 0)
			{
				cout << "�Բ���������1-100֮�������" << endl;

			}
			if (stu[i].policy <= 100 && stu[i].policy >= 0)
			{
				flag = true;

			}
		} while (flag == false);
		//����ѧ�ּ���
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

		cout << "=========>>��ʾ�� �Ƿ����д��д��ѧ���ɼ� �� ��Y / N��";//ѯ���Ƿ����
		cin >> sign;
		++i;

	}
	Write(stu, i);//д��txt

}


//screen�������ѧ����GPA//����ѧ����GPA//��ϵͳ��δʹ�øú���
void Statistic(Student stu[])
{
	system("cls");
	int n = Read(stu);
	cout << endl;
	cout << "==========>>\t\t���ѧ��ͳ������\t\t<<============" << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << "\t" << "ѧ��\t" << "����\t" << "GPA\t";
	cout << endl;
	cout << "------------------------------------------------------" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "\t" << stu[i].ID << "\t" << stu[i].name << "\t" << stu[i].totalscore << endl;

	}
	cout << "------------------------------------------------------" << endl;
	system("pause");

}

void SortFun(Student stu[])//��GPA����
{
	int i;
	int j;
	int k;
	double s;
	string tmp;
	int n = Read(stu);//��ȡscoore.txt�е�ѧ������
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			if (stu[j].totalscore < stu[j + 1].totalscore)
			{//����
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
	Write(stu, n);//����д��score.txt
	for (int i = 0; i < n; i++)
	{
		stu[i].order = i + 1;//ȷ��������Ա���������

	}
}

//����ѧ���ɼ�//Teachet&Student
void Lookup(Student stu[])
{
	system("cls");
	int n = Read(stu);
	string s;
	int i = 0;
	cout << endl;
	cout << "==========================>>\t\t���Ƴɼ���ѯ\t\t<<=========================" << endl << endl;
	cout << "=========================>>\t\t��ѯ\t\t<<==============================" << endl;
	system("pause");
	Sleep(1500);
	//cout << "������Ҫ����ѧ����ѧ��";
	//cin >> s;
	while ((stu[i].ID != tmpKey) && i < n)//���Ƿ��и�ѧ��
	{
		i++;

	}
	if (i == n)
	{
		cout << "==========>>\t\t�Բ����޷��ҵ���ѧ��\t\t<<============" << endl;

	}
	else
	{
		cout << endl << endl << endl;
		cout << "ѧ��\t" << stu[i].ID << endl << endl;
		cout << "����\t" << stu[i].name << endl << endl;
		cout << "������ѧ����\t" << stu[i].highmaths << endl << endl;
		cout << "��ѧӢ��\t" << stu[i].english << endl << endl;
		cout << "���Դ���\t" << stu[i].linear << endl << endl;
		cout << "C++�������\t" << stu[i].cpp << endl << endl;
		cout << "����������ͳ��\t" << stu[i].gailv << endl << endl;
		cout << "�����߼�\t" << stu[i].ddca << endl << endl;
		cout << "��ѧ����\t" << stu[i].pe << endl << endl;
		cout << "���ִ�ʷ\t" << stu[i].history << endl << endl;
		cout << "˼������뷨��\t" << stu[i].policy << endl << endl;

	}

	system("pause");
}
//����ѧ��GPA//Teachet&Student
void Lookup_GPA(Student stu[])
{
	system("cls");
	SortFun(stu);
	int n = Read(stu);
	string str;
	int ii = 0;

	cout << endl;
	//cout << "============>>\t\t����ѧ���ɼ�\t\t<<============" << endl;
	//cout << "������Ҫ����ѧ����ѧ��";
	//cin >> str;
	cout << "==========================>>\t\t���Ƴɼ���ѯ\t\t<<=========================" << endl;
	cout << endl;
	cout << "=========================>>\t\tGPA��ѯ\t\t<<==============================" << endl;
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
		cout << endl << endl << endl;
		cout << "ѧ��\t" << stu[ii].ID << endl << endl;
		cout << "����\t" << stu[ii].name << endl << endl;
		cout << "GPA\t" << stu[ii].totalscore << endl << endl;
		cout << "����\t" << stu[ii].order << " / " << n << endl << endl;

	}

	system("pause");
}

//�޸�ѧ���ɼ�//Teacher
void Modify(Student stu[])
{
	system("cls");
	int n = Read(stu);
	string s;
	bool flag;
	int i = 0;
	cout << endl;
	cout << "===========>>\t\t�޸�ѧ���ɼ�\t\t<<=============" << endl;
	cout << "������Ҫ�޸ĳɼ�ѧ����ѧ�ţ� ";
	cin >> s;
	while (stu[i].ID != s && i < n)
	{
		i++;

	}
	if (i == n)
	{
		cout << "================>>\t\t�Բ����޷��ҵ���ѧ��\t\t<<===================";
		cout << endl;
	}
	else
	{
		cout << "------------------------------------------------------------------------------------" << endl;
		cout << "ѧ��" << "\t" << "����" << "\t"
			<< "����" << "\t" << "��Ӣ" << "\t" << "�ߴ�" << "\t"
			<< "C++" << "\t" << "������" << "\t" << "����" << "\t"
			<< "����" << "\t" << "����ʷ\t" << "˼��" << "\t"
			<< "GPA" << "\t" << endl;
		cout << "------------------------------------------------------------------------------------" << endl;
		cout << stu[i].ID << "\t" << stu[i].name << "\t"
			<< stu[i].highmaths << "\t" << stu[i].english << "\t" << stu[i].linear << "\t"
			<< stu[i].cpp << "\t" << stu[i].gailv << "\t" << stu[i].ddca << "\t"
			<< stu[i].pe << "\t" << stu[i].history << "\t" << stu[i].policy
			<< "\t" << stu[i].totalscore << endl;
		cout << endl << "�����������ѧ���ɼ��� " << endl;
		do
		{
			flag = false;
			cout << "������ѧ�����ɼ���";

			cin >> stu[i].highmaths;
			if (stu[i].highmaths > 100 || stu[i].highmaths < 0)
			{
				cout << "�Բ���������1-100֮�������" << endl;

			}
			if (stu[i].highmaths <= 100 && stu[i].highmaths >= 0)
			{
				flag = true;

			}


		} while (flag == false);

		do
		{
			flag = false;
			cout << "��ѧӢ��ɼ���";
			cin >> stu[i].english;
			if (stu[i].english > 100 || stu[i].english < 0)
			{
				cout << "�Բ���������1-100֮�������" << endl;

			}
			if (stu[i].english <= 100 && stu[i].english >= 0)
			{
				flag = true;

			}
		} while (flag == false);

		do
		{
			flag = false;
			cout << "���Դ����ɼ���";
			cin >> stu[i].linear;
			if (stu[i].linear > 100 || stu[i].linear < 0)
			{
				cout << "�Բ���������1-100֮�������" << endl;

			}
			if (stu[i].linear <= 100 && stu[i].linear >= 0)
			{
				flag = true;

			}
		} while (flag == false);

		do
		{
			flag = false;
			cout << "C++������Ƴɼ���";
			cin >> stu[i].cpp;
			if (stu[i].cpp > 100 || stu[i].cpp < 0)
			{
				cout << "�Բ���������1-100֮�������" << endl;

			}
			if (stu[i].cpp <= 100 && stu[i].cpp >= 0)
			{
				flag = true;

			}
		} while (flag == false);


		do
		{
			flag = false;
			cout << "������������ͳ�Ƴɼ���";
			cin >> stu[i].gailv;
			if (stu[i].gailv > 100 || stu[i].gailv < 0)
			{
				cout << "�Բ���������1-100֮�������" << endl;

			}
			if (stu[i].gailv <= 100 && stu[i].gailv >= 0)
			{
				flag = true;

			}
		} while (flag == false);


		do
		{
			flag = false;
			cout << "�����߼��ɼ��� ";
			cin >> stu[i].ddca;
			if (stu[i].ddca > 100 || stu[i].ddca < 0)
			{
				cout << "�Բ���������1-100֮�������" << endl;

			}
			if (stu[i].ddca <= 100 && stu[i].ddca >= 0)
			{
				flag = true;

			}
		} while (flag == false);


		do
		{
			flag = false;
			cout << "��ѧ�����ɼ���";
			cin >> stu[i].pe;
			if (stu[i].pe > 100 || stu[i].pe < 0)
			{
				cout << "�Բ���������1-100֮�������" << endl;

			}
			if (stu[i].pe <= 100 && stu[i].pe >= 0)
			{
				flag = true;

			}
		} while (flag == false);


		do
		{
			flag = false;
			cout << "���ִ�ʷ��Ҫ�ɼ���";
			cin >> stu[i].history;
			if (stu[i].history > 100 || stu[i].history < 0)
			{
				cout << "�Բ���������1-100֮�������" << endl;

			}
			if (stu[i].history <= 100 && stu[i].history >= 0)
			{
				flag = true;

			}
		} while (flag == false);

		do
		{
			flag = false;
			cout << "˼������뷨�γɼ��� ";
			cin >> stu[i].policy;
			if (stu[i].policy > 100 || stu[i].policy < 0)
			{
				cout << "�Բ���������1-100֮�������" << endl;

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
		cout << "=========>>\t\t�Ƿ񱣴�����\t\t(y / n)";//ѯ���Ƿ񱣴��޸ĺ����Ϣ
		cin >> key;
		if (key != 'n' && key != 'N')
		{
			Write(stu, n);//����д��

		}




	}

}

//���������ַ���//��Ϊstring����
void strSwap(string& a, string& b)///���������ַ���
{
	string tmpa = a;
	a = b;
	b = tmpa;

}

//ɾ��ѧ���ĳɼ�//Teacher
void Delete(Student stu[])
{
	system("cls");
	int n = Read(stu);
	string s;
	int i = 0;
	int j;
	cout << endl;
	cout << "===========>>\t\tɾ��ѧ���ɼ�\t\t<<==================" << endl;
	cout << "������Ҫɾ����ѧ����ѧ�ţ� ";
	cin >> s;
	while (stu[i].ID != s && i < n)
	{
		i++;

	}
	if (i == n)
	{
		cout << "==============>>\t\t�Բ����޷��ҵ���ѧ��\t\t<<===============";
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
		cout << "==============>>\t\t��ʾ���ѳɹ�ɾ���� " << endl;

	}
	Write(stu, n - 1);//д��txt��ע��˴���n-1����Ϊ��ɾ��ѡ���˵���Ϣ


}

//���루ʹ�ð༶���������ӣ�//Teacher
void Insert(Student stu[])
{

	system("cls");
	int n = Read(stu);//ֱ�Ӷ�λ����n��ͬѧ��ʵ�ֺ���Ĳ���
	int i = 0;
	bool flag;

	char s = '0';
	cout << endl;
	cout << "=======================>>\t\t����ѧ���ɼ�\t\t<<=====================" << endl;
	while (s != 'n' && s != 'N')
	{
	loop:

		cout << "ѧ�ţ�";
		cin >> stu[n].ID;
		int c = 0;
		while (c < n)
		{
			c++;
			if (stu[n].ID == stu[n - c].ID)
			{
				cout << "�������ѧ�Ŵ��ڣ����������� " << endl;
				goto loop;
			}
		}
		cout << "������";
		cin >> stu[n].name;
		do
		{
			flag = false;
			cout << "������ѧ�����ɼ��� ";

			cin >> stu[n].highmaths;
			if (stu[n].highmaths > 100 || stu[n].highmaths < 0)
			{
				cout << "�Բ���������1-100֮�������" << endl;

			}
			if (stu[n].highmaths <= 100 && stu[n].highmaths >= 0)
			{
				flag = true;

			}


		} while (flag == false);

		do
		{
			flag = false;
			cout << "��ѧӢ��ɼ��� ";
			cin >> stu[n].english;
			if (stu[n].english > 100 || stu[n].english < 0)
			{
				cout << "�Բ���������1-100֮�������" << endl;

			}
			if (stu[n].english <= 100 && stu[n].english >= 0)
			{
				flag = true;

			}
		} while (flag == false);

		do
		{
			flag = false;
			cout << "���Դ����ɼ��� ";
			cin >> stu[n].linear;
			if (stu[n].linear > 100 || stu[n].linear < 0)
			{
				cout << "�Բ���������1-100֮�������" << endl;

			}
			if (stu[n].linear <= 100 && stu[n].linear >= 0)
			{
				flag = true;

			}
		} while (flag == false);

		do
		{
			flag = false;
			cout << "C++������Ƴɼ��� ";
			cin >> stu[n].cpp;
			if (stu[n].cpp > 100 || stu[n].cpp < 0)
			{
				cout << "�Բ���������1-100֮�������" << endl;

			}
			if (stu[n].linear <= 100 && stu[n].linear >= 0)
			{
				flag = true;

			}
		} while (flag == false);


		do
		{
			flag = false;
			cout << "������������ͳ�Ƴɼ��� ";
			cin >> stu[n].gailv;
			if (stu[n].gailv > 100 || stu[n].gailv < 0)
			{
				cout << "�Բ���������1-100֮�������" << endl;

			}
			if (stu[n].gailv <= 100 && stu[n].gailv >= 0)
			{
				flag = true;

			}
		} while (flag == false);


		do
		{
			flag = false;
			cout << "�����߼��ɼ��� ";
			cin >> stu[n].ddca;
			if (stu[n].ddca > 100 || stu[n].ddca < 0)
			{
				cout << "�Բ���������1-100֮�������" << endl;

			}
			if (stu[n].ddca <= 100 && stu[n].ddca >= 0)
			{
				flag = true;

			}
		} while (flag == false);


		do
		{
			flag = false;
			cout << "��ѧ�����ɼ��� ";
			cin >> stu[n].pe;
			if (stu[n].pe > 100 || stu[n].pe < 0)
			{
				cout << "�Բ���������1-100֮�������" << endl;

			}
			if (stu[n].pe <= 100 && stu[n].pe >= 0)
			{
				flag = true;

			}
		} while (flag == false);


		do
		{
			flag = false;
			cout << "���ִ�ʷ��Ҫ�ɼ��� ";
			cin >> stu[n].history;
			if (stu[n].history > 100 || stu[n].history < 0)
			{
				cout << "�Բ���������1-100֮�������" << endl;

			}
			if (stu[n].history <= 100 && stu[n].history >= 0)
			{
				flag = true;

			}
		} while (flag == false);

		do
		{
			flag = false;
			cout << "˼������뷨�γɼ��� ";
			cin >> stu[n].policy;
			if (stu[n].policy > 100 || stu[n].policy < 0)
			{
				cout << "�Բ���������1-100֮�������" << endl;

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
		//����GPA

		cout << "GPA: " << stu[n].totalscore << endl;
		n++;
		cout << "=========>>\t\t�Ƿ�������루y/n��";
		cin >> s;
	}

	Write(stu, n);//д����Ϣ

}
//����
void Sort(Student stu[])//��GPA ����
{
	system("cls");
	int i;
	int j;
	int k;
	double s;
	string tmp;

	cout << endl << "==========>>\t\t��������\t\t<<===========" << endl;
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
	cout << "ѧ��" << "\t" << "����" << "\t"
		<< "����" << "\t" << "��Ӣ" << "\t" << "�ߴ�" << "\t"
		<< "C++" << "\t" << "������" << "\t" << "����" << "\t"
		<< "����" << "\t" << "����ʷ\t" << "˼��" << "\t"
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

void zongce(Student stu[])//�۲�
{
	system("cls");
	SortFun(stu);
	int n = Read(stu);//txt�����û�������
	string str;
	int i = 0;
	double percent;
	cout << endl;
	cout << "==========================>>\t\t�۲����Ų�ѯ\t\t<<=========================" << endl << endl;
	cout << "=========================>>\t\t��ѯ\t\t<<==============================" << endl << endl;
	system("pause");
	Sleep(1500);
	while ((stu[i].ID != tmpKey) && i < n)
	{
		i++;

	}
	if (i == n)
	{
		cout << "==========>>\t\t�Բ����޷��ҵ���ѧ��\t\t<<============" << endl;

	}
	//��ѧ��ǰ���Ǹ���60+�Լ����75+
	else
	{
		cout << endl << endl << endl;
		cout << "ѧ��\t" << stu[i].ID << endl << endl;
		cout << "����\t" << stu[i].name << endl << endl;
		cout << "GPA\t" << stu[i].totalscore << endl << endl;
		Sleep(1500);
		if (stu[i].highmaths >= 60 && stu[i].english >= 60 && stu[i].linear >= 60 && stu[i].cpp >= 60
			&& stu[i].gailv >= 60 && stu[i].ddca >= 60 && stu[i].pe >= 60 && stu[i].history >= 60
			&& stu[i].policy >= 60)
		{
			cout << "�ɼ����棺   ";
			cout << "��ͬѧû�йҿƼ�¼�����ƾ�ͨ���� " << endl << endl;

			Sleep(1500);
			if (stu[i].pe >= 75)
			{
				cout << "��ⷽ�棺 ";
				cout << "������75�֣��л�ý�ѧ����ʸ�  " << endl << endl;
				Sleep(1500);


				percent = stu[i].order / n;
				if (stu[i].order == 1)
				{
					cout << "��ϲ���ù��ҽ�ѧ�� " << endl << endl;
					Sleep(2000);



				}
				else
				{
					if (percent > 0 && percent <= 0.1)//���˹���������ǰ0 - 10%
					{
						cout << "��ϲ����Уһ�Ƚ�ѧ��!  " << endl << endl;
						Sleep(2000);


					}
					else if (percent > 0.1 && percent <= 0.2)//10 - 20%
					{
						cout << "��ϲ����У���Ƚ�ѧ��!  " << endl << endl;
						Sleep(2000);


					}
					else if (percent > 0.2 && percent <= 0.3)//20% - 30%
					{
						cout << "��ϲ����У���Ƚ�ѧ�� " << endl << endl;
						Sleep(2000);


					}
					else
					{
						cout << "δ��ý�ѧ���ٽ�������  " << endl << endl;
						Sleep(2000);


					}


				}
			}
			else
			{
				cout << "���ܳɼ���꣬������ⲻ�ϸ��޷���ý�ѧ��  " << endl << endl;
			}
		}
		else
		{
			cout << "���ڹҿƼ�¼�����ɻ�ý�ѧ�� " << endl << endl;
		}


	}
	system("pause");
}



//���ѧ���ĳɼ�(����ѧ������)
void Output(Student stu[])
{
	system("cls");
	int i;
	int j;
	int k;
	double s;
	string tmp;

	cout << endl << "==========>>\t\tѧ������\t\t<<===========" << endl;
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
	cout << "ѧ��" << "\t" << "����" << "\t"
		<< "����" << "\t" << "��Ӣ" << "\t" << "�ߴ�" << "\t"
		<< "C++" << "\t" << "������" << "\t" << "����" << "\t"
		<< "����" << "\t" << "����ʷ\t" << "˼��" << "\t"
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


