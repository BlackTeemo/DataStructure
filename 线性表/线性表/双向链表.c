#include"Ë«ÏòÁ´±í.h"


void Init_DuL(DuLinkList DuL)
{
	//if ( DuL )
		//return ERROR;
	//DuL = (DuLinkList)malloc(sizeof(DuLNode));
	DuL->next = DuL;
	DuL->prior = DuL;
	DuL->data = 0;
}

 DuLinkList  GetElemP_DuL(DuLinkList DuL, int i )
{
	DuLinkList P = DuL; 
	if (i == 1)
		return P;
	if (P->next != P)
	{
		for (int Tmp = 0; Tmp < i - 1 && P != DuL;++Tmp )
		{
			P = P->next;
		}
	}
	return P;
}

Status ListInsert_DuL(DuLinkList* DuL, int i, ElemType e)
{
	DuLinkList P = GetElemP_DuL(*DuL, i);
	DuLinkList S = (DuLinkList)malloc(sizeof(DuLNode));
	
	S->data = e;
	S->prior = P->prior;
	P->prior->next = S;
	S->next = P;
	P->prior = S;
	if (i == 1)
		*DuL = S;
	return OK;
}


void Visit_DuL(DuLinkList DuL)
{
	DuLinkList P = DuL->next ;
	printf("%d ", DuL->data);
	while (P != DuL)
	{
		printf("%d ", P->data );
		P = P->next;
	}
	printf("\n");
}


void Free_DuL(DuLinkList DuL)
{
	DuLinkList P = DuL->next;
	DuLinkList K = NULL;
	while (P != DuL)
	{
		K = P->next;
		free(P);
		P = K;
	}
	free(DuL);

}