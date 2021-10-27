#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int info;
    struct Node* left;
    struct Node* right;
   
}Node;
typedef Node* Tree;

void init(Tree *&T)
{
    T==NULL;
}
int IsEmpty(Tree* T)
{
    return(T==NULL);
}
Node* CreateNode(Node *p, int x) // chen 1 Node vao cay
{
    p = new Node;
    p->info = x;
    p->left = p->right = NULL;
    return p;   // ok
}
 
Node*  CreateTree(Node *p, int x)        // nhap cay
{   
        printf("Node: "); scanf("%d", &x);
        if (x==0) return NULL;
        p =  CreateNode(p,x);
        printf("Nhap con trai cua node %d: ",x);
        p->left=CreateTree(p->left,x);
        printf("Nhap con phai cua node %d: ",x);
        p->right=CreateTree(p->right,x);
    return p;       
}

//duyen preoder
void LNR(Tree T)
{
     if(T!=NULL)
     {
      LNR(T->left);
      printf("%d   ",T->info);//duyet goc
      LNR(T->right);
     }
}
//inoder
void NLR(Tree T)
{
     if(T!=NULL)
     {printf("%d   ",T->info);
      NLR(T->left);
      NLR(T->right);
     }
}   
//postoder
void LRN(Tree T)//duyet theo thu tu sau
{
     if(T!=NULL)
     {
      LRN(T->left);
      LRN(T->right);
      printf("%d   ",T->info);
     }
}
//tim x
Node* TimX(Tree T, int x)    
{  
    Tree p;
    if (T->info==x) return T;
    if(T==NULL) return NULL;
    p=TimX(T->left,x);
    if(p==NULL) TimX(T->right,x);
}
//tinh chieu cao
int ChieuCao(Tree T)
{
    if(T==NULL)
        return 0;
    int a=ChieuCao(T->left);
    int b=ChieuCao(T->right);
    if(a>b)
        return a+1;
    else
        return b+1;
}
// dem node
int DemNode(Tree T){
     if(T==NULL) return 0;
     else 
        return (DemNode(T->right)+DemNode(T->right))+1; 
    
}
int DEMLA(Tree T)
{   if(T==NULL) return 0;
    else
       if(T->left==NULL && T->right==NULL)
             return 1;
       else 
            return DEMLA(T->left)+DEMLA(T->right);
}
int main()
{
    Tree T;
    int x,chon;
    Node* p;
    do
    {
        printf("1:nhap phan tu cho cay: \n");
        printf("2: duyet cay theo preOder: \n ");
        printf("3:duyet theo inoder \n");
        printf("4:duyet theo postoder \n");
        printf("5: tim phan tu x: \n");
        printf("6:dem node \n");
        printf("7: chieu cao cua node la: \n");
        printf("8: dem so la cua cay: \n");
        printf("0 dung chuong trinh! \n");
        printf("chon: ");
        scanf("%d",&chon);
        switch (chon)
        {
        case 1:
            CreateTree(p,x);
            break;
        case 2:
            LNR(T);
            break;
        case 3:
                NLR(T) ;
                break;
        case 4:
                LRN(T);
             break;
        case 5:

                p=TimX(T,x);
                if(p!=NULL)
                    printf("Tim thay key %d\n", p->info);
                else printf("Key %d khong co trong cay\n", x);    
                break;
        case 6:
                printf("so node cua cay la: %d",DemNode(T));
                
                break;
         case 7:
         printf("chieu cao cua cay la: %d",ChieuCao(T));
               
                break;
        case 8:
                printf("so la cua cay la: %d", DEMLA(T));
                
                 break;       
        default: chon =0;
            break;
        }

    } while (chon!=0);
    

}