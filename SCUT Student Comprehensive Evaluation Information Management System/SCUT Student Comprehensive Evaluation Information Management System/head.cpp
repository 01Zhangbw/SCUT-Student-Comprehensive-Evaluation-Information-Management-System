#include "head.h"
//ȫ�����飬���ڴ�ȡѧ����Ϣ
Student stu[100];
//ȫ�ֱ����������ڵ�¼�ɹ����ȡ�˺ţ�����ѧ�������Ĳ�ѯ�Ĳ�������ѧ������Ϣ˽�л���
string tmpKey;
//��ͼ����
POINT p;
HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
HWND h = GetForegroundWindow();
CONSOLE_FONT_INFO consoleCurrentFont;
//��ȡ���������
int chang[1000];
int kuan[1000];
//��ȡ��ǰʱ��
int year = 0;
int month = 0;
int day = 0;
int hour = 0;
int minute = 0;
int second = 0;
int dayofweek = 0;
//�������� ��ȡ����ͼ����������ĸ���
int count_1 = 0;
//����ĵõ�ʱ���¼
int yeartc = 0;
int monthtc = 0;
int daytc = 0;
int hourtc = 0;
int minutetc = 0;
int secondtc = 0;
int dayofweektc = 0;
