#include "looplist.h"

int main()
{
	DataType value;
	
	looplist *Head = Looplist_Create();
	
	Looplist_Insert(Head, 1);
	Looplist_Insert(Head, 2);
	Looplist_Insert(Head, 3);
	Looplist_Insert(Head, 4);
	Looplist_Insert(Head, 5);
	Looplist_Traver_Head(Head);
	
	Head = Looplist_DeleteHead(Head);
	Looplist_Traver_NoHead(Head);
	
	Looplist_Delete(Head, 4);
	Looplist_Traver_NoHead(Head);
	
	Joseph(8, 3, 4);
		
	return 0;
}
