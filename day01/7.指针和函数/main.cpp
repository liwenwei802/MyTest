#include <iostream>

using namespace std;

//ջ֡:  ����������ʱ ϵͳ����stack �ռ�������һ���ڴ����� ��������������
  //��Ҫ����βκ;ֲ�����  �����������ý��� ��������Զ������ͷ�

//��ֵ�ʹ�ַ:

//ʵ�ε�ַ��ֵ
void swap(int *a,int *b)
{
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}
void test01()
{
	int a = 10;
	int b = 20;
	swap(&a, &b);
	cout << "a = " << a << "  b = " << b << endl;
}


//��άָ��������޸� һάָ���ֵ
void  retu(char ** a)
{
	*a = "liw";
}
void test02()
{
	char *ch = "lww";
	retu(&ch);
	cout << "ch = " << ch << endl;
}


//��������������
  //���ݵĲ������������� ����������׵�ַ(һ��ָ��Ĵ�С)
void arrmain(char a[])
{
	cout << "a = " << a << endl;
}
void test03()
{
	char *ch = "liwenwei";
	arrmain(ch);
}

//�ַ�����ƴ��  strcat
void test04()
{	
	char *str1 = "li";
	char *str2 = "wenwei";
	char *str3 = new char[strlen(str1) + strlen(str2) + 1];
	memset(str3, 0, strlen(str1) + strlen(str2) + 1);
	int q = strlen(str3);
	if (str3 == NULL)
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
}

//�ַ����Ƚϴ�С strcmp
  //strcmp(ch1,ch2) 
  //����ֵ��1 ch1 > ch2
  //����ֵ��0 ch1 = ch2
  //����ֵ��-1 ch1 < ch2
  //strncmp(ch1,ch2,count) �Ƚ�ch1 ch2 ǰn���ַ�
void test05()
{
	char *str = "hallo";
	char *ch = "hello";
	int x = strcmp(str, ch);
	cout << "x = " << x << endl;
}

//�ַ������� strcpy 
 //����ָ�����������
void supplychar(char *a,char **b)
{
	char *temp = new char[strlen(a) + 1];
	*b = temp;
	//strcpy(temp, a);//����ȫ
	strncpy(temp, a, strlen(a) + 1);
}
void test07()
{
	char *a = "liwenwei";
	char *b = NULL;
	supplychar(a, &b);
	cout << "b = " << b << endl;
	delete[] b;
	b = NULL;
}

//ȥ���ַ����ո�
void test08()
{
	char *str = "liwenwei zuishuai";


}

//strstr ���� :��str�� ��substr���ֵ�λ��
 //char *strstr(char *str,char *substr)  ����ֵ��һ�γ���substr��λ�� 
void test09()
{
	char *str = "li";
	char *substr = "wen";
	int count = 0;
	while(char *pos = strstr(str, substr))
	{
		count++;
		if (strlen(pos) >= strlen(substr))
		{
			str = pos + strlen(substr);
		}
		else
		{
			break;
		}
	}
	cout << "count = " << count << endl;
	//cout << "pos = " << pos << endl;
}
//ָ����ַ���������
void test06()
{
	/*char str1[] = "hello";
	char *str2 = "hello";
	*(str2+1)= 'R';*/

	char str1[] = { 'h','i' };  //�����ں����Զ���� '\0 '
	char str2[] = "hi";   //���ں����Զ���� '\0 '
	char *str3 = "hello";  //hello��һ���ַ������� �����������޸�

	cout << "sizeof(str1) = " << sizeof(str1) << endl; //2
	cout << "sizeof(str2)" << sizeof(str2) << endl; //3
	//cout << "sizeof(str3)" << sizeof(str3) << endl; //ָ��Ĵ�С �ĸ��ֽ�
}


void main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	test07();
	//test09();
	system("pause");
}