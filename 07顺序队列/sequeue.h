#ifndef __SEQUEUE_H_
#define __SEQUEUE_H_

#include <stdio.h>
#include <stdlib.h>

#define NUM 5
#define N (NUM+1)

//定义数据类型
typedef int DataType;
//定义结构体
typedef struct{
	DataType data[N];
	//保存出队的元素下标
	int front;
	//保存入队位置
	int rear;
}sequeue;

//1.创建一个空的顺序队列 
sequeue *Sequeue_Create();

//2.判断队列是否为空
int Sequeue_isEmpty(sequeue *sq);

//3.判断队列是否为满
int Sequeue_isFull(sequeue *sq);

//4.入队
void Sequeue_Push(sequeue *sq, DataType value_push);

//5.出队
DataType Sequeue_Pop(sequeue *sq); 


#endif



