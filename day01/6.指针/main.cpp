#include <iostream>
using namespace std;

//ָ��:��ַ
//ָ�����:���ַ�ı���
//ָ��Ĵ�С�������޹� ���ڵ�ǰʹ��ƽ̨�ܹ��йء� 
//32λ 4�ֽ�     64λ8�ֽ�
//Ұָ�� û����Ч�ĵ�ַ�ռ��ָ��

//Ұָ��Ĳ���
void test01()
{
	int i = 20;
	int *p = new int;//�ڶ�������һ���ڴ�ռ� ����ַ���뵽p��
	*p = 200;
	cout << *p << endl;
	cout << p << endl;
	cout << &p << endl;
	delete p;
	p = NULL;

	p = &i;
	cout << *p << endl;
	cout << p << endl;
	cout << &p << endl;
	cout << &i << endl;

	//int *q = 10;//0-255 ȷ����������ϵͳ  
}


//����ָ��/����ָ�� void *p
void test02() // ���Խ�������һ�ֱ�����ַ ���� ��ʹ��ʱ�������ǿת
{
	int a = 345;
	void  *p;//����ָ�� 
	p = &a;
	cout << *((int *)p) << endl;
}

//ָ�������
  //������ -- ��ַ���� �����Ա��޸�
  //ָ���Ǳ��� ���Կ�������������ֵ
void test03()
{
	//a[0]  == *(a + 0) 
	//a[1]  == *(a + 1)
	int a[] = { 0,1,2,3,4 };
	int *p = a;
	cout << "a[2] = " << *(p + 2) << endl;
}

//const����ָ��
void test04()
{
	int i = 20;
	int j = 30;
	const int *p = &i; //�����޸�ָ���ָ�� ������ֱ���޸�ָ���ֵ *p
	cout << "*p = " << *p << endl;
	p = &j;
	cout << "*p = " << *p << endl;
	j = 50;
	cout << "*p = " << *p << endl;


	int *const q = &j;//����ֱ���޸�ָ���ֵ*p	�������޸�ָ���ָ��
	//q = &i;
	*q = 20;

	const int *const n = &i;//
}

//ָ�������������
void test05()
{
	int a[] = { 0,1,2,3,4 };
	int *p = a;
	cout << "p����ǰ" << endl;
	cout << p << endl;
	cout << &p << endl;
	
	p++;
	cout << "p������" << endl;
	cout << *p << endl;
	cout << p << endl;
	cout << &p << endl;
}

//ָ��ļӼ�����
void test06()
{
	//�������Ͷ�ָ������ã� 
	    //�����˴�ָ��洢�ĵ�ַ��ʼ

}

//������֮һ
//��������� ָ�� - ָ�� = ƫ�ƹ���Ԫ�ظ���
void test07()
{
	int a[3] = { 1,2,6 };
	int *q = &a[2];
	int *p = a;
	int x = q - p;//     q-p/sizeof(int)
	cout << x << endl;
	cout << a[q - p] << endl;

}
//ָ������  1
   //һ���洢��ַ������ �����ڲ�����Ԫ�ض��ǵ�ַ
  //ָ������ı�����һ������ָ��
void test08()
{
	int a = 10;
	int b = 20;
	int c = 30;

	int *p1 = &a;
	int *p2 = &b;
	int *p3 = &c;

	int *arr[] = {p1,p2,p3 };

	cout <<"*(arr[0] = ) "<<*arr[0] << endl;  
	cout << "*(*(arr + 1)) = " << *(*(arr + 1)) << endl;  // = *arr[1] = b =20


	cout << &arr[0] << endl;
	cout << &arr[1] << endl;
}

//ָ������ 2
void test09()
{
	int a[] = { 10,80 };
	int b[] = { 20 ,30};
	int c[] = { 30 };

	int *arr[] = { a,b,c };
	cout << *(arr + 1)[1] << endl;
	cout << "arr[1] = " << *(*arr + 1);
}

// һ��ָ���Ǳ����ĵ�ַ
  //����ָ�� ��һ��ָ��ĵ�ַ

void test10()
{
	int a[] = { 1,2,3,4,5,6 };
	cout << "a = " << a << endl;
	cout << "a + 1 = " << a + 1 << endl;
	cout << "&a = " << &a << endl;
	cout << "&a +1 = " << &a + 1 << endl;
	cout << "sizeof(a) = " << sizeof(a) << endl;
}
void main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();

	//test07();
	//test08();
	test09();
	//test10();
	system("pause");
}
