#ifndef __SEQSTACK_H_
#define __SEQSTACK_H_

#include <stdio.h>
#include <stdlib.h>

#define N 32

//������������
typedef int DataType;
//����ṹ��
typedef struct{
	DataType data[N];
	int pos;
}seqstack;

//1.����˳��ջ
seqstack *Seqstack_Create();

//2.�ж�ջ��
int Seqstack_isEmpty(seqstack *sk);

//3.�ж�ջ��
int Seqstack_isFull(seqstack *sk); 

//4.��ջ
DataType Seqstack_Pop(seqstack *sk);

//5.��ջ
void Seqstack_Push(seqstack *sk, DataType value_push); 

//6.��ӡ����
void Seqstack_Show(seqstack *sk);


#endif
