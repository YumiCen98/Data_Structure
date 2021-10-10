#ifndef __BITREE_H_
#define __BITREE_H_

#include <stdio.h>
#include <stdlib.h>

//定义数据类型
typedef int DataType;

//定义结点结构体
typedef struct node{
	DataType data; //数据
	int code; //编号
	struct node *lchild; //指向左孩子 
	struct node *rchild; //指向右孩子 
}bitree;

//1.创建完全二叉树 
bitree *Bitree_Create_Full(int i, int n);

//1.创建任意二叉树
bitree *Bitree_Create_unFull();

//2.先序遍历
void Bitree_TraverbyFront(bitree *root);
 
//3.中序遍历
void Bitree_TraverbyMiddle(bitree *root);

//4.后序遍历 
void Bitree_TraverbyBack(bitree *root);


#endif

