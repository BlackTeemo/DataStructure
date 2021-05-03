#include"DataStructure.h"

typedef struct DuNode
{
	ElemType data;
	struct DuNode* prior;
	struct DuNode* next;

}DuLNode,*DuLinkList;

void Init_DuL(DuLinkList);

DuLinkList  GetElemP_DuL(DuLinkList,int);  //返回指定位置的节点 1 =< i <= 表长+1

Status ListInsert_DuL(DuLinkList*, int, ElemType); // 在第i个位置之前插入元素e 

void Visit_DuL(DuLinkList); //遍历双向链表

void Free_DuL(DuLinkList); // 释放 