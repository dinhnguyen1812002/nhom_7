//danh sách liên kết đơn 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct SinhVien
{
    char Ma[10];
    char HoVATen[40];
    float dtb;
}SV;
typedef struct Node
{
    SV info;
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
Node* CreatNode (SV x)
{
    Node* p=new Node;
    p->info=x;
    p->next=NULL;
    return p;
}
//ham nhap 1 sinh vien
void Nhap1SV(SV &x)
{
    printf("nhap ma sinh vien: "); 
    fflush(stdin);
    gets(x.Ma);
    printf("nhap ho va ten sinh vien: ");
    fflush(stdin);
    gets(x.HoVATen);
    printf("nhap diem trung binh ");
    scanf("%f",&x.dtb);
}
//nhập số lượng sinh viên trong danh sách
void nhapDS(Node* &head)
{
    int n;
    printf("nhap so luong sinh vien: ");
    scanf("%d",&n);
    SV x;
    for(int i=0;i<n;i++)
    {
        printf("\nsinh vien thu nhat: %d\n",i);
        Nhap1SV(x);
        Node* p = CreatNode(x);//tao một biến p 
        p->next=head; // p trỏ tới địa chỉ của node tiếp theo gán bằng head   
        head= p;
    }
}
//xuất 1 thong tin 1 sinh vien
void xuat1SV(SV x)
{
    printf("\n\t\t%s    \t\t%s      \t\t%.2f",x.Ma,x.HoVATen,x.dtb);
}
//xuất danh sách toàn bộ  sinh viên
void xuatDS(Node* head)
{
    Node* p = head;
    printf("\n\tMa so\t\tHo Va Ten\t\tDiem trung binh\n");
     while (p!=NULL)
        {
            xuat1SV(p->info);
            p=p->next;
        }
}
//–Xuất thông tin các sv có Điem trung bình >5
void lietkedtb(Node* head)
{
    int dem=0; //tao biến đếm bằng không 
	printf("\n ----- SV co Dtb > 5 la:\n");
	while(head != NULL) // trong khi head khác null
	{
		if(head->info.dtb >= 5) // nếu con trỏ head trỏ đến nội dung là điểm trung bình lớn hơn hoạc  bằng 5
			{
				xuat1SV(head->info); //thì gọi hàm xuất 1 sinh viên 
				dem++;// biến đếm +1 
			}
		head=head->next;
	}
	if(dem==0) printf("Khong ton tai !!!!");//nếu dem = 0 thì xuất ra là không có điểm 
	printf("\n-------------------------------\n");
}
//hàm tim sinh viên
void timSV(Node* head)
{

	int dem=0;//tao biến đếm bằng không 
     char k[40]; //tao một biến k 
     printf("\nNhap ten sv can tim: ");
    fflush(stdin);
    gets(k);
   
	while(head != NULL)
	{
		if(strcmp(head->info.HoVATen,k)==0)// sử dụng strcmp 
		{
			xuat1SV(head->info);dem++;
		}
		head= head->next;
	}
	if(dem==0) printf("Khong ton tai !!!!");
}
//Sắp xếp danh sách tăng theo ĐTB
void swap (SV &a, SV &b)
{
	SV t = a;
	a=b;
	b=t;
}
void sapXep(Node* &head)
{
//	printf("\n------ sau khi sap xep:\n");
	Node* i= head;
	while(i !=NULL)
	{
		Node* j= head;
		for(j; j!=NULL; j=j->next)
		{
			if(j->info.dtb > i->info.dtb)
				swap(j->info,i->info);
		}
		i=i->next;
	}
}

int main()
{
    Init(head);
    int x,chon;
    do
    {
        printf("\nphim 1: nhap danh sach: \n");
        printf("phim 2: xuat danh sach\n");
        printf("phim 3: liet ke diem trung binh: \n");
        printf("phim 4: tim sinh vien\n");
        printf("phim 0: de thoat: \n");
        printf("chon ");
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
            lietkedtb(head);  
           
            break;
        case 4: 
            timSV(head);
           
            break;     
        default:chon =0;
            break;
        }
    } while (chon!=0);
    
    
    
}