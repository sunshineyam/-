//#define _CRT_SECURE_NO_WARNINGS 1
#include "tree.h"
//前序遍历数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* array, int* pindex)
{
	if (array[*pindex] == '#')
	{
		(*pindex)++;
		return NULL;
	}
	else
	{
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->_left = NULL;
		root->_right = NULL;
		root->_data = array[*pindex];
		(*pindex)++;

		root->_left = BinaryTreeCreate(array, pindex);
		root->_right = BinaryTreeCreate(array, pindex);
		 
		return root;
	}
}
void Treetest()
{
	char array[100] = "ABD##E#H##CF##G##";
	int index = 0;
	BTNode* root = BinaryTreeCreate(array, &index);
	/*size_t size = BinaryTreeSize(root);
	printf("%d", size);*/
	printf("\n");
	size_t size = BinaryTreeLeafSize(root);
	printf("%d", size);
	printf("\n");
	size_t num = BinaryTreeHeight(root);
	printf("%d", num);
	printf("\n");
	BinaryTreePrevOrder(root);
	printf("\n");
	BinaryTreeInOrder(root);
	printf("\n");
	BinaryTreePostrder(root);
	BinaryLevelOrder(root);
	printf("\n");
	printf("%d ",BinaryTreeComplete(root));
}
void BinaryTreeDestory(BTNode** root)
{
	assert(root);

	
}
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	else
	{
		size_t lsize = BinaryTreeSize(root->_left);
		size_t rsize = BinaryTreeSize(root->_right);
		return 1 + lsize + rsize;
	}
}
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	else if (root->_left == NULL && root->_right == NULL)
		return 1;
	else
	{
		size_t lsize = BinaryTreeLeafSize(root->_left);
		size_t rsize = BinaryTreeLeafSize(root->_right);
		return lsize + rsize;
	}
}
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return 1 + BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}
int BinaryTreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;
	int lheight = BinaryTreeHeight(root->_left);
	int rheight = BinaryTreeHeight(root->_right);
	return lheight > rheight ? lheight+1 : rheight+1;
}
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	BTNode* ret;
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
    ret = BinaryTreeFind(root->_left, x);
	if (ret)
		return ret;

    ret = BinaryTreeFind(root->_right, x);
	if (ret)
		return ret;

	return NULL;
}
//先序
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;
	//BinaryTreePrevOrder(root->_data);//root作为递归的头，应先打印出来
	printf("%c", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}
//中序
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreePrevOrder(root->_left);
	printf("%c", root->_data);
	BinaryTreePrevOrder(root->_right);
}
//后序
void BinaryTreePostrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
	printf("%c", root->_data);
}
//层序遍历
void BinaryLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	if (root!=NULL)
	{
		QueuePush(&q, root);
		while (QueueEmpty(&q) != 0)
		{
			BTNode* front = QueueFront(&q);
			printf("%c ", front->_data);
			if (front->_left)
			{
				QueuePush(&q, front->_left);
			}
			if (front->_right)
			{
				QueuePush(&q, front->_right);
			}
			QueuePop(&q);
		}
	}	
}
//判断是否为完全二叉树
int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root != NULL)
	{
		QueuePush(&q, root);
		while (QueueEmpty(&q) != 0)
		{
			BTNode* front = QueueFront(&q);
			QueuePop(&q);
			if (front == NULL)
			{
				//ABCDEFG NULL NULL NULL H NULL NULL
				break;
			}
			QueuePush(&q, front->_left);
			QueuePush(&q, front->_right);
		}
		//判断是break跳出循环还是队列为空跳出循环
		while (QueueEmpty(&q) != 0)
		{
			BTNode* front = QueueFront(&q);
			if (front != NULL)
			{
				QueueDestory(&q);
				return 0;
			}
			QueuePop(&q);
		}
	}
	return 1;
}