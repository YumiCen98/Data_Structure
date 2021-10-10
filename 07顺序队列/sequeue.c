#include "sequeue.h"

//1.����һ���յ�˳����� 
sequeue *Sequeue_Create()
{
	//����ռ�
	sequeue *sq = (sequeue *)malloc(sizeof(sequeue));
	//��ʼ״̬��front��rear������0��ʶΪ��
	sq->front = 0;
	sq->rear = 0;
	
	printf("�������гɹ�\n");
	
	return sq; 
}

//2.�ж϶����Ƿ�Ϊ��
int Sequeue_isEmpty(sequeue *sq)
{
	return sq->front == sq->rear ? 1 : 0;
}

//3.�ж϶����Ƿ�Ϊ��
int Sequeue_isFull(sequeue *sq)
{
	return ((sq->rear+1)%N) == sq->front ? 1 : 0;
}

//4.���
void Sequeue_Push(sequeue *sq, DataType value_push)
{
	if(Sequeue_isFull){
		printf("����\n");
		return ;
	}
	
	//�����ݱ�����rear��Ӧ������λ����
	sq->data[sq->rear] = value_push;
	//rear������һ��Ԫ�ص��±�
	sq->rear = (sq->rear+1)%N;
	
	printf("��ӳɹ�\n");
}

//5.����
DataType Sequeue_Pop(sequeue *sq)
{
	if(Sequeue_isEmpty){
		printf("�ӿ�\n");
		return (DataType)-1;
	}
	
	//������ʱ��������Ҫ���ӵ�����
	DataType value = sq->data[sq->front];
	
	//front���Ʊ�����һ��Ҫ���ӵ����ݵ��±�
	sq->front = (sq->front+1)%N;
	printf("���ӳɹ�\n");
	
	return value;
}



