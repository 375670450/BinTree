#ifndef MAXHEAP_H
#define MAXHEAP_H 
#include"AllTypeDefinition.h"

//���ѵĲ����� 
MinHeap CreateMinHeap();
Boolean IsFullM(MinHeap H);
MinHeap MinHeapInsert(MinHeap H,MinHeapElem item);		//���ص���Ȼ��ԭ����H 
Boolean IsEmptyM(MinHeap H);
MinHeapElem DeleteMin(MinHeap H); 		//ɾ������������Ԫ�� 
MinHeap BuildMinHeap(MinHeap H);	//��һ������ѵ���Ϊ���� 
void MinHeapPrint(MinHeap H);

#endif
