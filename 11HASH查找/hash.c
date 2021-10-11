/**
 * ��ϣ����-���������� 
 * ��n�����в������ݣ�����n����ͨ������С��n�����������ȡ�࣬�����ĸ�����Ϊ�����ĸ����� 
 * ������Ϊ�����׵�ַ����ÿ���������������У�������ȡ���ͷ�巨���뵽��Ӧ�������У�
 * ����ʱֻ��Ҫ���������ȡ�࣬���������ҵ���Ӧ�����ٱ�������������ݡ�����������˲��Ҵ����� 
*/

#include "hash.h"

//1.������ϣ��(������ʮ����ͷ�ڵ�)
//������ά����洢ÿ��������׵�ַ 
HASH **Hash_Create()
{
	//����ʮ����ָ�룬����һ��ָ������
	HASH **h = (HASH **)malloc((sizeof(N * ADDR_SIZE)));
	int i;
	
	//����ʮ����ͷ���
	for(i=0; i<N; i++){
		h[i] = (struct node *)malloc(sizeof(struct node));
		h[i]->next = NULL;
	} 
	printf("��ϣ�����ɹ�\n"); 
	
	return h;
}

//2.��������
int Hash_InsertTable(HASH **h, int value)
{
	//�ҵ�ָ��������
	int  remainder = value % N;
	//ָ��ͷ�ڵ� 
	struct node *p = h[remainder];
	
	//ͷ�巨��������
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = value;
	
	temp->next = p->next;
	p->next = temp;
	
	return 0; 
}

//3.��ӡ�źõ�hash��
int Hash_ShowTable(struct node *head)
{
	int i = 0;
	//����������û�����ݣ�����-��ʾ������ڵ���û������
	if(head->next == NULL){
		puts("##");
		return -1;
	}
	
	//����������ӡ����
	while(head->next != NULL){
		head = head->next;
		printf("%d ", head->data);
	}
	putchar(10);
	
	return 0;
}

//4.��������
int Hash_SearchTable(HASH **h, int value)
{
	//���ݶ�����ȡ�࣬�õ���ֵ
	int remainder = value % N;
	//�ҵ���Ӧ����
	struct node *p = h[remainder];
	
	//�Ա�Ҫ���ҵ�����
	while(p->next != NULL){
		if(value == p->next->data){
			//�ҵ�����1
			return 1;
		}
		p = p->next;
	}
	
	//û���ҵ�
	return 0;
}



