#include"DataStructure.h"

typedef struct
{
	float	coef;
	int expn;
}term , ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}*Link , *Position;

typedef struct
{
	Link head;// , tail;
	int len;
}LinkList;

typedef LinkList polynomial;

void InitList(polynomial**); //初始化一个空的线性表

Position GetHead(LinkList* );//

void CreatPolyn(polynomial**, int ); 

Status SetCurElem(Link, ElemType*); //更新指定节点的值

Status LocateElem(LinkList*, ElemType*, Position**, int(*)(ElemType, ElemType));

int Compare(term, term);

Status InsFirst(Link, Link);

void Visit(LinkList*);

void AddPolyn(polynomial*, polynomial*);//多项式加法

void FreeList(polynomial*);

//Status NewCompare(LinkList*, term*);