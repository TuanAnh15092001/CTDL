#include<stdio.h>
#include<conio.h>
#include<math.h>
//Cau truc cay nhi phan
typedef int Itemtype;
struct TNode
{
    Itemtype Info;
    TNode* Left;
    TNode* Right;
};
struct BTree
{
    TNode* Root;
};

//Khai bao ham con
TNode* createTNode(Itemtype x);
void showTNode(TNode* p);
void initBTree(BTree &bt);
int insertTNode(TNode* &root, TNode* p);
void showBTree_NLR(TNode *root);
void showBTree_LNR(TNode *root);
void showBTree_LRN(TNode *root);
int countTNodeNoLeaf(TNode* root);
int countTNodeMedium(TNode* root);
int countTNodeX(TNode* root, Itemtype x);
int countTNodeBiggerThanX(TNode* root, Itemtype x);
bool KtraSNT(Itemtype x);
int countTNodeX_SNT(TNode* root);
void xoaNodeLa(TNode* &root, Itemtype x);


void menu();
void process();

//MAIN
int main(void)
{
    process();
}

//Dinh nghia ham con
void initBTree(BTree &bt)
{
    bt.Root = NULL;
}
//===================================
TNode* createTNode(Itemtype x)
{
    TNode* p = new TNode;
    if(!p)
        return NULL;
    p->Info = x;
    p->Left = NULL;
    p->Right = NULL;
    return p;
}
//===================================
void showTNode(TNode* p)
{
    printf("%d ", p->Info);
}
//===================================
int insertTNode(TNode* &root, TNode* p)
{
    if (p == NULL)
        return 0;
    if (root == NULL)
    {
        root = p;
        return 1;
    }
    if (root->Info == p->Info)
        return 0;

    if (root->Info > p->Info)
    {
        printf("\nThem %d vao ben trai %d", p->Info, root->Info);
        insertTNode(root->Left, p); //Thêm p vào bên nhánh trái (vì nhỏ hơn root)
    }
    else
    {
        printf("\nThem %d vao ben phai %d", p->Info, root->Info);
        insertTNode(root->Right, p); //Thêm p vào bên nhánh phải (vì lớn hơn root)
    }
    return 1;
}
//===================================
void showBTree_NLR(TNode *root)
{//Duyệt cây theo cách Node - Left - Right
    if (!root) return;
    showTNode(root);
    showBTree_NLR(root->Left);
    showBTree_NLR(root->Right);
}
//===================================
void showBTree_LNR(TNode *root)
{//Duyệt cây theo cách Left - Node - Right
    if (!root) return;
    showBTree_LNR(root->Left);
    showTNode(root);
    showBTree_LNR(root->Right);
}
//===================================
void showBTree_LRN(TNode *root)
{//Duyệt cây với Left - Right - Node
    if (!root) return;
    showBTree_LRN(root->Left);
    showBTree_LRN(root->Right);
    showTNode(root);
}
//===================================
int countTNode(TNode* root)
{
    if(!root) return 0;
    int cnl = countTNode(root->Left);
    int cnr = countTNode(root->Right);
    return (1 + cnl + cnr);
}
//===================================
int countTNodeNoLeaf(TNode* root)
{
    if(!root) return 0;
    int cnl = countTNodeNoLeaf(root->Left);
    int cnr = countTNodeNoLeaf(root->Right);
    if(root->Left || root->Right)
        return (1 + cnl + cnr);
    return (cnl + cnr);
}
//===================================
int countTNodeMedium(TNode* root)
{
    int n = countTNodeNoLeaf(root);
    if(n > 0)
        return (n - 1); //trừ nút gốc
    return 0;
}
//===================================
int countTNodeX(TNode* root, int x)
{
    if(!root) return 0;
    int nlx = countTNodeX(root->Left, x);
    int nrx = countTNodeX(root->Right, x);
    if(root->Info == x)
        return (1 + nlx + nrx);
    return (nlx + nrx);
}
//===================================
int countTNodeBiggerThanX(TNode* root, Itemtype x)
{
    if(!root) return 0;
    int nlx = countTNodeBiggerThanX(root->Left, x);
    int nrx = countTNodeBiggerThanX(root->Right, x);
    if(root->Info > x)
        return (1 + nlx + nrx);  
    return (nlx + nrx);
}
//===================================
bool KtraSNT(Itemtype x)
{
    if (x < 2)
        return false;
    int count = 0;
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
            count++;
    }
    if (count == 0)
    {
        return true;
    } else {
        return false;
    }
}
//===================================
int countTNodeX_SNT(TNode* root)
{
    if(!root) return 0;
    int nlx = countTNodeX_SNT(root->Left);
    int nrx = countTNodeX_SNT(root->Right);
    if(KtraSNT(root->Info) == true)
        return (1 + nlx + nrx);
    return (nlx + nrx);
}
//===================================
void xoaNodeLa(TNode* &root, Itemtype x)
{
    if (x < root->Info)
    {
        xoaNodeLa(root->Left, x);
    } else if (x > root->Info)
    {
        xoaNodeLa(root->Right, x);
    } else
    {
        TNode* temp = root;
        if (root->Left == NULL)
        {
            root = root->Right;
        } else if (root->Right == NULL)
        {
            root = root->Left;
        }
        delete temp;
    }
}
//===================================
void menu()
{
    printf("\n---------------MENU--------------");
    printf("\n1. Nhap du lieu cho cay          ");
    printf("\n2. In cay                        ");
    printf("\n3. Dem so nut tren cay           ");
    printf("\n4. Dem nut trong(trung gian)     ");
    printf("\n5. Kiem tra x trong cay          ");
    printf("\n6. Dem phan tu > x               ");
    printf("\n7. Dem phan tu la so nguyen to   ");
    printf("\n8. Xoa nut x(nut la)             ");
    printf("\n0. Thoat                         ");
    printf("\n---------------------------------");
}
//===================================
void process()
{
    int Luachon, ketqua;
    Itemtype x;
    BTree tree;
    do
    {
        menu();
        printf("\nHay nhap chuc nang: ");
        scanf("%d", &Luachon);
        switch (Luachon)
        {
        case 1:
            printf("Nhap so nguyen x: ");
            scanf("%d", &x);
            TNode* p;
            p = createTNode(x);
            insertTNode(tree.Root, p);
            break;
        case 2:
            printf("PreOrder NLR: ");
            showBTree_NLR(tree.Root);
            printf("\nInOrder LNR: ");
            showBTree_LNR(tree.Root);
            printf("\nPostOrder LRN: ");
            showBTree_LRN(tree.Root);
            break;
        case 3:
            ketqua = countTNode(tree.Root);
            printf("Cay co %d nut.", ketqua);
            break;
        case 4:
            ketqua = countTNodeMedium(tree.Root);
            printf("Cay co %d nut trong(nut trung gian).", ketqua);
            break;
        case 5:
            printf("Nhap x: ");
            scanf("%d", &x);
            ketqua = countTNodeX(tree.Root, x);
            if (ketqua >= 1)
            {
                printf("Ton tai gia tri x = %d trong cay.", x);
            } else printf("Khong ton tai gia tri x = %d trong cay.", x);
            break;
        case 6:
            printf("Nhap x: ");
            scanf("%d", &x);
            ketqua = countTNodeBiggerThanX(tree.Root, x);
            printf("PreOrder NLR: ");
            showBTree_NLR(tree.Root);
            printf("\nCo %d phan tu lon hon %d", ketqua, x);
            break;
        case 7:
            ketqua = countTNodeX_SNT(tree.Root);
            printf("PreOrder NLR: ");
            showBTree_NLR(tree.Root);
            printf("\nCo %d phan tu la so nguyen to", ketqua);
            break;
        case 8:
            printf("Nhap x: ");
            scanf("%d", &x);
            xoaNodeLa(tree.Root, x);
            printf("Cay sau khi xoa: ");
            showBTree_NLR(tree.Root);
            break;
        }
    } while (Luachon != 0);
}

