#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>
using namespace std;

//�жϻ����ַ���  �ַ������Ŷ��͵��Ŷ���һ��
void test01()
{
	char *str = "heloeh";
	char *start = str;
	char *end = str + strlen(str) - 1;
	while (end > start)
	{
		if ((*end) == (*start) )
		{
			end--;
			start++;
		}
		else
		{
			cout << "�ַ������ǻ����ַ���" << endl;
			break;
		}
	}
	if (end <= start)
	{
		cout << "�ַ����ǻ����ַ���" << endl;
	}
}
//�ַ�����ʽ������ ���
void test02()
{
	char buf[100] = { 0 };
	sprintf(buf, "%d%c%d=%d", 10, '+', 34, 10 + 34);
	puts(buf);
	int a;
	char buf2[100] = { 0 };
	sscanf("2", "%d", &a);
	cout << "a = " << a << endl;
}

//���ַ���str�� ��һ���ַ����ֵ�λ�� �����ַ����ַ����еĵ�ַ
	//char *strchr(const char *s,int c)
void test03()
{
	char *str = "liwenwei";
	char *ch = strchr(str, 'w');

	cout << " *ch = " << *ch << endl;
}
// ���ַ���str�� ����������һ���ַ����ֵ�λ�� �����ַ����ַ����еĵ�ַ
//char *strrchr(const char *s,int c)
void test04()
{
	char *str = "liwenwei";
	char *ch = strrchr(str, 'w');

	cout << " ch = " << ch << endl;
}

//������ʽ scanf("%[^\n]",str);//���ճ����з���������ַ�


//�ַ����ָ�� strtok  ���ռȶ��ķָ�������ַ���
  //�����ַ�����ֺ���׵�ַ "���":���ָ����� '\0' 
   //��һ�β�� ����1 �� ����ֵ�ԭ�� 
   //�� 1+�β��ʱ ��1�� NULLֵ 
void test05()
{
	char str[] = "www.brp59.com";
	char *p = strtok(str, ".");
	if (p == NULL)
	{
		cout << "�ָ�ʧ��" << endl;
	}
	cout << "p = " << p << endl;

	p = strtok(NULL, ".");
	cout << "p = " << p << endl;
}

//atoi �ַ��� ת����
//auof �ַ���ת������
//auol �ַ���ת������

void test06()
{
	char *str = "1.25";
	int x = atoi(str);
	float y = atof(str);
	long int z = atol(str);
	cout << "x = " << x << " y = " << y << " z = " << z << endl;

	cout << "sizeof(float) = " << sizeof(float) << endl;
	cout << "sizeof(double) = " << sizeof(double) << endl;
}
void main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	test06();
	system("pause");
}