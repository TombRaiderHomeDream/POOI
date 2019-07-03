#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

/******* 基本宏定义 *******************/
#define OK 1
#define ERROR 0

/******* 车结构定义 *******************/
typedef struct
{
    char AD;
    int car;
    int time;
}CAR;

/******* 栈结构定义 *******************/
#define S_Init 20

typedef struct
{
    CAR *data;
    int top;

    int size;
}stack;

/******* 队列结构定义 *****************/
typedef struct
{
    CAR *front;
    CAR *rear;
}queue;

/******* 函数 *************************/
	// 栈
int SInit(stack &S);
int SEmpty(stack S);
int SFull(stack S);
int Push(stack &S, CAR C);
CAR Pop(stack &S);

	// 队列
int QInit(queue &Q);
int QEmpty(queue Q);
int QAdd(queue &Q, CAR C);
CAR Qleave(queue &Q);

	// CAR
int CAdd(CAR C, stack &S, queue &Q);
int Cleave(CAR C, stack &S, queue &Q);

	// 其他
void Pause();

/******* 主函数 ***********************/
int main()
{
    stack S;
    SInit(S);

    stack SS;
    SInit(SS);

    queue Q;
    QInit(Q);

    CAR C;

    Pause();
    return 0;
}



/******* 函数实现 *********************/
void Pause()
{
    cout << "Enter any keys to 

continue...";
    int get = getch();

    return;
}

int SInit(stack &S)
{
    S.data = (int *) malloc (S_Init * 

sizeof(int));
    if (!S.data) return ERROR;

    S.top = 0;
    S.size = S_Init;

    return OK;
}

int SEmpty(stack S)
{
    if (S.top == 0)
    {
	return OK;
    }

    else return ERROR;
}

int SFull(stack S)
{
    if (S.top - 1 == S.size) return OK;

    else return ERROR;
}

int Push(stack &S, CAR C)
{
    if (S.top - 1 == S.size) // 栈满
    {
	return ERROR;
    }

    S.data[S.top++] = C;

    return OK;
}

CAR Pop(stack &S)
{
    if (S.top == 0) return NULL;

    S.top--;

    return S.data[S.top];
}

int QInit(queue &Q)
{
    Q.front = (int *) malloc (sizeof

(int));
    if (!Q.front) return ERROR;

    Q.rear = Q.front;

    return OK;
}

int QEmpty(queue Q)
{
    if (Q.front == Q.rear) return OK;

    else return OK;
}

int QAdd(queue &Q, CAR C)
{
    Q.rear = (int *) malloc (sizeof

(int));
    if (!Q.rear) return ERROR;

    *Q.rear = C;
    Q.rear++;

    return OK;
}

CAR Qleave(queue &Q)
{
    if (QEmpty(Q)) return NULL;

    int *p = Q.front;
    CAR data;

    data = *Q.front;

    Q.front++;

    return data;
}

int CAdd(CAR C, stack &S, queue &Q)
{
    cin >> C.AD >> C.car >> C.time;

    if (!SFull(S)) 
    {
	cout << C.car << " 号车进入 " << 

S.top << " 号位" << endl;

	Push(S, C)
    }

    else
    {
	cout << C.car << " 号车进入便道

等待" << endl;

	QAdd(Q, C)
    }

    return OK;
}

int Cleave(CAR C, stack &S, stack &SS, 

queue &Q)
{
    cin >> C.AD >> C.car >> C.time;

    CAR CC;

    if (!SEmpty(S))
    {
	while (CC.car != C.car)
	{
	    CC = Pop(S);
	    Push(SS, CC);
	    if (CC.car == C.car) 

SS.top--;
	}

	cout << C.car << " 号车离开， " 

<< "停留时间 " << C.time - CC.time << 

endl;
    }

    if (!SFull(S))
    {
	CC = Qleave(Q);

	cout << C.car << " 号车进入 " << 

S.top << " 号位" << endl;

	Push(S, CC);
    }

    return OK;
}
