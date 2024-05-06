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

//随机数
vector<int> random(int n)//生成一个有0 ~n-1的vector容器随机数数组 
{
	vector<int> temp;
	for (int i = 0; i < n; i++)
		temp.push_back(i);
	random_shuffle(temp.begin(), temp.end());
	return temp;
}
void printCovidMenu(int a)//打印疫情菜单
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
//疫情板块
void covid(Student user)//疫情菜单
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
//考试
void exam(Student user) {
	system("cls");//清屏
	ifstream ifs;//创建一个ifstream的对象
	vector<string> vec;//
	vector<Info> info;//建立一个存储试题信息的容器

	readTest(ifs, vec, info);//读取试题的题库

	int key, num, a, b;
	int i = 0;
	float score = 0;//初始化分数的值为0
	vector<int>wrongID;


	cout << "--------------------------Start------------------------------" << endl;//开始答题
	cout << "请输入题目数量: ";//提示用户输入自己所答的题数。由用户自定义，自主选择所答题目数量，给予考生一定的自由度
	fflush(stdin);//清除缓冲区
	cin >> num;//用户输入所答题的数量
	int total = info.size();//统计题库的题目
	srand(time(NULL));
	vector<int> ii = random(total);//产生一个0 ~ n-1的随机数数组 （n为题库中题目的数量）

	cout << "按任意键考试开始!" << endl;//提示用户进入答题


	key = cin.get();//获取键盘输入的指令
	if (key == 0 || key == 224 || key == 32)
		key = cin.get();
	//开始
	while (i < num)
	{
		if (info[ii[i]].rightTime <= 5)//答题系统的智能型，当所答的题目被答对的次数超过五次，就认为此题目难度较小，不再出
		{
			cout << "第" << i + 1 << "题";//i表示题目编号减1的值

			cout << info[ii[i]].statement << endl;//输出题干
			cout << info[ii[i]].optionsA << endl;//输出A项
			cout << info[ii[i]].optionsB << endl;//输出B项
			cout << info[ii[i]].optionsC << endl;//输出C项
			cout << info[ii[i]].optionsD << endl;//输出D项


			string answer;
			cout << "***请作答:";//提示考生作答

			cin >> answer;//考生输入答案

			if (answer == info[ii[i]].rightAnswer) {
				score += (float)(100.0 / num);//由于题目数量为自定义，因此单题分数有所变化
				info[ii[i]].rightTime++;//该题目被答对的次数++
				cout << "答案正确!" << endl;
			}
			else {
				cout << "答案错误!" << endl;
				wrongID.push_back(ii[i]);//将错题的编号压入wrongID容器中（vector）

			}
			cout << "---------当前分数:" << score << "分------" << endl;

			Sleep(1800);//停止1.8s
			i++;//跳转到下一题
		}
		else//当智能跳题时
		{
			i++;
			num++;
		}
	}
	cout << "考试完成!" << endl;//提示考试结束
	cout << "你的分数是" << score << endl;//输出测试的分数
	Sleep(3000);
	system("cls");
	if (wrongID.size())//当有错题时，输出错题及其正确答案，帮助用户了解测试情况，便于总结
	{
		cout << "你的错题为： " << endl << endl;
		for (int i = 0; i < wrongID.size(); i++)
		{
			cout << "第 " << i + 1 << "道错题 :" << endl;
			cout << info[wrongID[i]].statement << endl;//输出题干
			cout << info[wrongID[i]].optionsA << endl;//输出A项
			cout << info[wrongID[i]].optionsB << endl;//输出B项
			cout << info[wrongID[i]].optionsC << endl;//输出C项
			cout << info[wrongID[i]].optionsD << endl;//输出D项
			cout << "正确答案是: " << info[wrongID[i]].rightAnswer << endl;//输出正确答案
			cout << endl;
		}
	}

	else
		cout << "全对了，你的疫情防控知识掌握不错，再接再厉哦！" << endl;//对全对的用户进行鼓励

	char name[15] = "rankings.txt";//读取排行榜文件
	ofstream outfile(name, std::ios::app);//将输出的数据添加到文件结尾


	if (!outfile.is_open()) {//无法打开文件的异常处理
		cout << "cannot open";

		exit(0);
	}

	outfile << "学号：" << user.ID << " ";//写入txt用户的学号信息
	outfile << "考试成绩：" << score << " ";//写入txt用户考试成绩信息
	outfile << endl;//写入空行，更加美观
	outfile.close();

	Sleep(1800);

	system("pause");
}


void readTest(ifstream& ifs, vector<string>& vec, vector<Info>& info)
{

	Info info_1;//创建一个Info的对象

	char c;
	string str;
	ifs.open("testData.txt");//读取testData.txt
	int i = 0;
	while (!ifs.eof())//当txt中无内容时，停止读取操作
	{
		getline(ifs, str);//将testData.txt的内容的一行赋值到str

		if (str != "") {//当txt中无内容时，停止读取操作

			vec.push_back(str);//将str的内容压栈到vec容器中（vector）
			i += 1;
			if (i == 1) {
				info_1.statement = str;//当i为1时，str的内容为题目的题干，赋值到info_1的 题干 这一数据成员

			}
			if (i == 2) {
				info_1.optionsA = str;//当i为2时，str的内容为题目的A项，赋值到info_1的 optionA 这一数据成员

			}
			if (i == 3) {
				info_1.optionsB = str;//当i为3时，str的内容为题目的B项，赋值到info_1的 optionB 这一数据成员

			}
			if (i == 4) {
				info_1.optionsC = str;//当i为4时，str的内容为题目的C项，赋值到info_1的 optionC 这一数据成员

			}
			if (i == 5) {
				info_1.optionsD = str;//当i为5时，str的内容为题目的D项，赋值到info_1的 optionD 这一数据成员

			}
			if (i == 6) {
				info_1.rightAnswer = str;//当i为6时，即读取到正确答案这一内容
				info_1.rightTime = 0;//对题库中的一道题的被答对次数进行初始化
			}
			if (i == 6) {
				info.push_back(info_1);//将info_1这一对象压入info中
				i = 0;//重新将i的值赋为0，即开始进行下一道题目的读取
			}
			str = "";//将str置空
		}
	}
	if (ifs.is_open())
		ifs.close();//读取文件操作结束后，将其关闭
}



void rankings() {//历史记录

	system("cls");

	char name[50] = { "rankings.txt" };
	ifstream readfile(name);


	const int LINE_LENGTH = 1000;
	char str[LINE_LENGTH];
	while (readfile.getline(str, LINE_LENGTH))
	{
		cout << str << endl;//将历史成绩显示在控制台
	}
	readfile.close();
	system("pause");
}