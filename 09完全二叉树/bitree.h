#ifndef __BITREE_H_
#define __BITREE_H_

#include <stdio.h>
#include <stdlib.h>

//������������
typedef int DataType;

//������ṹ��
typedef struct node{
	DataType data; //����
	int code; //���
	struct node *lchild; //ָ������ 
	struct node *rchild; //ָ���Һ��� 
}bitree;

//1.������ȫ������ 
bitree *Bitree_Create_Full(int i, int n);

//1.�������������
bitree *Bitree_Create_unFull();

//2.�������
void Bitree_TraverbyFront(bitree *root);
 
//3.�������
void Bitree_TraverbyMiddle(bitree *root);

//4.������� 
void Bitree_TraverbyBack(bitree *root);


#endif

