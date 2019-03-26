//#d_SECURE_NO_WARNINGS 1
#include "Sort.h"
void Swap(int*a, int* b)
{
	int tmp = 0;
	    tmp = *a;
		*a = *b;
		*b = tmp;
}
void print(int* a,int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end]>a[end + 1])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
				break;
			a[end + 1] = tmp;
		}
	}
}

void ShellSort(int *a, int n)
{
	int gap = n;
	int i = 0;
	for (i = 0; i <= n - gap - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end>=0)
		{
			gap = gap / 3 + 1;
			if (a[end] > a[end + gap])
			{
				a[end + gap] = a[end];
				end--;
			}
			else
				break;
			a[end + gap] = tmp;
		}
	}
}
//void SelectSort(int *a, int n)
//{
//	//int begin = 0;
//	//int end = n - 1;
//	int min=0;
//	int j = 0;
//	int i = 0;
//	for (i = 0; i < n - 1; i++)//控制循环趟数
//	{
//		min = i;
//		for (j = i + 1; j < n; j++)
//		{
//			if (a[j] < a[min])
//			{
//				min = j;
//			}
//		}
//		Swap(&a[min], &a[i]);
//	}
//	/*while (begin<end)
//	{
//		if (a[begin] > a[end])
//		{
//			Swap(&a[begin], &a[end]);
//		}
//		else
//		{
//			begin++;
//			end--;
//		}
//	}*/
//}
void SelectSort(int *a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int min = begin;
		int max = end;
		for (int i = begin; i < end; i++)
		{
			if (a[i] > a[max])
			{
				max = i;
			}
			if (a[i] < a[min])
			{
				min = i;
			}
			Swap(&a[begin], &a[min]);
			Swap(&a[end], &a[max]);
		}
		begin++;
		end--;
	}
}
void AdjustDown(int *a, int n,int parents)
{
	int child = parents * 2 + 1;
	while (child < n)
	{
		if (a[child] < a[child + 1] && child + 1 < n)
		{
			child++;
		}
		if (a[child] > a[parents])
		{
			Swap(&a[child], &a[parents]);
			parents = child;
			child = parents * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int *a, int n)
{
	int i = 0;
	for (i = (n-2)/2; i >=0; i--)
	{
		//降序，建小堆
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	//选数
	while (end >= 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, a[end], 0);
		--end;
	}
}
void test()
{
	int a[] = { 5, 3, 6, 4, 7 ,1};
	int n = sizeof(a) / sizeof(a[0]);
	/*InsertSort(a, n);
	print(a,n);*/
	/*ShellSort(a, n);
	print(a, n);*/
	/*SelectSort(a, n);
	print(a, n);*/
	/*HeapSort(a, n);
	print(a, n);*/
	/*BubbleSort(a, n);
	print(a, n);*/
	/*QuickSort(a, 0, n - 1);
	print(a, n);*/
	/*QuickSort2(a, 0, n-1);
	print(a, n);*/
	/*PointSort(a, 0, n - 1);
	print(a, n);*/
	/*QuickSortNonR(a, 0, n - 1);
	print(a, n);*/
	/*MergeSort(a, n);
	print(a, n);*/
	CountSort(a, n);
	print(a, n);
}
//冒泡排序
void BubbleSort(int* a, int n)
{
	int i = 0;
	int end = n-1;
	while (end >= 0)
	{
		for (i = 0; i < end; i++)
		{
			if (a[i]>a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
			}
		}
		end--;
	}
}
//快排的部分排序,获取key,划分区间[begin,key-1][key+1,end],进行第一趟排序
int PartQuickSort(int*a, int begin, int end)
{
	//int key = begin;
	int key = GetMidIndex(a, begin, end);
	while (begin<end)
	{
		while (begin<end && a[key] <= a[end])
		{
			end--;
		}
		while (begin<end && a[begin] <= a[key])
		{
			begin++;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[key]);
	return begin;
}
//快排
void QuickSort(int*a, int left, int right)
{
	if (left >= right)
		return;
	int div = PartQuickSort(a, left, right);
	
	QuickSort(a, left, div - 1);
	QuickSort(a, div + 1, right);;
}
//三数取中法(key为三个数的大小排在中间的位置）,获取key
int GetMidIndex(int*a, int begin, int end)
{
	int mid = begin + ((begin - end) >> 1);
	if (a[mid] > a[begin])
	{
		if (a[begin] > a[end])
		{
			return begin;
		}
		else
		{
			if (a[mid] > a[end])
				return end;
			else
				return mid;
		}
	}
	else//(mid<begin)
	{
		if (a[begin] < a[end])
			return begin;
		else
		{
			if (a[mid] < a[end])
				return end;
			else
				return mid;
		}
	}
}
void QuickSort2(int*a, int left, int right)
{
	int div = PartQuickSort(a, left, right);
	if (left >= right)
		return;
	QuickSort2(a, left, div - 1);
	QuickSort2(a, div + 1, right);;
}
//前后指针法排序
//划分区间[begin,prev][prev+1,end]
int PartPointSort(int* a, int begin, int end)
{
	int prev = begin;
	int cur = begin + 1;
	while (cur<=end)
	{
		
		if (a[cur] < a[begin])
		{
			prev++;
			Swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	Swap(&a[begin] ,& a[prev]);
	return prev;
}
void PointSort(int*a, int left, int right)
{
	if (left >= right)
		return;
	int div = PartPointSort(a, left, right);

	PointSort(a, left, div - 1);
	PointSort(a, div + 1, right);;
}
//非递归排序
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
			StackPush(&st, div-1);
			StackPush(&st, begin);
		}
		if (end > div + 1)
		{
			StackPush(&st, div+1);
			StackPush(&st, end);
		}
	}
}


//归并排序
void _MergeSort(int* a, int begin, int end, int* tmp)
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
		{
			tmp[index++] = a[begin1++];
		}
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
	//把数据拷回原数组
	index = begin;
	while (begin <= end)
	{
		a[index++] = tmp[begin++];
	}
}
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}
//非比较排序
//int a[] = { 5, 3, 6, 4, 7, 1 }; min=1;max=7,range=7;
void CountSort(int* a, int n)
{
	//计算范围
	int max = a[0], min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i]>max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	//统计个数
	int range = max - min + 1;
	int* count = (int*)malloc(sizeof(int)*range);
	memset(count, 0, sizeof(int)*range);
	int i = 0;
	//count的下标代表a数组中的元素；count数组中的元素代表a数组中元素的个数；
	//读入a数组中元素的个数
	for (i = 0; i < n; i++)
	{
		count[a[i] - min]++;//count[a[i] - min]代表a[i]出现的次数
	}
	int j = 0;
	//输出count数组中的元素
	for (i = 0; i < range; i++)
	{
		while (count[i]--)
		{
			a[j++] = i + min;
		}
	}
}
