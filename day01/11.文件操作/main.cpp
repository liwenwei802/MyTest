#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//printf -- 
//sprintf -- 
//fprintf --

//ϵͳ�ļ�
	//��׼���� stdin -- 0
	//��׼��� stdout -- 1
	//��׼���� stderr -- 2
void test01()
{
	FILE *fp = fopen("G:/fopen/test01.txt","w+");
	char *buf = "liwenweizuishuai";
	if (fp == NULL)
	{
		perror("fopen error");// -- ��Ļ --��׼����
		return;
	}
	int ret = fputs(buf, fp);
	//�ļ��Ľ������ EOF
	//cout << "ret = " << ret << endl;
	fclose(fp);
}

void test02()
{
	FILE *fp = fopen("G:/fopen/test01.txt", "r");
	char *ch = (char *)malloc(sizeof(char) * 1024);
	memset(ch, 0, 1024);
	if (fp == NULL)
	{
		perror("fopen error");// -- ��Ļ --��׼����
		return;
	}
	fgets(ch, 1024, fp); 
    cout << "ch = " << ch << endl;
	if (ch == NULL)
	{
		free(ch);
		ch = NULL;
	}
	fclose(fp);
}
//foef //�ж��Ƿ񵽴��ļ���β

//���û���������� д���ļ���
void test03()
{
	FILE *fp = fopen("G:/fopen/test02.txt", "w");
	if (fp == NULL)
	{
		perror("fopen error");// -- ��Ļ --��׼����
		return;
	}
	char buf[4096];
	while (1)
	{
		fgets(buf, 4096, stdin);
		if (strncmp(buf,":wq",3) == 0)
		{
			break;
		}
		fputs(buf, fp);
	}

	fclose(fp);
}

void main()
{
	//test01();
	//test02();
	test03();
	system("pause");
}

