#include "bitree.h"

int main()
{
	//bitree *root = Bitree_Create_Full(1, 10);
	bitree *root = Bitree_Create_unFull();
	
	printf("前序遍历："); 
	Bitree_TraverbyFront(root);
	putch(10);
	
	printf("中序遍历："); 
	Bitree_TraverbyMiddle(root);
	putch(10);
	
	printf("后序遍历："); 
	Bitree_TraverbyBack(root);
	putch(10);

	return 0;
}
