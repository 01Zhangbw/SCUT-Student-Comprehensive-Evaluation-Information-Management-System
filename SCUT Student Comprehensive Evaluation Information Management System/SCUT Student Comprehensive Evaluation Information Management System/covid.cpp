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

//�����
vector<int> random(int n)//����һ����0 ~n-1��vector������������� 
{
	vector<int> temp;
	for (int i = 0; i < n; i++)
		temp.push_back(i);
	random_shuffle(temp.begin(), temp.end());
	return temp;
}
void printCovidMenu(int a)//��ӡ����˵�
{
	system("cls");
	char name[50] = { "CovidMenu.txt" };
	inFile(name);
	switch (a)
	{
	case 1:
		printCursor(80, 15);
		break;
	case 2:
		printCursor(80, 19);
		break;

	case 3:
		printCursor(80, 23);
		break;
	case 4:
		printCursor(80, 27);
		break;
	default:
		break;

	}

}
//������
void covid(Student user)//����˵�
{
	int a;
	while (1)
	{
		a = chooseOption(5, printCovidMenu);
		switch (a)
		{
		case 1:
			exam(user);
			continue;
		case 2:

			rankings();
			continue;
		case 3:

			picture();
			continue;
		case 4:

			checkpicture();
			continue;
		default:
			break;

		}
		break;
	}
}
//����
void exam(Student user) {
	system("cls");//����
	ifstream ifs;//����һ��ifstream�Ķ���
	vector<string> vec;//
	vector<Info> info;//����һ���洢������Ϣ������

	readTest(ifs, vec, info);//��ȡ��������

	int key, num, a, b;
	int i = 0;
	float score = 0;//��ʼ��������ֵΪ0
	vector<int>wrongID;


	cout << "--------------------------Start------------------------------" << endl;//��ʼ����
	cout << "��������Ŀ����: ";//��ʾ�û������Լ���������������û��Զ��壬����ѡ��������Ŀ���������迼��һ�������ɶ�
	fflush(stdin);//���������
	cin >> num;//�û����������������
	int total = info.size();//ͳ��������Ŀ
	srand(time(NULL));
	vector<int> ii = random(total);//����һ��0 ~ n-1����������� ��nΪ�������Ŀ��������

	cout << "����������Կ�ʼ!" << endl;//��ʾ�û��������


	key = cin.get();//��ȡ���������ָ��
	if (key == 0 || key == 224 || key == 32)
		key = cin.get();
	//��ʼ
	while (i < num)
	{
		if (info[ii[i]].rightTime <= 5)//����ϵͳ�������ͣ����������Ŀ����ԵĴ���������Σ�����Ϊ����Ŀ�ѶȽ�С�����ٳ�
		{
			cout << "��" << i + 1 << "��";//i��ʾ��Ŀ��ż�1��ֵ

			cout << info[ii[i]].statement << endl;//������
			cout << info[ii[i]].optionsA << endl;//���A��
			cout << info[ii[i]].optionsB << endl;//���B��
			cout << info[ii[i]].optionsC << endl;//���C��
			cout << info[ii[i]].optionsD << endl;//���D��


			string answer;
			cout << "***������:";//��ʾ��������

			cin >> answer;//���������

			if (answer == info[ii[i]].rightAnswer) {
				score += (float)(100.0 / num);//������Ŀ����Ϊ�Զ��壬��˵�����������仯
				info[ii[i]].rightTime++;//����Ŀ����ԵĴ���++
				cout << "����ȷ!" << endl;
			}
			else {
				cout << "�𰸴���!" << endl;
				wrongID.push_back(ii[i]);//������ı��ѹ��wrongID�����У�vector��

			}
			cout << "---------��ǰ����:" << score << "��------" << endl;

			Sleep(1800);//ֹͣ1.8s
			i++;//��ת����һ��
		}
		else//����������ʱ
		{
			i++;
			num++;
		}
	}
	cout << "�������!" << endl;//��ʾ���Խ���
	cout << "��ķ�����" << score << endl;//������Եķ���
	Sleep(3000);
	system("cls");
	if (wrongID.size())//���д���ʱ��������⼰����ȷ�𰸣������û��˽��������������ܽ�
	{
		cout << "��Ĵ���Ϊ�� " << endl << endl;
		for (int i = 0; i < wrongID.size(); i++)
		{
			cout << "�� " << i + 1 << "������ :" << endl;
			cout << info[wrongID[i]].statement << endl;//������
			cout << info[wrongID[i]].optionsA << endl;//���A��
			cout << info[wrongID[i]].optionsB << endl;//���B��
			cout << info[wrongID[i]].optionsC << endl;//���C��
			cout << info[wrongID[i]].optionsD << endl;//���D��
			cout << "��ȷ����: " << info[wrongID[i]].rightAnswer << endl;//�����ȷ��
			cout << endl;
		}
	}

	else
		cout << "ȫ���ˣ�����������֪ʶ���ղ����ٽ�����Ŷ��" << endl;//��ȫ�Ե��û����й���

	char name[15] = "rankings.txt";//��ȡ���а��ļ�
	ofstream outfile(name, std::ios::app);//�������������ӵ��ļ���β


	if (!outfile.is_open()) {//�޷����ļ����쳣����
		cout << "cannot open";

		exit(0);
	}

	outfile << "ѧ�ţ�" << user.ID << " ";//д��txt�û���ѧ����Ϣ
	outfile << "���Գɼ���" << score << " ";//д��txt�û����Գɼ���Ϣ
	outfile << endl;//д����У���������
	outfile.close();

	Sleep(1800);

	system("pause");
}


void readTest(ifstream& ifs, vector<string>& vec, vector<Info>& info)
{

	Info info_1;//����һ��Info�Ķ���

	char c;
	string str;
	ifs.open("testData.txt");//��ȡtestData.txt
	int i = 0;
	while (!ifs.eof())//��txt��������ʱ��ֹͣ��ȡ����
	{
		getline(ifs, str);//��testData.txt�����ݵ�һ�и�ֵ��str

		if (str != "") {//��txt��������ʱ��ֹͣ��ȡ����

			vec.push_back(str);//��str������ѹջ��vec�����У�vector��
			i += 1;
			if (i == 1) {
				info_1.statement = str;//��iΪ1ʱ��str������Ϊ��Ŀ����ɣ���ֵ��info_1�� ��� ��һ���ݳ�Ա

			}
			if (i == 2) {
				info_1.optionsA = str;//��iΪ2ʱ��str������Ϊ��Ŀ��A���ֵ��info_1�� optionA ��һ���ݳ�Ա

			}
			if (i == 3) {
				info_1.optionsB = str;//��iΪ3ʱ��str������Ϊ��Ŀ��B���ֵ��info_1�� optionB ��һ���ݳ�Ա

			}
			if (i == 4) {
				info_1.optionsC = str;//��iΪ4ʱ��str������Ϊ��Ŀ��C���ֵ��info_1�� optionC ��һ���ݳ�Ա

			}
			if (i == 5) {
				info_1.optionsD = str;//��iΪ5ʱ��str������Ϊ��Ŀ��D���ֵ��info_1�� optionD ��һ���ݳ�Ա

			}
			if (i == 6) {
				info_1.rightAnswer = str;//��iΪ6ʱ������ȡ����ȷ����һ����
				info_1.rightTime = 0;//������е�һ����ı���Դ������г�ʼ��
			}
			if (i == 6) {
				info.push_back(info_1);//��info_1��һ����ѹ��info��
				i = 0;//���½�i��ֵ��Ϊ0������ʼ������һ����Ŀ�Ķ�ȡ
			}
			str = "";//��str�ÿ�
		}
	}
	if (ifs.is_open())
		ifs.close();//��ȡ�ļ����������󣬽���ر�
}



void rankings() {//��ʷ��¼

	system("cls");

	char name[50] = { "rankings.txt" };
	ifstream readfile(name);


	const int LINE_LENGTH = 1000;
	char str[LINE_LENGTH];
	while (readfile.getline(str, LINE_LENGTH))
	{
		cout << str << endl;//����ʷ�ɼ���ʾ�ڿ���̨
	}
	readfile.close();
	system("pause");
}