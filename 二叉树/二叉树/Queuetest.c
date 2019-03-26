//#define _CRT_SECURE_NO_WARNINGS 1
#include "tree.h"
void QueueInit(Queue* pq)
{
	assert(pq);
	/*pq->_head = NULL;
	pq->_tail = NULL;*/
	pq->_head = (QueueNode*)malloc(sizeof(QueueNode));
	assert(pq->_head);
	pq->_tail = pq->_head;
	pq->_head->_next = NULL;
}
void Queuetest()
{
	Queue q;
	QueueInit(&q);
	BuyQueueNode(2);
	print(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	print(&q);
	printf("\n");
	QueuePop(&q);
	/*QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);*/
	print(&q);
	printf("\n");
	printf("%d ", QueueFront(&q));
	printf("\n");
	printf("%d ", QueueBack(&q));
	QueueEmpty(&q);
	printf("%d ", QueueSize(&q));
	QueueDestory(&q);

}
void print(Queue* pq)
{
	QueueNode* cur = pq->_head->_next;
	assert(pq);
	while (cur != NULL)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
}
void QueueDestory(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->_head->_next;
	while (cur != NULL)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(cur);
}
QueueNode* BuyQueueNode(QUDataType x)
{
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	assert(newnode);
	newnode->_data = x;
	newnode->_next = NULL;
	return newnode;
}
void QueuePush(Queue* pq, QUDataType x)
{
	assert(pq);
	QueueNode* newnode = BuyQueueNode(x);
	assert(newnode);
	//if (pq->_head == NULL)
	//{
	//	/*QueueNode* head = BuyQueueNode(x);*/
	//	pq->_tail = newnode;
	//	pq->_head = newnode;
	//	/*head->_data = x;*/
	//}
	///*newnode->_data = x;
	//newnode->_next = NULL;*/
	//pq->_tail->_next = newnode;
	//pq->_tail = newnode;

	newnode->_data = x;
	newnode->_next = NULL;
	pq->_tail->_next = newnode;
	pq->_tail = newnode;
}
void QueuePop(Queue* pq)
{
	assert(pq && pq->_head);
	QueueNode* cur = pq->_head;
	if (QueueEmpty(pq) == 0)
	{
		return;
	}
	else
	{
		pq->_head = cur->_next;
		free(cur);
		cur = NULL;
	}
	
	/*if (QueueEmpty(pq) == 0)
	{
		return;
	}
	QueueNode* cur = pq->_head;	
	if (pq->_head == pq->_tail)
	{
		pq->_head = NULL;
		pq->_tail = NULL;
	}
	else
		pq->_head = pq->_head->_next;
	free(cur);*/
}
QUDataType QueueFront(Queue* pq)
{
	assert(pq);
	if (pq->_head == NULL)
		return NULL;
	return pq->_head->_next->_data;
}
QUDataType QueueBack(Queue* pq)
{
	assert(pq);
	if (pq->_tail == NULL)
		return NULL;
	return pq->_tail->_data;
}
int QueueEmpty(Queue* pq)
{
	return pq->_head != pq->_tail;
}
int QueueSize(Queue* pq)
{
	size_t size = 0;
	if (QueueEmpty(pq) == 0)
		return 0;
	else
	{
		QueueNode* cur = pq->_head;
		while (cur->_next)
		{
			size++;
			cur = cur->_next;
		}
		return size;
	}
}