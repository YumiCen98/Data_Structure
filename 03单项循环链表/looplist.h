#ifndef __LOOPLIST_H_
#define __LOOPLIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct node{
	DataType data;
	struct node *next;
}looplist;

//1.创建一个空的单向循环链表 
looplist *Looplist_Create();

//2.插入数据
void Looplist_Insert(looplist *Head, DataType value_insert);

//3.含头节点打印数据
void Looplist_Traver_Head(looplist *Head);

//4.删除头节点
looplist *Looplist_DeleteHead(looplist *Head);

//5.删除数据
void Looplis_Delete(looplist *Head, DataType value_delete);

//6.删除头节点后打印数据 
void Looplist_Traver_NoHead(looplist *Head);

//7.约瑟夫问题
void Joseph(int n, int k, int m); 

#endif
