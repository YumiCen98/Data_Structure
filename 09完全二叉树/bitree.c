#include "bitree.h"

//1.������ȫ������ 
//i�����ڵ�ı�ţ�һ��Ϊ1��n�������� 
bitree *Bitree_Create_Full(int i, int n)
{
	//�ȴ������ڵ㲢���ñ��
	bitree *root = (bitree *)malloc(sizeof(bitree));
	root->code = i;
	
	//�жϵ�ǰ����Ƿ�����������2*i <= n 
	if(2*i <= n){
		root->lchild = Bitree_Create_Full(2*i, n);
	}else{
		root->lchild = NULL;
	}
	
	//�ж��Ƿ������������2*i+1 <= n 
	if(2*i+1 <= n){
		root->rchild = Bitree_Create_Full(2*i+1, n);
	}else{
		root->rchild = NULL;
	}

	return root;
} 

//1.�������������
bitree *Bitree_Create_unFull()
{
	char ch;
	scanf("%c",&ch);
	//�磺1248###5##36##7## 
	
	if('#' == ch){
		return NULL;
	}
	
	//�ȴ������ڵ㲢���ñ��
	bitree *root = (bitree *)malloc(sizeof(bitree));
	root->data = ch;
	
	root->lchild = Bitree_Create_unFull();
	root->rchild = Bitree_Create_unFull();
	
	return root; 
}

//2.������� (������) (�ݹ�˼��)
void Bitree_TraverbyFront(bitree *root)
{
	if(root == NULL){
		return ;
	}
	
	//�������ڵ� 
	printf("%c ",root->data);
	
	//�ж��Ƿ����������
	if(root->lchild != NULL){
		Bitree_TraverbyFront(root->lchild);
	}
	
	//�ж��Ƿ����������
	if(root->rchild != NULL){
		Bitree_TraverbyFront(root->rchild);
	}
}
 
//3.�������������ң� 
void Bitree_TraverbyMiddle(bitree *root)
{
	//�ж��Ƿ����������
	if(root->lchild != NULL){
		Bitree_TraverbyMiddle(root->lchild);
	}
	
	//�������ڵ�
	printf("%c ",root->data);
	
	//�ж��Ƿ����������
	if(root->rchild != NULL){
		Bitree_TraverbyMiddle(root->rchild);
	}
}

//4.������� �����Ҹ��� 
void Bitree_TraverbyBack(bitree *root)
{
	//�ж��Ƿ����������
	if(root->lchild != NULL){
		Bitree_TraverbyBack(root->lchild);
	}
	
	//�ж��Ƿ����������
	if(root->rchild != NULL){
		Bitree_TraverbyBack(root->rchild);
	}
	
	//�������ڵ�
	printf("%c ",root->data);
}



