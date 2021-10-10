#include "linklist.h"

//创建一个空的单链表
//如果是有头结点的单链表，
//定义一个头结点，让数据域不赋值，指针域为空来表示当前链表为空
linklist *Linklist_Create(){
	linklist *Head = (linklist *)malloc(sizeof(linklist));
	//头节点数据位为空，指针指针指向NULL 
	Head->next = NULL;
	
	return Head; 
}

//头插法插入数据
void Linklist_Insert_Head(linklist *Head, DataType value_insert){
	//开辟空间并赋值
    //(因为创建空单链表时只是开辟了头结点的空间，
	//所以每次插入数据之前需要重新开辟空间)
	linklist *temp = (linklist *)malloc(sizeof(linklist));
	temp->data = value_insert;
	temp->next = NULL;
	
	//将原本头结点后面结点的地址保存在新插入结点的指针域里面
    //头结点后面结点的地址:Head->next
    //新插入结点的指针域:temp->next
	temp->next = Head->next;
	
	//将新插入结点的地址保存在头结点的指针域里面
    //新插入结点的地址:temp
    //头结点的指针域:Head->next
	Head->next = temp;
	
	return ;
}

//遍历单链表
int Linklist_Traver(linklist *Head){
	//定义一个指针遍历保存第一个有数据的结点的地址
	linklist *p = Head->next;
	
	//循环遍历单链表，直到p保存结点的指针域为NULL时循环结束
	while(p->next != NULL){
		printf("%d ",p->data);
		
		//p指向下一个结点（p保存下一个结点的地址）
		p = p->next;
	}
	//打印最后一个节点的值
	printf("%d\n",p->data);
}

//尾插法插入数据
void Linklist_Insert_Tail(linklist *Head, DataType value_insert){
	//申请空间并赋值
	linklist *temp = (linklist *)malloc(sizeof(linklist));
	temp->data = value_insert;
	temp->next = NULL;
	
	//找到最后一个结点
	//linklist *p = Head;
	while(Head->next != NULL){
		Head = Head->next;
	}
	
	//将新插入的结点保存在最后一个结点的后面
    //将新插入的结点的地址保存在p指向的结点的指针域里面
	Head->next = temp;
	//将新插入结点的指针域置为NULL
	temp->next = NULL;
}

//判断单链表是否为空
//如果为空返回1，否则返回0
int Linklist_isEmpty(linklist *Head){
	return NULL == Head->next ? 1 : 0;
}

//头删法删除数据（返回删除的数据）
DataType Linklist_Delete_Head(linklist *Head){
	//判断单链表是否为空 
	if(Linklist_isEmpty(Head)){
		printf("删除失败，单链表为空\n");
		return (DataType)-1; 
	}
	
	//保存删除值 
	DataType value = Head->next->data;
	//保存删除的地址，用于后面的释放 
	linklist *temp = Head->next;
	
	Head->next = Head->next->next;
	
	free(temp); 
	temp = NULL; //防止野指针 
	
	return value;
}

//尾删法删除数据
DataType Linklist_Delete_Tail(linklist *Head){
	//判断单链表是否为空 
	if(Linklist_isEmpty(Head)){
		printf("删除失败，单链表为空\n");
		return (DataType)-1; 
	}
	
	linklist *p = Head->next; 
	//找到倒数第二个节点 
	while(p->next->next != NULL){
		p = p->next;
	}
	
	//保存最后一个节点的地址，用于free 
	linklist *temp = p->next;
	DataType value = p->next->data;
	
	p->next = NULL; 
	free(temp);
	temp = NULL;
	
	return value; 	
}

//按照数据修改数据
void Linklist_Change_ByData(linklist *Head, DataType value_old, DataType value_new){
	//判断单链表是否为空 
	if(Linklist_isEmpty(Head)){
		printf("修改失败，单链表为空\n");
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
	/*如果直接用Head就不需要这一步，如果用p需要用这一步验证最后一个数据 
	if(value_old == p->data){
		p->data = value_new;
		flags = 1;
	}*/
	if(0 == flags){
		printf("修改失败，没有找到该数据\n");
		return ;
	}
	printf("按照数据修改成功\n");
}

//按照位置查找数据 (相对位置)
DataType Linklist_Search_ByPos(linklist *Head, int pos_search){
	//判断单链表是否为空 
	if(Linklist_isEmpty(Head)){
		printf("查找失败，单链表为空\n");
		return ; 
	}
	
	if(pos_search < 0){
		printf("查找位置有误\n");
	}
	
	linklist *p = Head;
	int i; 
	for(i=0; i<=pos_search; i++){
		if(NULL == p->next){
			printf("查找位置有误\n");
			return (DataType)-1;
		}
		p = p->next;
	}
	return p->data;
}

//按照数据查找位置
int Linklist_Search_ByData(linklist *Head, DataType value_search){
	//判断单链表是否为空 
	if(Linklist_isEmpty(Head)){
		printf("查找失败，单链表为空\n");
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
	printf("没有查到该数据\n");
}

//按照位置插入数据
void Linklist_Inseart_ByPos(linklist* Head, int pos_insert, DataType value_insert){
	if(pos_insert < 0){
		printf("插入位置有误\n");
		return ;
	}
	
	linklist *temp = (linklist *)malloc(sizeof(linklist));
	temp->data = value_insert;
	temp->next = NULL;
	
	//判断单链表是否为空，为空则头插 
	if(Linklist_isEmpty(Head)){
		Head->next = temp;
		temp->next = NULL;
	}else{
		int i=0;
		//移动Head指针到插入位置的前一个节点 
		for(i=0; i<pos_insert; i++){
			if(NULL == Head->next){
				printf("插入位置有误\n");
				return ;
			} 
			Head = Head->next; 
		}
		temp->next = Head->next;
		Head->next = temp;
		printf("按照位置插入成功\n");
	}
	
	/* 
	while(NULL != Head->next){
		Head = Head->next;
		i++;
		if(i == pos_insert){
			temp->next = Head->next;
			Head->next = temp;
			printf("按照位置插入成功\n");
			return ;
		}
	}*/
}

//直接插入排序（经典排序算法）
//确保事先有序，插入新数据时，与链表数据对比插入合适的位置 
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
	//判断单链表是否为空，为空则头插 
	if(Linklist_isEmpty(Head)){
		Head->next = temp;
		temp->next = NULL;
		printf("插入排序成功\n"); 
	}else{
		while(NULL != Head->next){
			if(value_insert < Head->next->data){
				temp->next = Head->next;
				Head->next = temp;
				printf("插入排序成功\n"); 
				return ;
			}
			Head = Head->next;
		}
		Head->next = temp;
		temp->next = NULL;
		printf("插入排序成功\n"); 
	}*/
}

//链表翻转，头删法删除原链表，并保存删除的数据，再用头插法插入新的链表 
void Linklist_Overturn(linklist *Head){
	//判断单链表是否为空 
	if(Linklist_isEmpty(Head)){
		printf("单链表为空\n");
		return ; 
	}
	
	//定义两个指针变量来执行链表的翻转
	//p指针保存头节点后的第一个有数据的节点的地址 
	linklist *p = Head->next; 
	//q指针每次指向删除的节点的地址，后续用于插入 
	linklist *q; 
	//头结点的指针域等于空来初始化头结点
	Head->next = NULL;
	
	//循环让q指针保存p指向的节点的首地址 
	while(NULL != p){
		//q指针保存p指向的结点的地址
		q = p;
		//p指针后移保存下一个结点的地址
		p = p->next; 
		
		//通过头插法将q指向的结点插入到头结点的后面
		q->next = Head->next;
		Head->next = q;
	}
	
	return ;
}



