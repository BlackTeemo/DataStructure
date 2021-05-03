#include"DataStructure.h"

#define MAXSIZE 100

typedef struct 
{
	ElemType data;
	int cur;
}Component ,SLinkList[MAXSIZE];

void InitSpace_SL(SLinkList*); //初始化静态单链表

int Malloc_SL(SLinkList*); //从备用空间获得一个节点 

void Free_SL(SLinkList*, int);//将下标为K的空闲节点回收到备用链表

int LocateElem_SL(SLinkList*, ElemType ); //定位函数 没查询到返回0 

void difference(SLinkList*); // 

void Visit(SLinkList*);