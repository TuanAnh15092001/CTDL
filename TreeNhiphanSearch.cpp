/*
Buoi 8: Cay Nhi Phan tim kiem
SV: Dang Vu Gia Huy
MSSV: 2001207179
Ca: 1 sang thu 7
*/

#include<stdio.h>
//#include<conio.h>

typedef int ItemType;

//Khai bao cau truc
struct TNode{
	ItemType data;
	TNode *left;
    TNode *right;
};

struct BSTree{
	TNode *root;
};

//Khai bao ham con
TNode *createTNode(ItemType x);
void iNitBSTree(BSTree &bt);
void showNode(TNode *p);
int insertTNode(TNode* &root, TNode* p);
void showBSTree_NLR(TNode *root);
void showBSTree_LNR(TNode *root);
void showBSTree_LRN(TNode *root);
void xoaNodeX(TNode* &root, ItemType x);
bool checkNegative(int a);
void findMaxNegative(TNode *root, TNode *&p);
int countEvenNumbers(TNode *root);

void menu();
void process();

//MAIN
int main(void)
{
    process();
}

//Dinh nghia ham con
void iNitBSTree(BSTree &bt)
{
    bt.root = NULL;
}
//===================================
TNode* createTNode(ItemType x)
{
    TNode* p = new TNode;
    if(!p)
        return NULL;
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}
//===================================
void showNode(TNode* p)
{
    printf("%d ", p->data);
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
    if (root->data == p->data)
        return 0;

    if (root->data > p->data)
    {
        printf("\nThem %d vao ben trai %d", p->data, root->data);
        insertTNode(root->left, p); //Thêm p vào bên nhánh trái (vì nhỏ hơn root)
    }
    else
    {
        printf("\nThem %d vao ben phai %d", p->data, root->data);
        insertTNode(root->right, p); //Thêm p vào bên nhánh phải (vì lớn hơn root)
    }
    return 1;
}
//===================================
void showBSTree_NLR(TNode *root)
{//Duyệt cây theo cách Node - Left - Right
    if (!root) return;
    showNode(root);
    showBSTree_NLR(root->left);
    showBSTree_NLR(root->right);
}
//===================================
void showBSTree_LNR(TNode *root)
{//Duyệt cây theo cách Left - Node - Right
    if (!root) return;
    showBSTree_LNR(root->left);
    showNode(root);
    showBSTree_LNR(root->right);
}
//===================================
void showBSTree_LRN(TNode *root)
{//Duyệt cây với Left - Right - Node
    if (!root) return;
    showBSTree_LRN(root->left);
    showBSTree_LRN(root->right);
    showNode(root);
}
//===================================
void xoaNodeX(TNode* &root, ItemType x)
{
    if (x < root->data)
    {
        xoaNodeX(root->left, x);
    } else if (x > root->data)
    {
        xoaNodeX(root->right, x);
    } else
    {
        TNode* temp = root;
        if (root->left == NULL)
        {
            root = root->right;
        } else if (root->right == NULL)
        {
            root = root->left;
        }
        delete temp;
    }
}
//===================================
bool checkNegative(int a)
{
	if(a > 0)
		return false;
	return true;
}
//===================================
void findMaxNegative(TNode *root, TNode *&p)
{
	if(!root) return;
	findMaxNegative(root->left, p);
	if(checkNegative(root->data) == true)
	{
		p->data = root->data;
	}
	findMaxNegative(root->right, p);
}
//===================================
int countEvenNumbers(TNode *root)
{
	if(!root)
        return 0;
	int left = countEvenNumbers(root->left);
	int right = countEvenNumbers(root->right);
	if(root->data % 2 == 0)
		return 1 + left + right;
	return left + right;
}
//===================================
void menu()
{
    printf("\n-----------------MENU----------------");
    printf("\n1. Tao cay nhi phan tim kiem         ");
    printf("\n2. Xuat cay nhi phan tim kiem        ");
    printf("\n3. Xoa X tren cay nhi phan           ");
    printf("\n4. Tim max Am tren cay               ");
    printf("\n5. Dem phan tu chan tren cay         ");
    printf("\n0. Thoat                             ");
    printf("\n-------------------------------------");
}
//===================================
void process()
{
    int luachon, ketqua;
    ItemType x;
    BSTree tree;
    iNitBSTree(tree);

    do
    {
        menu();
        printf("\nHay nhap chuc nang: ");
        scanf("%d", &luachon);
        switch (luachon)
        {
        case 1:
            printf("Nhap so nguyen x: ");
            scanf("%d", &x);
            TNode* p;
            p = createTNode(x);
            insertTNode(tree.root, p);
            break;
        case 2:
            printf("PreOrder NLR: ");
            showBSTree_NLR(tree.root);
            printf("\nInOrder LNR: ");
            showBSTree_LNR(tree.root);
            printf("\nPostOrder LRN: ");
            showBSTree_LRN(tree.root);
            break;
        case 3:
            printf("Nhap x: ");
            scanf("%d", &x);
            xoaNodeX(tree.root, x);
            printf("Cay sau khi xoa: ");
            showBSTree_NLR(tree.root);
            break;
        case 4:
            p->data = NULL;
			findMaxNegative(tree.root, p);
			if(p->data != NULL)
				printf("\nMax Am: %d", p->data);
			else
				printf("\nKhong ton tai Max am !!!");
            break;
        case 5:
            ketqua = countEvenNumbers(tree.root);
            printf("\nCo %d phan tu chan tren cay", ketqua);
            break;
        }
    } while (luachon != 0);
    
}