#include "graph.h"
#include "linkqueue.h"

int main()
{
	graph *gh = Graph_Create();

	Graph_Input(gh);
	Graph_Output(gh);
	
	printf("深度优先搜索:\n"); 
	Graph_DFS(gh, 0);
	
	printf("广度优先搜索:\n"); 
	Graph_BFS(gh, 0); 
	
	return 0;
}



