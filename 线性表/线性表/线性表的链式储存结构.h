#include"DataStructure.h"


typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode , *LinkList;

Status GetElem_L(LinkList, int , ElemType *); // ��ȡָ��λ�ýڵ������

Status ListInsert_L(LinkList, int, ElemType); //ָ��λ�ò���Ԫ��e

Status ListDelete_L(LinkList, int, ElemType*); //ɾ��ָ��λ�õ�Ԫ�ز���e���ظ�ֵ

void  CreateList_L(LinkList  , int ); //���򴴽�����

void MergeList_L(LinkList, LinkList, LinkList); //�鲢������������

void Visit_L(LinkList); // ��������

void CreateList_LL(LinkList,int); //���򴴽�

void Destory_L(LinkList); //��������

void Merge_L(LinkList, LinkList);//������������

Status DeleteAndInsertSub(LinkList, LinkList, int, int, int);

Status DeleteBetween(LinkList, int, int); //ɾ�������н�������ֵ֮��Ľڵ�

Status Reverse_L(LinkList *); // ��������

void DestoryR_L(LinkList);// ����ݻ�

void VisitR_L(LinkList); //�������
