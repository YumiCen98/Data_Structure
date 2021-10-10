#ifndef __GRAPH_H_
#define __GRAPH_H_

#define N 5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* GraphDataType;

typedef struct{
	GraphDataType data[N];
	int relation[N][N];
}graph;

//1.图的创建和表示
graph *Graph_Create();

//2.输入关系
void Graph_Input(graph *gh);

//3.输出关系
void Graph_Output(graph *gh); 

//4.深度优先搜索（DFS）
void Graph_DFS(graph *gh, int code);

//5.广度优先搜索（BFS）
void Graph_BFS(graph *gh, int code); 



#endif



