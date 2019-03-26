#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __Queue_H__
#define __Queue_H__

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <malloc.h>

typedef int QUDataType;
typedef struct QueueNode
{
	struct QueueNode* _next;
	QUDataType _data;
}QueueNode;
typedef struct Queue
{
	QueueNode* _head;
	QueueNode* _tail;
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue*pq);
void test();
QueueNode* BuyQueueNode(QUDataType x);
void print(Queue* pq);
void QueuePush(Queue* pq, QUDataType x);
void QueuePop(Queue* pq);
QUDataType QueueFront(Queue* pq);
QUDataType QueueBack(Queue* pq);
int QueueSize(Queue* pq);
int QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);


#endif  //__Queue_H__