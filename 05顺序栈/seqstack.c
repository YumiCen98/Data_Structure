#include "seqstack.h"

//1.�����յ�˳��ջ
seqstack *Seqstack_Create()
{
	seqstack *sk = (seqstack *)malloc(sizeof(seqstack));
	sk->pos = -1;
	
	return sk;
}

//2.�ж�ջ��
int Seqstack_isEmpty(seqstack *sk)
{
	return -1 == sk->pos ? 1 : 0;
}

//3.�ж�ջ��
int Seqstack_isFull(seqstack *sk)
{
	return N-1 == sk->pos ? 1 : 0;
}

//4.��ջ
DataType Seqstack_Pop(seqstack *sk)
{
	if(Seqstack_isEmpty(sk)){
		printf("ջ��\n"); 
		return ;
	}
	DataType value = sk->data[sk->pos];
	sk->pos--;
	printf("��ջ�ɹ�\n");
	
	return value;
}

//5.��ջ
void Seqstack_Push(seqstack *sk, DataType value_push)
{
	if(Seqstack_isFull(sk)){
		printf("ջ��\n");
		return ;
	}
	sk->data[++sk->pos] = value_push;
	printf("ѹջ�ɹ�\n");
}

//6.��ӡ����
void Seqstack_Show(seqstack *sk)
{
	if(Seqstack_isEmpty(sk)){
		printf("ջ��\n"); 
		return ;
	}
	int i=0;
	for(i=sk->pos; i>=0; i--){
		printf("pos = %d value = %d\n", i, sk->data[i]);
	}
} 
