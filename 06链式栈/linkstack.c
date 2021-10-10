#include "linkstack.h"

//1.�����յ���ʽջ
linkstack *Linkstack_Create()
{
	linkstack *lk = (linkstack *)malloc(sizeof(linkstack));
	lk->next == NULL;
	printf("������ʽջ�ɹ�\n");
	
	return lk;
}

//2.��ջ
void Linkstack_Push(linkstack *lk, DataType value_push)
{
	linkstack *temp = (linkstack *)malloc(sizeof(linkstack));
	temp->data = value_push;
	temp->next = NULL;
	
	temp->next = lk->next;
	lk->next = temp;
	printf("��ջ�ɹ�\n");
	
	return ;
}

//3.��ջ
DataType Linkstack_Pop(linkstack *lk)
{
	if(Linkstack_isEmpty(lk)){
		printf("ջ��\n");
		
		return (DataType)-1;
	}
	
	DataType value = lk->data;
	linkstack *p = lk->next;
	
	lk->next = p->next;
	free(p);
	p = NULL;
	printf("��ջ�ɹ�\n");
	//printf("��ջ������Ϊ��%d\n",value);
	
	return value; 
}

//4.��ӡջ����
void Linkstack_Show(linkstack *lk)
{
	linkstack *p = lk->next;
	while(NULL != p->next){
		printf("%d ",p->data);
		p = p->next;	
	}
	putch(10);
	return ;
}

//5.�ж�ջ��
int Linkstack_isEmpty(linkstack *lk)
{
	return NULL == lk->next ? 1 : 0;
}



