#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int Type;
#define _Undigraph 1
#define _Digraph 2
typedef struct Graph
{
	int nVertex;
	int nEdge;
	int* pMatrix;
	Type Graph_Type;
}Graph;

Graph* CreateGraph();
void PrintGraph(Graph* pGraph);
void DFS(Graph* pGraph, int nBegin);//����ͼ,������ʼ�ڵ�
void DFS_Iteration(Graph* pGraph, int Begin, int* pMark);//ͼ,��ʼ�ڵ�,�������
void Graph_CTest();



