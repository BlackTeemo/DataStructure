#include"线性表的静态单链表储存结构.h"

int LocateElem_SL(SLinkList* S, ElemType e)
{
	
	int n = S[0]->cur;
	while (n)
	{
		if (S[n]->data == e)
			break;
		
		n = S[n]->cur;
	}
	return n;
}

void InitSpace_SL(SLinkList* Space)
{
	for (int i = 0; i < MAXSIZE - 1; ++i)
	{
		Space[i]->cur = i + 1;
	}
	Space[MAXSIZE - 1]->cur = 0;
}


int Malloc_SL(SLinkList* Space)
{
	int i = Space[0]->cur;
	if (Space[0]->cur)
	{
		Space[0]->cur = Space[i]->cur;
	}

	return i;
}

void Free_SL(SLinkList* Space, int K)
{
	Space[K]->cur = Space[0]->cur;
	Space[0]->cur = K;
}

void difference(SLinkList* Space)
{
	InitSpace_SL(Space);
	int S = Malloc_SL(Space);
	int r = S;
	int m, n, i;
	scanf("%d%d", &m, &n);
	char c = getchar();

	for (int j = 1; j <= m; ++j)
	{
		i = Malloc_SL(Space);
		scanf("%d", &(Space[i]->data));
		c = getchar();

		Space[r]->cur = i;
		r = i;

	}

	Space[r]->cur = 0; // 尾节点置空 
	int Tmp;
	int p , K;
	for (int j = 1; j <= n; ++j)
	{
		scanf("%d", &Tmp);
		c = getchar();
		p = S;
		K = Space[p]->cur;
		while (K && Space[K]->data != Tmp)
		{
			p = K;
			K = Space[K]->cur;
		}
		if (K == Space[r]->cur) //没找到
		{
			i = Malloc_SL(Space);
			Space[i]->data = Tmp;
			Space[i]->cur = Space[r]->cur;
			Space[r]->cur = i;
			r = i;
		}
		else
		{
			Space[p]->cur = Space[K]->cur;
			Free_SL(Space, K);
			if (r == K)
				r = p;
		}
	}

}

void Visit(SLinkList* Space)
{
	int P = Space[1]->cur;
	while (P)
	{
		printf("%d ", Space[P]->data);
		P = Space[P]->cur;
	}
	printf("\n");

}