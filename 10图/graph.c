#include "graph.h"
#include "linkqueue.h"

//1.ͼ�Ĵ����ͱ�ʾ
graph *Graph_Create()
{
	graph *gh = (graph *)malloc(sizeof(graph));
	
	int i,j;
	for(i=0; i<N; i++){
		gh->data[i] = (char *)malloc(16);
	}
	
	strcpy(gh->data[0], "V1");
	strcpy(gh->data[1], "V2");
	strcpy(gh->data[2], "V3");
	strcpy(gh->data[3], "V4");
	strcpy(gh->data[4], "V5");
	
	//�����еĹ�ϵ����ʼ��Ϊ0
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			gh->relation[i][j] = 0;
		}
	} 
	printf("ͼ�������\n"); 
	
	return gh;
}

//2.�����ϵ
void Graph_Input(graph *gh)
{
	//������������ڣ���ֵ��ֵΪ1
	int i,j;
	printf("�����ϵ���� (1,2)\n");
	while(scanf("(%d,%d)", &i, &j) == 2){
		getchar();
		gh->relation[i][j] = gh->relation[j][i] = 1;
	}
}

//3.�����ϵ
void Graph_Output(graph *gh)
{
	int i,j;
	printf("	%s	%s	%s	%s	%s\n",gh->data[0], 
		gh->data[1], gh->data[2], gh->data[3], gh->data[4]);
	for(i=0; i<N; i++){
		printf("%s	",gh->data[i]);
		for(j=0; j<N; j++){
			printf("%-5d ",gh->relation[i][j]);
		}
		putchar(10);
	}
}

//���ʱ�� 
int dfs_visited[N] = {0};

//4.�������������DFS��
//��ĳһ������������ȱ���������������Ϊ�Ѿ����ʹ�
//Ȼ�������������ڽӵ�
void Graph_DFS(graph *gh, int code)
{
	//�ȱ���
	printf("%d %s\n", code, gh->data[code]);
	//������������Ϊ�����ʹ�
	dfs_visited[code] = 1; 
	
	//�����������ڽӵ�
	int i;
	for(i=0; i<N; i++){
		//�ж��Ƿ����ڽӵ㲢��û�б����ʹ�
		if((1 == gh->relation[code][i]) && (0 == dfs_visited[i])){
			//�ݹ���õ�ǰ��������������������i���ڽӵ㣬��������
			Graph_DFS(gh, i); 
		}
	}
}

//���ʱ�� 
int bfs_visited[N] = {0};

//5.�������������BFS��
void Graph_BFS(graph *gh, int code)
{
	int n, i;
	
	//����һ������
	linkqueue *lq = Linkqueue_Create();
	
	//����ʼ����ı����Ӳ��ұ��Ϊ�����ʹ�
	Linkqueue_Push(lq, code); 
	bfs_visited[code] = 1;
	
	//ѭ��ִ�г��Ӳ��ж��Ƿ���û�з��ʵ��ڽӵ㣬������ӣ�Ȼ���ٳ����ж�
	while(!Linkqueue_isEmpty(lq)){
		//����һ�����
		n = Linkqueue_Pop(lq);
		printf("%d %s\n", n, gh->data[n]);
		
		//��n��Ŷ�Ӧ��û�б����ʹ����ڽӵ���Ӳ��ұ��Ϊ�����ʹ�
		for(i=0; i<N; i++){
			//�жϱ��Ϊn�Ķ����Ƿ���û�б����ʹ����ڽӵ�
			if((1 == gh->relation[n][i]) && (0 == bfs_visited[i])){
				//��û�б����ʹ����ڽӵ���Ӳ����Ϊ�����ʹ�
				Linkqueue_Push(lq, i);
				bfs_visited[i] = 1;
			}
		}
	}
}



