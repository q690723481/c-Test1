#pragma once
#define MAX_SIZE 1000
#include <stdio.h>
#include <string.h>
#include <malloc.h>
struct Queue {
    int*  const elems;	   	//elems申请内存用于存放队列的元素
    const  int  max;	  	//elems申请的最大元素个数max
    int   head, tail;	 	//队列头head和尾tail，队空head=tail;初始head=tail=0
};

void initQueue(Queue* const p, int m);	//初始化p指队列：最多申请m个元素
void initQueue(Queue* const p, const Queue& s); //用s深拷贝初始化p指队列
void initQueue(Queue* const p, Queue&& s); //用s移动初始化p指队列
int  number(const Queue* const p);	//返回p指队列的实际元素个数
int  size(const Queue* const p);			//返回p指队列申请的最大元素个数max
Queue* const enter(Queue* const p, int e);  //将e入队列尾部，并返回p
Queue* const leave(Queue* const p, int& e); //从队首出元素到e，并返回p
Queue* const assign(Queue* const p, const Queue& q); //深拷贝赋s给队列并返回p
Queue* const assign(Queue* const p, Queue&& q); //移动赋s给队列并返回p
char* print(const Queue* const p, char* s);//打印p指队列至s尾部并返回s：s[0]=’\0’
void destroyQueue(Queue* const p);	 //销毁p指向的队列

void initQueue(Queue* const p, int m)//初始化p指队列：最多申请m个元素
{
    int* max = (int*)&p->max;//对p->max进行强制类型转换
    *max = m;
    (int&)p->elems =(int) new int[m];
    
        //    :elems(new int[m]),max(m),pos(0)
    p->head = 0;
    p->tail = 0;


}

void initQueue(Queue* const p, const Queue& s)
{
    if (s.elems!=nullptr)
    {
        int* max = (int*)&p->max;
        *max = s.max;//修改p->max
        for (int i = 0; i < s.max; i++)
        {
            int* elem = (int*)&p->elems[i];
            *elem = *(s.elems + i);
        }


        p->head = s.head;
        p->tail = s.tail;
    }
}

void initQueue(Queue* const p, Queue&& s) //用s移动初始化p指队列
{
    if (s.elems)
    {
        int max = (int)&p->max;
        max = (s.max);//修改p->max
        for (int i = 0; i < s.max; i++)
        {
            int* elem = (int*)&p->elems[i];
            *elem = *(s.elems + i);
        }


        p->head = s.head;
        p->tail = s.tail;
    }
}
int  number(const Queue* const p)	//返回p指队列的实际元素个数
{
    return (p->tail - p->head + p->max) % p->max;//循环队列的实际元素个数

}
int  size(const Queue* const p)//返回p指队列申请的最大元素个数max
{
    return p->max;
}

Queue* const enter(Queue* const p, int e)  //将e入队列尾部，并返回p
{
    if ((p->tail + 1) % (p->max) == p->head)
    {
        throw "Queue is full!";
    }
    p->elems[p->tail] = e;
    p->tail = (p->tail + 1) % p->max;
    return p;
}

Queue* const leave(Queue* const p, int& e)//从队首出元素到e，并返回p
{
    if (p->tail == p->head)
    {
        throw NULL;
    }
    e = p->elems[p->head];
    p->head = (p->head + 1) % p->max;
    return p;
}

Queue* const assign(Queue* const p, const Queue& q) //深拷贝赋s给队列并返回p
{
    if (q.elems!=nullptr)
    {
        int* max = (int*)&p->max;
        *max = q.max;//修改p->max
        for (int i = 0; i < q.max; i++)
        {
            int* elem = (int*)&p->elems[i];
            *elem = *(q.elems + i);
        }


        p->head = q.head;
        p->tail = q.tail;
    }
    return p;
}

Queue* const assign(Queue* const p, Queue&& q)
{
    return NULL;
}

char* print(const Queue* const p, char* s)//打印p指队列至s尾部并返回s
{
    int i, j;
    for (i = 0, j = p->head; i < number(p); i++, j = (j + 1) % p->max) {

        s[i] = p->elems[j];
    }
    
    return s;

}

//销毁p指向的队列
void destroyQueue(Queue* const p)
{
    delete[] (p->elems);
    delete(&p->head);
    delete(&p->tail);
    delete(&p->max);
}
