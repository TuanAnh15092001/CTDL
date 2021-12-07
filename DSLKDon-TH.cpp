/*
Buoi 1: DSLK Don (int)
SV: Dang Vu Gia Huy
MSSV: 2001207179
Ca 1 sang thu 7
*/
#include <stdio.h>
#include <conio.h>
#include <math.h>

//Khai bao cau truc
typedef int Itemtype;

struct Node
{
    Itemtype info;
    Node* next;
};

struct Slist
{
    Node* head;
    Node* tail;
};

//Khai bao ham con
Node* createNode(Itemtype x);
void showNode(Node* p);
void menu();
void xulyMenu();
void iNitSList(Slist &s);
void addTail(Slist &s, Node*p); //cau a
void printSList(Slist s);
void insertXbeforeY(Slist &s, Itemtype x, Itemtype y); // cau b
void deleteHead (Slist &s);
void deleteTail (Slist &s);
void deleteQ (Slist &s, Node *q);
void deletelonhonX(Slist &s, Itemtype x); //cau c
void deleteChan(Slist &s); // cau d
void sxGiamDan(Slist s); // cau e
void sxTangDan(Slist s); // cau e
int demSNT(Slist s); //cau f
int tongSCP(Slist s); //cau g
int timmin(Slist s); // cau h
int timmax(Slist s); // cau h


//ham Main
void main()
{
    xulyMenu();
    _getch();
}

Node* createNode(Itemtype x)
{
    Node* p = new Node;
    if (!p)
    {
        printf("\nKhong cap phat thanh cong!!!");
        return NULL;
    }
    p->info = x;
    p->next = NULL;
}

void showNode(Node* p)
{
    printf("%d  ", p->info);
}

void menu()
{
    printf("\n----------------------MENU----------------------");
    printf("\n0.Thoat chuong trinh");
    printf("\n1.Tao Node");
    printf("\n2.Hien thi thong tin Node");
    printf("\n3.Them mot phan tu vao cuoi");
    printf("\n4.In danh sach");
    printf("\n5.Them x vao truoc y");
    printf("\n6. Xoa tat ca phan tu lon hon X");
    printf("\n7.Xoa cac phan tu chan trong dslk");
    printf("\n8. Sap xep tang dan va giam dan");
    printf("\n9. Dem so nguyen to trong dslk");
    printf("\n10. Tinh tong so chinh phuong");
    printf("\n11.Tim phan tu max, min");
    printf("\n------------------------------------------------");
}

void xulyMenu()
{
    int chon, count;
    int result;
    int MAX, MIN;
    Itemtype k;
    Itemtype t;
    Node* pnew = NULL;
    Slist dslk;
    iNitSList(dslk);
    do
    {
        menu();
        printf("\nNhap 1 so: ");
        scanf("%d", &chon);
        switch (chon)
        {
        case 0:
            printf("Chuong trinh ket thuc!!!");
            return;
            break;
        case 1:
            printf("Nhap gia tri can tao:");
            scanf("%d", &k);
            pnew = createNode(k);
            printf("Node vua tao la: ");
            showNode(pnew);
            _getch();
            break;
        case 2:
            showNode(pnew);
            _getch();
            break;
        case 3:
            printf("Nhap gia tri can them: ");
            scanf("%d", &k);
            pnew = createNode(k);
            addTail(dslk, pnew);
            printf("Danh sach sau khi them %d vao cuoi la: ", k);
            printSList(dslk);
            _getch();
            break;
        case 4:
            printf("Danh sach sau khi them: ");
            printSList(dslk);
            _getch();
            break;
        case 5:
            printf("Nhap y: ");
            scanf("%d", &k);
            printf("Nhap x can chen vao truoc so %d: ", k);
            scanf("%d", &t);
            insertXbeforeY(dslk, t, k);
            printf("Danh sach sau khi them: ");
            printSList(dslk);
            _getch();
            break;
        case 6:
            printf("Nhap x: ");
            scanf("%d", &k);
            deletelonhonX(dslk, k);
            printf("\nDanh sach sau khi xoa: ");
            printSList(dslk);
            _getch();
            break;
        case 7:
            deleteChan(dslk);
			printf("\nDanh sach sau khi xoa");
			printSList(dslk);
            _getch();
            break;
        case 8:
            sxTangDan(dslk);
			printf("\nDSLK sau khi sap xep tang dan: ");
			printSList(dslk);

			sxGiamDan(dslk);
			printf("\nDSLK sau khi sap xep giam dan: ");
			printSList(dslk);
            _getch();
			break;
        case 9:
            count = demSNT(dslk);
            printf("Co %d so nguyen to trong dslk", count);
            _getch();
            break;
        case 10:
            result = tongSCP(dslk);
            printf("\nTong so chinh phuong trong dslk la %d", result);
            _getch();
			break;
        case 11:
            MAX = timmax(dslk);
            MIN = timmin(dslk);
            printf("\nMax: %d ", MAX);
			printf("\nMin: %d ", MIN);
            _getch();
			break;
        default:
            break;
        }
    } while (chon >= 0);
    
}

void iNitSList(Slist &s)
{
    s.head = s.tail = NULL;
}

void addTail(Slist &s, Node*p)
{
    if (p == NULL)
        return;

    if (s.head == NULL)
    {
        s.head = s.tail = p;
    } else {
        s.tail->next = p;
        s.tail = p;
    }
}

void printSList(Slist s)
{
    Node* p = s.head;
    while (p)
    {
        showNode(p);
        p = p->next;
    }
}
void insertXbeforeY(Slist &s, Itemtype x, Itemtype y)
{
	Node *pnew = createNode(x);
	Node *p = s.head;
	Node *q;
	q = p;
	if(s.head->info == y)
	{
		pnew->next = s.head;
		s.head = pnew;
		return;
	}
	while(p!=NULL)
	{
		if( p-> info == y)
		{
			break;
		}
		q = p;
		p = p->next;
	}
	if(p == NULL)
        return;

	pnew->next = q->next;
	q->next = pnew;
}

void deleteHead (Slist &s)
{
    if (s.head == NULL)
        return;
    Node *p = s.head;
    s.head = p->next;
    p->next = NULL;

    delete p;
}

void deleteTail (Slist &s)
{
    if (s.head==NULL)
		return;
	Node *p = s.head;
	while (p->next != s.tail)
		p=p->next;

	Node *q = s.tail;
	s.tail = p;
	s.tail->next = NULL;
	delete q;
}

void deleteQ (Slist &s, Node *q)
{
	if(q==NULL)
		return;
	if(q==s.head)
		deleteHead(s);
	else if (q==s.tail)
	{
		deleteTail(s);
	}
	else
	{
		Node *qbefore = s.head; //dung truoc q
		while (qbefore->next != q)
		{
			qbefore=qbefore->next;
			q->next=NULL;
			delete q;
		}
	}
}

void deletelonhonX(Slist &s, Itemtype x)
{
	Node *p=s.head;
	Node *q=p;
	while(p)
	{
		if (p->info <= x)
		{
			q=p; //q la node truoc node p
			p=p->next;
		}
		else
		{
			Node *pdelete = p;
			p=p->next;
			deleteQ(s,pdelete);
		}
	}
}

void deleteChan(Slist &s)
{
	Node *p = s.head;
	Node *q = p;
	while(p)
	{
		if( p->info % 2 != 0)
		{
			q = p;
			p = p->next;
		}
		else
		{
			Node *pdelete = p;
			p = p->next;
			deleteQ(s, pdelete);
		}
	}
}

void swap(int &a, int &b)
{
	int temp = a; 
	a = b;
	b = temp;
}

void sxTangDan(Slist s)
{
	for(Node *p = s.head; p!=NULL; p = p->next)
		for(Node *q = p->next; q!=NULL; q= q->next)
		{
			if( p->info > q-> info)
			{
				swap(p->info, q->info);
			}
		}
}

void sxGiamDan(Slist s)
{
	for(Node *p = s.head; p!=NULL; p = p->next)
		for(Node *q = p->next; q!=NULL; q = q->next)
		{
			if( p->info < q-> info)
			{
				swap(p->info, q->info);
			}
		}
}

bool kiemtraSNT(int x)
{
	int dem = 0;
	for(int i= 1; i <= x; i++)
	{
		if( x % i == 0)
			dem++;
	}
	if(dem == 2)
		return true;
	return false;
}
int demSNT(Slist s)
{
	int count = 0;
	Node *p = s.head;
	while(p != NULL)
	{
		if(kiemtraSNT( p->info) == true)
			count++;
		p = p->next;
	}
	return count;
}

bool kiemtraSCP(int n)
{
	if((int)sqrt((float)n) == sqrt((float)n))
		return true;
	return false;
}

int tongSCP(Slist s)
{
	int sum = 0;
	Node *p = s.head;
	while(p!= NULL)
	{
		if(kiemtraSCP(p->info) == true)
			sum += p->info;
		p = p->next;
	}
	return sum;
}

int timmax(Slist s)
{
	Node *p = s.head;
	int max = p->info;
	while(p!=NULL)
	{
		if( max < p->info)
			max = p->info;
		p = p->next;
	}
	return max;
}

int timmin(Slist s)
{
	Node *p = s.head;
	int min = p->info;
	while(p!=NULL)
	{
		if( min > p->info)
			min = p->info;
		p = p->next;
	}
	return min;
}