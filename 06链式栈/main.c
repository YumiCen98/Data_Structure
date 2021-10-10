#include "linkstack.h"

//����ƥ��
//�ж�һ����ѧ���ʽ�е������Ƿ�ƥ��
//����ֵΪ1��ʾƥ�䣬����ֵΪ-1��ʾ��ƥ��
int KuohaoPipei(char *str)
{
	DataType ch;
	
	//����һ��ջ 
	linkstack *lk = Linkstack_Create();
	
	//������ʽ���жϵ��ַ���'(',������ջ�������
    //')'����ջһ�����ţ�Ȼ���ж�
	while('\0' != *str){
		if(*str == '('){
			Linkstack_Push(lk, '(');
		}else if(*str == ')'){
			if(Linkstack_isEmpty(lk)){
				return -1;
			}else{
				ch = Linkstack_Pop(lk);
				if(ch != '('){
					return -1;
				}
			}
		}
		str++;
	}
	
	if(Linkstack_isEmpty(lk)){
		return 1;
	}else{
		return -1;
	}
}

int main()
{
	DataType value; 
	int judge;
//	linkstack *lk = Linkstack_Create();
//	
//	Linkstack_Push(lk, 1);
//	Linkstack_Push(lk, 2);
//	Linkstack_Push(lk, 3);
//	Linkstack_Push(lk, 4);
//	Linkstack_Push(lk, 5);
//	Linkstack_Show(lk);
//	
//	value = Linkstack_Pop(lk);
//	Linkstack_Show(lk);

	char str[32] = {0};
	printf("�������ű��ʽ��");
	scanf("%s",str);
	judge = KuohaoPipei(str);
	if(1 == judge){
		printf("ƥ��ɹ�\n");
	}else{
		printf("ƥ��ʧ��\n");
	}
	
	return 0;
}
