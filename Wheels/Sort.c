#include"C-MergeSort.c"
#include"Sort.h"
void Merge(int* arr, int nLow, int nHigh)
{
	int nBegin1 = 0;
	int nBegin2 = 0;
	int nEnd1 = 0;
	int nEnd2 = 0;

	nBegin1 = nLow;
	nEnd1 = nLow + (nHigh - nLow) / 2;
	nBegin2 = nEnd1 + 1;
	nEnd2 = nHigh;

	int* pTemp = NULL;
	pTemp = (int*)malloc(sizeof(int) * (nHigh - nLow + 1));
	//�ڶ�������Ķ��������ԭ��:
	//���ڹ涨��������ĳ���
	//ע��:����������ڴ���Ҫ�ͷ�
	int i = 0;
	while (nBegin1 <= nEnd1 && nBegin2 <= nEnd2)
	{
		if (arr[nBegin1] < arr[nBegin2])//��벿�����Ұ벿�ֽ��бȽ�
		{
			pTemp[i] = arr[nBegin1];//��С��Ԫ��ˢ�������������
			i++;//��������������
			nBegin1++;//��벿��������
		}
		else
		{
			pTemp[i] = arr[nBegin2];//��С��Ԫ��ˢ�������������
			i++;//��������������
			nBegin2++;//�Ұ벿��������
		}
	}
	//�������ĳһ������ʣ��Ԫ��,ȫ���������������
	while (nBegin1 <= nEnd1)
	{
		pTemp[i] = arr[nBegin1];//��С��Ԫ��ˢ�������������
		i++;//��������������
		nBegin1++;//ʣ�ಿ��������
	}
	while (nBegin2 <= nEnd2)
	{
		pTemp[i] = arr[nBegin2];//��С��Ԫ��ˢ�������������
		i++;//��������������
		nBegin2++;//ʣ�ಿ��������
	}
	//����������������Ԫ�ظ���ԭ������
	for (int i = 0; i < nHigh - nLow + 1; i++)
	{
		arr[nLow+i] = pTemp[i];//nLow+i��Ҫ
	}
	//�ͷŶ�������
	free(pTemp);
	pTemp = NULL;
}
void MergeSort(int* arr, int nLow, int nHigh)
{
	if (arr == NULL || nLow >= nHigh) return;
	int nMid = nLow + (nHigh - nLow) / 2;

	MergeSort(arr, nLow, nMid);
	MergeSort(arr, nMid+1, nHigh);

	Merge(arr, nLow, nHigh);
}

void PrintArr(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n");
	return;
}
void Sort_test()
{
	int arr[] = { 2,6,3,7,5,9,0,1 };
	MergeSort(arr,0,7);
	PrintArr(arr, 8);
	return ;

}