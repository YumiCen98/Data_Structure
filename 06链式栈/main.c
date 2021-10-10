#include "linkstack.h"

//括号匹配
//判断一个数学表达式中的括号是否匹配
//返回值为1表示匹配，返回值为-1表示不匹配
int KuohaoPipei(char *str)
{
	DataType ch;
	
	//创建一个栈 
	linkstack *lk = Linkstack_Create();
	
	//如果表达式中判断的字符是'(',将其入栈，如果是
    //')'，出栈一个括号，然后判断
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
	printf("输入括号表达式：");
	scanf("%s",str);
	judge = KuohaoPipei(str);
	if(1 == judge){
		printf("匹配成功\n");
	}else{
		printf("匹配失败\n");
	}
	
	return 0;
}
