#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


//fseek() ����
  //�ļ���дָ��  ��һ���ļ���ֻ��һ��
  //int fseek()
     //����1 �ļ�
     //����2 ƫ����(ʸ��:+ ��� -��ǰ )
	 //����3 SEEK_SET :�ļ���ͷλ��
	 //����4 SEEK_CUR :�ļ���ǰλ��
     //����4 SEEK_END :�ļ���βλ��
   //����ֵ ʧ�� -1 �ɹ� 0

//ftell() 
	//��ȡ�ļ�λ��
    //����:���ļ���ǰ��дλ�õ���ʼλ�õ�ƫ����

    //����ftell + fseek(SEEK_END);����ȡ�ļ���С

//rewind() :�ؾ��ļ���дָ��  ����дָ���Ƶ���ʼ

typedef struct student {
	int age;
	char name[10];
	int num;
}stu_t;
void test01()
{
	stu_t stu[4] = {
		18,"afei",10,
		20,"andy",20,
		30,"lily",30,
		16,"james",40
	};
	stu_t s1;
	FILE *fp = fopen("G:/fopen/tes08.txt", "wb+");
	if (fp == NULL)
	{
		perror("fopen error");
		return;
	}
	fwrite(stu, 1, sizeof(stu), fp);

	fseek(fp, -20*2, SEEK_END);
	

	//cout << "sizeof(stu_t) = " << sizeof(stu_t) << endl;
	fread(&s1, 1, sizeof(s1), fp);
	cout << "age = " << s1.age << " s1.name = " << s1.name << " s1.num = " << s1.num << endl;
	//fseek(fp,0,SEEK_END)
	fclose(fp);
}

//����fseek() �� ftell() �����ļ���С
void test02()
{
	FILE *fp = fopen("G:/fopen/tes08.txt", "r");
	if (fp == NULL)
	{
		perror("fopen error");
		return;
	}
	fseek(fp, 0, SEEK_END);//���ļ�ָ���Ƶ��ļ���β
	int ret = ftell(fp);//����ָ���ƫ����
	cout << "ret = " << ret << endl;
	fclose(fp);
}

//���ļ� ����ϵͳ���� ϵͳ��Դ���Ľϴ�
   //int stat (const char *path,struct stat *buf)
    
		//��1:�ļ�����·��
		//��2:�ļ����Խṹ��
		//����ֵ�� �ɹ��� 0�� ʧ�ܣ� -1��
void test03()
{
	struct stat buf;
	int ret = stat("G:/fopen/tes08.txt", &buf);
	//��������:�ں������ý���ʱ ���Գ䵱����ֵ
	cout << "�ļ��Ĵ�СΪ: " << buf.st_size << endl;
}

//�ļ�������
   //������:�ڴ��е�һ������
      //��һ�η���������̹����� �����ܻ�ȡ�������� �������ڴ���
// ��Ļ -- stdout -- stdout������
// ���� -- stdin  -- stdin ������

//�ֶ�ˢ�»�����
//int fflush(FILE *stream);
  //�ɹ� 0  ʧ�� -1
int fflush(FILE *stream)
{
	FILE *fp = fopen("G:/fopen/tes08.txt", "r");
	if (fp == NULL)
	{
		perror("fopen error");
		return;
	}
	while(1)
	{
		
	}


	fclose(fp);
}

void test04()
{
	

}
void main()
{
	//test01();
	//test02();
	test03();
	system("pause");
}