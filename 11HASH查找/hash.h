#ifndef __HASH_H_
#define __HASH_H_

#include <stdio.h>
#include <stdlib.h>

//创建13个头节点 
#define N 13
//64位系统指针地址大小为8 
#define ADDR_SIZE 8

typedef struct node{
	int data;
	struct node *next;
}HASH;

//1.创建哈希表(创建了十三个头节点)
HASH ** Hash_Create();

//2.插入数据
int Hash_InsertTable(HASH **h, int value);

//3.打印排好的hash表
int Hash_ShowTable(struct node *head);

//4.查找数据
int Hash_SearchTable(HASH **h, int value); 

#endif
