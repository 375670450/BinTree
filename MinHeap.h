#ifndef MAXHEAP_H
#define MAXHEAP_H 
#include"AllTypeDefinition.h"

//最大堆的操作集 
MinHeap CreateMinHeap();
Boolean IsFullM(MinHeap H);
MinHeap MinHeapInsert(MinHeap H,MinHeapElem item);		//返回的仍然是原来的H 
Boolean IsEmptyM(MinHeap H);
MinHeapElem DeleteMin(MinHeap H); 		//删除并返回最大的元素 
MinHeap BuildMinHeap(MinHeap H);	//将一个无序堆调整为最大堆 
void MinHeapPrint(MinHeap H);

#endif
