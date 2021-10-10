#include "looplist.h"

//1.����һ���յĵ���ѭ������ 
looplist *Looplist_Create(){
	looplist *Head = (looplist *)malloc(sizeof(looplist));
	Head->next = Head;
	
	return Head;
}

//2.��������
void Looplist_Insert(looplist *Head, DataType value_insert){
	looplist *temp = (looplist *)malloc(sizeof(looplist));
	temp->data = value_insert;
	temp->next = NULL;
	
	//������ĩβ����β�壬����������ͷ�� 
	/*
	looplist *p = Head;
	while(p != Head->next){
		Head = Head->next;
	}*/
	
	temp->next = Head->next;
	Head->next = temp;
	
	printf("����ɹ�\n"); 
}

//3.��ͷ�ڵ��ӡ����
void Looplist_Traver_Head(looplist *Head){
	looplist *p = Head;
	while(p != Head->next){
		Head = Head->next;
		printf("%d ",Head->data);
	}
	putch(10);
}

//4.ɾ��ͷ�ڵ㣬��Ҫ�����µ�ͷ(�׵�ַ) 
looplist *Looplist_DeleteHead(looplist *Head){
	looplist *p = Head;
	while(p != Head->next){
		Head = Head->next;
	}
	Head->next = p->next;
	free(p);
	p = NULL;
	printf("ɾ��ͷ�ڵ�ɹ�\n");
	
	return Head->next;
}

//5.ɾ�����ݣ���һ�������ݵ�ͷ�ڵ㲻��ɾ�� 
void Looplist_Delete(looplist *Head, DataType value_delete){
	looplist *p = Head;
	while(p != Head->next){
		if(value_delete == Head->next->data){
			Head->next = Head->next->next;
			printf("ɾ�����ݳɹ�\n");
			return ;
		}
		Head = Head->next;
	} 
	printf("û���ҵ�Ҫɾ��������\n");
}

//6.ɾ��ͷ�ڵ���ӡ���� 
void Looplist_Traver_NoHead(looplist *Head){
	looplist *p = Head;
	while(p != Head->next){
		//û�пհ׵�ͷ�ڵ��ˣ�������Ҫ�ȴ�ӡͷ�ڵ� 
		printf("%d ",Head->data);
		Head = Head->next;
	} 
	printf("%d ",Head->data);
	putch(10);
}

//Լɪ������
void Joseph(int n, int k, int m){
	//����һ������ѭ������
	looplist *Head = Looplist_Create();
	
	int i;
	looplist *temp;
	
	//�������� 
	for(i = n; i >0; i--){
		Looplist_Insert(Head, i);
	}
	printf("Լɪ�򻷴������\n");
	//ɾ��ͷ�ڵ� 
	Head = Looplist_DeleteHead(Head);
	Looplist_Traver_NoHead(Head);
	
	//��λ�����Ϊk������ 
	for(i = 1; i<k; i++){
		Head = Head->next;
	}
	//printf("k = %d\n",Head->data);
	
	//ѭ��ɾ������m���Ǹ����
	//ѭ��������������ֻʣ�����һ�����
	while(Head != Head->next){
		//Ϊ��ɾ��ָ���Ľ�㣬����hָ�뱣������m-1�Ľ��
		for(i = 1; i<m-1; i++){
			Head = Head->next;
		}
		//printf("m-1 = %d\n",Head->data);
		
		//ɾ��h����Ľ��
		temp = Head->next;
		Head->next = temp->next;
		
		printf("%d ",temp->data);
		
		free(temp);
		temp = NULL;
		
		//����һ����������ʼ����
		Head = Head->next; 
	} 
	
	printf("%d\n",Head->data);
	free(Head);
	Head = NULL;
	
	return ;
}


