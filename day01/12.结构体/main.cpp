#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//���� ���ݵķ�װ
  // �ؼ��� struct ��������һ���ṹ������
  // stu �ǽṹ�������
  //�����ṹ��������� struct stu


//�������������
typedef  union test
{
	char ch;
	short sh;
	int var;
	double m;
}test;//������ �ڲ����г�Ա������ַһ�� ��ͬ������������ĵ�ַ
  //������Ĵ�С ���ڲ���Ա������ �����Ǹ���Ա�����Ĵ�С
  //�޸���������һ����Ա������ֵ ������Ա��������֮�޸� 

void test01()
{
	test obj;
	cout << "sizeof(obj) = " << sizeof(obj) << endl;
	printf("&obj.ch = %p\n", &obj.ch);
	cout << "&obj = " << &obj << endl;
	cout << "&obj.var = " << &obj.var << endl;
}

//ö��
// enum color{ö�ٳ���}; ö�ٳ��� �����Ǹ����� �����Ǹ�ֵ 
//Ĭ�ϳ�ֵ��0��ʼ ����������ǰһ��������1
//enum color{red,green,blue,black};

enum color { red, green, blue, black };
void test02()
{
	int flag = 2;
	if (flag == blue)
	{
		cout << "nb" << endl;
	}
}

//�ṹ�� ������
//�ṹstruct stu��ֻ��һ������ һ��ģ�� û�пռ� �����Ը��ṹ���Ա��ֵ 
typedef  struct student 
{
	int id;
	int age;
	char name[128];	
}stu_t;

void test03() //�ṹ��
{
	int x = sizeof(stu_t);
	cout << "x = " << x << endl;
}
//�ṹ������
  
void test04()
{
	stu_t *stu = (stu_t *)malloc(sizeof(stu_t) * 4);
	if (stu == NULL)
	{
		cout << "�ռ�����ʧ��" << endl;
		return;
	}
	if (stu != NULL)
	{
		free(stu);
		stu = NULL;
	}
}

//�ṹ���׽ṹ��
typedef struct tcu_stu
{
	stu_t s1;
	char subject[128];
}t_stu;
void test05()
{
	t_stu s2 ={{12,22,"liwenwei"},"shuxue"};
	//strcpy(s2.s1.name , "hello");
	cout << "s2.s1.name = " << s2.s1.name << endl;
}


typedef  struct 
{
	int id;
	int age;
	char name[128];
	char *School;
}tc_stu;
//�ṹ����ָ��
void test06()
{
	tc_stu *stu =(tc_stu *)malloc(sizeof(tc_stu) * 4);
	if (stu == NULL)
	{
		cout << "�ռ�����ʧ��" << endl;
		return;
	}

	for (int i = 0;i < 4;i++)
	{
		stu[i].School = (char *)malloc(sizeof(char) * 20);
		if (stu[i].School == NULL)
		{
			cout << "stu[" << i << "]��" << "School�ռ�����ʧ��" << endl;
			return;
		}
		strcpy(stu[i].School, "hello");
		//stu[i].School = "hello";//���ܸı�ѿռ�ָ���ָ��
	}

	for (int i = 0; i < 4; i++)
	{
		cout << "stu[" << i << "].School = " << stu[i].School << endl;
	}

	for (int i = 0;i < 4;i++)
	{
		if (stu[i].School != NULL)
		{
			free(stu[i].School);
			stu[i].School = NULL;
		}
	}
}

typedef struct a_tea
{
	int a;
}a_t;

typedef struct tea
{
	int id;
	char *p;
	a_t *b;
}t;

void Relese(t *tmp)
{
	if (tmp->b != NULL)
	{
		free(tmp->b);
		tmp->b = NULL;
	}
	if (tmp->p != NULL)
	{
		free(tmp->p);
		tmp->p = NULL;
	}
	if (tmp != NULL)
	{
		free(tmp);
		tmp = NULL;
	}
}
void test07()
{
	t *tmp = (t *)malloc(sizeof(t));
	if (tmp == NULL)
	{
		return;
	}
	tmp->id = 100;
	tmp->p = (char *)malloc(128);
	strcpy(tmp->p, "hello");
	tmp->b = (a_t *)malloc(sizeof(a_t));
	tmp->b->a = 120;

	cout << "tmp->id = " << tmp->id << endl;
	cout << "tmp->p = " << tmp->p << endl;
	cout << "tmp->d->a = " << tmp->b->a << endl;
	Relese(tmp);
	tmp = NULL;
}


void main()
{
	//test01();
	//cout << "sizeof(student) = " << sizeof(student) << endl;
	//stu_t s1 = { 12,22,"liwenwei" }, s2 = { 13,21,"lxh" };
	
	//s1.name = "liwenwei";//��Ϊ�������ǳ��� ���Բ���ֱ�Ӹ�ֵ
	//strcpy(s1.name, "liwenwei");

	//cout << "s1.name = " << s1.name << endl;
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	test07();
	system("pause");
}