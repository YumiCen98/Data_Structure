#include "linkstack.h"

//1.创建空的链式栈
linkstack *Linkstack_Create()
{
	linkstack *lk = (linkstack *)malloc(sizeof(linkstack));
	lk->next == NULL;
	printf("创建链式栈成功\n");
	
	return lk;
}

//2.入栈
void Linkstack_Push(linkstack *lk, DataType value_push)
{
	linkstack *temp = (linkstack *)malloc(sizeof(linkstack));
	temp->data = value_push;
	temp->next = NULL;
	
	temp->next = lk->next;
	lk->next = temp;
	printf("入栈成功\n");
	
	return ;
}

//3.出栈
DataType Linkstack_Pop(linkstack *lk)
{
	if(Linkstack_isEmpty(lk)){
		printf("栈空\n");
		
		return (DataType)-1;
	}
	
	DataType value = lk->data;
	linkstack *p = lk->next;
	
	lk->next = p->next;
	free(p);
	p = NULL;
	printf("出栈成功\n");
	//printf("出栈的数据为：%d\n",value);
	
	return value; 
}

//4.打印栈数据
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

//5.判断栈空
int Linkstack_isEmpty(linkstack *lk)
{
	return NULL == lk->next ? 1 : 0;
}



