#include"线性表顺序存储结构.h"

Status InitList_Sq(SqList* L)
{
	L->elem = (ElemType* )malloc(sizeof(ElemType) * LIST_INIT_SIZE);
	if (!L->elem)
		exit(OVERFLOW);
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return OK;
}

Status ListInsert_Sq(SqList* L, int i, ElemType e)
{
	if (i < 1 || i > L->length + 1)
		return ERROR;
	if (i >= L->listsize)
	{
		ElemType* newSpace = (ElemType*)realloc((void *)L, ((size_t)L->listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newSpace)
			exit(OVERFLOW);
		L->elem = newSpace;
		L->listsize += 10;
	}
	ElemType* q = &(L->elem[i - 1]);   //插入位置
	for (ElemType* p = &(L->elem[L->length - 1]); p >= q; p--)
	{
		*(p + 1) = *p;
	}
	*q = e;
	L->length++;
	return OK;

}


Status ListDelete_Sq(SqList* L, int i, ElemType* e)
{

	if (i < 1 || i > L->length)
		return ERROR;
	ElemType* p = &(L->elem[i - 1]);
	e = *p;
	ElemType* q = &(L->elem[L->length - 1]);
	for (; p < q; p++)
	{
		*p = p[1];
	}
	L->length--;
	*q = 0;
	return OK;
}

Status LocateElem_Sq(SqList* L, ElemType e, Status(*Compare)(ElemType, ElemType))
{
	int i = 1;

	ElemType* p = &(L->elem[0]);
	while (i <= L->length && !Compare(*p, e))
	{
		i++;
		p++;
	}

	if (i <= L->length)
		return i;
	else
		return 0;
}


Status Compare(ElemType X, ElemType Y)
{
	if (X == Y)
		return TRUE;
	else
		return FALSE;
}


void MergeList_Sq(SqList* La, SqList* Lb, SqList* Lc)
{
	ElemType* Pa = La->elem;
	ElemType* Pb = Lb->elem;
	Lc->length = 0;
	Lc->listsize = La->length + Lb->length;
	Lc->elem = (ElemType*)malloc(Lc->listsize * sizeof(ElemType));
	if (!Lc->elem)
		exit(OVERFLOW);
	ElemType* Pc = Lc->elem;
	while (Pa <= &(La->elem[La->length - 1]) && Pb <= &(Lb->elem[Lb->length - 1]))
	{

		if (*Pa <= *Pb)
			*(Pc++) = *(Pa++);
		else
			*(Pc++) = *(Pb++);
		Lc->length++;
	}

	while (Pa <= &(La->elem[La->length - 1]))
		* (Pc++) = *(Pa++);
		Lc->length++;
	while (Pb <= &(Lb->elem[Lb->length - 1]))
		*(Pc++) = *(Pb++);
		Lc->length++;
}



void Destory_Sq(SqList* L)
{
	if (L->elem)
		free(L->elem);
}

void Visit_Sq(SqList* L)
{
	if (L->length == 0)
		return ERROR;
	ElemType* P = L->elem;

	for (; P <= &(L->elem[L->length - 1]); P++)
	{
		printf("%d ", *P);
	}
	printf("\n");


}



void DeleteK(SqList* L, int i, int K)
{
	if (0 < i <= L->length && K >= 0 && K <= L->length - i + 1)
	{
		if (K == 0)
			return;
		//memcpy(&(L->elem[i - 1]), &(L->elem[i - 1 +K ]), sizeof(ElemType) * (L->length - i - K + 1 ));
		for (int J = i; J + K  <= L->length + 1 ; ++J)
		{
			L->elem[J - 1] = L->elem[J + K - 1];
		}
		L->length = L->length - K;
	}

}

void OrderInsert_Sq(SqList* L, ElemType e)
{
	if (L->length >= L->listsize)
	{
		L->elem = realloc(L->elem, sizeof(ElemType) * (L->length + LISTINCREMENT));
		L->listsize += LISTINCREMENT;
	}
	/* int i;
	for ( i = 0; i < L->length; ++i)
	{
		if (e <= L->elem[i])
		{
			for (int T = L->length - 1; T >= i; --T)
			{
				L->elem[T + 1] = L->elem[T];
			}
			L->elem[i] = e;
			break;
		}
	}
	if (i == L->length)
		L->elem[i] = e;
	*/

	int J = L->length - 1;
	
	while (J >= 0 && e < L->elem[J])
	{
		J--;
	}

	for (int i = L->length - 1; i >= J + 1; --i)
	{
		L->elem[i + 1] = L->elem[i];
	}
	L->elem[J + 1] = e;
	L->length++;
}

Status Compare_Sq(SqList *L1, SqList *L2)
{
	int i;
	for ( i = 0; i < L1->length && i < L1->length; ++i)
	{
		if (L1->elem[i] == L2->elem[i])
			continue;
		else
		{ 
			if (L1->elem[i] < L2->elem[i])
				return 1; // A < B ;
			else
				return -1; //A > B
		}
	}
	if (i == L1->length && i == L2->length)
		return 0; //A = B
	else if (i == L1->length && i < L2->length)
		return 1;  //A < B
	else if (i > L1->length && i == L2->length)
		return -1;  //A > B
}