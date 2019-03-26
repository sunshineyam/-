#ifndef __Heap_H__
#define __Heap_H__
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <malloc.h>
#include <Windows.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _array;
	int _size;
	int _capacity;
}Heap;
void HeapInit(Heap* hp, HPDataType* _a, int n);
void HeapDestory(Heap* hp);
void AdjustDown(HPDataType* a, int n, int root);
void HeapCreate1(HPDataType* a, size_t n, int parents);
void HeapPrint(Heap* hp);
void HeapPush(Heap* hp, HPDataType x);
void HeapPop(Heap* hp);
HPDataType HeapTop(Heap* hp);
int HeapSize1(Heap* hp);int HeapEmpty1(Heap* hp);void HeapSort1(int* a, int n);
void test();
#endif // __Heap_H__