#include <iostream>
using namespace std;

//��������
  //1 �ֲ�����: �ӱ������忪ʼ ����������� -- �����ڲ�
  //2 ȫ�ֱ���:������������main����֮ǰ�� ��������ֹ������ -- ����ִ���ڼ�
  //3 static�ֲ�����:������������main����֮ǰ�� ��������ֹ������ -- ����ִ���ڼ�
  //4 static ȫ�ֱ��� : ������������main����֮ǰ�� ��������ֹ������ -- ����ִ���ڼ�
  
//����������:����Ϊ��������洢�ռ�,����Ϊ����ָ����ʼֵ��
//������,�������ҽ���һ�����塣 
//��������:���������������������ͺ�����

//�ֲ����� 
//������ :�Ӱ����ñ����ĵ�һ���д����Ž��� 
void test01()
{
	{
		int a = 10;//����������������
	}
}

//static �ֲ�����
void test02()
{
	static int a = 20;

}

//����ָ����ָ��Ķѿռ�
//p[i][j] = *(p + i)[j] == *(*(p + i) + j)
void test03()
{
	char **p = (char **)malloc(sizeof(char *) * 5);
	if (p == NULL)
	{
		cout << "����ָ��ռ�����ʧ��" << endl;
		return;
	}
	for (int i = 0;i < 5;i++)
	{
		p[i] = (char*)malloc(sizeof(char) * 100);
		if (p[i] == NULL)
		{
			cout << "�ռ�����ʧ��" << endl;
			return;
		}
		memset(p[i], 0, sizeof(char) * 100);
	}
	//�ͷſռ� 
	for(int i = 0 ;i < 5;i++)
	{
		if (p[i])
		{
			free(p[i]);
			p[i] = NULL;
		}
	}
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
}

void main()
{
	
	test03();
	system("pause");
}