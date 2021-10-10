#include "linkqueue.h"

int main()
{
	DataType value;
	linkqueue *lq = Linkqueue_Create();
	
	Linkqueue_Push(lq, 1);
	Linkqueue_Push(lq, 2);
	Linkqueue_Push(lq, 3);
	Linkqueue_Push(lq, 4);
	Linkqueue_Push(lq, 5);
	
	Linkqueue_Pop(lq);
	Linkqueue_Pop(lq);
	Linkqueue_Pop(lq);
	Linkqueue_Pop(lq);
	Linkqueue_Pop(lq);

	return 0;
}


