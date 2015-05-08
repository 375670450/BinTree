#include<stdio.h>
#include<stdlib.h>
#include"HuffmanTree.h"
#include"Queue.h"

HuffmanTree Huffman(MinHeap H){
	//假设 H->Size 个权值已经存在H->Data[]->Weight里(H->Data这个数组相当于集合F） 
	HuffmanTree HT; 
	
	BuildMinHeap(H);		//先按权值调整为最小堆 
	if( !H || IsEmptyMin(H) ){
		printf("HuffmanTree build error.\n");
//		return NULL;
	}else{
		while( H->Size>1 ){			//总共做 H->Size - 1 次合并（用for循环？） 
			HuffmanTree HT = (HuffmanTree)malloc(sizeof(struct HuffmanTreeNode));
			HT->Deepth = 0;
			HT->Data = '?';
			HT->Left = DeleteMin(H);
			printf("HT->Left:%c :Deepth=%d ,Weight=%d \n",HT->Left->Data,HT->Left->Deepth,HT->Left->Weight);
			HT->Left->Deepth++;
			HT->Right = DeleteMin(H);
			printf("HT->Right:%c :Deepth=%d ,Weight=%d \n",HT->Right->Data,HT->Right->Deepth,HT->Right->Weight);
			HT->Right->Deepth++;   
			HT->Weight = HT->Left->Weight + HT->Right->Weight;
			H = MinHeapInsert(H,HT);   
		}
		//退出循环，必然只剩一棵树
	}
	HT = DeleteMin(H);
	return HT;
} 

void HuffmanLevelPrint(HuffmanTree HT){
	// print out HuffmanTree by level order
	if( !HT ){
		printf("HuffmanTree Empty. \n");
		return ;
	}
	
	Queue * PtrQ;
	PtrQ = CreateQueue();
	AddQ(PtrQ,HT);
	HuffmanTree temp;
	while( !IsEmptyQ(PtrQ) ){
		temp = DeleteQ(PtrQ);
		printf("%c :Deepth = %d ,Weight = %d \n",temp->Data,temp->Deepth,temp->Weight);
		if(temp->Left) AddQ(PtrQ,temp->Left);
		if(temp->Right) AddQ(PtrQ,temp->Right);
	}
	printf("\n");
	return;
} 
 
 
int WPL(HuffmanTree HT){
	// level Order Traversal
	int length = 0;
	Queue * PtrQ;
	PtrQ = CreateQueue();
	HuffmanTree T = HT;
	AddQ(PtrQ,T);
	while( !IsEmptyQ(PtrQ) ){
		T = DeleteQ(PtrQ);
		if( !T->Left && !T->Right ){
			length+=T->Weight * T->Deepth;
			continue;
		}
		if( T->Left ){
			T->Left->Deepth+=T->Deepth;
			AddQ(PtrQ,T->Left);
		}
		if( T->Right ){
			T->Right->Deepth+=T->Deepth;
			AddQ(PtrQ,T->Right);
		}
	}
	return length;
} 
