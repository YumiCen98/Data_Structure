#ifndef __LINKSTACK_H_
#define __LINKSTACK_H_

#include <stdio.h>
#include <stdlib.h>

//定义数据类型
//typedef int DataType;
typedef char DataType;

//定义结点结构体
typedef struct node{
	DataType data;
	struct node *next;
}linkstack;

//1.创建空的链式栈
linkstack *Linkstack_Create();

//2.入栈
void Linkstack_Push(linkstack *lk, DataType value_push);

//3.出栈
DataType Linkstack_Pop(linkstack *lk);

//4.打印栈数据
void Linkstack_Show(linkstack *lk);

//5.判断栈空
int Linkstack_isEmpty(linkstack *lk); 


#endif
