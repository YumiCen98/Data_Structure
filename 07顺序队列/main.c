#include "sequeue.h"

int main()
{
	sequeue *sq = Sequeue_Create();
	
	Sequeue_Push(sq, 1);
	Sequeue_Push(sq, 2);
	Sequeue_Push(sq, 3);
	Sequeue_Push(sq, 4);
	Sequeue_Push(sq, 5);
	
	while(!Sequeue_isEmpty(sq)){
		printf("³ö¶Ó£º%d\n",Sequeue_Pop(sq));
	}
	
	return 0;
}
