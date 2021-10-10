#include "linklist.h"

//多文件编程的意义在于多人 

int main()
{
	DataType value;
	int pos; 
	//创建有头单链表 
	linklist *h1 = Linklist_Create();
	Linklist_Insert_Tail(h1, 1); 
	Linklist_Insert_Tail(h1, 2); 
	Linklist_Insert_Tail(h1, 3); 
	Linklist_Insert_Tail(h1, 5); 
	Linklist_Insert_Tail(h1, 6);
	Linklist_Insert_Tail(h1, 7);
	Linklist_Insert_Tail(h1, 8);
	Linklist_Traver(h1); 
	
	value = Linklist_Delete_Head(h1); 
	printf("头删法删除的数据为：%d \n",value);
	Linklist_Traver(h1); 
	
	value = Linklist_Delete_Tail(h1);
	printf("尾删法删除的数据为：%d \n",value);
	Linklist_Traver(h1); 
	
	Linklist_Change_ByData(h1, 8, 80); 
	Linklist_Traver(h1); 
	
	value = Linklist_Search_ByPos(h1, 2);
	printf("按位置2查找到的数据为：%d \n",value);
	
	pos = Linklist_Search_ByData(h1, 7);
	printf("按数据7查找到的位置为：%d \n",pos);
	
	Linklist_Inseart_ByPos(h1, 6, 9);
	Linklist_Traver(h1); 
	
	Linklist_Sort(h1, 4);
	printf("插入排序后：");
	Linklist_Traver(h1); 
	
	Linklist_Overturn(h1);
	printf("翻转后的链表为：");
	Linklist_Traver(h1); 

	return 0;
}
