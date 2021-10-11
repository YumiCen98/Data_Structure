#include "hash.h"

int main()
{
	int i = 0, num;
	//11个数据，那么m = n/0.75 = 14， 最大质数为13
	int count[11] = {23, 34, 14, 38, 46, 16, 68, 15, 7, 31, 26};
	
	//创建hash表
	HASH **h = Hash_Create();
	
	printf("原数据："); 
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
	
	printf("请输入要查找的数据>>");
	scanf("%d",&num); 
	if(Hash_SearchTable(h, num)){
		printf("查找到了 %d\n",num);
	}else{
		printf("未找到了 %d\n",num);
	}
	
	return 0;
}
