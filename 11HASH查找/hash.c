/**
 * 哈希查找-除留余数法 
 * 从n个数中查找数据，将这n个数通过除以小于n的最大质数来取余，余数的个数作为链表表的个数， 
 * 余数作为链表首地址，将每个余数存入数组中，所有数取余后头插法插入到对应的链表中，
 * 查找时只需要对这个质数取余，根据余数找到对应链表，再遍历链表查找数据。这样便减少了查找次数。 
*/

#include "hash.h"

//1.创建哈希表(创建了十三个头节点)
//创建二维数组存储每个链表的首地址 
HASH **Hash_Create()
{
	//申请十三个指针，创建一个指针数组
	HASH **h = (HASH **)malloc((sizeof(N * ADDR_SIZE)));
	int i;
	
	//创建十三个头结点
	for(i=0; i<N; i++){
		h[i] = (struct node *)malloc(sizeof(struct node));
		h[i]->next = NULL;
	} 
	printf("哈希表创建成功\n"); 
	
	return h;
}

//2.插入数据
int Hash_InsertTable(HASH **h, int value)
{
	//找到指定的链表
	int  remainder = value % N;
	//指向头节点 
	struct node *p = h[remainder];
	
	//头插法插入数据
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = value;
	
	temp->next = p->next;
	p->next = temp;
	
	return 0; 
}

//3.打印排好的hash表
int Hash_ShowTable(struct node *head)
{
	int i = 0;
	//如果链表后面没有数据，则用-表示链表存在但是没有数据
	if(head->next == NULL){
		puts("##");
		return -1;
	}
	
	//遍历链表，打印数据
	while(head->next != NULL){
		head = head->next;
		printf("%d ", head->data);
	}
	putchar(10);
	
	return 0;
}

//4.查找数据
int Hash_SearchTable(HASH **h, int value)
{
	//数据对质数取余，得到键值
	int remainder = value % N;
	//找到对应链表
	struct node *p = h[remainder];
	
	//对比要查找的数据
	while(p->next != NULL){
		if(value == p->next->data){
			//找到返回1
			return 1;
		}
		p = p->next;
	}
	
	//没有找到
	return 0;
}



