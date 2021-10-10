#include "doublelist.h"

//1.����һ���յ�˫��ѭ������
doublelist *Doublelist_Create(){
	//�ڶ������ٿռ�
	doublelist *Head = (doublelist *)malloc(sizeof(doublelist));
	
	//��ͷ��������ָ�뱣��ͷ���ĵ�ַ
	Head->next = Head;
	Head->front = Head;
	printf("˫��ѭ���������ɹ�\n");
	
	return Head;
}

//2.��������
void Doublelist_Insert(doublelist *Head, DataType value_insert){
	doublelist *temp = (doublelist *)malloc(sizeof(doublelist));
	temp->data = value_insert;
	
	/*
	if(Head == Head->next){
		Head->next = temp;
		Head->front = temp;
		
		temp->next = Head;
		temp->front = Head; 
	}else{
		//����ʱ��ͷ����front��β�ڵ��nextָ�򲻱䣬���ù� 
		temp->next = Head->next;
		Head->next->front = temp;
		
		Head->next = temp;
		temp->front = Head; 
	}*/
	
	//��ΪHead->next = Head,�����������Լ�Ϊ
	temp->next = Head->next;
	Head->next->front = temp;
	
	Head->next = temp;
	temp->front = Head; 
	
	printf("����ɹ�\n");
}

//3.����������˳�������
void Doublelist_Traver(doublelist *Head){
	doublelist *p = Head;
	while(p != Head->next){
		Head = Head->next;
		printf("%d ",Head->data);
	}
	putch(10);
	
	while(p != Head->front){
		printf("%d ",Head->data);
		Head = Head->front;
	}
	printf("%d ",Head->data);
	putch(10);
}

//4.������ɾ������
void Doublelist_Delete(doublelist *Head, DataType value_delete){
	if(Head->next == Head)
    {
        printf("����Ϊ��\n");
        return ;
    }

	doublelist *p = Head;
	while(p != Head->next){
		Head = Head->next;
		if(value_delete == Head->data){
			Head->front->next = Head->next;
			Head->next->front = Head->front;
			printf("ɾ���ɹ�\n"); 
		}
	}
}

//5.˫��ѭ������ͷɾ��ɾ������
DataType Doublelist_DeletefromHead(doublelist *Head){
	if(Head->next == Head)
    {
        printf("����Ϊ��\n");
        return ;
    }

	//�����������Ҫɾ���Ľ��ĵ�ַ
	doublelist *p = Head->next;
	DataType value = p->data;
	
	Head->next = p->next;
	p->next->front = Head;
	printf("ɾ���ɹ�\n"); 
	
	free(p);
	p = NULL;
	
	return value;
}

 


