//#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
typedef int STDataType;
typedef struct Stack
{
	STDataType* _array;
	int _top;//Õ»¶¥
	int _capacity;//ÈÝÁ¿
}Stack;
void StackInit(Stack* ps);
void StackDestory(Stack* ps);
void StackPush(Stack* ps,STDataType x);
void StackPop(Stack* ps);
STDataType StackTop(Stack* ps);
int StackEmpty(Stack* ps);
int StackSize(Stack* ps);
void TestStack();



