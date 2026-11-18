#include <stdio.h>
void nhap(float *a, int n){
  for(int i = 0; i < n; i++){
    printf("Nhap phan tu thu %d: ", i);
    scanf("%f", a + i);
  }
}
void in(float *a, int n){
  for(int i = 0; i < n; i++){
    printf("%.2f ", *(a + i));
  }
}
int main(){
  float a[100];
  int n;
  do{
  	printf("Nhap so phan tu: ");
  	scanf("%d", &n);
  } while (n <= 0 || n > 100);
  nhap(a, n);
  in(a, n);
}
