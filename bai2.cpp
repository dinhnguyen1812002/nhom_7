#include<stdio.h>


struct Node
{
	int Data; 
	struct Node *pLeft;
	struct Node *pRight;
};
typedef struct Node NODE;
typedef NODE* Tree;


void Init(Tree &t)
{
	t = NULL;
}


void InSert(Tree &t, int x)
{
	
	if(t == NULL)
	{
		NODE *q = new NODE;
		q ->Data = x;
		q ->pLeft = q ->pRight = NULL;
		t = q;
	}
	else
	{
		if(t ->Data > x)
		{
			InSert(t ->pLeft, x);
		}
		else if(t ->Data < x)
		{
			InSert(t ->pRight, x);
		}
	}
}
void deleteTree(Tree &t) {
    if (t == NULL) {
        return;
    }
    if (t->pLeft) {
        deleteTree(t->pLeft);
    }
     if (t->pRight) {
        deleteTree(t->pRight);
    }
    delete t;

  t=NULL;
}
void CreateTree(Tree &t)
{
	Init(t); 
	int LuaChon;
	do{
	printf("\n1. Nhap du lieu");
		printf ( "\n0. Ket thuc");
		printf  ("\nNhap vao lua chon cua ban: ");
		scanf("%d",&LuaChon) ;

		if(LuaChon == 1)
		{
			int x;
			printf( "\nNhap du lieu Node can them: ");
			scanf("%d",&x);
			InSert(t, x); 
		}
	}while(LuaChon != 0);
}

void NLR(Tree t)
{
	if(t != NULL)
	{
		printf("\t%d",t->Data);
		NLR(t ->pLeft);
		NLR(t ->pRight);
	}
}

void LNR(Tree t)
{
	if(t != NULL)
	{
		LNR(t ->pLeft);
		printf("\t%d",t->Data);
		LNR(t ->pRight);
	}
}

void LRN(Tree t)
{
	if(t != NULL)
	{
		LRN(t ->pLeft);
		LRN(t ->pRight);
		printf("\t%d",t->Data);
	}
}

void TimPhanTuTheMang(Tree &p, Tree &q) 
{

	if(q ->pRight != NULL)
	{
		TimPhanTuTheMang(p, q ->pRight);
	}
	else 
	{
		p ->Data = q ->Data; 
		p = q; 
		q = q ->pLeft; 
	}
}

void XoaNode(Tree &t, int x) 
{

	if(t == NULL)
	{
		return;
	}
	if(t ->Data > x)
	{
		XoaNode(t ->pLeft, x);
	}
	else if(t ->Data < x)
	{
		XoaNode(t ->pRight, x);
	}
	else 
	{
		NODE *p = t; 
		
		
		if(t ->pLeft == NULL)
		{
			
			t = t ->pRight;
		}
		else if(t ->pRight == NULL)
		{
			
			t = t ->pLeft;
		}
		
		else 
		{
			
			TimPhanTuTheMang(p, t ->pLeft);
			
            
		}
		delete p; 
	}
}

int main()
{
	Tree t; 
	int chon;
	printf("1.Nhap cay:");
	printf("\n2.Duyet cay:");
	printf("\n3.XoaNode :");
	printf("\n4.XoaCay:");
	do{
		printf("\nBan muon lam gi? ");scanf("%d",&chon);
		switch (chon){
			case 1:
				CreateTree(t);
				break;
			case 2:
				printf("\nNLR\n");
				NLR(t);

				printf("\nLNR\n");
				LNR(t);

				printf("\nLRN\n");
				LRN(t);
				break;
			case 3 :
				int y;
				printf( "\nNhap vao Node can xoa: ");
				scanf("%d",&y);

				XoaNode(t, y);

				printf("\nCay sau khi xoa: \n") ;
				printf("\nNLR\n") ;
				NLR(t);
				break;
			case 4 :
				deleteTree(t);
				NLR(t);
		}
	}while(chon != 0);
	return 0;
}
