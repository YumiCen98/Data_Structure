#include "linklist.h"

//����һ���յĵ�����
//�������ͷ���ĵ�����
//����һ��ͷ��㣬�������򲻸�ֵ��ָ����Ϊ������ʾ��ǰ����Ϊ��
linklist *Linklist_Create(){
	linklist *Head = (linklist *)malloc(sizeof(linklist));
	//ͷ�ڵ�����λΪ�գ�ָ��ָ��ָ��NULL 
	Head->next = NULL;
	
	return Head; 
}

//ͷ�巨��������
void Linklist_Insert_Head(linklist *Head, DataType value_insert){
	//���ٿռ䲢��ֵ
    //(��Ϊ�����յ�����ʱֻ�ǿ�����ͷ���Ŀռ䣬
	//����ÿ�β�������֮ǰ��Ҫ���¿��ٿռ�)
	linklist *temp = (linklist *)malloc(sizeof(linklist));
	temp->data = value_insert;
	temp->next = NULL;
	
	//��ԭ��ͷ��������ĵ�ַ�������²������ָ��������
    //ͷ��������ĵ�ַ:Head->next
    //�²������ָ����:temp->next
	temp->next = Head->next;
	
	//���²�����ĵ�ַ������ͷ����ָ��������
    //�²�����ĵ�ַ:temp
    //ͷ����ָ����:Head->next
	Head->next = temp;
	
	return ;
}

//����������
int Linklist_Traver(linklist *Head){
	//����һ��ָ����������һ�������ݵĽ��ĵ�ַ
	linklist *p = Head->next;
	
	//ѭ������������ֱ��p�������ָ����ΪNULLʱѭ������
	while(p->next != NULL){
		printf("%d ",p->data);
		
		//pָ����һ����㣨p������һ�����ĵ�ַ��
		p = p->next;
	}
	//��ӡ���һ���ڵ��ֵ
	printf("%d\n",p->data);
}

//β�巨��������
void Linklist_Insert_Tail(linklist *Head, DataType value_insert){
	//����ռ䲢��ֵ
	linklist *temp = (linklist *)malloc(sizeof(linklist));
	temp->data = value_insert;
	temp->next = NULL;
	
	//�ҵ����һ�����
	//linklist *p = Head;
	while(Head->next != NULL){
		Head = Head->next;
	}
	
	//���²���Ľ�㱣�������һ�����ĺ���
    //���²���Ľ��ĵ�ַ������pָ��Ľ���ָ��������
	Head->next = temp;
	//���²������ָ������ΪNULL
	temp->next = NULL;
}

//�жϵ������Ƿ�Ϊ��
//���Ϊ�շ���1�����򷵻�0
int Linklist_isEmpty(linklist *Head){
	return NULL == Head->next ? 1 : 0;
}

//ͷɾ��ɾ�����ݣ�����ɾ�������ݣ�
DataType Linklist_Delete_Head(linklist *Head){
	//�жϵ������Ƿ�Ϊ�� 
	if(Linklist_isEmpty(Head)){
		printf("ɾ��ʧ�ܣ�������Ϊ��\n");
		return (DataType)-1; 
	}
	
	//����ɾ��ֵ 
	DataType value = Head->next->data;
	//����ɾ���ĵ�ַ�����ں�����ͷ� 
	linklist *temp = Head->next;
	
	Head->next = Head->next->next;
	
	free(temp); 
	temp = NULL; //��ֹҰָ�� 
	
	return value;
}

//βɾ��ɾ������
DataType Linklist_Delete_Tail(linklist *Head){
	//�жϵ������Ƿ�Ϊ�� 
	if(Linklist_isEmpty(Head)){
		printf("ɾ��ʧ�ܣ�������Ϊ��\n");
		return (DataType)-1; 
	}
	
	linklist *p = Head->next; 
	//�ҵ������ڶ����ڵ� 
	while(p->next->next != NULL){
		p = p->next;
	}
	
	//�������һ���ڵ�ĵ�ַ������free 
	linklist *temp = p->next;
	DataType value = p->next->data;
	
	p->next = NULL; 
	free(temp);
	temp = NULL;
	
	return value; 	
}

//���������޸�����
void Linklist_Change_ByData(linklist *Head, DataType value_old, DataType value_new){
	//�жϵ������Ƿ�Ϊ�� 
	if(Linklist_isEmpty(Head)){
		printf("�޸�ʧ�ܣ�������Ϊ��\n");
		return ; 
	}
	
	//linklist *p = Head->next;
	int flags = 0;
	while(Head->next != NULL){
		Head = Head->next;
		if(value_old == Head->data){
			Head->data = value_new;
			flags = 1;
		}
	} 
	/*���ֱ����Head�Ͳ���Ҫ��һ���������p��Ҫ����һ����֤���һ������ 
	if(value_old == p->data){
		p->data = value_new;
		flags = 1;
	}*/
	if(0 == flags){
		printf("�޸�ʧ�ܣ�û���ҵ�������\n");
		return ;
	}
	printf("���������޸ĳɹ�\n");
}

//����λ�ò������� (���λ��)
DataType Linklist_Search_ByPos(linklist *Head, int pos_search){
	//�жϵ������Ƿ�Ϊ�� 
	if(Linklist_isEmpty(Head)){
		printf("����ʧ�ܣ�������Ϊ��\n");
		return ; 
	}
	
	if(pos_search < 0){
		printf("����λ������\n");
	}
	
	linklist *p = Head;
	int i; 
	for(i=0; i<=pos_search; i++){
		if(NULL == p->next){
			printf("����λ������\n");
			return (DataType)-1;
		}
		p = p->next;
	}
	return p->data;
}

//�������ݲ���λ��
int Linklist_Search_ByData(linklist *Head, DataType value_search){
	//�жϵ������Ƿ�Ϊ�� 
	if(Linklist_isEmpty(Head)){
		printf("����ʧ�ܣ�������Ϊ��\n");
		return -1; 
	}
	
	int i=0;
	while(Head->next != NULL){
		Head = Head->next;
		if(value_search == Head->data){
			return i;
		}
		i++;
	} 
	printf("û�в鵽������\n");
}

//����λ�ò�������
void Linklist_Inseart_ByPos(linklist* Head, int pos_insert, DataType value_insert){
	if(pos_insert < 0){
		printf("����λ������\n");
		return ;
	}
	
	linklist *temp = (linklist *)malloc(sizeof(linklist));
	temp->data = value_insert;
	temp->next = NULL;
	
	//�жϵ������Ƿ�Ϊ�գ�Ϊ����ͷ�� 
	if(Linklist_isEmpty(Head)){
		Head->next = temp;
		temp->next = NULL;
	}else{
		int i=0;
		//�ƶ�Headָ�뵽����λ�õ�ǰһ���ڵ� 
		for(i=0; i<pos_insert; i++){
			if(NULL == Head->next){
				printf("����λ������\n");
				return ;
			} 
			Head = Head->next; 
		}
		temp->next = Head->next;
		Head->next = temp;
		printf("����λ�ò���ɹ�\n");
	}
	
	/* 
	while(NULL != Head->next){
		Head = Head->next;
		i++;
		if(i == pos_insert){
			temp->next = Head->next;
			Head->next = temp;
			printf("����λ�ò���ɹ�\n");
			return ;
		}
	}*/
}

//ֱ�Ӳ������򣨾��������㷨��
//ȷ���������򣬲���������ʱ�����������ݶԱȲ�����ʵ�λ�� 
void Linklist_Sort(linklist *Head, DataType value_insert){
	linklist *temp = (linklist *)malloc(sizeof(linklist)); 
	temp->data = value_insert;
	temp->next = NULL;
	
	while(NULL != Head->next && Head->next->data < value_insert){
		Head = Head->next;
	}
	temp->next = Head->next;
	Head->next = temp;
	
	/*
	//�жϵ������Ƿ�Ϊ�գ�Ϊ����ͷ�� 
	if(Linklist_isEmpty(Head)){
		Head->next = temp;
		temp->next = NULL;
		printf("��������ɹ�\n"); 
	}else{
		while(NULL != Head->next){
			if(value_insert < Head->next->data){
				temp->next = Head->next;
				Head->next = temp;
				printf("��������ɹ�\n"); 
				return ;
			}
			Head = Head->next;
		}
		Head->next = temp;
		temp->next = NULL;
		printf("��������ɹ�\n"); 
	}*/
}

//����ת��ͷɾ��ɾ��ԭ����������ɾ�������ݣ�����ͷ�巨�����µ����� 
void Linklist_Overturn(linklist *Head){
	//�жϵ������Ƿ�Ϊ�� 
	if(Linklist_isEmpty(Head)){
		printf("������Ϊ��\n");
		return ; 
	}
	
	//��������ָ�������ִ������ķ�ת
	//pָ�뱣��ͷ�ڵ��ĵ�һ�������ݵĽڵ�ĵ�ַ 
	linklist *p = Head->next; 
	//qָ��ÿ��ָ��ɾ���Ľڵ�ĵ�ַ���������ڲ��� 
	linklist *q; 
	//ͷ����ָ������ڿ�����ʼ��ͷ���
	Head->next = NULL;
	
	//ѭ����qָ�뱣��pָ��Ľڵ���׵�ַ 
	while(NULL != p){
		//qָ�뱣��pָ��Ľ��ĵ�ַ
		q = p;
		//pָ����Ʊ�����һ�����ĵ�ַ
		p = p->next; 
		
		//ͨ��ͷ�巨��qָ��Ľ����뵽ͷ���ĺ���
		q->next = Head->next;
		Head->next = q;
	}
	
	return ;
}



