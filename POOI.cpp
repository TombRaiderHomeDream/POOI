#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

/************ 基本定义 *********************/
typedef double DElemType;
typedef int IElemType;

const int OK(1);
const int ERROR(0);
	// 数学算法
#define Add 1   // 加法
#define Reduce 2  // 减法

/************ 结构定义 *********************/
typedef struct LPOOI
{
    IElemType c;
    DElemType e;

    int length;

    struct LPOOI *next;
}LPOOI, *POOI;

/************ 全局变量 *********************/
int algoritm(0); // 加减乘除选择

/* 函数声明 */
/************ 初始化 ***********************/
int Init(POOI &P); // 建空表
int Create(POOI &P); // 建表
					 /************ 基本要求 *********************/
void Show(POOI P); // 显示
void Order(POOI &P); // 排序
void Add_Reduce(); // 加减

/************ 选作（附加）******************/
void ValueX(POOI P); // X 处的值
void Differential(); // 导数
int Mult(); // 乘法
void Quantic(POOI P); //输出形式
					 /************ 其他 *************************/
void Pause(); // 暂停
int Interface(); // 主界面

/************ 主函数 ***********************/
int main()
{
    int choice;

    while (true)
    {
	switch (choice = Interface())
	{
	    case 1:
    		// 建立多项式
    		POOI P;
    		Create(P);

		Pause();
		break;

	    case 2:
		// 显示
		Order(P);
		Show(P);

		Pause();
		break;

	     case 3:
    		// 加法
    		algoritm = Add;
    		Add_Reduce();

		Pause();
		break;

	    case 4:
		// 求导
		Differential();

		Pause();
		break;

	    case 5:
		// 乘法
    		//Mult();

		Pause();
		break;
		
	   case 6:
    		// 输出形式
   		//Order(P);
    		//Quantic(P);

		Pause();
		break;

	   case 0:
		// 结束
		exit(0);
	}
    }

    Pause();
    return 0;
}

/************ 函数实现 *********************/
int Interface()
{
    int choice;

    system("cls");

    cout << "     学号: 20181112408     姓名：吴逢燃            \n ";  //cout就等价于printf
    cout << "\n\n\n\n";                             
    cout << "\t\t             一元稀疏多项式  \n";
    cout << "\t\t======================================";
    cout << "\n\n";
    cout << "\t\t             1：建立一元稀疏多项式       \n";
    cout << "\t\t             2：显示         \n";
    cout << "\t\t             3：加法     \n";
    cout << "\t\t             4：减法         \n\n";
    cout << "\t\t             5：求导         \n";
    cout << "\t\t             6：乘法      \n";
    cout << "\t\t             7：类数学表达式 \n\n";
    cout << "\t\t             0：退出         \n";
    cout << "\n";
    cout << "\t\t请选择：" << flush;

    cin >> choice;

    return choice;
}

void Pause() // 暂停
{
    cout << "end...";
    int get = _getch();

    return;
}

int Init(POOI &P) // 建空表
{
    P = (POOI) malloc (sizeof(LPOOI));
    if (!P) return ERROR;

    P->next = NULL;

    P->length = 0;

    return OK;
}

int Create(POOI &P) // 建表
{
    if (!Init(P)) return ERROR;

    POOI p;
    POOI q;

    p = P;
    q = P;

    cout << "data: ";

    do // 尾插法
    {
	p = (POOI) malloc (sizeof(LPOOI));
	if (!p) return ERROR;

	cin >> p->c >> p->e;

	p->next = NULL;
	q->next = p;
	q = q->next;

	P->length++;

	if (cin.get() == '\n') break;
    }while(true);

    return OK;
}

void Show(POOI P)  // 显示
{
    puts("/*");

    cout << "data: ";

    cout << P->length;

    P = P->next;

    while (P)
    {
	cout << ", " << P->c << ", " << P->e;

	P = P->next;
    }

    puts("\n*/");

    return;
}

void Order(POOI &P)  // 排序
{
    POOI p;
    POOI q;
    POOI p_P; // 记录 P

    p = P->next->next;
    P->next->next = NULL;

    while (p) 
    {
	q = p->next;
	p_P = P;

	while (p_P->next && p_P->next->e > p->e) // 在新序列中循环
	{
	    p_P = p_P->next;
	}

	p->next = p_P->next;// 找到指定位置插入
	p_P->next = p;
	p = q;
    }

    return;
}

void Add_Reduce()  // 把 pa pb 表连接起来，通过插入操作把合并的表加起来
{
    POOI Pa;
    POOI Pb;

    Create(Pa);
    Create(Pb);
	
    if (algoritm == Reduce)  // 为减法做准备，把 Pb 表填负号,然后加起来
    {
	POOI o = Pb->next;

	while (o)
	{
	    o->c = -o->c;

	    o = o->next;
	}
    }

    POOI p; // 复制 Pa
    POOI q; // 复制 Pb

	// 连接 Pa Pb
    p = Pa;
    q = Pb;

    Pa->length += Pb->length;  // 保留一下 pa pb 的表长

    q = q->next;

    while (p->next)
    {
	p = p->next;
    }

    p->next = q;  // 连接成功

	// 加法操作
    int flag(0);

    POOI pp;

    pp = Pa->next->next;

    Pa->next->next = NULL;

    while (pp)
    {
	p = pp;
	q = Pa->next;

	while (q)
	{
	    if (q->e == p->e)	// 相同指数项系数相加
	    {
 		q->c += p->c;

		Pa->length--;  // 记录长度

		flag = 1;
		break;
	    }

  	    q = q->next;
	}

	pp = pp->next; // 注意指针变化

	if (!flag)  // 插入不同指数的项
	{
	    p->next = Pa->next;
	    Pa->next = p;
	}

	flag = 0;
    }

    algoritm = 0; // 归零

    Order(Pa); // 排序

    Show(Pa); // 显示

    return;
} // 加减法

void Differential() // 导数
{
    POOI Pa;

    Create(Pa);

    POOI p;

    p = Pa->next;

    while (p) // 依次求导
    {
	p->c *= p->e;
	p->e--;

	p = p->next;
    }

    Order(Pa);  // 排序

    Show(Pa);  // 显示

    return;
}

int Mult() // 乘法
{
    POOI Pa;
    POOI Pb;

    Create(Pa);
    Create(Pb);

    POOI Pc;  // 申请新表
    Init(Pc);

    POOI p; // 复制 Pa
    POOI q; // 新节点

    Pb = Pb->next;
    p = Pa->next;

    while (Pb)
    {
	while (p)
	{
	    q = (POOI) malloc (sizeof(LPOOI));
	    if (!q) return ERROR;

	    q->c = p->c * Pb->c; // 赋值
	    q->e = p->e + Pb->e;

	    q->next = Pc->next;	// 头插法连接
	    Pc->next = q;

	    Pc->length++; // 记录长度

	    p = p->next; // 往下走
	}

	p = Pa->next;
	Pb = Pb->next;
    }

    // 进行加法。。。。就不多事再写一个函数了
    int flag(0);

    POOI pp;

    pp = Pc->next->next;

    Pc->next->next = NULL;

    while (pp)
    {
	p = pp;
	q = Pc->next;

	while (q)
	{
	    if (q->e == p->e)	// 相同指数项系数相加
	    {
 		q->c += p->c;

		Pc->length--;  // 记录长度

		flag = 1;
		break;
	    }

  	    q = q->next;
	}

	pp = pp->next; // 注意指针变化

	if (!flag)  // 插入不同指数的项
	{
	    p->next = Pc->next;
	    Pc->next = p;
	}

	flag = 0;
    }

    Order(Pc);

    Show(Pc);

    return OK;
}

void Quantic(POOI P) //输出形式
{
    puts("/*");

    P = P->next;

    char ch; // 记录 + -
    int i(0); // 第一次显示不带符号

    while (P)
    {
	if (P->c < 0)
	{
	    ch = '-';
	}

	else ch = '+';

	if (i)
	{
	    if ((P->c != 1) && (P->c !=-1)) // 缺省系数 1
	    {
	        cout << ch << P->c << "x^" << P->e;
	    }

	    else cout << ch << "x^" << P->e;
	}

	else // 第一项不显示符号
	{
	    if ((P->c != 1) && (P->c !=-1)) // 缺省系数 1
	    {
	        cout << P->c << "x^" << P->e;
	    }

	    else cout << "x^" << P->e;
	}

	P = P->next; // 往下走
	i++;
    }

    puts("\n*/");

    return;
}

void ValueX(POOI P)
{
    return;
}
https://igg-games.com/