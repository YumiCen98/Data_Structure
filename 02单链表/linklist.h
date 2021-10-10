#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

//定义节点结构体 
typedef struct node{ //为了能够定义结构体类型的指针，此处必须给定结构体名 
	DataType data; //数据域 
	struct node *next; 
	//指针域，为了能够操作后面结点
	//所以指针的类型定义为当前结构体类型
}linklist; 

//创建单链表
//extern表明该函数可能在别的源文件里定义
extern linklist *Linklist_Create();

//头插法插入数据
extern void Linklist_Insert_Head(linklist *Head, DataType value_insert);

//遍历单链表
extern int Linklist_Traver(linklist *Head);

//尾插法插入数据
extern void Linklist_Insert_Tail(linklist *Head, DataType value_insert);

//判断单链表是否为空
extern int Linklist_isEmpty(linklist *Head);

//头删法删除数据
extern DataType Linklist_Delete_Head(linklist *Head);

//尾删法删除数据
extern DataType Linklist_Delete_Tail(linklist *Head); 

//按照数据修改数据
extern void Linklist_Change_ByData(linklist *Head, DataType value_old, DataType value_new);

//按照位置查找数据
extern DataType Linklist_Search_ByPos(linklist *Head, int pos_search);

//按照数据查找位置
extern int Linklist_Search_ByData(linklist *Head, DataType value_search);

//按照位置插入数据
extern void Linklist_Inseart_ByPos(linklist* Head, int pos_insert, DataType value_insert);

//直接插入排序
extern void Linklist_Sort(linklist *Head, DataType value_insert);

//链表翻转
extern void Linklist_Overturn(linklist *Head);
 

#endif 
