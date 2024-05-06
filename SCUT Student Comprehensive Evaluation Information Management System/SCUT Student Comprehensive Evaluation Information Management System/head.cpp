#include "head.h"
//全局数组，用于存取学生信息
Student stu[100];
//全局变量，用于在登录成功后存取账号，便于学生后来的查询的操作（让学生的信息私有化）
string tmpKey;
//作图操作
POINT p;
HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
HWND h = GetForegroundWindow();
CONSOLE_FONT_INFO consoleCurrentFont;
//存取坐标的数组
int chang[1000];
int kuan[1000];
//存取当前时间
int year = 0;
int month = 0;
int day = 0;
int hour = 0;
int minute = 0;
int second = 0;
int dayofweek = 0;
//疫情心声 存取所作图的所有坐标的个数
int count_1 = 0;
//体测心得的时间记录
int yeartc = 0;
int monthtc = 0;
int daytc = 0;
int hourtc = 0;
int minutetc = 0;
int secondtc = 0;
int dayofweektc = 0;
