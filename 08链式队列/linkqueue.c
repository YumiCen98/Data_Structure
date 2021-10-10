#include "linkqueue.h"

//1.������ʽ����
linkqueue *Linkqueue_Create()
{
	//��������ָ��
	linkqueue *lq = (linkqueue *)malloc(sizeof(linkqueue));
	
	//����һ��ͷ��㲢����nextָ�뱣��NULL��ʶΪ��
	lq->front = lq->rear = (linknode *)malloc(sizeof(linknode));
	lq->front->next = NULL; 
	
	return lq;
}

//2.��ӣ�ͷ�巨��ӣ� 
void Linkqueue_Push(linkqueue *lq, DataType value_push)
{
	//����ռ䲢��ֵ
	linknode *temp = (linknode *)malloc(sizeof(linknode));
	temp->data = value_push;
	temp->next = NULL;
	
	//���½����뵽rear��Ӧ���ĺ���
    //rear����ָ���򱣴��½��ĵ�ַ
	lq->rear->next = temp;
	//�½���ָ���򱣴�NULL
	temp->next = NULL;
	//rear�����²�����ĵ�ַ
	lq->rear = temp;
	
	printf("%d ��ӳɹ�\n",value_push);
}

//3.���ӣ�βɾ�����ӣ� 
void Linkqueue_Pop(linkqueue *lq)
{
	if(Linkqueue_isEmpty(lq)){
		printf("�ӿ�\n");
		//return (DataType)-1; 
		return ;
	}
	
	//��front��Ӧ���ĺ���Ľ��ɾ��
	linknode *temp = lq->front->next; 
	lq->front->next = temp->next; 
	
	DataType value = temp->data;
	
	free(temp);
	temp = NULL;
	printf("%d ���ӳɹ�\n",value);
	
	//�����һ�����ɾ��֮����Ҫ��rearָ��ָ��ͷ���
	if(NULL == lq->front->next){
		lq->rear = lq->front;
	}
	
	//return value;
}

//4.�ж϶ӿ�
int Linkqueue_isEmpty(linkqueue *lq)
{
	return NULL == lq->front->next ? 1 : 0;
}



