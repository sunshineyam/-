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
//	newNode->_next = NULL;//NULL指针指的是内存为0的地址
//	return newNode;
//}
//void SlistPushFront(Slist* plist, SLDataType x)
//{
//	assert(plist);
//	SlistNode* newhead= BuySlistNode(x);
//	newhead->_next = plist->_head;//newhead的指针指向原来的头
//	plist->_head = newhead;//原来的头指向newhead
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
//		//	prev = cur;//prev用来保存cur的前一个位置的节点，如果不保存的话，
//		//	           //直接free了最后一个节点，那么倒数第二个节点就会变成野指针
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
////1、cur代表头的节点；prev代表头前面的那个节点
////1、删除链表中等于给定值val的所有节点
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
//////2、反转一个单链表
//////2、1->2->3->4->NULL
//////NULL<-1-<2-<3-<4
////SlistNode* reverseList(SlistNode* _head)
////{
////	SlistNode* prev = NULL;
////	SlistNode* cur = _head;
////	SlistNode* next = NULL;
////	while (cur)
////	{
////		//先获取下一个节点
////		next = cur->_next;//
////		//更改指向
////		cur->_next = prev;
////		prev = cur;
////		cur = next;
////	}
////	return prev;
////}
//////3、给定一个带有头结点 head 的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个
//////   中间结点
//////SlistNode* middleNode(SlistNode* _head)
//////{
//////	struct SlistNode* cur = _head;
//////	int count = 0;
//////	int mid = 0;
//////	//统计链表节点个数
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
//////slow 每次移动一个位置；fast每次移动两个位置；当fast为空时，slow移到中间位置
//////偶数的中间数为两个数的第二个
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
//////4、输入一个链表，输出该链表中倒数第k个结点。
//////让fast指针先走k步，然后slow、fast一起走，当fast走到null时，slow走到倒数第k个节点
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
////			return NULL;//K大于链表的总节点数
////	}
////	while (fast)
////	{
////		fast = fast->_next;
////		slow = slow->_next;
////	}
////	return slow;
////}
//////5、将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的
//////   找到新链表的头节点：两个链表值小的头节点作为新链表的头节点
//////   逐个比较两个链表的剩余元素，按从小到大尾插到新的链表当中
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
//////	//确定新的头节点
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
//////		// 确定后面的元素
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
//////	//确定最后一个元素
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