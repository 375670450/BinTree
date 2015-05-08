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

//【用无序结点建树】 

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include"AllTypeDefinition.h"
#include"Queue.h"
#include"BinTree.h"  


void LevelOrderPrintLeaves(BinTree BT){
	//层序遍历算法
	if( BT==NULL ) return ;				//若是空树则返回 
	
	Queue * PtrQ;
	PtrQ = CreateQueue();
	BinTree T;
//	T = BT;			//写成下面这个形式更标准 
	AddQ(PtrQ,BT);
	while( !IsEmptyQ(PtrQ) ){			//循环条件只写队列非空即可 
		T = DeleteQ(PtrQ);
		if( T->Left==NULL && T->Right==NULL )
			printf("%d ",T->Data);
		if(T->Left)  AddQ(PtrQ,T->Left);		//因为AddQ远比printf要复杂，因此判断条件 
		if(T->Right) AddQ(PtrQ,T->Right);		//应加在AddQ前面 
	}
	printf("\n");								//每次输出完全部数据就换一行
}


//关键：【看懂题目】indices指的是数组的元素下标，意味着输入的数据先以数组的形式存放
//从第一个输入的结点开始依次标为0,1,2,3..（所以没有8）而输入的数字代表其子结点的下标 

void ListLeaves(int Lines){
	int i;
	char left[3],right[3];			//有时输入的数据较杂时可以用字符串存储 
	int Left[Lines];				//下标代表编号 
	int Right[Lines];
	int Mark[Lines];
	
	memset(Mark,0,sizeof(Mark));
	memset(Left,-1,sizeof(Left));
	memset(Right,-1,sizeof(Right));
	
	//Input All the data
	for(i=0;i<Lines;i++){
		scanf("%s %s",left,right);
  		if( *left=='-' ) Left[i] = -1;			//-1表示无结点 
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


