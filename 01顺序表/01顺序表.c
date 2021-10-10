#include <stdio.h>
#include <stdlib.h>

#define N 32

//�����ݵ����ͽ���ȡ����������Ա��е��������ͽ����޸ģ�
//��ߴ������չ��
typedef int DataType;

//����һ���ṹ��
typedef struct{
	DataType data[N];
	int pos;
}seqlist;

//1.����˳��� 
seqlist *Seqlist_Creat(); 

//2.����˳��� 
void Seqlist_Show(seqlist *st); 

//3.�ж�˳����Ƿ�Ϊ�� 
int Seqlist_isFull(seqlist *st); 

//4.�ж�˳����Ƿ�Ϊ��
int Seqlist_isEmpty(seqlist *st); 

//5.����Ԫ��
void Seqlist_Insert(seqlist *st, DataType value);

//6.��λ�ò���
void Seqlist_InsertbyPos(seqlist *st, int pos_insert, DataType value_insert); 

//7.��λ�ò���Ԫ��
DataType Seqlist_SearchbyPos(seqlist *st, int value_pos); 

//8.��Ԫ�ز���λ�� 
int Seqlist_SearchbyData(seqlist *st, DataType value); 

//9.ɾ��ĩβԪ�ز�����ɾ����Ԫ�� 
DataType Seqlist_Delete_End(seqlist *st); 

//10.��λ��ɾ��������ɾ�������� 
DataType Seqlist_DeletebyPos(seqlist *st, int pos_delete); 

//11.���������޸�����
void Seqlist_ChangebyData(seqlist *st, DataType value_data, DataType value_change);

//12.����λ���޸����� 
void Seqlist_ChangebyPos(seqlist *st, int value_pos, DataType value_change);
 
int main()
{
	DataType value_temp;
	int value_pos;
	
	seqlist *st1 = Seqlist_Creat();
	
	Seqlist_Insert(st1, 1);
	Seqlist_Insert(st1, 2);
	Seqlist_Insert(st1, 3);
	Seqlist_Insert(st1, 4);
	Seqlist_Insert(st1, 5);
	Seqlist_Show(st1);
	
	value_temp = Seqlist_Delete_End(st1);
	printf("ɾ����Ԫ��Ϊ��%d\n",value_temp);
	Seqlist_Show(st1);
	
	Seqlist_InsertbyPos(st1, 2, 10);
	Seqlist_Show(st1);
	
	value_temp = Seqlist_DeletebyPos(st1, 2); 
	printf("ɾ����Ԫ��Ϊ��%d\n",value_temp);
	Seqlist_Show(st1);
	
	Seqlist_ChangebyData(st1, -1, 10);
	Seqlist_Show(st1);
	
	Seqlist_ChangebyPos(st1, -1, 100);
	Seqlist_Show(st1);
	
	value_temp = Seqlist_SearchbyPos(st1, -1);
	printf("��λ�ò��ҵ�����Ϊ��%d\n",value_temp);
	value_pos = Seqlist_SearchbyValue(st1, 4);
	printf("�����ݲ��ҵ�λ��Ϊ��%d\n",value_pos);
	
	return 0;
}


//��Ҫ��ÿһ�����ܷ�װ�ɺ��������������������ӷ���
//����һ���յ�˳���
seqlist *Seqlist_Creat(){
	//�ڶ�������ռ�
	seqlist *st = (seqlist *)malloc(sizeof(seqlist));
	//��ʼ��,��ʶ��ǰ˳�����û��Ԫ��
	st->pos = -1;
	printf("˳������ɹ�\n");
	
	//����˳�����׵�ַ
	return st;
}

//����˳��� 
void Seqlist_Show(seqlist *st){
	int i=0;
	for(i=0; i<=st->pos; i++){
		printf("%d ",st->data[i]);
	}
	putchar(10); //���� 
}

//�ж�˳����Ƿ���
//���Ϊ������������1�����򷵻�0
Seqlist_isFull(seqlist *st){
	/* 
	if(st->pos == N-1){
		return 1;
	}else{
		return 0;
	}*/
	return st->pos == N-1 ? 1 : 0;
}

//�ж�˳����Ƿ�Ϊ��
//���Ϊ�շ���1��ʧ�ܷ���0
int Seqlist_isEmpty(seqlist *st){
	return -1 == st->pos ? 1 : 0;
}

//����ĩβԪ��
void Seqlist_Insert(seqlist *st, DataType value){
	//��������֮ǰ���жϵ�ǰ˳����Ƿ�Ϊ��
	if(Seqlist_isFull(st) == 1){
		printf("����ĩβʧ�ܣ�˳�������\n");
		return ;
	}
	//�������һ��Ԫ�صı���pos����
	st->pos++;
	//�����ݲ��뵽posλ�õĵط�
	st->data[st->pos] = value;
	printf("����ĩβ�ɹ�\n");
}

//��λ�ò���
void Seqlist_InsertbyPos(seqlist *st, int pos_insert, DataType value_insert){
	int i;
	
	//�ж�˳����Ƿ�Ϊ�� 
	if(Seqlist_isFull(st)){
		printf("��λ�ò���ʧ�ܣ�˳�������\n");
		return ; //return������ 
	}
	
	//�жϲ����λ���Ƿ����
	if(pos_insert < 0 || pos_insert > st->pos + 1){
		printf("����λ������\n"); 
		return ; //return������ 
	} 
	
	//��������λ����˳���ĩβ��ֱ�Ӳ��� 
	if(pos_insert == st->pos+1){
		st->data[pos_insert] = value_insert;
		st->pos++; 
	}else{
		//��pos_insert֮����������������ƶ� 
		for(i=st->pos; i>=pos_insert; i--){
			st->data[i+1] = st->data[i];
		}
		//����������ݷ���pos_insertλ��
		st->data[pos_insert] = value_insert; //���� 
		st->pos++;
	} 
	printf("��λ�ò���ɹ�\n");
}

//��λ�ò������� 
DataType Seqlist_SearchbyPos(seqlist *st, int value_pos){
	if(value_pos<0 || value_pos>st->pos)
	{
		printf("����λ������\n");
		return (DataType)-1;
	}
	DataType value = st->data[value_pos];
	printf("��λ�ò��ҳɹ�\n");
	
	return value;
}

//�����ݲ���λ�� 
int Seqlist_SearchbyValue(seqlist *st, DataType value){
	int i;
	for(i=0; i<=st->pos; i++){
		if(value == st->data[i]){
			printf("�����ݲ��ҳɹ�\n"); 
			return i;
		}
	}
	printf("��Ԫ��δ�鵽\n");
	return -1;	
}

//ɾ��ĩβԪ�ز�����ɾ����Ԫ�� 
DataType Seqlist_Delete_End(seqlist *st){
	//��ɾ������֮ǰ�ж��Ƿ�Ϊ��
	if(Seqlist_isEmpty(st) == 1){
		printf("ɾ��ĩβʧ�ܣ�˳���Ϊ��\n");
		return (DataType)-1;
	}
	//����ɾ�������� 
	DataType value_temp = st->data[st->pos];
	st->pos--;
	printf("ɾ��ĩβ�ɹ�\n"); 
	
	return value_temp;
}

//��λ��ɾ��������ɾ�������� 
DataType Seqlist_DeletebyPos(seqlist *st, int pos_delete){
	int i;
	
	//�ж�˳����Ƿ�Ϊ�� 
	if(Seqlist_isEmpty(st)){
		printf("��λ��ɾ��ʧ�ܣ�˳���Ϊ��\n");
		return ;
	} 
	
	//�ж�ɾ��λ���Ƿ����
	if(pos_delete < 0 || pos_delete > st->pos + 1){
		printf("ɾ��λ������\n");
		return (DataType)-1; 
	} 
	
	//����ɾ�������� 
	DataType value_temp = st->data[pos_delete]; 
	
	//���ɾ��λ��Ϊĩβ��ֱ��ɾ��
	if(pos_delete == st->pos + 1){
		st->pos--;
	}else{
		//ɾ��pos_deleteλ�õ����ݣ��������������������ǰ�� 
		for(i=pos_delete; i<=st->pos; i++){
			st->data[i] = st->data[i+1];
		}
		st->pos--;
	}
	printf("��λ��ɾ���ɹ�\n");
	
	return value_temp; 
}

//���������޸�����
void Seqlist_ChangebyData(seqlist *st, DataType value_data, DataType value_change){
	//ѭ���Ա�ÿһ�����ݣ�����ҵ�����ĳ��µ�����
	int i;
	int flag = 0;
	for(i=0; i<=st->pos; i++){
		if(value_data == st->data[i]){
			st->data[i] = value_change;
			flag = 1;
		}
	}
	if(0 == flag){
		printf("�������޸�ʧ�ܣ����ݲ�����\n");
		return ; 
	}
	printf("��ֵ�޸ĳɹ�\n");
}

//����λ���޸����� 
void Seqlist_ChangebyPos(seqlist *st, int value_pos, DataType value_change){
	if(value_pos<0 || value_pos>st->pos){
		printf("��λ���޸�ʧ�ܣ��޸�λ������\n");
		return ;
	}else{
		st->data[value_pos] = value_change;
		printf("��λ���޸ĳɹ�\n");
	}
}






