#include"线性表的链式储存结构.h"

Status GetElem_L(LinkList L, int i, ElemType* e)
{
	if (!L->next || i < 0)
		return ERROR;
	LinkList P = L->next;
	int j = 1;
	while (P && j < i)
	{
		P = P->next;
		j++;
	}

	if (!P || i > i)
		return ERROR;
	*e = P->data;
	return OK;
}

Status ListInsert_L(LinkList L, int i, ElemType e )
{
	LinkList P = L;
	int j = 0;
	while (P && j < i-1)
	{
		P = P->next;
		j++;
	}

	if (!P || j > i - 1)
		return ERROR;
	LinkList NewNode = (LinkList)malloc(sizeof(LNode));
	if (!NewNode)
		return ERROR;

	NewNode->data = e;
	NewNode->next = P->next;
	P->next = NewNode;

	return OK;
}

Status ListDelete_L(LinkList L, int i , ElemType* e)
{

	LinkList P = L;
	int j = 0;

	while (P || j < i - 1)
	{
		P = P->next;
		j++;
	}

	if (!P || j > i - 1)
		return ERROR;

	LinkList T = P->next;
	P->next = P->next->next;
	*e = T->data;
	free(T);
	
	return OK;
}

void  CreateList_L(LinkList L, int n)
{
	
	L->next = NULL;
	LinkList P;
	char c;
	for (int i = 0; i < n; ++i)
	{
		P = (LinkList)malloc(sizeof(LNode));
	
		scanf("%d", &P->data);
		c = getchar();
		P->next = L->next;
		L->next = P;
	}

}

void CreateList_LL(LinkList L, int n)
{
	LinkList TL = L;
	LinkList P = NULL;
	char c = 0;
	for (int i = 0; i < n; ++i)
	{
		P = (LinkList)malloc(sizeof(LNode));
		P->next = NULL;
		scanf("%d", &(P->data));
		c = getchar();
		TL->next = P;
		TL = P;	
	}
}

void MergeList_L(LinkList La, LinkList Lb, LinkList Lc)
{
	LinkList Pa = La->next;
	LinkList Pb = Lb->next;
	Lc = La;
	while (Pa && Pb)
	{
		if (Pa->data <= Pb->data)
		{
			Lc->next = Pa;
			Lc = Pa;
			Pa = Pa->next;
		}
		else
		{
			Lc->next = Pb;
			Lc = Pb;
			Pb = Pb->next;
		}

	}

	Lc->next = Pa ? Pa : Pb;
	free(Lb);

}

void Visit_L(LinkList L)
{
	LinkList P = L->next;
	while (P)
	{
		printf("%d ", P->data);
		P = P->next;
	}
	printf("\n");

}

void Destory_L(LinkList L)
{
	LinkList P = L->next;
	LinkList K = NULL;
	while (P)
	{
		K= P->next;
		free(P);
		P = K;
	}

}


void Merge_L(LinkList Ha, LinkList Hb)
{
	LinkList P = Hb->next;
	//free(Hb);
	LinkList Hp = Ha;
	while (Hp->next != NULL)
	{
		Hp = Hp->next;
	}
	Hp->next = P;
}


Status DeleteAndInsertSub(LinkList La, LinkList Lb, int i, int j, int len)
{
	if (i < 0 || j < 0 || len < 0)
		return INFEASIBLE;
	LinkList P = La->next; 
	int K = 1;
	LinkList Prev = NULL;

	while (P && K < i)
	{
		Prev = P;
		P = P->next;
		K++;
	}
	if (!P)
		return INFEASIBLE;
	LinkList q = P;
	K = 1;
	while (q && K < len)
	{
		q = q->next;
		K++;
	}
	if (!q)
		return INFEASIBLE;
	Prev->next = q->next;
	if (j == 1)
	{
		q->next = Lb->next;
		Lb->next = q;
	}
	else
	{
		LinkList s = Lb->next;
		K = 1;
		while (s && K < j - 1)
		{
			s = s->next;
			K++;
		}
		q->next = s->next;
		s->next = P;
	}
	return OK;
}



Status DeleteBetween(LinkList L, int Min_k, int Max_k)
{
	if (Min_k == Max_k)
		return ERROR;
	LinkList Pa = L->next;
	LinkList Pb = L;
	LinkList PPerror = NULL;
								//LinkList PNext = NULL;
	while (Pa != NULL)
	{

		if (Pa->data > Min_k && !PPerror)
		{
			PPerror = Pb;
		}
		else if (Pa->data >= Max_k)
		{
			break;
		}

		Pa = Pa->next;
		Pb = Pb->next;
	}

	//if (Pa == NULL)
	//{
		//printf("表中没有比 Max_k 大的数\n");
	//}
	
	
	LinkList Tmp = PPerror->next;
	LinkList Tmp2 = NULL;
	while (Tmp->next != Pa)
	{
		Tmp2 = Tmp->next;
		free(Tmp);
		Tmp = Tmp2;
	}
	PPerror->next = Tmp->next;
	free(Tmp);

	return(OK);
	
}

Status Reverse_L(LinkList *L)
{
	if (!(*L))
		return ERROR;
	LinkList Pa = (*L)->next;
	LinkList Pb = (*L)->next;
	LinkList Pc = *L;
	LinkList Pd = NULL;
	while (Pa != NULL)
	{
		Pd = Pb;
		Pb = Pa->next;
		Pa->next = Pc;
		Pa = Pb;
		Pc = Pd;
	}
	(*L)->next = NULL;
	*L = Pc;
	//(*L)->next = NULL;
	
	return OK;
}


void DestoryR_L(LinkList L)
{
	if (!L)
		return;
	LinkList P = L;
	while (P->next != NULL)
	{
		L = P->next;
		free(P);
		P = L; 
	}
}

void VisitR_L(LinkList L)
{
	if (!L)
		return;
	while (L->next != NULL)
	{
		printf("%d ", L->data);
		L = L->next;
	}
	printf("\n");
}

void LessReverse_L(LinkList *La, LinkList *Lb)
{
	LinkList Pa, Pb;
	Pa = (*La)->next;
	Pb = (*Lb)->next;
	(*Lb)->next = NULL;
	LinkList Perror = La;
	while (Pa && Pb)
	{
		if (Pa->data < Pb->data)
		{
			Perror->next = Pa;
			Perror = Pa;
			Pa = Pa->next;
		}
		else
		{
			Perror->next = Pb;
			Perror = Pb;
			Pb = Pb->next;
		}
	}
	if (Pa == NULL && Pb != NULL)
		Perror->next = Pb;
	else if( Pa != NULL && Pb == NULL)
		Perror->next = Pa;
	
	//Perror->next = Pa?Pa:Pb;

	Visit_L(*La);
	Reverse_L(La);
}