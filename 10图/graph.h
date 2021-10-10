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

//1.ͼ�Ĵ����ͱ�ʾ
graph *Graph_Create();

//2.�����ϵ
void Graph_Input(graph *gh);

//3.�����ϵ
void Graph_Output(graph *gh); 

//4.�������������DFS��
void Graph_DFS(graph *gh, int code);

//5.�������������BFS��
void Graph_BFS(graph *gh, int code); 



#endif



