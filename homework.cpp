#include<iostream>
using namespace std;
int n=0;
struct node
{
    int data;// dữ liệu 1 cái node
    struct node *pNext; // con trỏ liên kết cái node với nhau
};
typedef struct node NODE ;// thay thế struct node thành NODE

// khai báo cấu trúc của dslk
struct list 
{
    NODE *pHead; // node quản lí đầu ds
    NODE *pTail; // node quản lí cuối ds
};
typedef struct list LIST; // thay thế struct list thành LIST

void KhoiTao(LIST &l)
{
    l.pHead = NULL; // cho node trỏ đến NULL vì dslk đơn chưa có phần tử
    l.pTail = NULL; // cho node trỏ đến NULL vì dslk đơn chưa có phần tử
}

// viết hàm khởi tạo 1 cái node 
NODE *KhoiTaoNODE(int x)
{
    NODE *p = new NODE ; // cấp phát vùng nhớ cho NODE p
    if (p == NULL)
    {
        cout << " Không đủ bộ nhớ để cấp phát\n ";
        return NULL;
    }
    p ->  data = x; // truyền giá trị x vào data
    p -> pNext = NULL; // đầu tiên khai báo node thì nó chưa có liên kết đến node nào hết => con trỏ cửa nó sẽ trỏ đến NULL 
    return p; // trả về NODE p vừa khởi tạo 
}
// hàm thêm node vào đầu dslk
void Themvaodau(LIST &l, NODE *p)
{
    // ds đang rỗng 
    if( l.pHead == NULL )
    {
        l.pHead = l.pTail = p; // node đầu cũng chính là node cuối 
    }
    else
    {
    p -> pNext = l.pHead; // cho con tro của node can thêm liên kết đến node đầu  
    l.pHead = p;    // cập nhật lại dslk là node p
    }
}
// hàm thêm node p vào cuối dsld đơn

void Themvaocuoi(LIST &l, NODE *p)
{
    if( l.pHead == NULL )
    {
        l.pHead = l.pTail = p; // node đầu cũng chính là node cuối 
    }
    else
    {
    l.pTail -> pNext = p ; // con trỏ của pTail liên kết với node p
    l.pTail = p; // cập nhất p node bằng pTail
    }
}

// hàm xuất dslk đơn
void xuatds(LIST l)
{
    for (NODE *k = l.pHead; k != NULL; k = k->pNext)
    {
        cout << k -> data << " ";   
    }
}

//ham tìm gtln trong ds
int timMAX(LIST l)
{
    int max = l.pHead->data; // gsu node đầu là node lớn nhất
    for (NODE *k = l.pHead->pNext;k != NULL; k = k-> pNext ) // bắt đầu duyệt từ node 2 để kiểm tra 
    {
        if( max < k -> data)
        {
            max = k->data; // cập nhật lại max
        }
    }
    return max;
}

// chèn 
void chenNode(LIST &l, NODE *p)
{
    int x;
    cout<< " nhap gia tri so can chen phia truoc";
    cin >> x;
    NODE *q = KhoiTaoNODE(x);
    if (q->data == l.pHead->data && l.pHead -> pNext == NULL)
    {
        Themvaodau(l,p);
    }
    else 
    {
        NODE *g = new NODE;
        for (NODE *k = l.pHead;k != NULL; k = k-> pNext )// duyet danh sach tu dau den cuoi de tim node q
        {
            if (q->data == k->data)
            {
                NODE *h = KhoiTaoNODE(p->data);
                h->pNext = k;
                g->pNext = h;
            }
            g=k;
        }
    }
}

void menu(LIST &l)
{
    int luachon;
    while(69)
    {
        system("cls");
        cout << "\n\n\t========== MENU ==========";
        cout << "\n\t1. Them node vao danh sach";
        cout << "\n\t2. xuat danh sach";
        cout << "\n\t3. chen phan tu vao phia truoc ";
        cout << "\n\t0. thoat";
        cout << "\n\t========== END  ==========";

        cout<<"\n Nhap lua chon: ";
        cin>> luachon;
        if(luachon == 1)
        {
            int x;
            cout << "\n Nhap gia tri so nguyen: ";
            cin >> x;
            NODE *p = KhoiTaoNODE(x);
            Themvaocuoi(l,p);
        }
        else if (luachon == 2 )
        {
            xuatds(l);
            system("pause");
        }
        else if(luachon == 3)
        {
            int x;
            cout << "Nhap gia tri so nguyen: ";
            cin >> x;
            NODE *p = KhoiTaoNODE(x);
            chenNode(l,p);
        }
        else 
        {
            break;
        }



    }
}
 
int main()
{
    LIST l;
    KhoiTao(l);
    menu(l);
    return 0; 
}