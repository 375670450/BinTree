#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"Queue.h"
#include"Stack.h"
#include"AVLTree.h"
//平衡二叉树定义：任一结点左右子树均为AVL树；且左右子树高度差的绝对值不超过1
//平衡因子定义：Balanced Factor(BF) = Height【Left】 - Height【Right】 (BF = -1,0,1)

//牢记插入元素时如何选择调整方案 

int AVLHeight(AVLTree T){
	if( !T ){
		return 0;
	}else{
		int left,right;
		left = AVLHeight(T->Left);
		right = AVLHeight(T->Right);
		return Max(left,right)+1;
	}
}

AVLTree AVLInsert(ElementType X,AVLTree T){
	//递归算法实现比非递归慢，但是程序可读性强很多，因此AVL插入也一般用递归算法
	//返回的是插入点的父节点 
	//【重难点】判断什么时候选择怎样的调整方法 
	if( !T ){
		//找到了要插入的地方
		T = (AVLTree)malloc(sizeof(AVLNode));		//不用新造一个结点，直接用传来的空结点即可 
		T->Height = 1;
		T->Data = X;
		T->Left = T->Right = NULL;
	}else{										//T->Data == X情况无需特别说明，无任何操作即可 
		if( T->Data > X ){
			T->Left = AVLInsert(X,T->Left);
			if( AVLHeight(T->Left)-AVLHeight(T->Right)==2 ){
				//需要左旋
				if( X < T->Left->Data ){
					// 插入点的数值小于失衡点的左结点数值，
					//暗示着插入点就插在失衡点的左结点的左结点
					//也就是产生了LL型失衡，可以简单地直接用一次左旋即可
					T = SingleLeftRotation(T); 
				}else{
					//需要二次旋转
					T = DoubleLeftRightRotation(T); 
				}
			}
		}else if( T->Data < X ){
			T->Right = AVLInsert(X,T->Right);
			if( AVLHeight(T->Left)-AVLHeight(T->Right)==-2 ){
				//需要右旋
				if( X > T->Right->Data ){
					//解释同上 
					T = SingleRightRotation(T);
				}else{
					T = DoubleRightLeftRotation(T);
				}
			}
		}
	}
	T->Height = Max(AVLHeight(T->Left),AVLHeight(T->Right))+1;		//更新高度专用语句 
	return T;
}

AVLTree SingleLeftRotation(AVLTree A){
	//用A作为根节点的名字与,课本上的附图结点名相符 
	//注意：A必须有一个左子结点B
	//将A与B做左单旋，更新A与B的高度，返回新的根节点B
	//不必保存根节点，因为返回一个新的结点，用原根节点接住即可(T=....)
	AVLTree B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	//记得要更新高度(变动可能比较大) 
	A->Height = Max(AVLHeight(A->Left),AVLHeight(A->Right))+1;		//高度的公式固定这么写
	B->Height = Max(AVLHeight(B->Left),AVLHeight(B->Right))+1; 
	return B;					//代替原来的根节点 
}

AVLTree SingleRightRotation(AVLTree A){
	AVLTree B = A->Right;
	A->Right = B->Left;
	B->Left = A;
	//记得要更新高度(变动可能比较大) 
	A->Height = Max(AVLHeight(A->Left),AVLHeight(A->Right))+1;		//高度的公式固定这么写
	B->Height = Max(AVLHeight(B->Left),AVLHeight(B->Right))+1; 
	//其实B的高度也可写成 B->Height = Max(AVLHeight(B->Left),A->Height); 
	return B;					//代替原来的根节点 
}

AVLTree DoubleLeftRightRotation(AVLTree A){
	//注意：A必须有一个左子结点（B），B必须有一个右子结点C 
	// First Right then Left , converse from the Name	 
	A->Left = SingleRightRotation(A->Left);
	return SingleLeftRotation(A);			//直接返回的是改变了的新的根节点（C） 
}

AVLTree DoubleRightLeftRotation(AVLTree A){
	// First Left then Right
	A->Right = SingleLeftRotation(A->Right);
	return SingleRightRotation(A);
}

void AVLInOrderPrint(AVLTree T){
	Stack * PtrS;
	PtrS = CreateStack();
	while( T || !IsEmptyS(PtrS) ){
		while( T ){
			Push(PtrS,T);
			T = T->Left; 
		}
		if( !IsEmptyS(PtrS) ){
			T = Pop(PtrS);
			printf("%d ",T->Data);
			T = T->Right;
		}
	}
	printf("\n");
	
	return ;
}


