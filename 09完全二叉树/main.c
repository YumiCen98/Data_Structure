#include "bitree.h"

int main()
{
	//bitree *root = Bitree_Create_Full(1, 10);
	bitree *root = Bitree_Create_unFull();
	
	printf("ǰ�������"); 
	Bitree_TraverbyFront(root);
	putch(10);
	
	printf("���������"); 
	Bitree_TraverbyMiddle(root);
	putch(10);
	
	printf("���������"); 
	Bitree_TraverbyBack(root);
	putch(10);

	return 0;
}
