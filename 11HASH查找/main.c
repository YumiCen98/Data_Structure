#include "hash.h"

int main()
{
	int i = 0, num;
	//11�����ݣ���ôm = n/0.75 = 14�� �������Ϊ13
	int count[11] = {23, 34, 14, 38, 46, 16, 68, 15, 7, 31, 26};
	
	//����hash��
	HASH **h = Hash_Create();
	
	printf("ԭ���ݣ�"); 
	for(i=0; i<11; i++){
		printf("%d ",count[i]);
		Hash_InsertTable(h, count[i]);
	}
	putchar(10);
	
	printf("\n********************\n");
	
	for(i=0; i<11; i++){
		Hash_ShowTable(h[i]);
	}
	
	printf("********************\n");
	putchar(10);
	
	printf("������Ҫ���ҵ�����>>");
	scanf("%d",&num); 
	if(Hash_SearchTable(h, num)){
		printf("���ҵ��� %d\n",num);
	}else{
		printf("δ�ҵ��� %d\n",num);
	}
	
	return 0;
}
