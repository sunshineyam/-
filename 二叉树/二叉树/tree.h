#pragma once
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <malloc.h>

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

BTNode* BinaryTreeCreate(BTDataType* array, int* pindex);
void BinaryTreeDestory(BTNode** root);
int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root);
int BinaryTreeLevelKSize(BTNode* root,int k);
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
int BinaryTreeHeight(BTNode* root);
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostrder(BTNode* root);
void BinaryLevelOrder(BTNode* root);
int BinaryTreeComplete(BTNode* root);
void Treetest();


typedef BTNode* QUDataType;
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
void Queuetest();
QueueNode* BuyQueueNode(QUDataType x);
void print(Queue* pq);
void QueuePush(Queue* pq, QUDataType x);
void QueuePop(Queue* pq);
QUDataType QueueFront(Queue* pq);
QUDataType QueueBack(Queue* pq);
int QueueSize(Queue* pq);
int QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);


