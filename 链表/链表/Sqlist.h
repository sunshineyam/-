//#define _CRT_SECURE_NO_WARNINGS 1
//#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __Seqlist_H__
#define __Seqlist_H__

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include <Windows.h>

//typedef int SLDataType;
//typedef struct SlistNode
//{
//	SLDataType _data;
//	struct SlistNode* _next;
//}SlistNode;
//typedef struct Slist
//{
//	SlistNode* _head;
//}Slist;

//void SlistInit(Slist* plist);
//void SlistPrint(Slist* plist);
//SlistNode* BuySlistNode(SLDataType x);
//void SlistPushFront(Slist* plist, SLDataType x);
//void SlistPushBack(Slist* plist, SLDataType x);
//void SlistPopBack(Slist* plist);
//void SlistPopFront(Slist* plist);
//SlistNode* SlistFind(Slist* plist, SLDataType x);
//void SlistInsertAfter(SlistNode* pos, SLDataType x);
////void SlistEraseAfter(SlistNode* pos);
//void SlistRemove(Slist* plist, SLDataType x);
typedef int SLDataType;
typedef struct ListNode
{
	SLDataType val;
	struct ListNode* next;
    struct ListNode* pHead;
}ListNode;
struct ListNode* partition(ListNode* pHead, int x);

void test();


//void SlistDesory(Slist* plist);


//void removeElements(SlistNode* _head, int val);
//SlistNode* reverseList(SlistNode* _head);
//SlistNode* middleNode(SlistNode* _head);
//SlistNode* FindKthToTil(SlistNode* _head, unsigned int k);
//SlistNode* mergeTwoLists(SlistNode* l1, SlistNode* l2);

#endif __