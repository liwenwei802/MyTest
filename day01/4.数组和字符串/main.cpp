#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string.h>
#include <time.h>
using namespace std;
void main()
{
	//��ͬ�������͵����򼯺�
	int arr[] = { 1,2,3 };
	printf("&arr[0] = %p\n", &arr[0]);//ȡ������Ԫ�صĵ�ַ

	printf("arr = %p\n", arr);//ȡ�����ַ   

	cout << "sizeof(arr) = " << sizeof(arr) << endl;
	cout << "sizeof(arr[0] = )" << sizeof(arr[0]) << endl;
	cout << "�����Ԫ�ظ��� = " << sizeof(arr) / sizeof(arr[0]) << endl;

	//������Ϊ��ַ arr = &arr[0]

	//�����ʼ��

	//��ά����Ĵ�С
	int arr2[][3] = { {1,2,3},{ 4,5 } };
	cout << "��ά����Ĵ�СΪ :" << sizeof(arr2) << endl;
	//һ��Ԫ�ش�С
	cout << "һ��Ԫ�ش�СΪ ��" << sizeof(arr2[0]) / sizeof(arr2[0][0]) << endl;

	char ch[6] = { 'h','e','l','l','0'};
	char ch2[] = "hello world";
	int x = sizeof(ch);
	int y = sizeof(ch2);
	cout << "x = " << x << " y = " << y << endl;
	cout << ch2 << endl;

	cout << "��Ҫ��ʼ��ȡ�ַ�����" << endl;
	char *s =NULL;
	s = new char[10];
	if (s == NULL)
	{
		cout << "����ռ�ʧ��" << endl;
		return;
	}
	strcpy(s, ch);
	cout << "s = " << s << endl;
	int m = sizeof(s);

	cout << "m =  " << m << endl;
	//s = (char *)malloc(sizeof(char) * 10);
    //gets(s);//�Ӽ��̻�ȡһ���ַ����� �����ַ������׵�ַ

	char *str = new char[20];
	fgets(str, 20, stdin);
	cout << "str = " << str << endl;
	cout << "put��������� " << endl;
	puts(str);
	rewind(stdin);
	char li = getchar();
	cout << "li = " << li << endl;

	fputs(str, stdout);
	delete[] str;
	delete[] s;

	//�ַ�����ƴ��
	char *str1 = "li";
	char *str2 = "wenwei";
	char *str3 = new char[strlen(str1) + strlen(str2) + 1];
	memset(str3, 0, strlen(str1) + strlen(str2) + 1);
	int q = strlen(str3);
	if(str3 == NULL)
	{
		cout << "�ڴ�ռ�����ʧ��" << endl;
		return;
	}
	int h = strlen(str1) + strlen(str2);
	strcat(str3, str1);
	strcat(str3, str2);
	//strcat(str3, '\0');
	cout << "ƴ�Ӻ��str3Ϊ" << endl;
	cout << "str3 = " << str3 << endl;
	time_t  Time;
	time(&Time);
	cout << Time << endl;

	system("pause");
}