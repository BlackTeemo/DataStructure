#include"DataStructure.h"


typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode , *LinkList;

Status GetElem_L(LinkList, int , ElemType *); // 获取指定位置节点的数据

Status ListInsert_L(LinkList, int, ElemType); //指定位置插入元素e

Status ListDelete_L(LinkList, int, ElemType*); //删除指定位置的元素并用e返回该值

void  CreateList_L(LinkList  , int ); //倒序创建链表

void MergeList_L(LinkList, LinkList, LinkList); //归并两个有序链表

void Visit_L(LinkList); // 遍历链表

void CreateList_LL(LinkList,int); //正序创建

void Destory_L(LinkList); //销毁链表

void Merge_L(LinkList, LinkList);//连接两个链表

Status DeleteAndInsertSub(LinkList, LinkList, int, int, int);

Status DeleteBetween(LinkList, int, int);