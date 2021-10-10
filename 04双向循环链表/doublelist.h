#ifndef __DOUBLELIST_H_
#define __DOUBLELIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

//定义结点结构体
typedef struct node{
	DataType data;
	struct node *next; //保存后一个结点的地址
	struct node *front; //保存前一个结点的地址
}doublelist;

//1.创建一个空的双向循环链表
doublelist *Doublelist_Create();

//2.插入数据
void Doublelist_Insert(doublelist *Head, DataType value_insert);

//3.遍历链表（先顺序后逆序）
void Doublelist_Traver(doublelist *Head); 

//4.按内容删除数据
void Doublelist_Delete(doublelist *Head, DataType value_delete); 

//5.双向循环链表头删法删除数据
DataType Doublelist_DeletefromHead(doublelist *Head);


#endif
