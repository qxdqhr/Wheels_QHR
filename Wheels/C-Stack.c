#include"C-Stack.h"

Stack* CreateStack()
{
	Stack* pstack = (Stack*)malloc(sizeof(Stack));
	pstack->nNum = 0;
	pstack->pTop = NULL;
	return pstack;
}
Node* CreateNode_Stack(int i)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->nVal = i;
	node->pNext = NULL;
	return node;
}
void PushNode(Stack ** pStack, Node* node)
{
	if (*pStack == NULL)
	{
		printf("ջδ�����봴��һ����ջ\n");
		return;
	}
	else
	{
		if ((*pStack)->nNum == 0)
		{
			(*pStack)->pTop = node;
			(*pStack)->nNum = 1;
			return;
		}
		else
		{
			node->pNext=(*pStack)->pTop;
			(*pStack)->pTop = node;
			(*pStack)->nNum++;
			return;
		}


	}
}
Node* PullTopNode(Stack** pStack)
{
	if (*pStack == NULL)
	{
		printf("ջδ����,�봴��һ����ջ\n");
		return NULL;
	}
	else
	{
		if ((*pStack)->nNum == 0)
		{
			printf("ջ����Ԫ��,������ջ�����Ԫ��\n");
			return NULL;
		}
		else
		{
			Node* pnode;
			pnode = (*pStack)->pTop;
			(*pStack)->pTop = (*pStack)->pTop->pNext;
			(*pStack)->nNum--;
			printf("��ջ�ɹ�,��ջԪ��%d\n",pnode->nVal);
			return pnode;

		}
	}
}
void ClearStack(Stack** pstack)
{
	for (Node* pnode = NULL;\
		(*pstack)->nNum!=0 ; \
		pnode = PullTopNode(pstack), free(pnode), pnode = NULL\
		);
}
void DestroyStack(Stack** pstack)
{
	if ((*pstack)->nNum != 0)
	{
		
		ClearStack(pstack);

	}
	free(*pstack);
	*pstack = NULL;
}
void ArrToStack(Stack** pstack,int *arr,int arrlen)
{
	if (*pstack == NULL)
	{
		printf("ջδ����,�봴��һ����ջ\n");
		return ;
	}
	else
	{
		if(arr==NULL&& arrlen==0)
		{
			printf("��ȷ��Ҫ��ջ��Ԫ�ظ���\n");
			int Num = 0;
			scanf_s("%d", &Num);
			int* arr1 = (int*)malloc(sizeof(int) * Num);
			for (int i = 0; i < Num; i++)
			{
				printf("�������%d��Ԫ��(�±�Ϊ%d)", i + 1, i);
				scanf_s("%d", &(arr1[i]));
				PushNode(pstack, CreateNode_Stack(arr1[i]));
			}
		}
		else
		{
			for (int i = 0; i < arrlen; i++)
			{
				if (arr)
				{
					PushNode(pstack, CreateNode_Stack(arr[i]));
				}
				
			}
		}
	}
}
void Stack_CTest()
{
	Stack* pstack = NULL;
	Node* pnode = NULL;
	pstack = CreateStack();
	int arr[] = { 1,2,3,4,5,6,7 };
	ArrToStack(&pstack, NULL, 0);

	

	//pnode=PullTopNode(&pstack);
	//printf("%d", pnode->nVal);
	//pnode = PullTopNode(&pstack);
	//printf("%d", pnode->nVal);
	//pnode = PullTopNode(&pstack);
	//printf("%d", pnode->nVal);
	//pnode = PullTopNode(&pstack);
	//printf("%d", pnode->nVal);
	//ClearStack(&pstack);
	DestroyStack(&pstack);
	pnode = PullTopNode(&pstack);
	
	return;


}