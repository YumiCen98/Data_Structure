#ifndef __LINKQUEUE_H_
#define __LINKQUEUE_H_

#include <stdio.h>
#include <stdlib.h>

//������������
typedef int DataType;

//������ṹ��
typedef struct node{
	DataType data;
	struct node *next;
}linknode;

//����ṹ����ڷ��ز�����ʽ���е�����ָ��
typedef struct{
	//����ͷ���ĵ�ַ
	linknode *front;
	//ÿ�α������һ�����ĵ�ַ
	linknode *rear;
}linkqueue;

//1.������ʽ����
linkqueue *Linkqueue_Create();

//2.���
void Linkqueue_Push(linkqueue *lq, DataType value_push); 

//3.���� 
void Linkqueue_Pop(linkqueue *lq); 

//4.�ж϶ӿ�
int Linkqueue_isEmpty(linkqueue *lq); 


#endif
