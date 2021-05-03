#include"DataStructure.h"
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10 



typedef struct List {

	ElemType* elem; //存储空间基址
	int length; // 当前长度
	int listsize; // 当前分配的储存容量(以sizeof(ElemType)为单位)
}SqList;

Status InitList_Sq(SqList* ); //顺序存储结构初始化

Status ListInsert_Sq(SqList* , int , ElemType ); // 指定位置插入

Status ListDelete_Sq(SqList* , int , ElemType* );//删除指定位置的元素 并用e返回其值

Status LocateElem_Sq(SqList*,ElemType , Status (*Compare)(ElemType,ElemType)); //查找

Status Compare(ElemType, ElemType); //比较函数

void MergeList_Sq(SqList*, SqList*, SqList*); //顺序表的合并

void Destory_Sq(SqList* ); //销毁

void Visit_Sq(SqList*); //遍历

void DeleteK(SqList*, int, int); //删除表中第i个元素起的K个元素

void OrderInsert_Sq(SqList*, ElemType); //插入一个元素 保持该顺序表的有序性

Status Compare_Sq(SqList*, SqList*); //前缀比较法
