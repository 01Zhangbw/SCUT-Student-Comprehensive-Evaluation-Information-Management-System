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

void printGPAMenu(int a)//��ӡGPA�˵�
{
	system("cls");
	char name[50] = { "GPAMenu.txt" };//Studentlogin.txt��ȡ�Ŀ�ʼ����
	inFile(name);

	switch (a)
	{
	case 1:
		printCursor(80, 8);
		break;//��ʾ���
	case 2:
		printCursor(80, 13);
		break;
	case 3:
		printCursor(80, 18);
		break;
	default:break;
	}

}

//gpa���
void gpa(Student user)//GPA ���
{
	int a;
	while (1)
	{
		a = chooseOption(4, printGPAMenu);
		switch (a)
		{
		case 1:

			Lookup(stu);//��ѯ���Ƴɼ�
			continue;
		case 2:

			Lookup_GPA(stu);//��ѯGPA
			continue;
		case 3:

			zongce(stu);//�۲�����
			continue;

		default:
			break;

		}
		break;
	}
}

Teacher::Teacher(const string& teachIDs, const string& teachnames, const string& teachpasswords) //��ʦ��ĳ�ʼ��
{
	teachID = teachIDs;
	teachname = teachnames;
	teachpassword = teachpasswords;
}

Student::Student(const string& id, const string& names, const string& passwords,
	double highmathss, double englishs, double linears, double cpps,
	double gailvs, double ddcas, double pes, double historys,
	double policys, double totalscores,
	double highmaths_rates, double english_rates,
	double linear_rates, double cpp_rates, double gailv_rates,
	double ddca_rates, double pe_rates, double history_rates,
	double policy_rates, double totalrates, int orders, string contents)//ѧ����ĳ�ʼ��
{
	setID(id);
	setname(names);
	setpassword(passwords);
	setmaths(highmathss);
	seteng(englishs);
	setlin(linears);
	setcpp(cpps);
	setgll(gailvs);
	setddca(ddcas);
	setpe(pes);
	sethis(historys);
	setpol(policys);
	settotalscore(totalscores);
	highmaths_rate = highmaths_rates;
	english_rate = english_rates;
	linear_rate = linear_rates;
	cpp_rate = cpp_rate;
	gailv_rate = gailv_rates;
	ddca_rate = ddca_rates;
	pe_rate = pe_rates;
	history_rate = history_rates;
	policy_rate = policy_rates;
	order = orders;

	content = contents;





}
long long convert(string  s)//����string����ת��long long ���ͣ�����ѧ��֮��ıȽϴ�С
{
	int num;
	long long total = 0;
	for (int i = 0; i < s.size(); i++)
	{
		num = s[i] - '0';
		total = total * 10 + num;

	}
	return total;
}

void Student::setID(const string& str)//ѧ��ѧ��
{
	ID = str;



}
void Student::setname(const string& str)//ѧ������
{
	name = str;


}
void Student::setpassword(const string& str)//ѧ������
{
	password = str;


}

void Student::setmaths(double maths)//����
{
	if (maths >= 0 && maths <= 100)
	{
		highmaths = maths;

	}
	else
	{
		cout << "the grade is 0 - 100 range! please modify it! ";
	}

}

void Student::seteng(double e)//Ӣ��
{
	if (e >= 0 && e <= 100)
	{
		english = e;

	}
	else
	{
		cout << "the grade is 0 - 100 range! please modify it! ";
	}

}
void Student::setlin(double l)//�ߴ�
{
	if (l >= 0 && l <= 100)
	{
		linear = l;

	}
	else
	{
		cout << "the grade is 0 - 100 range! please modify it! ";
	}

}
void Student::setcpp(double maths)//C++
{
	if (maths >= 0 && maths <= 100)
	{
		cpp = maths;

	}
	else
	{
		cout << "the grade is 0 - 100 range! please modify it! ";
	}

}
void Student::setgll(double maths)//������
{
	if (maths >= 0 && maths <= 100)
	{
		gailv = maths;

	}
	else
	{
		cout << "the grade is 0 - 100 range! please modify it! ";
	}

}
void Student::setddca(double maths)//�����߼�
{
	if (maths >= 0 && maths <= 100)
	{
		ddca = maths;

	}
	else
	{
		cout << "the grade is 0 - 100 range! please modify it! ";
	}

}
void Student::setpe(double maths)//��������ϵͳ�������ɼ���Ϊ���ɼ�
{
	if (maths >= 0 && maths <= 100)
	{
		pe = maths;

	}
	else
	{
		cout << "the grade is 0 - 100 range! please modify it! ";
	}

}
void Student::sethis(double maths)//����ʷ
{
	if (maths >= 0 && maths <= 100)
	{
		history = maths;

	}
	else
	{
		cout << "the grade is 0 - 100 range! please modify it! ";
	}

}
void Student::setpol(double maths)//˼������뷨��
{
	if (maths >= 0 && maths <= 100)
	{
		policy = maths;

	}
	else
	{
		cout << "the grade is 0 - 100 range! please modify it! ";
	}

}
void Student::settotalscore(double maths)//��ѧ�ּ���
{
	if (maths >= 0 && maths <= 100)
	{
		totalscore = maths;

	}
	else
	{
		cout << "the grade is 0 - 100 range! please modify it! ";
	}

}

