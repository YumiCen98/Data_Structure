#ifndef __LOOPLIST_H_
#define __LOOPLIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct node{
	DataType data;
	struct node *next;
}looplist;

//1.����һ���յĵ���ѭ������ 
looplist *Looplist_Create();

//2.��������
void Looplist_Insert(looplist *Head, DataType value_insert);

//3.��ͷ�ڵ��ӡ����
void Looplist_Traver_Head(looplist *Head);

//4.ɾ��ͷ�ڵ�
looplist *Looplist_DeleteHead(looplist *Head);

//5.ɾ������
void Looplis_Delete(looplist *Head, DataType value_delete);

//6.ɾ��ͷ�ڵ���ӡ���� 
void Looplist_Traver_NoHead(looplist *Head);

//7.Լɪ������
void Joseph(int n, int k, int m); 

#endif
