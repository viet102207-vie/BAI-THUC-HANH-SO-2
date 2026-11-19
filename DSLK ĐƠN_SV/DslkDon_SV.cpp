#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct    {
    	char hoten[30];
    	int masv;
    	float d1, d2, d3;
}Data;
typedef struct tagNode    {
    	Data infor;
    	struct tagNode *link;
}Node;
typedef struct    {
    	Node *pHead;  
    	Node *pTail;
    	int spt;
}LList;

void initList(LList *L)
    {
    	L->pHead = NULL;
    	L->pTail = NULL;
    	L->spt = 0;
    }
int emptyList(LList L)
 {
    	return (L.spt == 0); 
}

void insert_Head(LList *L, Data x)
    {
    	Node *pp;
    	pp = (Node*) malloc(sizeof(Node));
    	pp->infor = x;
    	pp->link = NULL;
    	if(emptyList(*L)){
    			L->pHead = pp;
    			L->pTail = pp;
    		}  	
        else {
    		pp->link = L->pHead;
    		L->pHead = pp;
    		}
    	L->spt++;
    }
void insert_Tail(LList *L, Data x)
    {
    	Node *pp;
    	pp = (Node*) malloc(sizeof(Node));
    	pp->infor = x;
    	pp->link = NULL;
    	if(emptyList(*L)){
    			L->pHead = pp;
    			L->pTail = pp;
    		}  	
        else {
    		L->pTail->link = pp;
    		L->pTail = pp;
    		}
    	L->spt++;
    }
void insert_After(LList *L, Node *q, Data x){
	Node *pp;
	if(NULL==q) return;
	else{
		pp = (Node*)malloc(sizeof(Node));
		pp->infor = x;
		pp->link = q->link;
		q->link = pp;
		if(q==L->pTail) L->pTail = pp;
		L->spt++;
	}
}
void nhap(Data *x){
    printf("Nhap ma sv: ");
    scanf("%d", &(x->masv));
    if(x->masv > 0){
        printf("Nhap ten sv: ");
        scanf("%s", (x->hoten));
        printf("Nhap diem mon 1: ");
        scanf("%f", &(x->d1));
        printf("Nhap diem mon 2: ");
        scanf("%f", &(x->d2));
        printf("Nhap diem mon 3: ");
        scanf("%f", &(x->d3));
    }
}
void in(Data x){
    printf("Ten: %s, Ma: %d, Diem 1: %.2f, Diem 2: %.2f, Diem 2: %.2f\n", 
            x.hoten, x.masv, x.d1, x.d2, x.d3);
}
void processList(LList L){
    Node *pp = L.pHead;
    while( pp != NULL ){
        	in(pp->infor); 
        	pp = pp->link;
    	}
}
void delete_Head(LList *L) {
    if (emptyList(*L)) {
        printf("Danh sach rong!\n");
        return;
    }
Node *pp = L->pHead;
L->pHead = L->pHead->link;
free(pp);
L->spt--;
if (L->pHead == NULL) {
        L->pTail = NULL;
    }
}
void delete_After(LList *L, Node *q){
	Node *pp;
	if(NULL==q) return;
	else{
		pp = q->link;
		if(q->link == L->pTail)
		L->pTail = q;
		q->link = pp->link;
		free(pp);
		L->spt--;
	}
}
void delete_K(LList *L, char K[30]){
	Node *pp=L->pHead, *q;
	while(pp!=NULL && !strstr(pp->infor.hoten, K)){
		q=pp;
		pp=pp->link;
	}
	if(NULL==pp) return;
	else
	if(pp==L->pHead) delete_Head(L);
	else delete_After(L, q);
}
Node *search(LList L, char name[30]){
	Node *pp = L.pHead;
	while (pp != NULL && !strstr(pp -> infor.hoten, name))
	pp = pp -> link;
	return pp;
}
void tach(LList L, LList *L1, LList *L2){
	Node *pp = L.pHead;
    initList(L1);
    initList(L2);
    while(pp != NULL){
        float dtb = (pp->infor.d1 + pp->infor.d2 + pp->infor.d3) / 3;
        if(dtb < 5)
            insert_Tail(L1, pp->infor);
        else
            insert_Tail(L2, pp->infor);
        pp = pp->link;
    }
}
int main(){
    LList L;
	int kt = 0;
	Data x;
	initList(&L); 
	do{
	    printf("\nChuong trinh lam viec voi DSLK don SV\n");
	    printf("\n1: Them nut vao dau danh sach");
	    printf("\n2: Them nut vao cuoi danh sach");
	    printf("\n3: Them nut vao sau mot nut khac trong danh sach");
	    printf("\n4: Xoa nut o dau danh sach");
	    printf("\n5: Xoa nut o sau mot phan tu danh sach");
	    printf("\n6: Tim kiem theo ten sinh vien");
	    printf("\n7: Xoa theo ten");
	    printf("\n8: Tach danh sach theo diem");
	    printf("\n9: Duyet ds");
	    printf("\n0: Thoat");
	    printf("\nMoi ban chon: ");
	    int chon;
	    scanf("%d", &chon);
	    switch(chon){
	        case 1: 
	            printf("Nhap so thông tin sv can them\n");
	            nhap(&x);
	            if(x.masv > 0) 
                	insert_Head(&L, x);
            	break;
            case 2:	
	            printf("Nhap so thông tin sv can them\n");
	            nhap(&x);
	            if(x.masv > 0) 
                	insert_Tail(&L, x);
            	break;
            case 3:
	            printf("Nhap thong tin sv can them\n");
                nhap(&x);
                if(x.masv > 0 && L.pHead != NULL)
                insert_After(&L, L.pHead, x);
            	break;
            case 4: 
//                printf("Ban muon xoa nguoi co ten la gi?");
//                scanf("%s", name);
            delete_Head(&L);
                break;
            case 5:
            if (emptyList(L)) {
            printf("Danh sach rong!\n");
            }
            else if (L.pHead == L.pTail) {
            delete_Head(&L);
            }
            else {
            Node *q = L.pHead;
            while (q->link != L.pTail) {
            q = q->link;
            }
            delete_After(&L, q);
        }
            break;
            case 6:
            	{
			char ten[30];
            printf("Nhap ten sinh vien can tim: ");
            scanf("%s", ten);
            Node *pp = search(L, ten);
            if(pp != NULL){
            	printf("Tim thay sinh vien:\n");
            	in(pp->infor);
			} else {
				printf("Khong tim thay sinh vien");
			}
			break;
		   }
		    case 7:
		    {
            char K[30];
            printf("Nhap ten sinh vien can xoa: ");
            scanf("%s", K);
            delete_K(&L, K);
            break;
            }
            
            case 8:
            {
            LList L1, L2;
            tach(L, &L1, &L2);
            printf("\nDanh sach sinh vien co DTB < 5:\n");
            processList(L1);
            printf("\nDanh sach sinh vien co DTB >= 5:\n");
            processList(L2);
            break;
            }
            case 9: 
                processList(L);
                break;    
            case 0: 
                printf("Bye bye\n");
	            kt = 1;
        }
	}while(kt==0); 
}
