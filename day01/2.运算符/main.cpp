#include<iostream>
using namespace std;

void main()
{
	//���������
	int a = 10, b= 20, c = 30;
	int x = (a = 1, b = 2, c = 3);
	cout << "x = " << x << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;

	//��Ŀ�����
	//���ʽ1 �����ʽ2 �����ʽ3
	//���ʽ1 ��һ���б���ʽ ���Ϊ�档������Ŀ���� ȡֵ���ʽ2
	//						   ���Ϊ�١�������Ŀ���� ȡֵ���ʽ3
	int m = a > b ? 69 : a < b ? 3 : 5;
	cout << "m = " << m << endl;


	system("pause");
}