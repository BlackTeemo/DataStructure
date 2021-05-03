#include"PoLynomial.h"

void InitList(polynomial** L)
{
	*L = (polynomial*)malloc(sizeof(polynomial));
	(*L)->len = 0;
	(*L)->head = NULL;
	//L->tail = NULL;
}

Position GetHead(LinkList* L)
{
	Link P = L->head;
	if (!P) //如果为NULL 申请新空间
	{
		P = (Position)malloc(sizeof(struct LNode));
		P->next = L->head;
		L->head = P;
	}
	return P;
}


void CreatPolyn(polynomial** P, int n)
{

	InitList(P);
	//Link h = GetHead(*P);
	ElemType e;
	char c;
	Position q = NULL;
	for (int i = 0; i < n; ++i)
	{
		scanf("%f%d", &(e.coef), &(e.expn));
		c = getchar();
		int Tmp = LocateElem(*P, &e, &q, Compare);
		if (Tmp == 1)
		{
			q->data.coef = q->data.coef + e.coef;
			q->data.expn = q->data.expn + e.expn;
		}
		else if(Tmp == FALSE)
		{
			Position Tmp = (Position)malloc(sizeof(struct LNode));
			Tmp->data.coef = e.coef;
			Tmp->data.expn = e.expn;
			Tmp->next = NULL;
			InsFirst(q, Tmp);
		}
		else
		{
			q->data.coef = e.coef;
			q->data.expn = e.expn;
		}

	}
}

//Status SetCurElem(Link L, ElemType* e)
//{
	//(L->data).coef = e->coef;
	//(L->data).expn = e->expn;
//}

Status LocateElem(LinkList* L, ElemType* e, Position** q, int(*Compare)(ElemType, ElemType))
{
	Position K = NULL;
	Position  P = L->head;
	if (P == NULL)
	{
		Position T = (Position)malloc(sizeof(struct LNode));
		T->data.coef = 0;
		T->data.expn = 0;
		T->next = L->head;
		L->head = T;
		*q = T;
		return 2;
	}
	while (P)
	{
		if (Compare(P->data, *e) == 0)
		{
			*q = P;
			return TRUE;
		}
		else if (Compare(P->data, *e) > 0)
		{
			*q = K;
			return FALSE;
		}
		else
		{
			K = P;
			P = P->next;
		}
	}

	*q = K;
	return FALSE;
}

int Compare(term a, term b)
{
	if (a.expn < b.expn)
		return -1;
	else if (a.expn == b.expn)
		return 0;
	else if (a.expn > b.expn)
		return 1;
}

Status InsFirst(Link h, Link s)
{
	s->next = h->next;
	h->next = s;
	return OK;
}

void Visit(LinkList* L)
{
	Position  P = L->head;
	int n = 0;
	while (P)
	{
		if (n == 0)
			printf("%fX^%d",P->data.coef,P->data.expn);
		else
		{
			printf(" + %fX^%d", P->data.coef, P->data.expn);
		}
		P = P->next;
		n++;
	}
}


void AddPolyn(polynomial* Pa, polynomial* Pb)
{
	//Position Na = Pa->head;
	//Position Nb = Pa->head;

	//Position q = NULL;
	//Position Tmp;
	//while (Na && Nb)
	//{
	//	switch (LocateElem(Pa, &(Nb->data), &q, Compare))
	//	{
	//	case TRUE:
	//		q->data.coef = q->data.coef + Nb->data.coef;
	//		
	//		break;
	//	case FALSE:
	//		Tmp = (Position)malloc(sizeof(struct LNode));
	//		Tmp->data.coef = Nb->data.coef;
	//		Tmp->data.expn = Nb->data.expn;
	//		
	//		Tmp->next = q->next;
	//		q->next = Tmp;
	//		InsFirst(q, Tmp);
	//		
	//		break;
	//	}
	//	Nb = Nb->next;
	//}
	Link La = Pa->head;
	Link PLa = Pa->head;
	Link Lb = Pb->head;
	free(Pb);
	while (Lb)
	{
		int n = 0;
		La = Pa->head;
		PLa = Pa->head;
		while (La)
		{

			if (La->data.expn == Lb->data.expn)
			{
				La->data.coef = La->data.coef + Lb->data.coef;
				Link Tmp = Lb;
				Lb = Lb->next;
				free(Tmp);
				break;
			}
			else if (La->data.expn > Lb->data.expn)
			{
				Link Tmp = Lb;
				Lb = Lb->next;
				Tmp->next = La;
				if (n == 0)
				{
					Pb->head = Tmp;
					break;
				}
				else
				{
					PLa->next = Tmp;
					break;
				}
			}
			else
			{
				if (n == 0)
				{
					La = La->next;
					n++;
					continue;
				}
				else
				{
					PLa = PLa->next;
					La = La->next;
					n++;
					continue;
				}
			}
		}
		if (La == NULL)
		{
			Link Tmp = Lb;
			Lb = Lb->next;
			PLa->next = Tmp;
			Tmp->next = La;
		}
		
		
	}
	
}


void FreeList(polynomial* P)
{
	Link L1 = P->head;
	Link L2;
	while (L1)
	{
		L2 = L1->next;
		free(L1);
		L1 = L2;
	}
	free(P); 
}


Status NewCompare(LinkList* L, term* T)
{
	Link P = L->head;
	if (!L || !T)
		return -1;
	while (P)
	{
		if (P->data.expn == T->expn)
	{
		P->data.coef = P->data.coef + T->coef;
		return 0;
	}
		else if (P->data.expn > T->expn)
		{

		}
	}
}


