#ifndef __HASH_H_
#define __HASH_H_

#include <stdio.h>
#include <stdlib.h>

//����13��ͷ�ڵ� 
#define N 13
//64λϵͳָ���ַ��СΪ8 
#define ADDR_SIZE 8

typedef struct node{
	int data;
	struct node *next;
}HASH;

//1.������ϣ��(������ʮ����ͷ�ڵ�)
HASH ** Hash_Create();

//2.��������
int Hash_InsertTable(HASH **h, int value);

//3.��ӡ�źõ�hash��
int Hash_ShowTable(struct node *head);

//4.��������
int Hash_SearchTable(HASH **h, int value); 

#endif
