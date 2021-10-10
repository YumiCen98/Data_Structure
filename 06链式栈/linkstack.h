#ifndef __LINKSTACK_H_
#define __LINKSTACK_H_

#include <stdio.h>
#include <stdlib.h>

//������������
//typedef int DataType;
typedef char DataType;

//������ṹ��
typedef struct node{
	DataType data;
	struct node *next;
}linkstack;

//1.�����յ���ʽջ
linkstack *Linkstack_Create();

//2.��ջ
void Linkstack_Push(linkstack *lk, DataType value_push);

//3.��ջ
DataType Linkstack_Pop(linkstack *lk);

//4.��ӡջ����
void Linkstack_Show(linkstack *lk);

//5.�ж�ջ��
int Linkstack_isEmpty(linkstack *lk); 


#endif
