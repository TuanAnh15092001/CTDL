/*
	Buổi 4: Cây nhị Phân
	SV : Đặng Vũ Gia Huy
	MSSV : 2001207179
	CA : 1 sáng thứ 7
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<queue>
using namespace std;

//Khai báo cấu trúc
struct PhanSo{
	int mauso, tuso;
};

typedef PhanSo ItemType;

struct TNode{
	ItemType data;
	TNode *left;
	TNode *right;
};

struct BStree{
	TNode *root;
};

//Khai báo hàm con
TNode *createTNode(ItemType x);
void iNitBStree(BStree &btree);
void showNode(TNode *p);
void nhapPhanSo(ItemType &x);
int soSanhPS(ItemType a, ItemType b);
int inSertBStree(TNode *&root, TNode *p);
void createBStree(BStree &btree, int n);
void createBStreeRandom(BStree &btree, int n);
TNode *findX(TNode *root, ItemType x);
int deleteTNode(TNode *&root, TNode *f);

void menu();
void process();

//HÀM MAIN
int main(void)
{
	process();
}

void menu()
{
	printf("\n************************** MENU ***************************");
	printf("\n*1.  Tao cay nhi phan tim kiem tu ban phim                *");
	printf("\n*2.  Tao cay nhi phan tim kiem random                     *");
	printf("\n*3.  Xuat cay (Duyet NLR, LNR, LRN, NRL)                  *");
	printf("\n*4.  Tim X tren cay nhi phan                              *");
	printf("\n*5.  Xoa X tren cay nhi phan                              *");
	printf("\n*0.                   THOAT CHUONG TRINH                  *");
	printf("\n***********************************************************");

}

void process()
{
	BStree btree;
	ItemType x, y;
	int n;
	int luachon;
	TNode *pnew;
	TNode *p = new TNode;
	do
	{
		menu();
		printf("\nNhap chuc nang: ");
        scanf("%d", &luachon);
		switch(luachon)
		{
		case 1:
		{
			printf("Nhap so luong Node de them vao cay: ");
            scanf("%d", &n); 
			createBStree(bt, n);
            printf("Them thanh cong!!");
			break;
		}
		case 2:
		{
            printf("Nhap so luong Node de them vao cay: ");
			scanf("%d", &n); 
			createBStreeRandom(btree, n);
            printf("Them thanh cong!!");
			break;
		}
		case 3:
		{
            printf("NLR: "); show_NLR(btree.root);
            printf("\nLNR: "); show_LNR(btree.root);
            printf("\nLRN: "); show_LRN(btree.root);
            printf("\nNRL: "); show_NRL(btree.root);
			break;
		}
		case 4:
		{
            printf("\nNhap X: ");
            nhapPhanSo(x);
			pnew = findX(bt.root, x);
			if(pnew == NULL)
				printf("\nKhong tim thay %d/%d tren cay !!!", x.tuso, x.mauso);
			else
			{
				printf("\nTim thay %d/%d tren cay !!!", x.tuso, x.mauso);
			}
			break;
		}
		case 5:
            printf("\nNhap X: ");
            nhapPhanSo(x);
			pnew = findX(btree.root, x);
			if(pnew == NULL)
				printf("\nKhong tim thay phan tu tren cay !!!");
			else
			{
				deleteTNode(btree.root, pnew);
                printf("Xoa thanh cong!!");
			}
            break;
		}
	}while(luachon >= 0);
}
//====================================================
TNode *createTNode(ItemType x)
{
	TNode *p = new TNode;
	if(!p)
	{
		printf("\nKhong du bo nho!!!");
		return NULL;
	}
	p ->data = x;
	p ->left = NULL;
	p ->right = NULL;
	return p;
}
//====================================================
void iNitBStree(BStree &btree)
{
	btree.root = NULL;
}
//====================================================
void showNode(TNode *p)
{
	printf("%d/%d   ", p->data.tuso, p->data.mauso);
}
//====================================================
void nhapPhanSo(ItemType &x)
{
	printf("\nNhap tu so: ");
    scanf("%d", &x.tuso);
	do
	{
		printf("\nNhap mau so: ");
		scanf("%d", &x.mauso);
	}while(x.mauso == 0);
}
//============================================
int soSanhPS(ItemType a, ItemType b)
{//tra ve 0 neu a = b; 1 neu a > b; -1 neu a < b
	int x = a.tuso * b.mauso;
	int y = b.tuso * a.mauso;
	if(x == y)
        return 0;
	if(x < y)
        return -1;
	return 1;
}
//============================================
int inSertBStree(TNode *&root, TNode *p)
{
	if(!p)
        return 0;
	if(!root)
	{
		root = p;
		return 1;
	}
	if(soSanhPS(root->data, p->data) == 0)
		return 0;
	if(soSanhPS(root->data, p->data) == 1) 
		inSertBStree(root->left, p);
	else
		inSertBStree(root->right, p);
	return 1;
}
//===============================================
void createBStree(BStree &btree, int n)
{
	ItemType x;
	iNitBStree(btree);
	for(int i = 1; i <= n; i++)
	{
		printf("\nNhap Phan So: ");
		nhapPhanSo(x);
        TNode *p = createTNode(x);
		inSertBStree(btree.root, p);
	}
}
//=================================================
void createBStreeRandom(BStree &btree, int n)
{
	ItemType x;
	iNitBStree(btree);
	srand(unsigned(time(NULL)));
	for(int i = 1; i <= n; i++)
	{
		x.tuso = (rand() % 199) - 99;
		do
		{
			x.mauso = (rand() % 199) - 99;
		}while(x.mauso == 0);
		TNode *p = createTNode(x);
		inSertBStree(btree.root, p);
	}
}
//==================================================
TNode *findX(TNode *root, ItemType x)
{
	if(!root) return NULL;
	if(soSanhPS(root->data, x) == 0)
		return root;
	if(soSanhPS(root->data,x) == 1)
		findX(root->left, x);
	else
		findX(root->right, x);
}
//==================================================
TNode *replaceTNode(TNode *&p)
{
	TNode *f = p, *rp = p->right;
	while(rp ->left)
	{
		f = rp;
		rp = rp->left;
	}
	p ->data = rp ->data;
	if( f == p)
	{
		f->right = rp->right;
	}
	else
		f->left = rp ->right;
	return rp;
}
//==================================================
int deleteTNode(TNode *&root, TNode *f)
{
	if(!root) return 0;
	if(soSanhPS(root ->data,f->data) == 1)
		deleteTNode(root->left, f);
	else if(soSanhPS(root->data, f->data) == -1)
		deleteTNode(root->right, f);
	else
	{
		TNode *p = root;
		if(!root->left)
			root = root->right;
		else if(!root->right)
			root = root->left;
		else
		{
			TNode *p = root;
			TNode *rp = replaceTNode(p);
			delete rp;
		}
	}
}