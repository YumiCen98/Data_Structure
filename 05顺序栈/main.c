#include "seqstack.h"

int main()
{
	DataType value;
	seqstack *sk = Seqstack_Create();
	
	Seqstack_Push(sk, 1);
	Seqstack_Push(sk, 2);
	Seqstack_Push(sk, 3);
	Seqstack_Push(sk, 4);
	Seqstack_Push(sk, 5);
	Seqstack_Show(sk);
	
	value = Seqstack_Pop(sk); 
	printf("µ¯Õ»Êý¾ÝÎª£º%d\n",value);
	Seqstack_Show(sk);
	
	return 0;
}
