//Given a tree, you are supposed to list all the leaves in the order of top down,
// and left to right.
//
//Input Specification:
//
//Each input file contains one test case. For each case, the first line gives a
// positive integer N (<=10) which is the total number of nodes in the tree -- and 
// hence the nodes are numbered from 0 to N-1. Then N lines follow, each corresponds
//  to a node, and gives the indices of the left and right children of the node. 
//  If the child does not exist, a "-" will be put at the position. Any pair of 
//  children are separated by a space.
//
//Output Specification:
//
//For each test case, print in one line all the leaves' indices in the order of top down,
// and left to right. There must be exactly one space between any adjacent numbers, 
// and no extra space at the end of the line.
//
//Sample Input:
//8
//1 -
//- -
//0 -
//2 7
//- -
//- -
//5 -
//4 6
//Sample Output:
//4 1 5

//���������㽨���� 

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include"AllTypeDefinition.h"
#include"Queue.h"
#include"BinTree.h"  


void LevelOrderPrintLeaves(BinTree BT){
	//��������㷨
	if( BT==NULL ) return ;				//���ǿ����򷵻� 
	
	Queue * PtrQ;
	PtrQ = CreateQueue();
	BinTree T;
//	T = BT;			//д�����������ʽ����׼ 
	AddQ(PtrQ,BT);
	while( !IsEmptyQ(PtrQ) ){			//ѭ������ֻд���зǿռ��� 
		T = DeleteQ(PtrQ);
		if( T->Left==NULL && T->Right==NULL )
			printf("%d ",T->Data);
		if(T->Left)  AddQ(PtrQ,T->Left);		//��ΪAddQԶ��printfҪ���ӣ�����ж����� 
		if(T->Right) AddQ(PtrQ,T->Right);		//Ӧ����AddQǰ�� 
	}
	printf("\n");								//ÿ�������ȫ�����ݾͻ�һ��
}


//�ؼ�����������Ŀ��indicesָ���������Ԫ���±꣬��ζ����������������������ʽ���
//�ӵ�һ������Ľ�㿪ʼ���α�Ϊ0,1,2,3..������û��8������������ִ������ӽ����±� 

void ListLeaves(int Lines){
	int i;
	char left[3],right[3];			//��ʱ��������ݽ���ʱ�������ַ����洢 
	int Left[Lines];				//�±������ 
	int Right[Lines];
	int Mark[Lines];
	
	memset(Mark,0,sizeof(Mark));
	memset(Left,-1,sizeof(Left));
	memset(Right,-1,sizeof(Right));
	
	//Input All the data
	for(i=0;i<Lines;i++){
		scanf("%s %s",left,right);
  		if( *left=='-' ) Left[i] = -1;			//-1��ʾ�޽�� 
			else{
				 Left[i] = atoi(left);
				 Mark[(Left[i])] = 1;
		 	}
		if( *right=='-' ) Right[i] = -1;
			else{
				 Right[i] = atoi(right);
				 Mark[(Right[i])] = 1;
			}
	}

	//Find the Root
	for(i=0;i<Lines;i++){
		if( Mark[i]==0 ) break;
	}
	int Root = i;
	
	//Build up the BinTree
	BinTree BT = CreateTreeNode(Root);
	BinTree T = BT;
//	left = Left[Root];
//	right = Right[Root];
	Queue * PtrQ = CreateQueue();
	AddQ(PtrQ,T);
	while( !IsEmptyQ(PtrQ) ){					
		T = DeleteQ(PtrQ);
		if( Left[T->Data]!=-1 ){
			T->Left = CreateTreeNode(Left[T->Data]);
			AddQ(PtrQ,T->Left);
		}
		else
			T->Left = NULL;
		if( Right[T->Data]!=-1 ){
			T->Right = CreateTreeNode(Right[T->Data]);
			AddQ(PtrQ,T->Right);
		}
		else
			T->Right = NULL;
	}
	
	//LevelOrderPrint the leaves
	LevelOrderPrintLeaves(BT); 
} 


