#include "stdio.h"
#include "limits.h"
int a[100];
int n,i;
{
    void nhapMang(int x[100], int &n){
        printf("Nhap vao so luong phan tu: ");
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            printf("Nhap x[%d]:", i);
            scanf("%d", &x[i]);
        }
    }

    void xuatMang(int x[100], int n){
        printf("Gia tri cua mang la: ");
        for(int i=0; i<n; i++){
            printf("%d ", x[i]);
        }
    }

    void xoaMangTaiViTri(int x[100], int &n, int vi_tri){
        // 1 2 3 4 5
        // 1 2 4 5
        for(int i=vi_tri; i<n-1; i++){
            x[i] = x[i+1];
        }
        n--; 
    }

    void xoaMangTheoGiaTri(int x[100], int &n){
        int gt;
        printf("Nhap vao gia tri can xoa: ");
        scanf("%d", &gt);
        for(int i=0; i<n; i++){
            if(x[i]==gt)
                xoaMangTaiViTri(x, n, i);
        }
    }

    int main(){
        nhapMang(a, n);
        xuatMang(a, n);
        printf("\n");
        xoaMangTheoGiaTri(a, n);
        printf("\n");
        xuatMang(a, n);
    }
}