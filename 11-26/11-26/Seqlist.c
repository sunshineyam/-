#define _CRT_SECURE_NO_WARNINGS 1
#include "Seqlist.h"
//void SeqlistInit(Seqlist* ps, size_t capacity)
//{
//	memset(ps->_array, 0, sizeof(ps->_array));
//	ps->_size = 0;
//	ps->_capacity = capacity;
//}
void SeqlistInit(Seqlist* ps, size_t capacity)
{
	assert(ps);
	ps->_array = (SLDataType*)malloc(sizeof(SLDataType)*capacity);
	ps->_size = 0;
	ps->_capacity = capacity;
}
void SeqListPrint(Seqlist* ps)
{
	assert(ps);
	for (size_t i = 0; i < ps->_size; i++)
	{
		printf("%d ", ps->_array[i]);
	}
	printf("\n");
}

void SeqlistTest()
{
	Seqlist s;
	SeqlistInit(&s, 10);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 4);
	SeqListPrint(&s);

	/*SeqListPopBack(&s);
	SeqListPrint(&s);

	SeqListPushFront(&s, 1);
	SeqListPushFront(&s, 1);
	SeqListPushFront(&s, 1);
	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPopFront(&s);
    SeqListPrint(&s);

	SeqListFind(&s, 2);
	SeqListPrint(&s);
	SeqListInsert(&s, 0, 5);
	SeqListPrint(&s);
	SeqListErase(&s,0);
	SeqListPrint(&s);
	SeqListRemove(&s, 2);
	SeqListPrint(&s);
	SeqListModify(&s, 2, 5);
	SeqListPrint(&s);
	SeqListBubbleSort(&s);
	SeqListPrint(&s);
	SeqListBinaryFind(&s, 5);
	SeqListPrint(&s);*/
	SeqListRemoveAll(&s, 2);
	SeqListPrint(&s);

}

void SeqlistDestory(Seqlist* ps)
{
	assert(ps);
	if (ps != NULL)
	{
		free(ps->_array);
		ps->_array = NULL;
		ps->_capacity = ps->_size = 0;
	}
}
void CheckCapacity(Seqlist* ps)
{
	int* ptr = 0;
	assert(ps);
	if (ps->_size==ps->_capacity)
	{
		ps->_capacity *= 2;
		ptr = realloc(ps->_array, sizeof((SLDataType*)ps->_array)*ps->_capacity);
		assert(ps->_array);
	}
	if (ptr != NULL)
	ps->_array = ptr;
}
void SeqListPushBack(Seqlist* ps, SLDataType x)
{
	assert(ps);
	if (ps->_size == ps->_capacity)
	{
		CheckCapacity(ps);//防止越界访问
	}
	ps->_array[ps->_size++] = x;
}
void SeqListPopBack(Seqlist* ps)
{
	assert(ps && ps->_size > 0);
	//ps->_array[ps->_size] = 0;//如果_array是int型,则不能直接等于0
	ps->_size--;//缩小数组长度，则会把长度之外的数字剔除
}
void SeqListPushFront(Seqlist* ps, SLDataType x)
{
	assert(ps);
	int end = ps->_size - 1;
	//int i = 0;
	/*if (ps->_size == ps->_capacity)//有if语句时，目前的size和capacity不相等，
	                                   if语句不进去，即不调用CheckCapacity函数，
									   所以当CheckCapacity函数
	{*/                                //出错时，并不报错
		CheckCapacity(ps);
	//}
	/*for (i = 0; i < ps->_size; i++)
	{
		ps->_array[end + 1] = ps->_array[end];
	}*/
	while (end >= 0)
	{
		ps->_array[end+1] = ps->_array[end];
		--end;
	}
	ps->_array[0] = x;
	ps->_size++;//插入一个数据，size就要自加
}
void SeqListPopFront(Seqlist* ps)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->_size-1; i++)
	{
		ps->_array[i] = ps->_array[i+1];
	}
	ps->_size--;
}
int SeqListFind(Seqlist* ps, SLDataType x)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->_size; i++)
	{
		if (ps->_array[i] == x)
		{
			return i;
		}
	}
	return -1;
}
void SeqListInsert(Seqlist* ps, size_t pos, SLDataType x)
{
	assert(ps && pos<=ps->_size);
	CheckCapacity(ps);
	//int end = ps->_size - 1;
	//while ((int)pos <= end)//注意end等于0时，end还要进入循环,此时的end为无符号的
	                        //当pos是size_t时，size_t型是无符号的，两者相比之后，end会整形提升为无符号的
	//{
	//	ps->_array[end + 1] = ps->_array[end];//挪动end可以留出pos的位置，再插入x
	//	--end;
	//}

	size_t end = ps->_size;
	while (pos < end)//等于0时就终止
	{
		ps->_array[end] = ps->_array[end-1];
		--end;
	}
	ps->_array[pos] = x;
	ps->_size++;
}
void SeqListErase(Seqlist* ps, size_t pos)
{
	assert(ps && pos<=ps->_size);
	size_t start = pos;
	while (start < ps->_size - 1)
	{
		ps->_array[start] = ps->_array[start + 1];
		start++;
	}
	ps->_size--;
}
void SeqListRemove(Seqlist* ps, SLDataType x)
{
	assert(ps);
	size_t start = 0;
	while (start < ps->_size)
	{
		if (ps->_array[start] == x)
		{
			ps->_array[start] = ps->_array[start + 1];
		}
		start++;
		ps->_array[start] = ps->_array[start + 1];
	}
	ps->_size--;
}
void SeqListModify(Seqlist* ps, size_t pos, SLDataType x)
{
	assert(ps && pos < ps->_size - 1);
	ps->_array[pos] = x;
}
void SeqListBubbleSort(Seqlist *ps)
{
	assert(ps);
	size_t i = 0;
	size_t j = 0;
	SLDataType tmp = 0;
	for (i = 0; i < ps->_size-1;i++)//控制趟数
	{
		for (j = 0; j < ps->_size - 1 - i; j++)//控制对数
		{
			if (ps->_array[j]>ps->_array[j + 1])
			{
				tmp = ps->_array[j];
				ps->_array[j] = ps->_array[j + 1];
				ps->_array[j + 1] = tmp;
			}
		}
	}
}
int SeqListBinaryFind(Seqlist* ps, SLDataType x)
{
	assert(ps);
	size_t begin = 0;
	size_t end = ps->_size - 1;
	size_t mid = (begin + end) / 2;
	while (begin <= end)
	{
		if (x > ps->_array[mid])
		{
			begin = mid+1;
		}
		else if (x < ps->_array[mid])
		{
			end = mid - 1;
		}
		else
			return mid;
		//return 1;
	}
	return -1;
}
void SeqListRemoveAll(Seqlist* ps, SLDataType x)
{
	assert(ps); 
	size_t cur = 0;//不是x就往后走
	size_t dst = 0;//遇到x就不移
	while (cur < ps->_size)
	{
		if (ps->_array[cur] != x)
		{
			ps->_array[dst] = ps->_array[cur];
			++dst;
		}
		++cur;
	}
	ps->_size = dst;
}