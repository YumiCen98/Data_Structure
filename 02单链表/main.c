#include "linklist.h"

//���ļ���̵��������ڶ��� 

int main()
{
	DataType value;
	int pos; 
	//������ͷ������ 
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
	printf("ͷɾ��ɾ��������Ϊ��%d \n",value);
	Linklist_Traver(h1); 
	
	value = Linklist_Delete_Tail(h1);
	printf("βɾ��ɾ��������Ϊ��%d \n",value);
	Linklist_Traver(h1); 
	
	Linklist_Change_ByData(h1, 8, 80); 
	Linklist_Traver(h1); 
	
	value = Linklist_Search_ByPos(h1, 2);
	printf("��λ��2���ҵ�������Ϊ��%d \n",value);
	
	pos = Linklist_Search_ByData(h1, 7);
	printf("������7���ҵ���λ��Ϊ��%d \n",pos);
	
	Linklist_Inseart_ByPos(h1, 6, 9);
	Linklist_Traver(h1); 
	
	Linklist_Sort(h1, 4);
	printf("���������");
	Linklist_Traver(h1); 
	
	Linklist_Overturn(h1);
	printf("��ת�������Ϊ��");
	Linklist_Traver(h1); 

	return 0;
}
