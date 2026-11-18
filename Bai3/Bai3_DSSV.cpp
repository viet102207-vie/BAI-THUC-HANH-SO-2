#include <stdio.h>
typedef struct{
    char hten[30];
    int masv;
    float d1, d2, d3;
} SV;
void nhap(SV *a, int n){
    int i;
    for(i = 0; i < n; i++){
        scanf("%s", (a+i)->hten);
        scanf("%d", &(a+i)->masv);
        scanf("%f", &(a+i)->d1);
        scanf("%f", &(a+i)->d2);
        scanf("%f", &(a+i)->d3);
    }
}
void in(SV *a, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("\n%s %d %.2f %.2f %.2f",
            (a+i)->hten,
            (a+i)->masv,
            (a+i)->d1,
            (a+i)->d2,
            (a+i)->d3);
    }
}
int main(){
    SV a[100];
    int n;
    printf("Nhap so sinh vien: ");
    scanf("%d", &n);
    nhap(a, n);
    in(a, n);
    return 0;
}
