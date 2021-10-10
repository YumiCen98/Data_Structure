#include "graph.h"
#include "linkqueue.h"

//1.图的创建和表示
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
	
	//将所有的关系都初始化为0
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			gh->relation[i][j] = 0;
		}
	} 
	printf("图创建完毕\n"); 
	
	return gh;
}

//2.输入关系
void Graph_Input(graph *gh)
{
	//如果两个点相邻，则将值赋值为1
	int i,j;
	printf("输入关系，如 (1,2)\n");
	while(scanf("(%d,%d)", &i, &j) == 2){
		getchar();
		gh->relation[i][j] = gh->relation[j][i] = 1;
	}
}

//3.输出关系
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

//访问标记 
int dfs_visited[N] = {0};

//4.深度优先搜索（DFS）
//从某一个顶点出发，先遍历它，将其设置为已经访问过
//然后找这个顶点的邻接点
void Graph_DFS(graph *gh, int code)
{
	//先遍历
	printf("%d %s\n", code, gh->data[code]);
	//将整个顶点标记为被访问过
	dfs_visited[code] = 1; 
	
	//找这个顶点的邻接点
	int i;
	for(i=0; i<N; i++){
		//判断是否是邻接点并且没有被访问过
		if((1 == gh->relation[code][i]) && (0 == dfs_visited[i])){
			//递归调用当前函数继续找满足条件的i的邻接点，依次类推
			Graph_DFS(gh, i); 
		}
	}
}

//访问标记 
int bfs_visited[N] = {0};

//5.广度优先搜索（BFS）
void Graph_BFS(graph *gh, int code)
{
	int n, i;
	
	//创建一个队列
	linkqueue *lq = Linkqueue_Create();
	
	//将初始顶点的编号入队并且标记为被访问过
	Linkqueue_Push(lq, code); 
	bfs_visited[code] = 1;
	
	//循环执行出队并判断是否有没有访问的邻接点，将其入队，然后再出队判断
	while(!Linkqueue_isEmpty(lq)){
		//出队一个编号
		n = Linkqueue_Pop(lq);
		printf("%d %s\n", n, gh->data[n]);
		
		//将n编号对应的没有被访问过的邻接点入队并且标记为被访问过
		for(i=0; i<N; i++){
			//判断编号为n的顶点是否有没有被访问过的邻接点
			if((1 == gh->relation[n][i]) && (0 == bfs_visited[i])){
				//将没有被访问过的邻接点入队并标记为被访问过
				Linkqueue_Push(lq, i);
				bfs_visited[i] = 1;
			}
		}
	}
}



