//#define _CRT_SECURE_NO_WARNINGS 1
#include "MySort.h"
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void test()
{
	int a[] = { 9, 6, 4, 8, 3, 2, 1 };
	int n = sizeof(a) / sizeof(a[0]);
	/*InsertSort(a, n);
	Print(a, n);
	printf("\n");
	ShellSort(a, n);
	Print(a, n);*/
	/*SelectSort(a, n);
	Print(a, n);*/
	/*HeapSort(a, n);
	Print(a, n);*/
	/*BubbleSort(a, n);
	Print(a, n);*/
	/*QuickSort(a, 0, n-1);
	Print(a, n);*/
	/*MidQuickSort(a, 0, n - 1);
	Print(a, n);*/
	/*PointSort(a, 0, n - 1);
	Print(a, n);*/
	/*QuickSortNonR(a, 0, n - 1);
	Print(a, n);*/
	MergeSort(a, 0, n - 1);
	Print(a, n);

}
void Print(int *a, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}
void InsertSort(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end>=0)
		{
			if (a[end] > a[end + 1])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
				break;
			a[end+1] = tmp;
		}
	}
}
void ShellSort(int *a, int n)
{
	int gap = n;
	int i = 0;
	for (i = 0; i <= n-1-gap; i++)
	{
		gap = n / 3 + 1;
		int end = i;
		int tmp = a[end];
		while (end>=0)
		{
			if (a[end]>a[end + gap])
			{
				a[end] = a[end + gap];
				--end;
			}
			else
				break;
			a[end + gap] = tmp;
		}
	}
}
//int a[] = { 9, 6, 4, 8, 3, 2, 1 };
void SelectSort(int *a, int n)
{
	int end = n - 1;
	int begin = 0;
	int i = 0;
	while (begin < end)
	{
		int max = end;
		int min = begin;
		for (i = begin; i < end; i++)
		{
			if (a[i]>a[max])
				max = i;
			if (a[i] < a[min])
				min = i;
			Swap(&a[begin], &a[min]);
			Swap(&a[end], &a[max]);
		}
		begin++;
		end--;
	}
}
void AdjustDown(int *a, int n, int parents)
{
	int child = parents * 2 + 1;
	while (child < n)
	{
		if (a[child]<a[child + 1] && child + 1 < n)
			child++;
		if (a[child] > a[parents])
		{
			Swap(&a[child], &a[parents]);
			parents = child;
			child = parents * 2 + 1;
		}
		else
			break;
	}
}
void HeapSort(int *a, int n)
{
	int i = 0;
	//建堆
	for (i = (n-2)/2; i>=0; i--)
	{
		AdjustDown(a, n,i);
	}
	//选数
	int end = n - 1;
	while (end >= 0)
	{
		Swap(&a[0], &a[end]);
		end--;
		AdjustDown(a,a[end],0);
	}
}
void BubbleSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (end>0)
	{
		for (begin = 0; begin<end; begin++)
		{
			if (a[begin]>a[begin + 1])
				Swap(&a[begin], &a[begin + 1]);
		}
		--end;
	}
}
//快排
int PartQuickSort(int* a, int begin, int end)
{
	int key =begin;
	while (begin<end)
	{
	  while(begin<end && a[end] >= a[key])
			end--;
	  while (begin<end && a[begin] <= a[key])
			begin++;
	  Swap(&a[end], &a[begin]);
	}
	Swap(&a[key], &a[begin]);
	return begin;
}
void QuickSort(int*a, int left, int right)
{
	if (left >= right)
		return;
	int div=PartQuickSort(a, left, right);
	QuickSort(a, left, div - 1);
	QuickSort(a, div + 1, right);
}
//三数取中法
int GetMidIndex(int* a, int begin, int end)
{
	int mid = begin + ((end - begin) >> 1);
	while (begin < end)
	{
		if (a[begin]>a[end])
		{
			if (a[begin] < a[mid])
				return begin;
			else
			{
				if (a[mid]>a[end])
					return mid;
				else
					return end;
			}
		}
		else//a[begin]<a[end]
		{
			if (a[end] < a[mid])
				return end;
			else
			{
				if (a[begin]>a[mid])
					return begin;
				else
					return mid;
			}
		}
	}
}
int MidPartQuickSort(int* a, int begin, int end)
{
	int key = GetMidIndex(a, begin, end);
	//int key = begin;
	while (begin<end)
	{
		while (begin<end && a[end] >= a[key])
			end--;
		while (begin<end && a[begin] <= a[key])
			begin++;
		Swap(&a[end], &a[begin]);
	}
	Swap(&a[key], &a[begin]);
	return begin;
}
void MidQuickSort(int*a, int left, int right)
{
	if (left >= right)
		return;
	int div = MidPartQuickSort(a, left, right);
	QuickSort(a, left, div - 1);
	QuickSort(a, div + 1, right);
}
//前后指针法
int PartPointSort(int* a, int begin, int end)
{
	int prev = begin;
	int cur = begin + 1;
	while (cur <= end)
	{
		if (a[cur] < a[begin])
		{
			prev++;
			Swap(&a[cur], &a[prev]);
		}
		cur++;
	}
	Swap(&a[begin], &a[prev]);
	return prev;
}
void PointSort(int*a, int left, int right)
{
	if (left >= right)
		return;
	int div = PartPointSort(a, left, right);
	QuickSort(a, left, div - 1);
	QuickSort(a, div + 1, right);
}
//非递归
void QuickSortNonR(int* a, int left, int right)
{
	Stack st;
	StackInit(&st);
	StackPush(&st, right);
	StackPush(&st, left);
	while (StackEmpty(&st) != 0)
	{
		int begin = StackTop(&st);
		StackPop(&st);
		int end = StackTop(&st);
		StackPop(&st);
		int div = PartQuickSort(a, begin, end);
		if (begin < div - 1)
		{
			StackPush(&st, div - 1);
			StackPush(&st, begin);
		}
		if (end>div + 1)
		{
			StackPush(&st, end);
			StackPush(&st, div+1);
		}
	}
}
void _MergeSort(int*a, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;
	int mid = begin + ((end - begin) >> 1);
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid+1, end, tmp);
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int index = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}
	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}
	//拷数据到原数组
	index = begin;
	while (begin < end)
	{
		a[index++] = tmp[begin++];
	}
}
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int));
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}
void CountSort(int* a, int n)
{
	int min = a[0];
	int max = a[0];
	int i = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i]>max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int range = max - min + 1;
	int* count = (int*)malloc(sizeof(int));
	memset(count, 0, sizeof(int)*range);
	//拷数组a中的数据的个数到count数组中
	for (i = 0; i < range; i++)
	{
		count[a[i] - min]++;
	}
	int j = 0;
	//拷回a数组
	for (i = 0; i < range; i++)
	{
		while (count[i]--)
		{
			a[j++] = i + min;
		}
	}
}

