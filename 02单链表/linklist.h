#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

//����ڵ�ṹ�� 
typedef struct node{ //Ϊ���ܹ�����ṹ�����͵�ָ�룬�˴���������ṹ���� 
	DataType data; //������ 
	struct node *next; 
	//ָ����Ϊ���ܹ�����������
	//����ָ������Ͷ���Ϊ��ǰ�ṹ������
}linklist; 

//����������
//extern�����ú��������ڱ��Դ�ļ��ﶨ��
extern linklist *Linklist_Create();

//ͷ�巨��������
extern void Linklist_Insert_Head(linklist *Head, DataType value_insert);

//����������
extern int Linklist_Traver(linklist *Head);

//β�巨��������
extern void Linklist_Insert_Tail(linklist *Head, DataType value_insert);

//�жϵ������Ƿ�Ϊ��
extern int Linklist_isEmpty(linklist *Head);

//ͷɾ��ɾ������
extern DataType Linklist_Delete_Head(linklist *Head);

//βɾ��ɾ������
extern DataType Linklist_Delete_Tail(linklist *Head); 

//���������޸�����
extern void Linklist_Change_ByData(linklist *Head, DataType value_old, DataType value_new);

//����λ�ò�������
extern DataType Linklist_Search_ByPos(linklist *Head, int pos_search);

//�������ݲ���λ��
extern int Linklist_Search_ByData(linklist *Head, DataType value_search);

//����λ�ò�������
extern void Linklist_Inseart_ByPos(linklist* Head, int pos_insert, DataType value_insert);

//ֱ�Ӳ�������
extern void Linklist_Sort(linklist *Head, DataType value_insert);

//����ת
extern void Linklist_Overturn(linklist *Head);
 

#endif 
