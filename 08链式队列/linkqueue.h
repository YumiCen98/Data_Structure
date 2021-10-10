#ifndef __LINKQUEUE_H_
#define __LINKQUEUE_H_

#include <stdio.h>
#include <stdlib.h>

//定义数据类型
typedef int DataType;

//定义结点结构体
typedef struct node{
	DataType data;
	struct node *next;
}linknode;

//定义结构体便于返回操作链式队列的两个指针
typedef struct{
	//保存头结点的地址
	linknode *front;
	//每次保存最后一个结点的地址
	linknode *rear;
}linkqueue;

//1.创建链式队列
linkqueue *Linkqueue_Create();

//2.入队
void Linkqueue_Push(linkqueue *lq, DataType value_push); 

//3.出队 
void Linkqueue_Pop(linkqueue *lq); 

//4.判断队空
int Linkqueue_isEmpty(linkqueue *lq); 


#endif
