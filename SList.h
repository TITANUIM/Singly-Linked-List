 
 /***************************************************Singly-Linked-List********************************************************************/
 
// 单链表，顾名思义是一种链式存取的数据结构，用一组地址任意的存储单元存放线性表中的数据元素。
// 链表中的数据是以结点来表示的，每个结点的构成：元素(数据元素的映象) + 指针(指示后继元素存储位置)，
// 元素就是存储数据的存储单元，指针就是连接每个结点的地址数据。

//  SList.h

#pragma once
#include<assert.h>
#include <malloc.h>

typedef int DataType;

typedef struct SListNode
{
    DataType data;
    struct SListNode* next;
}SListNode;

void PushBack(SListNode* & pHead, DataType x);
void PopBack(SListNode* & pHead);
void PushFront(SListNode* & pHead, DataType x);
void PopFront(SListNode* & pHead);
SListNode* Find(SListNode* pHead, DataType x);
void Insert(SListNode* pos, DataType x);
void Erase(SListNode* pos);
void DestoryList(SListNode*& pHead);

void DestoryList(SListNode*& pHead)
{
    SListNode* cur = pHead;
    while (cur)
    {
        SListNode* tmp =  cur;
        cur = cur->next;
        free(tmp);
    }

    pHead = NULL;
}

SListNode* _BuyNode(DataType x)
{
    SListNode* tmp = (SListNode*)malloc(sizeof(SListNode));
    tmp->data = x;
    tmp->next = NULL;

    return tmp;
}

void PrintSlist(SListNode* pHead)
{
    SListNode* cur = pHead;
    while (cur)
    {
        printf("%d->",cur->data);
        cur = cur->next;
    }

    printf("NULL\n");
}

//void PushBack(SListNode** ppHead, DataType x)
//{
//    assert(ppHead);
//
//    // 1.空
//    // 2.不为空
//    if(*ppHead == NULL)
//    {
//        *ppHead = _BuyNode(x);
//    }
//    else
//    {
//        // 找尾
//        SListNode* tail = *ppHead;
//        while(tail->next != NULL)
//        {
//            tail = tail->next;
//        }
//
//        tail->next = _BuyNode(x);
//    }
//}

void PushBack(SListNode* & pHead, DataType x)
{
    // 1.空
    // 2.不为空
    if(pHead == NULL)
    {
        pHead = _BuyNode(x);
    }
    else
    {
        // 找尾
        SListNode* tail = pHead;
        while(tail->next != NULL)
        {
            tail = tail->next;
        }

        tail->next = _BuyNode(x);
    }
}

void PopBack(SListNode* & pHead)
{
    //
    // 1.空
    // 2.一个节点
    // 3.多个节点
    //
    if(pHead == NULL)
    {
        return;
    }
    else if(pHead->next == NULL)
    {
        free(pHead);
        pHead = NULL;
    }
    else
    {
        SListNode* tail = pHead;
        SListNode* prev = NULL;
        while (tail->next)
        {
            prev = tail;
            tail = tail->next;
        }

        free(tail);
        prev->next = NULL;
    }
}

void PushFront(SListNode* & pHead, DataType x)
{
    // 1.空
    // 2.不空
    if(pHead == NULL)
    {
        pHead = _BuyNode(x);
    }
    else
    {
        SListNode* tmp = _BuyNode(x);
        tmp->next = pHead;
        pHead = tmp;
    }
}

void PopFront(SListNode*& pHead)
{
    //
    // 1.空
    // 2.一个节点
    // 3.一个以上的节点
    //
    if(pHead == NULL)
    {
        return;
    }
    else if(pHead->next == NULL)
    {
        free(pHead);
        pHead = NULL;
    }
    else
    {
        SListNode* tmp = pHead;
        pHead = pHead->next;

        free(tmp);
    }
}

SListNode* Find(SListNode* pHead, DataType x)
{
    SListNode* cur = pHead;
    while (cur)
    {
        if (cur->data == x)
        {
            return cur;
        }

        cur = cur->next;
    }

    return NULL;
}

void Insert(SListNode* pos, DataType x)
{
    assert(pos);
    
    //SListNode* tmp = _BuyNode(x);
    //SListNode* next = pos->next;
    //pos->next = tmp;
    //tmp->next = next;

    SListNode* tmp = _BuyNode(x);
    tmp->next = pos->next;
    pos->next = tmp;

}

void Erase(SListNode*& pHead, SListNode* pos)
{
    assert(pos);
    assert(pHead);

    if (pHead == pos)
    {
        pHead = pHead->next;
        free(pos);
        return;
    }

    SListNode* prev = pHead;
    while (prev)
    {
        if (prev->next == pos)
        {
            prev->next = pos->next;
            free(pos);
            break;
        }

        prev = prev->next;
    }
}

/////////////////////////////////////////////////
// 删除一个无头单链表的非尾节点
void DelNonTailNode(SListNode* pos)
{
    assert(pos);
    assert(pos->next);

    SListNode* del = pos->next;
    SListNode* next = del->next;

    pos->data = del->data;
    pos->next = next;
    free(del);
}

// 在无头单链表的一个非头节点前插入一个节点
void InsertFrontNode(SListNode* pos, DataType x)
{
    assert(pos);

    //SListNode* tmp = _BuyNode(x);
    //tmp->next = pos->next;
    //pos->next = tmp;

    //DataType tmpData = pos->data;
    //pos->data = tmp->data;
    //tmp->data = tmpData;

    SListNode* tmp = _BuyNode(pos->data);
    tmp->next = pos->next;
    pos->next = tmp;
    pos->data = x;
}

//struct Ret
//{    
//    SListNode* first;
//    SListNode* second;
//};

SListNode* FindMidNode(SListNode* pHead)
{
    SListNode* fast = pHead;
    SListNode* slow = pHead;


    while (fast&&fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    //while (fast)
    //{
    //    if (fast->next)
    //    {
    //        fast = fast->next->next;
    //    }
    //    else
    //    {
    //        break;
    //    }

    //    slow = slow->next;
    //}

    return slow;
}

SListNode* FindKNode(SListNode* pHead, int k)
{
    SListNode* fast = pHead;
    SListNode* slow = pHead;

    while (fast && k--)
    {
        fast = fast->next;
    }

    if (k > 0)
        return NULL;

    while (fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

void PrintTailToHead(SListNode* pHead)
{
    if (pHead)
    {
        PrintTailToHead(pHead->next);
        printf("%d ", pHead->data);
    }
}

SListNode* Reverse(SListNode* pHead)
{
    SListNode* cur = pHead;
    SListNode* newHead = NULL;

    while(cur)
    {
        SListNode* tmp = cur;
        cur = cur->next;

        tmp->next = newHead;
        newHead = tmp;
    }

    return newHead;
}


.cpp 文件：

#include <stdio.h>

#include "SList.h"

// PushBack/PopBack
void Test1()
{
    SListNode* list = NULL;
    PushBack(list, 1);
    PushBack(list, 2);
    PushBack(list, 3);
    PushBack(list, 4);

    PrintSlist(list);


    PopBack(list);
    PopBack(list);
    PopBack(list);
    PopBack(list);
    PopBack(list);

    PrintSlist(list);
}

// PushFront/PopFront
void Test2()
{
    SListNode* list = NULL;
    PushFront(list, 1);
    PushFront(list, 2);
    PushFront(list, 3);
    PushFront(list, 4);
    PrintSlist(list);

    PopFront(list);
    PopFront(list);
    PopFront(list);
    PopFront(list);
    PopFront(list);

    PrintSlist(list);
}

// Find/Insert
void Test3()
{
    SListNode* list = NULL;
    PushFront(list, 1);
    PushFront(list, 2);
    PushFront(list, 3);
    PushFront(list, 4);
    PrintSlist(list);

    SListNode* pos = Find(list, 3);
    Insert(pos, 10);

    pos = Find(list, 1);
    Insert(pos, 100);

    PrintSlist(list);

    // ??
    pos = Find(list, 4);
    Erase(list, pos);

    pos = Find(list, 100);
    Erase(list, pos);

    pos = Find(list, 3);
    Erase(list, pos);

    PrintSlist(list);
}

//DelNonTailNode
void Test4()
{
    SListNode* list = NULL;
    PushBack(list, 1);
    PushBack(list, 2);
    PushBack(list, 3);
    PushBack(list, 4);

    PrintSlist(list);

    SListNode* pos = list;
    DelNonTailNode(pos);

    PrintSlist(list);
}

void Test5()
{
    SListNode* list = NULL;
    PushBack(list, 1);

    SListNode* pos = FindMidNode(list);
    printf("%d\n", pos->data);

    PushBack(list, 2);
    PushBack(list, 3);
    PushBack(list, 4);

    pos = FindMidNode(list);
    printf("%d\n", pos->data);

    pos = FindKNode(list, 4);
    pos = FindKNode(list, 100);
}

void Test6()
{
    SListNode* list = NULL;
    PushBack(list, 1);
    PushBack(list, 2);
    PushBack(list, 3);
    PushBack(list, 4);

    //PrintTailToHead(list);

    list = Reverse(list);
    PrintSlist(list);

    //PrintTailToHead(list);
}

void Test7()
{
    SListNode* list = NULL;
    PushBack(list, 1);
    PushBack(list, 2);
    PushBack(list, 3);
    PushBack(list, 4);
    PushBack(list, 5);
    PushBack(list, 6);
    PushBack(list, 7);

    SListNode* tail = Find(list, 7);
    tail->next = list;

    SListNode* lastOne = JoseCycle(list, 3);
    printf("幸存者：%d\n", lastOne->data);
}

void Test8()
{
    SListNode* list = NULL;
    PushBack(list, 3);
    PushBack(list, 2);
    PushBack(list, 3);
    PushBack(list, 6);
    PushBack(list, 0);
    PushBack(list, 9);
    PushBack(list, 7);
    PrintSlist(list);

    BubbleSort(list);
    PrintSlist(list);
}

void Test9()
{
    SListNode* list1 = NULL, *list2 = NULL;
    PushBack(list1, 2);
    PushBack(list1, 3);
    PushBack(list1, 8);
    PrintSlist(list1);

    PushBack(list2, 1);
    PushBack(list2, 3);
    PushBack(list2, 5);
    PushBack(list2, 7);
    PrintSlist(list2);

    SListNode* list = MergeList(list1, list2);
    PrintSlist(list);

    DestoryList(list);
}

void Test10()
{
    SListNode* list = NULL;
    PushBack(list, 1);
    PushBack(list, 2);
    PushBack(list, 3);
    PushBack(list, 4);
    PushBack(list, 5);
    PushBack(list, 6);
    PushBack(list, 7);
    PrintSlist(list);

    SListNode* tail = Find(list, 7);
    SListNode* enrtyNode = Find(list, 4);
    tail->next = enrtyNode;

    SListNode* meetNode = CheckCycle(list);
    int length = GetCycleLength(meetNode);
    printf("meetNode:%d, length:%d\n", meetNode->data, length);

    SListNode* retEntryNode = GetEntryNode(list);
    //assert(retEntryNode == enrtyNode);
}
