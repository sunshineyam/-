////#define _CRT_SECURE_NO_WARNINGS 1
//#include "Sqlist.h"
//void SlistInit(Slist* plist)
//{
//	assert(plist);
//	plist->_head = NULL;
//}
//void SlistPrint(Slist* plist)
//{
//	assert(plist);
//	SlistNode* cur = plist->_head;
//	while (cur)
//	{
//		printf("%d->", cur->_data);
//		cur = cur->_next;
//	}
//	printf("NULL");
//}
//SlistNode* BuySlistNode(SLDataType x)
//{
//	SlistNode* newNode = (SlistNode*)malloc(sizeof(SlistNode));
//	newNode->_data = x;
//	newNode->_next = NULL;//NULLָ��ָ�����ڴ�Ϊ0�ĵ�ַ
//	return newNode;
//}
//void SlistPushFront(Slist* plist, SLDataType x)
//{
//	assert(plist);
//	SlistNode* newhead= BuySlistNode(x);
//	newhead->_next = plist->_head;//newhead��ָ��ָ��ԭ����ͷ
//	plist->_head = newhead;//ԭ����ͷָ��newhead
//}
//void SlistPushBack(Slist* plist, SLDataType x)
//{
//	assert(plist);
//	SlistNode* cur = plist->_head;
//	if (plist->_head == NULL)
//	{
//		plist->_head = BuySlistNode(x);
//	}
//	else
//	{
//		while (cur->_next)
//		{
//			cur = cur->_next;
//		}
//		SlistNode* newNode = BuySlistNode(x);
//		cur->_next = newNode;
//	}
//}
//void SlistPopFront(Slist* plist)
//{
//	assert(plist);
//	SlistNode* next = plist->_head->_next;
//	free(plist->_head);
//	next = plist->_head;
//}
//void SlistPopBack(Slist* plist)
//{
//	assert(plist);
//	SlistNode* cur = plist->_head;
//	SlistNode* prev = NULL;
//	if (plist->_head == NULL)
//	{
//		free(plist->_head);
//		plist->_head = NULL;
//	}
//	else
//	{
//		//while (cur->_next)
//		//{
//		//	prev = cur;//prev��������cur��ǰһ��λ�õĽڵ㣬���������Ļ���
//		//	           //ֱ��free�����һ���ڵ㣬��ô�����ڶ����ڵ�ͻ���Ұָ��
//		//	cur = cur->_next;
//		//}
//		//free(cur);
//		//prev->_next = NULL;
//		while (cur->_next->_next)
//		{
//			cur = cur->_next;
//		}
//		free(cur->_next);
//		cur->_next = NULL;
//	}
//}
//SlistNode* SlistFind(Slist* plist, SLDataType x)
//{
//	assert(plist);
//	SlistNode* cur = plist->_head;
//	while (cur)
//	{
//		if (cur->_data == x)
//		{
//			return cur;
//		}
//		cur = cur->_next;
//	}
//	return cur;
//}
//void SlistInsertAfter(SlistNode* pos, SLDataType x)
//{
//	assert(pos);
//	SlistNode* newNode = BuySlistNode(x);
//	SlistNode* next = pos->_next;
//	pos->_next = newNode;
//	newNode->_next = next;
//}
////void SlistEraseAfter(SlistNode* pos)
////{
////	assert(pos);
////	SlistNode* next = pos->_next;
////	SlistNode* nextNext = next->_next;
////	pos->_next = nextNext;
////	free(next);
////	next = NULL;
////}
//void SlistRemove(Slist* plist, SLDataType x)
//{
//	assert(plist);
//	SlistNode* prev = plist->_head;
//	SlistNode* cur = prev->_next;
//	while (cur)
//	{
//		if (cur->_data == x)
//		{
//			prev->_next = cur->_next;
//			free(cur);
//			cur = prev->_next;
//		}
//		else
//		{
//			prev = cur;
//			cur = cur->_next;
//		}
//	}
//	if (plist->_head == x)
//	{
//		plist->_head = plist->_head->_next;
//	}
//}
//void SlistDesory(Slist* plist)
//{
//	assert(plist);
//	SlistNode* cur = plist->_head;
//	while (cur)
//	{
//		SlistNode* next = cur->_next;
//		free(cur);
//		cur = next;
//	}
//	plist->_head = NULL;
//}
//
//void test()
//{
//	Slist* list;
//	SlistInit(&list);
//	SlistPushFront(&list, 1);
//	SlistPushFront(&list, 2);
//	SlistPushFront(&list, 3);
//	SlistPushFront(&list, 5);
//	SlistPrint(&list);
//
//	/*SlistPushBack(&list, 5);
//	SlistPushBack(&list, 6);
//	SlistPrint(&list);
//
//	SlistFind(&list, 7);*/
//	/*SlistNode* pos = SlistFind(&list, 3);
//	SlistInsertAfter(pos,7);
//	SlistPrint(&list);*/
//	/*SlistEraseAfter(1);
//	SlistPrint(&list);*/
//	SlistDesory(&list);
//}
//
//
//
////1��cur����ͷ�Ľڵ㣻prev����ͷǰ����Ǹ��ڵ�
////1��ɾ�������е��ڸ���ֵval�����нڵ�
////void removeElements(SlistNode* _head, int val)
////{
////	 assert(_head);
////	 SlistNode* prev = NULL;
////	 SlistNode* cur = _head;
////	 SlistNode* next = NULL;
////	while (cur)
////	{
////		if (cur->_data == val)
////		{
////			next = cur->_next;
////			free(cur);
////			cur = next;
////			if (prev == NULL)
////			{
////				_head = next;
////			}
////			else
////			{
////				prev->_next = next;
////			}
////		}
////		else
////		{
////
////		}
////	}
////}
//////2����תһ��������
//////2��1->2->3->4->NULL
//////NULL<-1-<2-<3-<4
////SlistNode* reverseList(SlistNode* _head)
////{
////	SlistNode* prev = NULL;
////	SlistNode* cur = _head;
////	SlistNode* next = NULL;
////	while (cur)
////	{
////		//�Ȼ�ȡ��һ���ڵ�
////		next = cur->_next;//
////		//����ָ��
////		cur->_next = prev;
////		prev = cur;
////		cur = next;
////	}
////	return prev;
////}
//////3������һ������ͷ��� head �ķǿյ���������������м��㡣����������м��㣬�򷵻صڶ���
//////   �м���
//////SlistNode* middleNode(SlistNode* _head)
//////{
//////	struct SlistNode* cur = _head;
//////	int count = 0;
//////	int mid = 0;
//////	//ͳ������ڵ����
//////	while (cur)
//////	{
//////		count++;
//////		cur = cur->_next;
//////	}
//////	mid = count / 2;
//////	cur = _head;
//////	while (mid--)
//////	{
//////		cur = cur->_next;
//////	}
//////	return cur;
//////}
//////slow ÿ���ƶ�һ��λ�ã�fastÿ���ƶ�����λ�ã���fastΪ��ʱ��slow�Ƶ��м�λ��
//////ż�����м���Ϊ�������ĵڶ���
////SlistNode* middleNode(SlistNode* head)
////{
////	struct SlistNode* slow = head;
////	struct SlistNode* fast = head;
////	while (fast && fast->_next)                      
////	{
////		slow = slow->_next;
////		fast = fast->_next->_next;
////	}
////	return slow;
////}
//////4������һ����������������е�����k����㡣
//////��fastָ������k����Ȼ��slow��fastһ���ߣ���fast�ߵ�nullʱ��slow�ߵ�������k���ڵ�
////SlistNode* FindKthToTil(SlistNode* _head, unsigned int k)
////{
////	struct SlistNode* slow = _head;
////	struct SlistNode* fast = _head;
////	while (k--)
////	{
////		if (fast)
////		{
////			fast = fast->_next;
////		}
////		else
////			return NULL;//K����������ܽڵ���
////	}
////	while (fast)
////	{
////		fast = fast->_next;
////		slow = slow->_next;
////	}
////	return slow;
////}
//////5����������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵ�
//////   �ҵ��������ͷ�ڵ㣺��������ֵС��ͷ�ڵ���Ϊ�������ͷ�ڵ�
//////   ����Ƚ����������ʣ��Ԫ�أ�����С����β�嵽�µ�������
////// SlistNode* mergeTwoLists(SlistNode* l1, SlistNode* l2)
//////{
//////	SlistNode* _head;
//////	SlistNode* tail = NULL;
//////	
//////	if (l1 == NULL)
//////	{
//////		return l1;
//////	}
//////	if (l2 == NULL)
//////	{
//////		return l2;
//////	}
//////	//ȷ���µ�ͷ�ڵ�
//////	if (l1->_data < l2->_data)
//////	{
//////		_head = l1;
//////		l1 = l1->_next;
//////	}
//////	if (l1->_data < l2->_data)
//////	{
//////		_head = l2;
//////		l2 = l2->_next;
//////	}
//////	tail = _head;
//////	while (l1 && l2)
//////	{
//////		// ȷ�������Ԫ��
//////		if (l1->_data < l2->_data)
//////		{
//////			tail->_next = l1;
//////			tail = tail->_next;
//////			l1 = l1->_next;
//////		}
//////		else 
//////		{
//////			tail->_next = l2;
//////			tail = tail->_next;
//////			l2 = l2->_next;
//////		}
//////	}
//////	//ȷ�����һ��Ԫ��
//////	if (l1)
//////	{
//////		tail->_next = l1;
//////	}
//////	if (l2)
//////	{
//////		tail->_next = l2;
//////	}
//////	return _head;
//////}
//
//
struct ListNode* partition(struct ListNode* pHead, int x) 
{
	struct ListNode* lhead, *ltail;
	struct ListNode* ghead, *gtail;
	struct ListNode* cur = pHead;
	lhead = (struct ListNode*)malloc(sizeof(struct ListNode*));
	ghead = (struct ListNode*)malloc(sizeof(struct ListNode*));
	while (cur)
	{
		if (cur->val<x)
		{
			ltail->next = cur;
			ltail = ltail->next;
		}
		else
		{
			gtail->next = cur;
			gtail = gtail->next;
		}
		cur = cur->next;
	}
	gtail->next = NULL;
	ltail->next = ghead->next;
	return lhead->next;

}