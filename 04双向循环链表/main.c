#include "doublelist.h"

int main()
{
	DataType value;
	doublelist *Head = Doublelist_Create();
	
	Doublelist_Insert(Head, 1);
	Doublelist_Insert(Head, 2);
	Doublelist_Insert(Head, 3);
	Doublelist_Insert(Head, 4);
	Doublelist_Insert(Head, 5);
	Doublelist_Traver(Head);
	
	Doublelist_Delete(Head, 5);
	Doublelist_Traver(Head);
	
	value = Doublelist_DeletefromHead(Head);
	printf("ɾ������Ϊ��%d\n",value);
	Doublelist_Traver(Head);
	
	return 0;
} 
