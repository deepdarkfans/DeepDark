//��д����,��������ʾ��һ����10������Ԫ�ص�˳�����Ա�
//ʵ��˳�����Ա�Ĳ���,����,ɾ�����㷨

#include<iostream>
#include<stdio.h>
#define LIST_INIT_SIZE 100  //���ȳ�ʼ����
#define LIST_INCREMENT 10   //˳������󳤶�
using namespace std;
struct Sqlist
{
	long *elem,*newlist;
	int Length;
	int listsize;
};
void Error(const char *s)
{
	cout << s << endl;
	exit(1);
}
void InitList_Sq(Sqlist &L)   //���������ɸ�����Ԫ�ص�˳���,������ָ��,	��ʼ����
{
	L.elem = new long[LIST_INIT_SIZE];  //C++ �����ڴ�ռ�
	if (!L.elem)  //����޷�����
		Error("asd");  //���������Ϣ
	L.Length = 0;  //��ʼ����Ϊ0
	L.listsize = LIST_INIT_SIZE; //��Ϊ10,���ʮ��Ԫ��
}
void Create_Sq(Sqlist *L)
{
	int i, num;
	cout << "����˳���Ԫ�ظ���";
	cin >> num;
	cout << "������Ԫ������";
	for (i = 0; i < num; i++)//ѭ������������Ԫ��
	{
		cin >> L->elem[i];
		L->Length++;
	}
	cout << "����˳���ɹ�" << endl;
}
void Increment(Sqlist &L) //Ϊ˳�����չLIST_INCREMEN������Ԫ�ؿռ�
{
	L.newlist = new long[L.listsize + LIST_INCREMENT];  //����LIST_INCREMENT���洢�ռ�
	if (!L.newlist)
	{
		Error("error");
	}
	for (int i = 0; i < L.Length; i++)//��ԭ�ռ��е�����Ԫ��Ų���µ����ݿռ���
	{
		L.newlist[i] = L.elem[i];
	}//�ͷ�Ԫ����ռ�ÿռ�
	L.elem = L.newlist;//�ƽ��ռ��׵�ַ;
	delete[] L.elem;
	L.listsize += LIST_INCREMENT;//�޸ĵ�ǰ˳�������ռ�;
}
void ListInsert_Sq(Sqlist &L, int i, int e)
//��˳����е�i��λ�ò���Ԫ��e;������λ��.����������������Ϣ���˳�����
//i�ĺ���Χ��1<=i<=L.Length+1
{
	if ((i < 1) || (i > L.Length + 1))
		Error("Position ����");
	if (L.Length >= LIST_INIT_SIZE)//����ǰ�洢�ռ�����,�����ӿռ�
		Increment(L); //���ӿռ�
	long *q = &(L.elem[i - 1]); //ָ��qָ�����λ��
	long *p = &(L.elem[L.Length - 1]);
	for (p; p >= q; p--) //����ƶ�Ԫ��
	{
		*(p + 1) = *p;
	}
	*q = e;   //��L�ĵ�i��λ�ò���Ԫ��e
	L.Length++;  //�޸ĵ�ǰ˳�����
}
void ListDelete_Sq(Sqlist &L, int i, int &e)
//ɾ�����е�iԪ�ز���e������ֵ
{
	if (i<1 || i>L.Length) //ɾ��Ԫ�صĲ���������
		Error("Position cuowu");
	e = L.elem[i - 1];//����ɾ����Ԫ�ص�ֵ����e
	long *p = (&L.elem[i - 1]);  //ָ���ɾ��Ԫ�ص�λ��
	for (++p; p <= (L.elem + L.Length - 1); p++) //��ǰ�ƶ�Ԫ��
	{
		*(p - 1) = *p;
	}
	L.Length--; //�޸�L����
	cout << "ɾ��Ԫ����";
	cout << e << endl;
}
int LocatElem_Sq(Sqlist	L, int e)//����eԪ��,���ҵ�,�򷵻�Ԫ��λ��,���򷵻�0
{
	int j = 1;
	long *q = L.elem;
	while ((j<=L.Length)&&(*q!=e))
	{
		j++;
		q++;
	}
	if (j > L.Length)
		return j;
	else
		return 0;
}
void getElem_Sq(Sqlist L, int i, int &e)//���˳�����Ҫ�������Ǹ�Ԫ��
{
	if ((i < 1) || (i > L.Length))
		Error("Position cuowu");
	e = L.elem[i - 1]; //��e����˳����е�i��Ԫ�ص�ֵ
	cout << e << endl;
}
void printElem_Sq(Sqlist L)//���˳���������Ԫ��
{
	cout << "����" << endl;
	int i;
	for (i = 0; i < L.Length; i++)
	{
		cout << " " << L.elem[i];
	}
	cout << endl;
}
int mail()
{
	Sqlist L;
	int e, n, number;
	while (1)
	{
		cout << "    1��������Ϣ��" << endl;
		cout << "    2������Ԫ��" << endl;
		cout << "    3����ѯԪ��" << endl;
		cout << "    4��ɾ��Ԫ��" << endl;
		cout << "    5���˳�����" << endl;
		cout << "    ��ѡ����Ҫִ�еĲ���:";
		cin >> n;
		switch (n)
		{
		case 1:
			InitList_Sq(L);
			Create_Sq(&L);
			printElem_Sq(L);
			break;
		case 2:
			cout << "���������λ��Ԫ��";
			cin >> number >> e;
			while (e != 0)
			{
				ListInsert_Sq(L, number, e);
				printElem_Sq(L);
				cout << "����������λ�ú�Ԫ��:";
				cin >> number >> e;
			}
		case 3:
			cout << "��������ҵ�Ԫ��:";
			cin >> e;
			while (e != 0)
			{
				LocatElem_Sq(L, e);
				cout << "��Ԫ������˳����λ��λ���ǣ�" << LocatElem_Sq(L, e) << endl;
				cout << "��Ԫ���ǣ�";
				getElem_Sq(L, LocatElem_Sq(L, e), e);
				cout << "��������ҵ�Ԫ��:";
				cin >> e;
			}
			break;
		case 4:
			cout << "������Ҫɾ����λ�� :";
			cin >> number;
			ListDelete_Sq(L, number, e);
			printElem_Sq(L);
			break;//�������
		case 5:
			exit(1);
			break;//�������
		default:
			cout << "�����������������!!!!!" << endl;
			continue;
		}
		break;
		
	}

	return 0;
		
}


