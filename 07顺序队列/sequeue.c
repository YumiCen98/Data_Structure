#include "sequeue.h"

//1.创建一个空的顺序队列 
sequeue *Sequeue_Create()
{
	//申请空间
	sequeue *sq = (sequeue *)malloc(sizeof(sequeue));
	//初始状态让front和rear都保存0标识为空
	sq->front = 0;
	sq->rear = 0;
	
	printf("创建队列成功\n");
	
	return sq; 
}

//2.判断队列是否为空
int Sequeue_isEmpty(sequeue *sq)
{
	return sq->front == sq->rear ? 1 : 0;
}

//3.判断队列是否为满
int Sequeue_isFull(sequeue *sq)
{
	return ((sq->rear+1)%N) == sq->front ? 1 : 0;
}

//4.入队
void Sequeue_Push(sequeue *sq, DataType value_push)
{
	if(Sequeue_isFull){
		printf("队满\n");
		return ;
	}
	
	//将数据保存在rear对应的数组位置上
	sq->data[sq->rear] = value_push;
	//rear保存下一个元素的下标
	sq->rear = (sq->rear+1)%N;
	
	printf("入队成功\n");
}

//5.出队
DataType Sequeue_Pop(sequeue *sq)
{
	if(Sequeue_isEmpty){
		printf("队空\n");
		return (DataType)-1;
	}
	
	//定义临时变量保存要出队的数据
	DataType value = sq->data[sq->front];
	
	//front后移保存下一个要出队的数据的下标
	sq->front = (sq->front+1)%N;
	printf("出队成功\n");
	
	return value;
}



