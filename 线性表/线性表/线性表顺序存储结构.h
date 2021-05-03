#include"DataStructure.h"
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10 



typedef struct List {

	ElemType* elem; //�洢�ռ��ַ
	int length; // ��ǰ����
	int listsize; // ��ǰ����Ĵ�������(��sizeof(ElemType)Ϊ��λ)
}SqList;

Status InitList_Sq(SqList* ); //˳��洢�ṹ��ʼ��

Status ListInsert_Sq(SqList* , int , ElemType ); // ָ��λ�ò���

Status ListDelete_Sq(SqList* , int , ElemType* );//ɾ��ָ��λ�õ�Ԫ�� ����e������ֵ

Status LocateElem_Sq(SqList*,ElemType , Status (*Compare)(ElemType,ElemType)); //����

Status Compare(ElemType, ElemType); //�ȽϺ���

void MergeList_Sq(SqList*, SqList*, SqList*); //˳���ĺϲ�

void Destory_Sq(SqList* ); //����

void Visit_Sq(SqList*); //����

void DeleteK(SqList*, int, int); //ɾ�����е�i��Ԫ�����K��Ԫ��

void OrderInsert_Sq(SqList*, ElemType); //����һ��Ԫ�� ���ָ�˳����������

Status Compare_Sq(SqList*, SqList*); //ǰ׺�ȽϷ�
