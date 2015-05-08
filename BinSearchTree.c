#include<stdio.h>
#include<stdlib.h>
#include"BinSearchTree.h"

Position Find(ElementType X,BinTree BST){
	//非递归算法（迭代查找）:
	if( !BST ) return NULL;				//空树，查找失败
	BinTree T;
	T = BST;
	while( T ){
		if( T->Data == X){
			return T;
		}else if( T->Data > X ){
			T = T->Left;
		}else if( T->Data < X ){
			T = T->Right;
		}
	}
//递归算法 :(效率不高，不常用）	if( !BST ) return NULL;			
//								if( BST->Data==X ){
//									return BST;
//								}else if( BST->Data > X ){
//									return Find(X,BST->Left);
//								}else if( BST->Data < X ){
//									return Find(X,BST->Right);
//								}
}

Position FindMin(BinTree BST){
	//精简写法
	if( BST )
		while( BST->Left ) BST = BST->Left;
	return BST;	
}

Position FindMax(BinTree BST){
	//精简写法
	if( BST )
		while( BST->Right ) BST = BST->Right;
	return BST;	
} 

BinTree Insert(ElementType X,BinTree BST){
	//【关键】这里的插入有一个原则，就是不破坏原有结构只在叶节点插入 
	//插入操作的递归算法比非递归算法更简洁 
	if( !BST ){
		//如果原树为空，生成一棵树
		BST = (BinTree)malloc(sizeof(BinTree));
		BST->Left = BST->Right = NULL;
		BST->Data = X; 
	}else{
		if( BST->Data > X ){
			BST->Left = Insert(X,BST->Left);
		}else if( BST->Data < X ){
			BST->Right = Insert(X,BST->Right);
		}
	}
	return BST;
}

BinTree Delete(ElementType X,BinTree BST){
	//【重难点，自己再写一遍】 :为何free会出错？ 
	//也是一个递归算法：可以减少判断的次数（因为根据情况，删除的步骤可能很复杂） 
	//删除后返回所删除结点的父节点 
	BinTree tmp = NULL;
	if( !BST ) printf("Target TreeNode Cannot be Found.\n");
	else{
		if( BST->Data > X ){
			BST->Left = Delete(X,BST->Left);
		}else if( BST->Data < X ){
			BST->Right = Delete(X,BST->Right);
		}else if( BST->Data==X ){
			if( BST->Left && BST->Right ){	
			//该结点（被删除的结点）有两个结点（子树）,解决方案有两种：
			//一.选择其右子树中最小元素来填充该结点 
			//二.选择其左子树的最大元素来填充该结点【常用】 
				tmp = FindMax(BST->Left);
				BST->Data = tmp->Data;			//【填充】
				BST->Left = Delete(BST->Data,BST->Left);	//删除被填充的结点 
			}else{
				tmp = BST;
				if( !BST->Left ){
					//只有右结点或无子结点
					BST = BST->Right ; 
				}else if( !BST->Right ){
					//只有左结点或无子结点
					BST = BST->Left ;
				}
//				free(tmp);
			}
		}
	}
	return BST;
} 

int IsBinSearchTree(BinTree BST){
	int tag = 1;						//默认是
	// LevelOrderTraversal
	Queue * PtrQ;
	PtrQ = CreateQueue();
	BinTree T = BST;
	AddQ(PtrQ,T);
	while( !IsEmptyQ(PtrQ) ){
		T = DeleteQ(PtrQ);
		if( T->Left ){
			if( T->Left->Data >= T->Data )	tag = 0;
			AddQ(PtrQ,T->Left);
		}
		if( T->Right ){
			if( T->Right->Data <= T->Data ) tag = 0;
			AddQ(PtrQ,T->Right);
		}
	}
	
	return tag; 
}
