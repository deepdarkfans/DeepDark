//编写程序,建立并显示出一个有10个数据元素的顺序线性表
//实现顺序线性表的插入,查找,删除等算法

#include<iostream>
#include<stdio.h>
#define LIST_INIT_SIZE 100  //表长度初始定义
#define LIST_INCREMENT 10   //顺序表的最大长度
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
void InitList_Sq(Sqlist &L)   //创建有若干个数据元素的顺序表,引用型指针,	初始化表
{
	L.elem = new long[LIST_INIT_SIZE];  //C++ 开辟内存空间
	if (!L.elem)  //如果无法开辟
		Error("asd");  //输出错误信息
	L.Length = 0;  //初始长度为0
	L.listsize = LIST_INIT_SIZE; //表长为10,存放十个元素
}
void Create_Sq(Sqlist *L)
{
	int i, num;
	cout << "输入顺序表元素个数";
	cin >> num;
	cout << "请输入元素数据";
	for (i = 0; i < num; i++)//循环向数组输入元素
	{
		cin >> L->elem[i];
		L->Length++;
	}
	cout << "创建顺序表成功" << endl;
}
void Increment(Sqlist &L) //为顺序表扩展LIST_INCREMEN个数据元素空间
{
	L.newlist = new long[L.listsize + LIST_INCREMENT];  //增加LIST_INCREMENT更存储空间
	if (!L.newlist)
	{
		Error("error");
	}
	for (int i = 0; i < L.Length; i++)//将原空间中的数据元素挪到新的数据空间中
	{
		L.newlist[i] = L.elem[i];
	}//释放元素所占用空间
	L.elem = L.newlist;//移交空间首地址;
	delete[] L.elem;
	L.listsize += LIST_INCREMENT;//修改当前顺序表的最大空间;
}
void ListInsert_Sq(Sqlist &L, int i, int e)
//在顺序表中第i个位置插入元素e;若插入位置.不合理则给出相关信息并退出运行
//i的合理范围是1<=i<=L.Length+1
{
	if ((i < 1) || (i > L.Length + 1))
		Error("Position 错误");
	if (L.Length >= LIST_INIT_SIZE)//若当前存储空间已满,则增加空间
		Increment(L); //增加空间
	long *q = &(L.elem[i - 1]); //指针q指向插入位置
	long *p = &(L.elem[L.Length - 1]);
	for (p; p >= q; p--) //向后移动元素
	{
		*(p + 1) = *p;
	}
	*q = e;   //在L的第i个位置插入元素e
	L.Length++;  //修改当前顺序表长度
}
void ListDelete_Sq(Sqlist &L, int i, int &e)
//删除表中的i元素并用e返回其值
{
	if (i<1 || i>L.Length) //删除元素的参数不合理
		Error("Position cuowu");
	e = L.elem[i - 1];//将待删除的元素的值赋给e
	long *p = (&L.elem[i - 1]);  //指向待删除元素的位置
	for (++p; p <= (L.elem + L.Length - 1); p++) //向前移动元素
	{
		*(p - 1) = *p;
	}
	L.Length--; //修改L长度
	cout << "删除元素是";
	cout << e << endl;
}
int LocatElem_Sq(Sqlist	L, int e)//查找e元素,若找到,则返回元素位序,否则返回0
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
void getElem_Sq(Sqlist L, int i, int &e)//输出顺序表中要操作的那个元素
{
	if ((i < 1) || (i > L.Length))
		Error("Position cuowu");
	e = L.elem[i - 1]; //用e返回顺序表中第i个元素的值
	cout << e << endl;
}
void printElem_Sq(Sqlist L)//输出顺序表中所有元素
{
	cout << "如下" << endl;
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
		cout << "    1、创建信息表" << endl;
		cout << "    2、插入元素" << endl;
		cout << "    3、查询元素" << endl;
		cout << "    4、删除元素" << endl;
		cout << "    5、退出程序" << endl;
		cout << "    请选择所要执行的操作:";
		cin >> n;
		switch (n)
		{
		case 1:
			InitList_Sq(L);
			Create_Sq(&L);
			printElem_Sq(L);
			break;
		case 2:
			cout << "请输入插入位置元素";
			cin >> number >> e;
			while (e != 0)
			{
				ListInsert_Sq(L, number, e);
				printElem_Sq(L);
				cout << "请输入插入的位置和元素:";
				cin >> number >> e;
			}
		case 3:
			cout << "请输入查找的元素:";
			cin >> e;
			while (e != 0)
			{
				LocatElem_Sq(L, e);
				cout << "该元素所在顺序表的位置位置是：" << LocatElem_Sq(L, e) << endl;
				cout << "该元素是：";
				getElem_Sq(L, LocatElem_Sq(L, e), e);
				cout << "请输入查找的元素:";
				cin >> e;
			}
			break;
		case 4:
			cout << "请输入要删除的位置 :";
			cin >> number;
			ListDelete_Sq(L, number, e);
			printElem_Sq(L);
			break;//程序结束
		case 5:
			exit(1);
			break;//程序结束
		default:
			cout << "输入错误，请重新输入!!!!!" << endl;
			continue;
		}
		break;
		
	}

	return 0;
		
}


