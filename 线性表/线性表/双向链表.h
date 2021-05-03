#include"DataStructure.h"

typedef struct DuNode
{
	ElemType data;
	struct DuNode* prior;
	struct DuNode* next;

}DuLNode,*DuLinkList;

void Init_DuL(DuLinkList);

DuLinkList  GetElemP_DuL(DuLinkList,int);  //����ָ��λ�õĽڵ� 1 =< i <= ��+1

Status ListInsert_DuL(DuLinkList*, int, ElemType); // �ڵ�i��λ��֮ǰ����Ԫ��e 

void Visit_DuL(DuLinkList); //����˫������

void Free_DuL(DuLinkList); // �ͷ� 