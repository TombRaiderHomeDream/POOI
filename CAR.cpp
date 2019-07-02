#include <iosream>
#include <stdio.h>
#include <conio.h>

using namespace std;

/******* 基本宏定义 *******************/
#define OK 1
#define ERROR 0

/******* 车结构定义 *******************/
typedef struct
{
    char A;
    char D;

    int car;
    int time;
}CAR;

/******* 栈结构定义 *******************/
#define SInit 20
#define SAdd 10

typedef struct
{
    int top;

    int size;
}stack;

/******* 队列结构定义 *****************/
#define QInit 20
#define QAdd 10

typedef struct
{
    int front;
    int rear;
}queue;

/******* 函数 *************************/
	// 栈
int SInit(stack S);
int SEmpty(stack S);
int Push(stack S);
int Pop(satck S);

	// 其他
void Pause();

/******* 主函数 ***********************/
int main()
{
    Pause();
    return 0;
}



/******* 函数实现 *********************/
void Pause()
{
    cout << "Enter any keys to continue..."
    int get = getch();

    return;
}

int SInit(stack S)
{
}

int SEmpty(stack S)
{
}

int Push(stack S)
{
}

int Pop(stack S)
{
}