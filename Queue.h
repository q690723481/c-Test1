#pragma once
#define MAX_SIZE 1000
#include <stdio.h>
#include <string.h>
#include <malloc.h>
struct Queue {
    int*  const elems;	   	//elems�����ڴ����ڴ�Ŷ��е�Ԫ��
    const  int  max;	  	//elems��������Ԫ�ظ���max
    int   head, tail;	 	//����ͷhead��βtail���ӿ�head=tail;��ʼhead=tail=0
};

void initQueue(Queue* const p, int m);	//��ʼ��pָ���У��������m��Ԫ��
void initQueue(Queue* const p, const Queue& s); //��s�����ʼ��pָ����
void initQueue(Queue* const p, Queue&& s); //��s�ƶ���ʼ��pָ����
int  number(const Queue* const p);	//����pָ���е�ʵ��Ԫ�ظ���
int  size(const Queue* const p);			//����pָ������������Ԫ�ظ���max
Queue* const enter(Queue* const p, int e);  //��e�����β����������p
Queue* const leave(Queue* const p, int& e); //�Ӷ��׳�Ԫ�ص�e��������p
Queue* const assign(Queue* const p, const Queue& q); //�����s�����в�����p
Queue* const assign(Queue* const p, Queue&& q); //�ƶ���s�����в�����p
char* print(const Queue* const p, char* s);//��ӡpָ������sβ��������s��s[0]=��\0��
void destroyQueue(Queue* const p);	 //����pָ��Ķ���

void initQueue(Queue* const p, int m)//��ʼ��pָ���У��������m��Ԫ��
{
    int* max = (int*)&p->max;//��p->max����ǿ������ת��
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
        *max = s.max;//�޸�p->max
        for (int i = 0; i < s.max; i++)
        {
            int* elem = (int*)&p->elems[i];
            *elem = *(s.elems + i);
        }


        p->head = s.head;
        p->tail = s.tail;
    }
}

void initQueue(Queue* const p, Queue&& s) //��s�ƶ���ʼ��pָ����
{
    if (s.elems)
    {
        int max = (int)&p->max;
        max = (s.max);//�޸�p->max
        for (int i = 0; i < s.max; i++)
        {
            int* elem = (int*)&p->elems[i];
            *elem = *(s.elems + i);
        }


        p->head = s.head;
        p->tail = s.tail;
    }
}
int  number(const Queue* const p)	//����pָ���е�ʵ��Ԫ�ظ���
{
    return (p->tail - p->head + p->max) % p->max;//ѭ�����е�ʵ��Ԫ�ظ���

}
int  size(const Queue* const p)//����pָ������������Ԫ�ظ���max
{
    return p->max;
}

Queue* const enter(Queue* const p, int e)  //��e�����β����������p
{
    if ((p->tail + 1) % (p->max) == p->head)
    {
        throw "Queue is full!";
    }
    p->elems[p->tail] = e;
    p->tail = (p->tail + 1) % p->max;
    return p;
}

Queue* const leave(Queue* const p, int& e)//�Ӷ��׳�Ԫ�ص�e��������p
{
    if (p->tail == p->head)
    {
        throw NULL;
    }
    e = p->elems[p->head];
    p->head = (p->head + 1) % p->max;
    return p;
}

Queue* const assign(Queue* const p, const Queue& q) //�����s�����в�����p
{
    if (q.elems!=nullptr)
    {
        int* max = (int*)&p->max;
        *max = q.max;//�޸�p->max
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

char* print(const Queue* const p, char* s)//��ӡpָ������sβ��������s
{
    int i, j;
    for (i = 0, j = p->head; i < number(p); i++, j = (j + 1) % p->max) {

        s[i] = p->elems[j];
    }
    
    return s;

}

//����pָ��Ķ���
void destroyQueue(Queue* const p)
{
    delete[] (p->elems);
    delete(&p->head);
    delete(&p->tail);
    delete(&p->max);
}
