#include <stdio.h>
#include<conio.h>
#include <string>


#define MAX 100

struct Stack
{
	int INFO[MAX];
	int TOP;
};

struct BAIHAT
{
    char maBaiHat[6];
    char tenBaiHat[51];
    int thoiLuong;
};

struct QNode
{
    BAIHAT info;
    QNode *next;
};

struct Queue
{
    QNode *head;
    QNode *tail;
};

//Khai bao cac nguyen mau ham
//Bai 1
void initStack(Stack *S);
int isEmpty(Stack *S);
void pushS(struct Stack* S, int item);
int popS(struct Stack* S);
int top(Stack *S);
int Precedence(char x);
void InfixtoPostfix(char infix[], char postfix[]);

//Bai 2
QNode *creatQNode(BAIHAT &song);
void initQueue(Queue &q);
bool isQueueEmpty(Queue q);
void pushQ(Queue &q, QNode *p);
QNode *popQ(Queue &q);
void input1Song(BAIHAT &song);
void createQueue(Queue &q, int &n);
void printQueue(Queue q);
int tongThoiLuong(Queue q);
void printHead_Tail(Queue q);

void menu();
void process();

//ham MAIN
int main(void)
{
	process();
}

//Dinh nghia cac nguyen mau ham
void menu()
{
    printf("\n***************************************************");
	printf("\n*                       MENU                      *");
	printf("\n***************************************************");
    printf("\n*1.Chuyen bieu thuc trung to -> hau to            *");
    printf("\n*2.Tao Playlist                                   *");
    printf("\n*3.Xuat Playlist                                  *");
    printf("\n*4.Tong thoi luong cua playlist                   *");
    printf("\n*5.Bai hat dau & cuoi trong playlist              *");
    printf("\n*0.Thoat                                          *");
    printf("\n***************************************************");
}

void process()
{
	Queue q;
    char A[MAX], B[MAX];
	int N;
    int Luachon;
    do
    {
        menu();
		printf("\nMoi nhap lua chon: ");
		scanf("%d", &Luachon);
        switch (Luachon)
        {
        case 1:
            printf("Nhap bieu thuc trung to: ");
            fflush(stdin);
	        gets(A);
            InfixtoPostfix(A, B);
            printf("Bieu thuc hau to: %s", B);
            break;
        case 2:
			createQueue(q, N);
			printf("Playlist da duoc tao xong !!!");
            break;
		case 3:
			printQueue(q);
			break;
		case 4:
			printf("\nTong thoi luong la %d", tongThoiLuong(q));
			break;
		case 5:
			printHead_Tail(q);
			break;
        default:
            break;
        }
    } while (Luachon != 0);
}
//***************************************************
void initStack(Stack *S)
{
    S->TOP = -1;
}
//***************************************************
int isEmpty(Stack *S)
{
    if (S->TOP == -1)
        return 1;
    
    return 0;
}
//***************************************************
void pushS(struct Stack* S, int item)
{
    if (S->TOP == (MAX - 1))
	{
		printf("\nStack is full");
	}
	else
	{
		++S->TOP;
		S->INFO[S->TOP] = item;
	}
}
//***************************************************
int popS(struct Stack* S)
{
    int p = -1;
	if (S->TOP == -1)
		printf("\nStack is empty");
	else
	{
		p = S->INFO[S->TOP];
		--S->TOP;
	}
	return p;
}
//***************************************************
int top(Stack *S)
{
	return (S->INFO[S->TOP]);
}
//***************************************************
int Precedence(char x)
{
	if (x == '(')
		return 0;
	if (x == '+' || x == '-')
		return 1 ;
	if (x == '*' || x == '/' || x == '%')
		return 2;
	return 3;
}
//***************************************************
void InfixtoPostfix(char infix[], char postfix[])
{
	Stack S;
	char x, token;
	int i = 0, j = 0;    // i - index của trung tố, j - index của hậu tố
	initStack(&S);
	for (i = 0; infix[i] != '\0'; i++)
	{
		token = infix[i];
		if (isalnum(token))
			postfix[j++] = token;
		else
			if (token == '(')
				pushS(&S, '(');
			else
				if (token == ')')
					while ((x = popS(&S)) != '(')
						postfix[j++] = x;
				else
				{
					while (Precedence(token) <= Precedence(top(&S)) && !isEmpty(&S))
					{
						x = popS(&S);
						postfix[j++] = x;
					}
					pushS(&S, token);
				}
	}

	while (!isEmpty(&S))
	{
		x = popS(&S);
		postfix[j++] = x;
	}

	postfix[j] = '\0';
}
//***************************************************
QNode *creatQNode(BAIHAT &song)
{
    QNode *p = new QNode;
    if( p == NULL)
	{
		printf("Khong du bo nho cap phat!!!");
		return NULL;
	}
    p->info = song;
	p->next = NULL;

}
//***************************************************
void initQueue(Queue &q)
{
    q.head = q.tail = NULL;
}
//***************************************************
bool isQueueEmpty(Queue q)
{
	if(q.head == NULL)
		return true;
	return false;
}
//***************************************************
void pushQ(Queue &q, QNode *p)
{
	if(p!=NULL)
		if(q.head==NULL) {
			q.head= q.tail =p;
		} else
		{
			q.tail->next = p;
			q.tail = p;
		}
}
//***************************************************
QNode *popQ(Queue &q)
{
	QNode *p = NULL;
	if(q.head != NULL)
	{
		p = q.head;
		q.head = q.head -> next;
		p -> next = NULL;
	}
	return p;
}
//***************************************************
void input1Song(BAIHAT &song)
{
	printf("\nMa bai hat: ");
	fflush(stdin);
	gets(song.maBaiHat);
	printf("\nTen bai hat: ");
	fflush(stdin);
	gets(song.tenBaiHat);
	printf("\nthoi luong (giay(s)): ");
	scanf("%d", &song.thoiLuong);
}
//***************************************************
void createQueue(Queue &q, int &n)
{
	initQueue(q);
	BAIHAT song;
	do
	{
		printf("\nNhap so luong bai hat can them vao PlayList: ");
		scanf("%d", &n);

	}while(n <= 0);

	for(int i = 1; i <= n; i++)
	{
		printf("\nBai hat thu %d", i);
		input1Song(song);
		QNode *p = creatQNode(song);
		pushQ(q, p);
	}
}
//***************************************************
void printQueue(Queue q)
{
	QNode *p = q.head;
	printf("%-12s%-30s%-20s\n", "Ma Song", "Ten Song", "Thoi luong"); 
	while(p != NULL)
	{
		printf("%-12s%-30s%-20d\n", p->info.maBaiHat, p->info.tenBaiHat, p->info.thoiLuong);
		p = p->next;
	}
}
//***************************************************
int tongThoiLuong(Queue q)
{
	int sum =0;
	QNode *p = q.head;
	while(p!=NULL)
	{
		sum += p->info.thoiLuong;
		p = p->next;
	}
	return sum;
}
//***************************************************
void printHead_Tail(Queue q)
{
	if(q.head == NULL)
	{
		printf("\nPlaylist chua co bai hat nao!!!");
		return;
	}
	else
	{
		printf("\nBai hat dau tien trong PlayList la %s", q.head->info.tenBaiHat);
		printf("\nBai hat cuoi cung trong PlayList la %s", q.tail->info.tenBaiHat);
	}
}
//***************************************************