//#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"
void HeapInit(Heap* hp, HPDataType* a, int n)//n是数据个数
{
	assert(hp && a);
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType)*n);
	hp->_size = hp->_capacity = n;
	memcpy(hp->_array, a, sizeof(HPDataType)*n);
	for(int i = (hp ->_size - 2 )/ 2; i >= 0; i--)
	{
		AdjustDown(hp ->_array, hp ->_size, i);
	}
}
void test()
{
	Heap hp;
	int a[] = { 2, 7, 8, 0, 0, 7, 5, 3, 7, 9 };
	HeapInit(&hp,a,sizeof(a)/sizeof(int));
	/*HeapPrint(&hp);
	HeapCreate1(a, sizeof(a) / sizeof(int),0);
	HeapPrint(&hp);*/
	/*HeapPush(&hp, 1);
	HeapPush(&hp, 2);
	HeapPush(&hp, 3);
	HeapPush(&hp, 4);*/
	/*HeapPop(&hp);
	HeapPrint(&hp);*/
	HeapSort1(a, sizeof(a) / sizeof(int));
	HeapPrint(&hp);

}
void HeapDestory(Heap* hp)
{
	assert(hp);
	hp->_size = hp->_capacity = 0;
	free(hp->_array);
	hp->_array = NULL;
}
//void AdjustDown(HPDataType* a, size_t n, int root)
//{
//	assert(a);
//	int parent = root;
//	int child = parent * 2 + 1;
//	while (child < n)
//	{
//		//找左右孩子小的
//		if (a[child + 1] < a[child] && child + 1 < n)
//			child++;
//		if (a[child] < a[parent])
//		{
//			HPDataType tmp = a[child];
//			a[child] = a[parent];
//			a[parent] = tmp;
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//			break;
//	}
//}
void HeapPrint(Heap* hp)
{
	assert(hp);
	for (int i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_array[i]);
	}
	printf("\n");
}
void Swap(int* a, int* b)
{
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void HeapCreate1(HPDataType* a, size_t n, int root)
{
	int child = root * 2 + 1;
	//建大堆
	while (child<n)
	{
		if (a[child]>a[child+1] && a[child+1]<n)
		{
			child++;
		}
		if (a[child]>a[root])
		{
			Swap(&a[child], &a[root]);
			root = child;
			child = root * 2 + 1;
		}
		else
			break;
	}
}
void AdjustUp(HPDataType* a,size_t n)
{
	assert(a);
	int parent = (n-2)/2;
	int child = n - 1;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			HPDataType tmp = a[child];
			a[child] = a[parent];
			a[parent] = tmp;
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}
void HeapPush(Heap* hp, HPDataType x)
{
	assert(&hp);
	int newcapacity = 0;
	if (hp->_size == hp->_capacity)
	{
		newcapacity = (int*)realloc(newcapacity, hp->_capacity*2);
		assert(newcapacity);
	}
	if (newcapacity)
	{
		hp->_capacity = newcapacity;
		hp->_array[hp->_size] = x;
		hp->_size++;
	}
	AdjustUp(hp->_array,hp->_size);
}
void HeapPop(Heap* hp)
{
	assert(hp->_array);
	Swap(&hp->_array[0], &hp->_array[hp->_size - 1]);
	hp->_size--;
	AdjustDown(hp->_array, hp->_size, 0);
}
HPDataType HeapTop(Heap* hp)
{
	assert(hp->_array);
	return hp->_array[0];
}
int HeapSize1(Heap* hp)
{
	assert(hp->_array);
	return hp->_size;
}
int HeapEmpty1(Heap* hp)
{
	if (hp->_size == 0)
		return 1;
	return 0;
}
void HeapSort1(int* a, int n)
{
	int i = 0;
	//升序,建大堆；降序，建小堆
	//1.建堆
	for (i = (n-2)/2; i >=0; i--)
	{
		AdjustDown(a, n,i);//大堆
	}
	//2.选数
	int end = n - 1;
	while (end>0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, n, i);
		--end;
	}
}