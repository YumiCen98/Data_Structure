#include "graph.h"
#include "linkqueue.h"

int main()
{
	graph *gh = Graph_Create();

	Graph_Input(gh);
	Graph_Output(gh);
	
	printf("�����������:\n"); 
	Graph_DFS(gh, 0);
	
	printf("�����������:\n"); 
	Graph_BFS(gh, 0); 
	
	return 0;
}



