#include <iosream>
#include <stdio.h>
#include <conio.h>

using namespace std;

/******* �����궨�� *******************/
#define OK 1
#define ERROR 0

/******* ���ṹ���� *******************/
typedef struct
{
    char A;
    char D;

    int car;
    int time;
}CAR;

/******* ջ�ṹ���� *******************/
#define SInit 20
#define SAdd 10

typedef struct
{
    int top;

    int size;
}stack;

/******* ���нṹ���� *****************/
#define QInit 20
#define QAdd 10

typedef struct
{
    int front;
    int rear;
}queue;

/******* ���� *************************/
	// ջ
int SInit(stack S);
int SEmpty(stack S);
int Push(stack S);
int Pop(satck S);

	// ����
void Pause();

/******* ������ ***********************/
int main()
{
    Pause();
    return 0;
}



/******* ����ʵ�� *********************/
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