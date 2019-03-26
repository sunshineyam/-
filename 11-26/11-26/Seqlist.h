//#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __Seqlist_H__
#define __Seqlist_H__

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <Windows.h>

typedef int SLDataType;
typedef struct Seqlist
{
	SLDataType* _array;
	size_t _size;
	size_t _capacity;

}Seqlist;

void SeqlistInit(Seqlist* ps, size_t capacity);
void SeqlistDestory(Seqlist* ps);
void CheckCapacity(Seqlist* ps);
void SeqListPushBack(Seqlist* ps, SLDataType x);
void SeqListPopBack(Seqlist* ps);
void SeqListPrint(Seqlist* ps);
void SeqListPushFront(Seqlist* ps, SLDataType x);
void SeqListPopFront(Seqlist* ps);
int SeqListFind(Seqlist* ps, SLDataType x);
void SeqListInsert(Seqlist* ps, size_t pos, SLDataType x);
void SeqListErase(Seqlist* ps, size_t pos);
void SeqListRemove(Seqlist* ps, SLDataType x);
void SeqListModify(Seqlist* ps, size_t pos, SLDataType x);
void SeqListBubbleSort(Seqlist *ps);
int SeqListBinaryFind(Seqlist* ps, SLDataType x);
void SeqListRemoveAll(Seqlist* ps, SLDataType x);
#endif  //__Seqlist_H__