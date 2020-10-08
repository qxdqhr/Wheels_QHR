#pragma once
#include"C-Graph.h"
Graph* CreateGraph();
void PrintGraph(Graph* pGraph);
Graph* CreateGraph()
{
	//ȷ��ͼ�и�������
	Graph* pGraph = NULL;
	int nV = 0;
	int nE = 0;
	
	int type;
	pGraph = (Graph*)malloc(sizeof(Graph));
	if (pGraph == NULL)
	{
		printf("�ڴ����ʧ��\n");
		return pGraph;
	}
	printf("��ȷ��Ҫ������ͼ������:\n����ͼ:1\n����ͼ:2\n");
	while (1)
	{
		scanf_s("%d",&type);
		if (type == 1)
		{
			pGraph->Graph_Type = _Digraph;
			break;
		}
		else if (type == 2)
		{
			pGraph->Graph_Type = _Undigraph;
			break;
		}
		else
		{
			printf("�������,����������\n");
		}

	}


	printf("������ͼ�еĶ������ͱ���,�Կո�ָ�\n");
	scanf_s("%d %d",&nV,&nE);
	pGraph->nVertex = nV;
	pGraph->nEdge = nE;


	//��������
	pGraph->pMatrix = (int*)malloc(sizeof(int)* pGraph->nVertex * pGraph->nVertex);
	if (pGraph->pMatrix == NULL)
	{
		printf("�ڴ����ʧ��\n");
		free(pGraph);
		pGraph = NULL;
		return pGraph;
	}
	memset(pGraph->pMatrix,0, sizeof(int) * pGraph->nVertex * pGraph->nVertex);


	//ʹ��ѭ������ÿһ����
	int V1, V2;//ȷ����������
	for (int i = 0; i < pGraph->nEdge; i++)
	{
		printf("�������%d����",i+1);
		scanf_s("%d %d", &V1, &V2);
		if(pGraph->Graph_Type== _Undigraph )
		{
			//1.�Խ����޽ڵ�
			//2.�����ڷ�Χ��
			//3.��Ӧ����ֵ�ڵ�δ����ֵ
			if (V1 != V2 && \
				V1 <= pGraph->nVertex && \
				V2 <= pGraph->nVertex && \
				pGraph->pMatrix[(V1 - 1) * pGraph->nVertex + (V2 - 1)] == 0\
				)

			{
				pGraph->pMatrix[(V1 - 1) * pGraph->nVertex + (V2 - 1)] = 1;
				pGraph->pMatrix[(V2 - 1) * pGraph->nVertex + (V1 - 1)] = 1;
			}
			else
			{
				printf("�����ڵ㲻�Ϸ�,����������\n");
				i--;
			}
		}
		else if(pGraph->Graph_Type == _Digraph)
		{
			//1.�����ڷ�Χ��
			//2.��Ӧ����ֵ�ڵ�δ����ֵ
			if (V1 <= pGraph->nVertex && \
				V2 <= pGraph->nVertex && \
				pGraph->pMatrix[(V1 - 1) * pGraph->nVertex + (V2 - 1)] == 0\
				)

			{
				pGraph->pMatrix[(V1 - 1) * pGraph->nVertex + (V2 - 1)] = 1;
				pGraph->pMatrix[(V2 - 1) * pGraph->nVertex + (V1 - 1)] = 1;
			}
			else
			{
				printf("�����ڵ㲻�Ϸ�,����������\n");
				i--;
			}
		}		
	}
	return pGraph;
}
void PrintGraph(Graph* pGraph)
{
	if (pGraph == NULL)
	{
		printf("ͼ����ʧ��\n");
		return;
	}
	else
	{
		printf("ͼ�����ɹ�\n");
		for (int i = 0; i < pGraph->nVertex* pGraph->nVertex; i++)
		{// sizeof(pGraph->pMatrix)/sizeof(int)
			
			if (i%pGraph->nVertex==0)
			{
				printf("\n");
			}
			printf("%d\t", pGraph->pMatrix[i]);
		}
		printf("\n");
	}
}


void DFS(Graph* pGraph, int nBegin);//����ͼ,������ʼ�ڵ�
void DFS_Iteration(Graph* pGraph, int Begin, int* pMark);//ͼ,��ʼ�ڵ�,�������
void CreateGraph_CTest();
void DFS(Graph* pGraph, int nBegin)//����ͼ,������ʼ�ڵ�
{
	if (pGraph == NULL)return;
	//����������
	int* pMark = NULL;
	pMark = (int*)malloc(sizeof(int) * pGraph->nVertex);
	if (pMark == NULL)
	{
		printf("�ڴ�����ʧ��\n");
		return;
	}
	memset(pMark, 0, sizeof(int) * pGraph->nVertex);

	//����
	DFS_Iteration(pGraph, nBegin, pMark);
	printf("\n");
	//�ͷ�
	free(pMark);
	pMark = NULL;
	return;
}
void DFS_Iteration(Graph* pGraph, int Begin, int* pMark)//ͼ,��ʼ�ڵ�,�������
{
	//��������(��ӡ)
	printf("%d\t", Begin);
	//���������б��
	pMark[Begin - 1] = 1;
	//����
	int i;
	for (int i = 0; i < pGraph->nVertex; i++)
	{
		//�ҵ��й���δ�������Ľڵ�
		if (pGraph->pMatrix[(Begin - 1) * pGraph->nVertex + i] == 1 && pMark[i] == 0)
		{
			//(�ڵ����-1)*������:��ƫ�ƿ�ʼ�ڵ����-1��
			//+i��ʾ��ƫ��iλ��ʾ��
			DFS_Iteration(pGraph, i + 1, pMark);
			//��ʼ���������е���һ��Ԫ��
		}
	}
}
void CreateGraph_CTest()
{
	Graph* pGraph = NULL;
	pGraph = CreateGraph();
	PrintGraph(pGraph);
	DFS(pGraph, 4);
}