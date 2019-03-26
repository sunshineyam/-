//#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_array = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}
void StackDestory(Stack* ps)
{
	assert(ps);
	free(ps->_array);
	ps->_array = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}
void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		size_t newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		ps->_array = (STDataType*)realloc(ps->_array, sizeof(STDataType)*newcapacity);
		assert(ps->_array != NULL);
		ps->_capacity = newcapacity;
	}
	//ps->_top = x;
	ps->_array[ps->_top]=x;
	ps->_top++;
}
void TestStack()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	/*StackPop(&s);*/
	printf("%d ", StackTop(&s));
	StackEmpty(&s);
	/*printf("%d ", StackSize(&s));*/

}
void StackPop(Stack* ps)
{
	assert(ps && ps->_top > 0);
	ps->_top--;
}
STDataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->_array[ps->_top-1];//top从0开始，每插进去一个数字，top++
}
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0 ? 0 : 1;
}
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}
