#include "doublelist.h"

//1.创建一个空的双向循环链表
doublelist *Doublelist_Create(){
	//在堆区开辟空间
	doublelist *Head = (doublelist *)malloc(sizeof(doublelist));
	
	//让头结点的两个指针保存头结点的地址
	Head->next = Head;
	Head->front = Head;
	printf("双向循环链表创建成功\n");
	
	return Head;
}

//2.插入数据
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
		//插入时，头结点的front和尾节点的next指向不变，不用管 
		temp->next = Head->next;
		Head->next->front = temp;
		
		Head->next = temp;
		temp->front = Head; 
	}*/
	
	//因为Head->next = Head,所以上述可以简化为
	temp->next = Head->next;
	Head->next->front = temp;
	
	Head->next = temp;
	temp->front = Head; 
	
	printf("插入成功\n");
}

//3.遍历链表（先顺序后逆序）
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

//4.按内容删除数据
void Doublelist_Delete(doublelist *Head, DataType value_delete){
	if(Head->next == Head)
    {
        printf("链表为空\n");
        return ;
    }

	doublelist *p = Head;
	while(p != Head->next){
		Head = Head->next;
		if(value_delete == Head->data){
			Head->front->next = Head->next;
			Head->next->front = Head->front;
			printf("删除成功\n"); 
		}
	}
}

//5.双向循环链表头删法删除数据
DataType Doublelist_DeletefromHead(doublelist *Head){
	if(Head->next == Head)
    {
        printf("链表为空\n");
        return ;
    }

	//定义变量保存要删除的结点的地址
	doublelist *p = Head->next;
	DataType value = p->data;
	
	Head->next = p->next;
	p->next->front = Head;
	printf("删除成功\n"); 
	
	free(p);
	p = NULL;
	
	return value;
}

 


