#include "looplist.h"

//1.创建一个空的单向循环链表 
looplist *Looplist_Create(){
	looplist *Head = (looplist *)malloc(sizeof(looplist));
	Head->next = Head;
	
	return Head;
}

//2.插入数据
void Looplist_Insert(looplist *Head, DataType value_insert){
	looplist *temp = (looplist *)malloc(sizeof(looplist));
	temp->data = value_insert;
	temp->next = NULL;
	
	//遍历到末尾就是尾插，不遍历就是头插 
	/*
	looplist *p = Head;
	while(p != Head->next){
		Head = Head->next;
	}*/
	
	temp->next = Head->next;
	Head->next = temp;
	
	printf("插入成功\n"); 
}

//3.含头节点打印数据
void Looplist_Traver_Head(looplist *Head){
	looplist *p = Head;
	while(p != Head->next){
		Head = Head->next;
		printf("%d ",Head->data);
	}
	putch(10);
}

//4.删除头节点，需要返回新的头(首地址) 
looplist *Looplist_DeleteHead(looplist *Head){
	looplist *p = Head;
	while(p != Head->next){
		Head = Head->next;
	}
	Head->next = p->next;
	free(p);
	p = NULL;
	printf("删除头节点成功\n");
	
	return Head->next;
}

//5.删除数据，第一个有数据的头节点不能删除 
void Looplist_Delete(looplist *Head, DataType value_delete){
	looplist *p = Head;
	while(p != Head->next){
		if(value_delete == Head->next->data){
			Head->next = Head->next->next;
			printf("删除数据成功\n");
			return ;
		}
		Head = Head->next;
	} 
	printf("没有找到要删除的数据\n");
}

//6.删除头节点后打印数据 
void Looplist_Traver_NoHead(looplist *Head){
	looplist *p = Head;
	while(p != Head->next){
		//没有空白的头节点了，所以需要先打印头节点 
		printf("%d ",Head->data);
		Head = Head->next;
	} 
	printf("%d ",Head->data);
	putch(10);
}

//约瑟夫问题
void Joseph(int n, int k, int m){
	//创建一个单向循环链表
	looplist *Head = Looplist_Create();
	
	int i;
	looplist *temp;
	
	//插入数据 
	for(i = n; i >0; i--){
		Looplist_Insert(Head, i);
	}
	printf("约瑟夫环创建完毕\n");
	//删除头节点 
	Head = Looplist_DeleteHead(Head);
	Looplist_Traver_NoHead(Head);
	
	//定位到编号为k的数据 
	for(i = 1; i<k; i++){
		Head = Head->next;
	}
	//printf("k = %d\n",Head->data);
	
	//循环删除数到m的那个结点
	//循环结束的条件是只剩下最后一个结点
	while(Head != Head->next){
		//为了删除指定的结点，所以h指针保存数到m-1的结点
		for(i = 1; i<m-1; i++){
			Head = Head->next;
		}
		//printf("m-1 = %d\n",Head->data);
		
		//删除h后面的结点
		temp = Head->next;
		Head->next = temp->next;
		
		printf("%d ",temp->data);
		
		free(temp);
		temp = NULL;
		
		//从下一个结点继续开始数数
		Head = Head->next; 
	} 
	
	printf("%d\n",Head->data);
	free(Head);
	Head = NULL;
	
	return ;
}


