#ifndef __SEQUEUE_H_
#define __SEQUEUE_H_

#include <stdio.h>
#include <stdlib.h>

#define NUM 5
#define N (NUM+1)

//������������
typedef int DataType;
//����ṹ��
typedef struct{
	DataType data[N];
	//������ӵ�Ԫ���±�
	int front;
	//�������λ��
	int rear;
}sequeue;

//1.����һ���յ�˳����� 
sequeue *Sequeue_Create();

//2.�ж϶����Ƿ�Ϊ��
int Sequeue_isEmpty(sequeue *sq);

//3.�ж϶����Ƿ�Ϊ��
int Sequeue_isFull(sequeue *sq);

//4.���
void Sequeue_Push(sequeue *sq, DataType value_push);

//5.����
DataType Sequeue_Pop(sequeue *sq); 


#endif



