#include<stdio.h>
#include<stdlib.h>
#include"HuffmanTree.h"
#include"Queue.h"

HuffmanTree Huffman(MinHeap H){
	//���� H->Size ��Ȩֵ�Ѿ�����H->Data[]->Weight��(H->Data��������൱�ڼ���F�� 
	HuffmanTree HT; 
	
	BuildMinHeap(H);		//�Ȱ�Ȩֵ����Ϊ��С�� 
	if( !H || IsEmptyMin(H) ){
		printf("HuffmanTree build error.\n");
//		return NULL;
	}else{
		while( H->Size>1 ){			//�ܹ��� H->Size - 1 �κϲ�����forѭ������ 
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
		//�˳�ѭ������Ȼֻʣһ����
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
