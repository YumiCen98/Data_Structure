#ifndef __DOUBLELIST_H_
#define __DOUBLELIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

//������ṹ��
typedef struct node{
	DataType data;
	struct node *next; //�����һ�����ĵ�ַ
	struct node *front; //����ǰһ�����ĵ�ַ
}doublelist;

//1.����һ���յ�˫��ѭ������
doublelist *Doublelist_Create();

//2.��������
void Doublelist_Insert(doublelist *Head, DataType value_insert);

//3.����������˳�������
void Doublelist_Traver(doublelist *Head); 

//4.������ɾ������
void Doublelist_Delete(doublelist *Head, DataType value_delete); 

//5.˫��ѭ������ͷɾ��ɾ������
DataType Doublelist_DeletefromHead(doublelist *Head);


#endif
