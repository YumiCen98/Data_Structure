#ifndef __SEQSTACK_H_
#define __SEQSTACK_H_

#include <stdio.h>
#include <stdlib.h>

#define N 32

//定义数据类型
typedef int DataType;
//定义结构体
typedef struct{
	DataType data[N];
	int pos;
}seqstack;

//1.创建顺序栈
seqstack *Seqstack_Create();

//2.判断栈空
int Seqstack_isEmpty(seqstack *sk);

//3.判断栈满
int Seqstack_isFull(seqstack *sk); 

//4.弹栈
DataType Seqstack_Pop(seqstack *sk);

//5.入栈
void Seqstack_Push(seqstack *sk, DataType value_push); 

//6.打印数据
void Seqstack_Show(seqstack *sk);


#endif
