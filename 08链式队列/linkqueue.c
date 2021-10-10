#include "linkqueue.h"

//1.创建链式队列
linkqueue *Linkqueue_Create()
{
	//创建两个指针
	linkqueue *lq = (linkqueue *)malloc(sizeof(linkqueue));
	
	//创建一个头结点并且让next指针保存NULL标识为空
	lq->front = lq->rear = (linknode *)malloc(sizeof(linknode));
	lq->front->next = NULL; 
	
	return lq;
}

//2.入队（头插法入队） 
void Linkqueue_Push(linkqueue *lq, DataType value_push)
{
	//申请空间并赋值
	linknode *temp = (linknode *)malloc(sizeof(linknode));
	temp->data = value_push;
	temp->next = NULL;
	
	//将新结点插入到rear对应结点的后面
    //rear结点的指针域保存新结点的地址
	lq->rear->next = temp;
	//新结点的指针域保存NULL
	temp->next = NULL;
	//rear保存新插入结点的地址
	lq->rear = temp;
	
	printf("%d 入队成功\n",value_push);
}

//3.出队（尾删法出队） 
void Linkqueue_Pop(linkqueue *lq)
{
	if(Linkqueue_isEmpty(lq)){
		printf("队空\n");
		//return (DataType)-1; 
		return ;
	}
	
	//将front对应结点的后面的结点删除
	linknode *temp = lq->front->next; 
	lq->front->next = temp->next; 
	
	DataType value = temp->data;
	
	free(temp);
	temp = NULL;
	printf("%d 出队成功\n",value);
	
	//当最后一个结点删除之后，需要将rear指针指向头结点
	if(NULL == lq->front->next){
		lq->rear = lq->front;
	}
	
	//return value;
}

//4.判断队空
int Linkqueue_isEmpty(linkqueue *lq)
{
	return NULL == lq->front->next ? 1 : 0;
}



