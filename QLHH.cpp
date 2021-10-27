//quan lí hàng hóa bằng link list 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct HangHoa
{
    char Ma[10];
    char tenmathang[40];
    float gia;
}HH;
typedef struct Node
{
    HH info;
    struct Node* next;

}Node;
Node* head;
void Init (Node* &head)
{
    head = NULL;
}
int IsEmpty (Node* head)
{
    return (head==NULL);
}
Node* CreatNode (HH x)
{
    Node* p=new Node;
    p->info=x;
    p->next=NULL;
    return p;
}
void Nhap1mathang(HH &x)
{
    printf("nhap ma mat hang: "); 
    fflush(stdin);
    gets(x.Ma);
    printf("nhap ten mat hang: ");
    fflush(stdin);
    gets(x.tenmathang);
    printf("nhap diem trung binh ");
    scanf("%f",&x.gia);
}
//Nhập danh sách hàng hóa.
void nhapDS(Node* &head)
{
    int n;
    printf("nhap so luong hang hoa: ");
    scanf("%d",&n);
    HH x;
    for(int i=0;i<n;i++)
    {
        printf("\nnhap mat hang thu nhat: %d\n",i);
        Nhap1mathang(x);
        Node* p = CreatNode(x);//tao một biến p 
        p->next=head; // p trỏ tới địa chỉ của node tiếp theo gán bằng head   
        head= p;
    }
}
void xuat1mathang(HH x)
{
    printf("\n\t\t%s    \t\t%s      \t\t%.2f",x.Ma,x.tenmathang,x.gia);
}
//Xuất danh sách hàng hóa

void xuatDS(Node* head)
{
    Node* p = head;
    printf("\n\tMa mat hang\t\tten mat hang\t\tgia ban\n");
     while (p!=NULL)
        {
            xuat1mathang(p->info);
            p=p->next;
        }
}
//Tìm mặt hàng theo tên hàng, nếu có xuất thông tin mặt hang
//tìm thấy, nếu không có thông báo “Không tìm thấy”.
void TimMatHang(Node* head)
{

	int dem=0;//tao biến đếm bằng không 
     char k[40]; //tao một biến k 
     printf("\nNhap ten mat hang can tim: ");
    fflush(stdin);
    gets(k);
   
	while(head != NULL)
	{
		if(strcmp(head->info.tenmathang,k)==0)// sử dụng strcmp 
		{

			xuat1mathang(head->info);dem++;
		}
		head= head->next;
	}
	if(dem==0) printf("mat hang nay da het hoac khong ton tai !!!");
}
/*Sắp xếp danh sách hang
hóa tăng dần theo giá bán.*/
void swap (HH &a, HH &b)
{
	HH tam = a;
	a=b;
	b=tam;
}
void sapXep(Node* &head)
{
	Node* i= head;
	while(i !=NULL)
	{
		Node* j= head;
		for(j; j!=NULL; j=j->next)
		{
			if(j->info.gia > i->info.gia)
				swap(j->info,i->info);
		}
		i=i->next;
	}
}
int main()
{
    Init(head);
    int x, chon;
    do
    {
        printf("\nCHUONG TRINH QUAN LI HANG HOA \n");
        printf("phim 1: de nhap danh sach \n");
        printf("phim 2: xuat danh sach mat hang \n");
        printf("phim 3: de tim mat hang \n");
        printf("phim 4: de sap sep theo gia \n");
        printf("-------------------------------------------\n");
        printf("phim 0: de ket thuc \n");
        printf("chon chuc nang:  ");
        scanf("%d",&chon);
        switch (chon)
        {
        case 1:
            nhapDS(head);
            break;
        case 2: 
            xuatDS(head);
            break;
        case 3: 
            TimMatHang(head);
            break;  
        case 4: 
            sapXep(head);
            break;      
        default:chon =0;
            break;
        }
    } while (chon!=0);
    
    printf("LE NGUYEN DINH NGUYEN-- 2011068415");
}
