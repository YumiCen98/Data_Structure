#include <stdio.h>
#include <stdlib.h>

#define N 32

//对数据的类型进行取别名，方便对表中的数据类型进行修改，
//提高代码的拓展性
typedef int DataType;

//定义一个结构体
typedef struct{
	DataType data[N];
	int pos;
}seqlist;

//1.创建顺序表 
seqlist *Seqlist_Creat(); 

//2.遍历顺序表 
void Seqlist_Show(seqlist *st); 

//3.判断顺序表是否为满 
int Seqlist_isFull(seqlist *st); 

//4.判断顺序表是否为空
int Seqlist_isEmpty(seqlist *st); 

//5.插入元素
void Seqlist_Insert(seqlist *st, DataType value);

//6.按位置插入
void Seqlist_InsertbyPos(seqlist *st, int pos_insert, DataType value_insert); 

//7.按位置查找元素
DataType Seqlist_SearchbyPos(seqlist *st, int value_pos); 

//8.按元素查找位置 
int Seqlist_SearchbyData(seqlist *st, DataType value); 

//9.删除末尾元素并返回删除的元素 
DataType Seqlist_Delete_End(seqlist *st); 

//10.按位置删除并返回删除的数据 
DataType Seqlist_DeletebyPos(seqlist *st, int pos_delete); 

//11.按照数据修改数据
void Seqlist_ChangebyData(seqlist *st, DataType value_data, DataType value_change);

//12.按照位置修改数据 
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
	printf("删除的元素为：%d\n",value_temp);
	Seqlist_Show(st1);
	
	Seqlist_InsertbyPos(st1, 2, 10);
	Seqlist_Show(st1);
	
	value_temp = Seqlist_DeletebyPos(st1, 2); 
	printf("删除的元素为：%d\n",value_temp);
	Seqlist_Show(st1);
	
	Seqlist_ChangebyData(st1, -1, 10);
	Seqlist_Show(st1);
	
	Seqlist_ChangebyPos(st1, -1, 100);
	Seqlist_Show(st1);
	
	value_temp = Seqlist_SearchbyPos(st1, -1);
	printf("按位置查找到数据为：%d\n",value_temp);
	value_pos = Seqlist_SearchbyValue(st1, 4);
	printf("按数据查找到位置为：%d\n",value_pos);
	
	return 0;
}


//需要将每一个功能封装成函数，这样调用起来更加方便
//创建一个空的顺序表
seqlist *Seqlist_Creat(){
	//在堆区申请空间
	seqlist *st = (seqlist *)malloc(sizeof(seqlist));
	//初始化,标识当前顺序表中没有元素
	st->pos = -1;
	printf("顺序表创建成功\n");
	
	//返回顺序表的首地址
	return st;
}

//遍历顺序表 
void Seqlist_Show(seqlist *st){
	int i=0;
	for(i=0; i<=st->pos; i++){
		printf("%d ",st->data[i]);
	}
	putchar(10); //换行 
}

//判断顺序表是否满
//如果为满，函数返回1，否则返回0
Seqlist_isFull(seqlist *st){
	/* 
	if(st->pos == N-1){
		return 1;
	}else{
		return 0;
	}*/
	return st->pos == N-1 ? 1 : 0;
}

//判断顺序表是否为空
//如果为空返回1，失败返回0
int Seqlist_isEmpty(seqlist *st){
	return -1 == st->pos ? 1 : 0;
}

//插入末尾元素
void Seqlist_Insert(seqlist *st, DataType value){
	//插入数据之前先判断当前顺序表是否为满
	if(Seqlist_isFull(st) == 1){
		printf("插入末尾失败，顺序表已满\n");
		return ;
	}
	//保存最后一个元素的变量pos自增
	st->pos++;
	//将数据插入到pos位置的地方
	st->data[st->pos] = value;
	printf("插入末尾成功\n");
}

//按位置插入
void Seqlist_InsertbyPos(seqlist *st, int pos_insert, DataType value_insert){
	int i;
	
	//判断顺序表是否为满 
	if(Seqlist_isFull(st)){
		printf("按位置插入失败，顺序表已满\n");
		return ; //return不能少 
	}
	
	//判断插入的位置是否合适
	if(pos_insert < 0 || pos_insert > st->pos + 1){
		printf("插入位置有误\n"); 
		return ; //return不能少 
	} 
	
	//如果插入的位置是顺序表末尾则直接插入 
	if(pos_insert == st->pos+1){
		st->data[pos_insert] = value_insert;
		st->pos++; 
	}else{
		//将pos_insert之后的数据依次往后移动 
		for(i=st->pos; i>=pos_insert; i--){
			st->data[i+1] = st->data[i];
		}
		//将插入的数据放在pos_insert位置
		st->data[pos_insert] = value_insert; //插入 
		st->pos++;
	} 
	printf("按位置插入成功\n");
}

//按位置查找数据 
DataType Seqlist_SearchbyPos(seqlist *st, int value_pos){
	if(value_pos<0 || value_pos>st->pos)
	{
		printf("查找位置有误\n");
		return (DataType)-1;
	}
	DataType value = st->data[value_pos];
	printf("按位置查找成功\n");
	
	return value;
}

//按数据查找位置 
int Seqlist_SearchbyValue(seqlist *st, DataType value){
	int i;
	for(i=0; i<=st->pos; i++){
		if(value == st->data[i]){
			printf("按数据查找成功\n"); 
			return i;
		}
	}
	printf("按元素未查到\n");
	return -1;	
}

//删除末尾元素并返回删除的元素 
DataType Seqlist_Delete_End(seqlist *st){
	//在删除数据之前判断是否为空
	if(Seqlist_isEmpty(st) == 1){
		printf("删除末尾失败，顺序表为空\n");
		return (DataType)-1;
	}
	//保存删除的数据 
	DataType value_temp = st->data[st->pos];
	st->pos--;
	printf("删除末尾成功\n"); 
	
	return value_temp;
}

//按位置删除并返回删除的数据 
DataType Seqlist_DeletebyPos(seqlist *st, int pos_delete){
	int i;
	
	//判断顺序表是否为空 
	if(Seqlist_isEmpty(st)){
		printf("按位置删除失败，顺序表为空\n");
		return ;
	} 
	
	//判断删除位置是否合适
	if(pos_delete < 0 || pos_delete > st->pos + 1){
		printf("删除位置有误\n");
		return (DataType)-1; 
	} 
	
	//保存删除的数据 
	DataType value_temp = st->data[pos_delete]; 
	
	//如果删除位置为末尾则直接删除
	if(pos_delete == st->pos + 1){
		st->pos--;
	}else{
		//删除pos_delete位置的数据，并将后面的数据依次往前移 
		for(i=pos_delete; i<=st->pos; i++){
			st->data[i] = st->data[i+1];
		}
		st->pos--;
	}
	printf("按位置删除成功\n");
	
	return value_temp; 
}

//按照数据修改数据
void Seqlist_ChangebyData(seqlist *st, DataType value_data, DataType value_change){
	//循环对比每一个数据，如果找到将其改成新的数据
	int i;
	int flag = 0;
	for(i=0; i<=st->pos; i++){
		if(value_data == st->data[i]){
			st->data[i] = value_change;
			flag = 1;
		}
	}
	if(0 == flag){
		printf("按数据修改失败，数据不存在\n");
		return ; 
	}
	printf("按值修改成功\n");
}

//按照位置修改数据 
void Seqlist_ChangebyPos(seqlist *st, int value_pos, DataType value_change){
	if(value_pos<0 || value_pos>st->pos){
		printf("按位置修改失败，修改位置有误\n");
		return ;
	}else{
		st->data[value_pos] = value_change;
		printf("按位置修改成功\n");
	}
}






