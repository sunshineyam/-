//#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void InsertSort(int* a, int n);
void ShellSort(int *a, int n);
void SelectSort(int *a, int n);
void AdjustDown(int *a, int n,int parents);
void HeapSort(int *a, int n);
void BubbleSort(int* a, int n);
void QuickSort(int*a, int left, int begin);
void QuickSort2(int*a, int left, int right);
void PointSort(int* a, int begin, int end);
void QuickSortNonR(int* a, int left, int right);
void MergeSort(int* a, int n);
void CountSort(int* a, int n);
void test();

typedef int STDataType;
typedef struct Stack
{
	STDataType* _array;
	int _top;//Õ»¶¥
	int _capacity;//ÈÝÁ¿
}Stack;
void StackInit(Stack* ps);
void StackDestory(Stack* ps);
void StackPush(Stack* ps, STDataType x);
void StackPop(Stack* ps);
STDataType StackTop(Stack* ps);
int StackEmpty(Stack* ps);
int StackSize(Stack* ps);