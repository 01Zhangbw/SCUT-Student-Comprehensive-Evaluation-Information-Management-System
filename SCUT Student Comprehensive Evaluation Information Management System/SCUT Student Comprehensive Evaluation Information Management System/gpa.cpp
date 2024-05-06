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

void printGPAMenu(int a)//打印GPA菜单
{
	system("cls");
	char name[50] = { "GPAMenu.txt" };//Studentlogin.txt存取的开始界面
	inFile(name);

	switch (a)
	{
	case 1:
		printCursor(80, 8);
		break;//显示光标
	case 2:
		printCursor(80, 13);
		break;
	case 3:
		printCursor(80, 18);
		break;
	default:break;
	}

}

//gpa板块
void gpa(Student user)//GPA 板块
{
	int a;
	while (1)
	{
		a = chooseOption(4, printGPAMenu);
		switch (a)
		{
		case 1:

			Lookup(stu);//查询各科成绩
			continue;
		case 2:

			Lookup_GPA(stu);//查询GPA
			continue;
		case 3:

			zongce(stu);//综测评定
			continue;

		default:
			break;

		}
		break;
	}
}

Teacher::Teacher(const string& teachIDs, const string& teachnames, const string& teachpasswords) //教师类的初始化
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
	double policy_rates, double totalrates, int orders, string contents)//学生类的初始化
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
long long convert(string  s)//用于string类型转化long long 类型，用于学号之间的比较大小
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

void Student::setID(const string& str)//学生学号
{
	ID = str;



}
void Student::setname(const string& str)//学生名字
{
	name = str;


}
void Student::setpassword(const string& str)//学生密码
{
	password = str;


}

void Student::setmaths(double maths)//数分
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

void Student::seteng(double e)//英语
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
void Student::setlin(double l)//线代
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
void Student::setgll(double maths)//概率论
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
void Student::setddca(double maths)//数字逻辑
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
void Student::setpe(double maths)//体育，此系统以体育成绩作为体测成绩
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
void Student::sethis(double maths)//近代史
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
void Student::setpol(double maths)//思想道德与法治
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
void Student::settotalscore(double maths)//总学分绩点
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

