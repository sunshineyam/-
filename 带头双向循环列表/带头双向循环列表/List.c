#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"
void TestList()
{
	List list;
	ListInit(&list);
	ListPushBack(&list, 1);
	ListPushBack(&list, 2);
	ListPushBack(&list, 3);
	ListPushBack(&list, 4);
	ListPrint(&list);
	/*ListPopBack(&list);
	ListPopBack(&list);
	ListPopBack(&list);*/
	/*ListPushFront(&list, 5);
	ListPushFront(&list, 6);
	ListPushFront(&list, 7);
	ListPrint(&list);
	ListPopFront(&list);
	ListPopFront(&list);
	ListPrint(&list);
	ListNode* pos;
	pos = ListFind(&list,2);
	ListInsert(pos, 8);
	ListPrint(&list);
	ListErase(&list,pos);
	ListPrint(&list);
	ListRemove(&list, 3);
	ListPrint(&list);*/
	//printf("size=%d\n", ListSize(&list));
	ListReverse(&list);
	ListPrint(&list);

}
ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->_next = NULL;
	node->_prev = NULL;
	node->_data = x;
	return node;
}
void ListInit(List* plist)
{
	assert(plist);
	//˫��������ͷ������Ҫ������head����һ��ռ�
	plist->_head = BuyListNode(-1);
	ListNode* head = plist->_head;
	head->_next = head;
	head->_prev = head;
	plist->_head = head;
}
void ListDestory(List* plist)
{
	assert(plist);
	//��������ͷ���
	ListNode* cur = plist->_head;
	ListNode* next;
	while (cur)
	{
		next = cur->_next;
		free(cur);
		cur = NULL;
		cur = next;
	}
}
void ListPushBack(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* newnode = BuyListNode(x);
	ListNode* head = plist->_head;
	ListNode* tail = head->_prev;
	tail->_next = newnode;
	newnode->_prev = tail;
	newnode->_next = head;
	head->_prev = newnode;
}
void ListPrint(List* plist)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* cur = head->_next;
	printf("<-head->");
	while (cur != head)
	{
		printf("<-%d->", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}
void ListPopBack(List* plist)
{
	assert(plist && plist->_head->_next != plist->_head);//����ɾ��ͷ�ڵ�
	ListNode* head = plist->_head;
	ListNode* tail = head->_prev;
	ListNode* cur = tail->_prev;
	free(tail);
	cur->_next = head;
	head->_prev = cur;
}
void ListPushFront(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* newnode = BuyListNode(x);
	ListNode* head = plist->_head;
	ListNode* first = head->_next;
	head->_next = newnode;
	newnode->_prev = head;
	newnode->_next = first;
	first->_prev = newnode;
}
void ListPopFront(List* plist)
{
	assert(plist && plist->_head->_next != plist->_head);
	ListNode* head = plist->_head;
	ListNode* next = head->_next;
	ListNode* nextnext = next->_next;
	free(next);
	head->_next = nextnext;
	nextnext->_prev = head;
}
ListNode* ListFind(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* cur = head->_next;
	while (cur != plist->_head)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* newnode = BuyListNode(x);
	ListNode* prev = pos->_prev;
	prev->_next = newnode;
	newnode->_prev = prev;
	newnode->_next = pos;
	pos->_prev = newnode;
}
void ListErase(ListNode* pos)
{
	//����ɾ��ͷ���
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* tail = pos->_next;
	prev->_next = tail;
	tail->_prev = prev;
	free(pos);
}
void ListRemove(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* node = ListFind(plist,x);
	if (node)
	{
		ListErase(node);
	}
}
int ListSize(List* plist)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* cur = head->_next;
	size_t size = 0;
	while (cur != head)
	{
		size++;
		cur = cur->_next;
	}
	return size;
}
//�շ���0���ǿշ���-1
int ListEmpty(List* plist)
{
	assert(plist);
	return plist->_head->_next == plist->_head ? 0 : -1;
}
//1������next��prev
//void ListReverse(List* plist)
//{
//	assert(plist);
//	ListNode* head = plist->_head;
//	ListNode* cur = head->_next;
//	while (cur != head)
//	{
//		ListNode* ptmp = cur->_next;
//		cur->_next = cur->_prev;
//		cur->_prev = ptmp;
//		cur = cur->_prev;
//	}
//	//ͷ�ڵ��next��prev����
//	ListNode* ptmp = head->_next;
//	head->_next = head->_prev;
//	head->_prev = ptmp;
//}
//2������begin��end;���ַ���ֻ������ֵ��û�иı�����ڵ�֮������ӹ�ϵ�����Բ��ù�ͷ���
void ListReverse(List* plist)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* begin = head->_next;
	ListNode* end = head->_prev;
	while (begin != end && end->_next != begin)
	{
		LTDataType tmp = begin->_data;
		begin->_data = end->_data;
		end->_data = tmp;

		begin = begin->_next;
		end = end->_prev;
	}
}