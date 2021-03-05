#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
using namespace std;


//printf() -- sprintf() -- fprintf()
//scanf()  -- sscanf()  -- fscanf()

//fprintf
void test01()
{
	FILE *fp = fopen("G:/fopen/tes03.txt", "w+");
	if (fp == NULL)
	{
		perror("fopen error");
		return;
	}
	printf("%d%c%d=%d\n", 10, '*', 7, 10 * 7);
	fprintf(fp, "%d%c%d=%d\n", 10, '*', 7, 10 * 7);
	fclose(fp);
}

void test02()
{
	FILE *fp = fopen("G:/fopen/tes04.txt", "w");
	if (fp == NULL)
	{
		perror("fopen error");
		return;
	}
	fputs("6\n",fp);
	fputs("7\n",fp);
	fputs("8\n",fp);
	fputs("\n",fp);
	fputs("\n",fp);
	fputs("\n",fp);

	fclose(fp);
}

void test03()
{
	FILE *fp = fopen("G:/fopen/tes04.txt", "r");
	int a;
	if (fp == NULL)
	{
		perror("fopen error");
		return;
	}
	while (true)
	{
		fscanf(fp, "%d\n", &a);
		printf("%d\n", a);
		if (feof(fp))
		{
			break;
		}
		
	}
	fclose(fp);
}

void test04()
{
	FILE *fp = fopen("G:/fopen/tes04.txt", "r");
	int a;
	if (fp == NULL)
	{
		perror("fopen error");
		return;
	}
	while (true)
	{
		char buf[1024];
		fgets(buf, 3, fp);
		
		if (feof(fp))
		{
			break;
		}
		cout << buf;
	}
	fclose(fp);
}

//�ļ�����
void test05()
{
	FILE *fp = fopen("G:/fopen/tes05.txt", "w+");
	if (fp == NULL)
	{
		perror("fopen error");
		return;
	}
	//���������
	srand(time(NULL));

	//ѭ����������� �����ļ���
	for (int i = 0 ;i < 10;i++)
	{
		fprintf(fp, "%d\n", rand() % 100);
	}
	fclose(fp);
}

void arrSort(int *arr)
{
	for (int i = 0; i < 10; i++)
		for (int j = i + 1; j <10; j++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
}

void test06()
{
	FILE *fp = fopen("G:/fopen/tes05.txt", "r");
	int arr[10];
	int i = 0;
	if (fp == NULL)
	{
		perror("fopen error");
		return;
	}
	while (true)
	{
		fscanf(fp, "%d\n", &arr[i]);
		i++;
		if (feof(fp))
		{
			break;
		}
	}
	arrSort(arr);
	fclose(fp);
	fp = fopen("G:/fopen/tes05.txt", "w+");
	for (i = 0;i < 10;i++)
	{
		fprintf(fp, "%d\n", arr[i]);
	}
	fclose(fp);
}

//fgets -- fputs 
//fgetc -- fputc
//fprintf -- fscanf   Ĭ�ϴ����ı��ļ�

//fwrite() 
//fread() ���� ��������������ļ�

//size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
//д���ݵ��ļ���
    //��1����д�������ݵĵ�ַ
	//��2����д�����ݵĴ�С
	//��3��д���Ĵ���		-- ��2 x ��3 = д�����ݵ��ܴ�С��
	//��4���ļ�
	//����ֵ�� �ɹ�����Զ�� ��3 ��ֵ��
	//-- - ͨ������2 �� 1. ����3��ʵ��д���ֽ�����
	//ʧ�ܣ�0

//fread()������ ���ļ�fp�ж������ݡ�
//size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
	//��1����ȡ�������ݴ洢��λ��
	//��2��һ�ζ�ȡ���ֽ���
	//��3����ȡ�Ĵ���				-- ��2 x ��3 = �������ݵ��ܴ�С
	//��4���ļ�
	//����ֵ�� �ɹ�������3.	-- - ͨ������2 �� 1. ����3�����������ֽ�����
	//0����ʧ�� -- �����ļ���β -- feof(fp)Ϊ�档

typedef struct student{
	int age;
	char name[10];
	int num;
}stu_t;
void test07()//fwrite()����
{
	stu_t stu[4] = {
		18,"afei",10,
		20,"andy",20,
		30,"lily",30,
		16,"james",40
	};
	FILE *fp = fopen("G:/fopen/tes06.txt", "w+");
	if (fp == NULL)
	{
		perror("fopen error");
		return;
	}

	int ret = fwrite(stu, 1, sizeof(stu_t) * 4, fp);
	if (ret == 0)
	{
		perror("fwrite error");
		return;
	}
	fclose(fp);
}

void test08()//fread()����
{
	FILE *fp = fopen("G:/fopen/tes06.txt", "r");
	if (fp == NULL)
	{
		perror("fopen error");
		return;
	}
	stu_t buf[4];
	int ret = fread(buf, sizeof(stu_t), 4, fp);
	cout << "ret = " << ret << endl;
	for (int i =0 ;i < 4;i++)
	{
		cout << "buf["<<i<<"].age = "<<buf[i].age << " ";
		cout << "buf[" << i << "].name = " << buf[i].name << " ";
		cout << "buf[" << i << "].num = " << buf[i].num << endl;
	}
	fclose(fp);
}

//���ļ�����  
//��֪һ���������͵��ļ� �Ը��ļ���ֵ ����һ����ͬ�����ļ�
  //1 �������ļ� һ��"r" ��һ��"w"
  //2 ��r�� fread  fwrite��w�ļ���
  //3 �жϵ����ļ���β ��ֹ
  //4 �ر�

void test09()
{
	FILE *fp = fopen("G:/fopen/tes07.txt", "r");
	char buf[1024];
	if (fp == NULL)
	{
		perror("fopen error");
		return;
	}
	FILE *fp2 = fopen("G:/fopen/tescp.txt", "w");
	if (fp2 == NULL)
	{
		perror("fopen error");
		return;
	}
	while (true)
	{
		fgets(buf, 1024, fp);
		if (feof(fp))
		{
			break;
		}
		fputs(buf, fp2);
	}
	fclose(fp);
	fclose(fp2);
}
void test10()
{
	FILE *fp = fopen("G:/fopen/guohuo.mp3", "rb");
	char buf[1024];
	if (fp == NULL)
	{
		perror("fopen error");
		return;
	}
	FILE *fp2 = fopen("G:/fopen/guohuocp.mp3", "wb");
	if (fp2 == NULL)
	{
		perror("fopen error");
		return;
	}
	while (true)
	{
		int ret = fread(buf, 1, sizeof(buf), fp);
		if (ret == 0)
		{
			break;
		}
		fwrite(buf, 1, ret, fp2);
	}
	fclose(fp);
	fclose(fp2);
}

void test11()
{
	int buf[1024] = { 0 };
	cout << "sizeof(buf) = " << sizeof(buf) << endl;

}
void main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//getchar();//Ϊ�˿����ļ�ǰ�������
	//test06();

	//test07();
	//test08();
	//test09();
	//test10();
	test11();
	system("pause");
}