/*
	Buoi 1: DSLK Don (int)
	SV: Dang Vu Gia Huy
	MSSV: 2001207179
	Ca 1 sang thu 7
*/

#include <stdio.h>
#include <conio.h>

//Khai bao cau truc
struct PhanSo{
	int tuso, mauso;
};

typedef PhanSo ItemType;

struct Node{
	ItemType info;
	Node *next;
};

struct Slist{
	Node *head;
	Node *tail;
};

//Khai bao ham con
Node* createNode(ItemType x);
void showNode(Node *p);
void nhapPhanSo(ItemType &x);
void xuatPhanSo(ItemType x);
void iNitSlist(Slist &s);
void createListPhanSo(Slist &s);
void addtail(Slist &s, Node *p);
void printSList(Slist s);

void menu();
void xulymenu();

void main()
{
	xulymenu();
	_getch();
};

void nhapPhanSo(ItemType &x)
{
	do
	{
		printf("\nNhap tu: ");
		scanf("%d", &x.tuso);
		printf("\nNhap mau: ");
		scanf("%d", &x.mauso);
	}while(x.mauso == 0);
}
void xuatPhanSo(ItemType x)
{
	printf("%d/%d ", x.tuso, x.mauso);
}
Node* createNode(ItemType x)
{
	Node *p = new Node;
	if(!p)
	{
		printf("\nCap phat khong thanh cong!!!");
		return NULL;
	}
	p->info = x;
	p->next = NULL;
	return p;
}

void showNode(Node *p)
{
	xuatPhanSo(p->info);
}

void createListPhanSo(Slist &s)
{
	int n;
	ItemType x;
	printf("\nNhap so luong phan so: ");
	scanf("%d", &n);
	for(int i=1;i<=n; i++)
	{
		printf("\nNhap phan so thu %d", i);
		nhapPhanSo(x);
		Node *p = createNode(x);
		addtail(s, p);
	}
}

void iNitSlist(Slist &s)
{
	s.head = s.tail = NULL;
}
void addtail(Slist &s, Node *p)
{
	if(p == NULL)
		return;
	if(s.head == NULL)
	{
		s.head = s.tail = p;
	}
	else
	{
		s.tail->next = p;
		s.tail = p;
	}
}
void printSList(Slist s)
{
	Node *p = s.head;
	while(p!= NULL)
	{
		showNode(p);
		p = p->next;
	}
}

void menu()
{
	printf("\n|-----------MENU-----------|");
	printf("\n|0. Thoat chuong trinh	 |");
	printf("\n|1. Tao List Phan So		 |");
	printf("\n|2. In danh sach Phan So   |");
	printf("\n|3. Them cuoi danh sach	 |");
	printf("\n|--------------------------|");
}

void xulymenu()
{
	int chon;
	ItemType x;
	Node *pnew = NULL;
	ItemType y;
	Slist dslk;
	iNitSlist(dslk);
	do
	{
		menu();
		printf("\nNhap 1 so: ");
		scanf("%d", &chon);
		switch(chon)
		{
		case 0:
			printf("\nChuong trinh ket thuc!!!");
			return;
		case 1:
			createListPhanSo(dslk);
			printSList(dslk);
			_getch();
			break;
		case 2:
			printSList(dslk);
			_getch();
			break;
		case 3:
			nhapPhanSo(x);
			pnew = createNode(x);
			addtail(dslk, pnew);
			printf("\nDanh sach sau khi them %d cuoi ds la: ", x);
			printSList(dslk);
			_getch();
			break;
		default:
			break;
		}
	}while(chon >= 0);
}
