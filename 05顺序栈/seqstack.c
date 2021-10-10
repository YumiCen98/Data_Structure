#include "seqstack.h"

//1.´´½¨¿ÕµÄË³ĞòÕ»
seqstack *Seqstack_Create()
{
	seqstack *sk = (seqstack *)malloc(sizeof(seqstack));
	sk->pos = -1;
	
	return sk;
}

//2.ÅĞ¶ÏÕ»¿Õ
int Seqstack_isEmpty(seqstack *sk)
{
	return -1 == sk->pos ? 1 : 0;
}

//3.ÅĞ¶ÏÕ»Âú
int Seqstack_isFull(seqstack *sk)
{
	return N-1 == sk->pos ? 1 : 0;
}

//4.µ¯Õ»
DataType Seqstack_Pop(seqstack *sk)
{
	if(Seqstack_isEmpty(sk)){
		printf("Õ»¿Õ\n"); 
		return ;
	}
	DataType value = sk->data[sk->pos];
	sk->pos--;
	printf("µ¯Õ»³É¹¦\n");
	
	return value;
}

//5.ÈëÕ»
void Seqstack_Push(seqstack *sk, DataType value_push)
{
	if(Seqstack_isFull(sk)){
		printf("Õ»Âú\n");
		return ;
	}
	sk->data[++sk->pos] = value_push;
	printf("Ñ¹Õ»³É¹¦\n");
}

//6.´òÓ¡Êı¾İ
void Seqstack_Show(seqstack *sk)
{
	if(Seqstack_isEmpty(sk)){
		printf("Õ»¿Õ\n"); 
		return ;
	}
	int i=0;
	for(i=sk->pos; i>=0; i--){
		printf("pos = %d value = %d\n", i, sk->data[i]);
	}
} 
