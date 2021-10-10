#include "bitree.h"

//1.创建完全二叉树 
//i：根节点的编号，一般为1，n：结点个数 
bitree *Bitree_Create_Full(int i, int n)
{
	//先创建根节点并设置编号
	bitree *root = (bitree *)malloc(sizeof(bitree));
	root->code = i;
	
	//判断当前结点是否有左子树：2*i <= n 
	if(2*i <= n){
		root->lchild = Bitree_Create_Full(2*i, n);
	}else{
		root->lchild = NULL;
	}
	
	//判断是否存在右子树：2*i+1 <= n 
	if(2*i+1 <= n){
		root->rchild = Bitree_Create_Full(2*i+1, n);
	}else{
		root->rchild = NULL;
	}

	return root;
} 

//1.创建任意二叉树
bitree *Bitree_Create_unFull()
{
	char ch;
	scanf("%c",&ch);
	//如：1248###5##36##7## 
	
	if('#' == ch){
		return NULL;
	}
	
	//先创建根节点并设置编号
	bitree *root = (bitree *)malloc(sizeof(bitree));
	root->data = ch;
	
	root->lchild = Bitree_Create_unFull();
	root->rchild = Bitree_Create_unFull();
	
	return root; 
}

//2.先序遍历 (根左右) (递归思想)
void Bitree_TraverbyFront(bitree *root)
{
	if(root == NULL){
		return ;
	}
	
	//遍历根节点 
	printf("%c ",root->data);
	
	//判断是否存在左子树
	if(root->lchild != NULL){
		Bitree_TraverbyFront(root->lchild);
	}
	
	//判断是否存在右子树
	if(root->rchild != NULL){
		Bitree_TraverbyFront(root->rchild);
	}
}
 
//3.中序遍历（左根右） 
void Bitree_TraverbyMiddle(bitree *root)
{
	//判断是否存在左子树
	if(root->lchild != NULL){
		Bitree_TraverbyMiddle(root->lchild);
	}
	
	//遍历根节点
	printf("%c ",root->data);
	
	//判断是否存在右子树
	if(root->rchild != NULL){
		Bitree_TraverbyMiddle(root->rchild);
	}
}

//4.后序遍历 （左右根） 
void Bitree_TraverbyBack(bitree *root)
{
	//判断是否存在左子树
	if(root->lchild != NULL){
		Bitree_TraverbyBack(root->lchild);
	}
	
	//判断是否存在右子树
	if(root->rchild != NULL){
		Bitree_TraverbyBack(root->rchild);
	}
	
	//遍历根节点
	printf("%c ",root->data);
}



