#include <stdio.h>
void nhap(float *a, int n, int m){
    int i, j;
    
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            printf("Nhap a[%d][%d]: ", i, j);
            scanf("%f", a + i*m + j);
        }
    }
}
void in(float *a, int n, int m){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            printf("%.2f ", *(a + i*m + j));
        }
        printf("\n");
    }
}
int main(){
    float a[100][100];
    int n, m;
    printf("Nhap so hang cot: ");
    scanf("%d%d", &n, &m);
    nhap((float*)a, n, m);
    in((float*)a, n, m);
    return 0;
}
