#include<stdio.h>
#include<stdlib.h>
#include"BinSearchTree.h"

Position Find(ElementType X,BinTree BST){
	//�ǵݹ��㷨���������ң�:
	if( !BST ) return NULL;				//����������ʧ��
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
//�ݹ��㷨 :(Ч�ʲ��ߣ������ã�	if( !BST ) return NULL;			
//								if( BST->Data==X ){
//									return BST;
//								}else if( BST->Data > X ){
//									return Find(X,BST->Left);
//								}else if( BST->Data < X ){
//									return Find(X,BST->Right);
//								}
}

Position FindMin(BinTree BST){
	//����д��
	if( BST )
		while( BST->Left ) BST = BST->Left;
	return BST;	
}

Position FindMax(BinTree BST){
	//����д��
	if( BST )
		while( BST->Right ) BST = BST->Right;
	return BST;	
} 

BinTree Insert(ElementType X,BinTree BST){
	//���ؼ�������Ĳ�����һ��ԭ�򣬾��ǲ��ƻ�ԭ�нṹֻ��Ҷ�ڵ���� 
	//��������ĵݹ��㷨�ȷǵݹ��㷨����� 
	if( !BST ){
		//���ԭ��Ϊ�գ�����һ����
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
	//�����ѵ㣬�Լ���дһ�顿 :Ϊ��free����� 
	//Ҳ��һ���ݹ��㷨�����Լ����жϵĴ�������Ϊ���������ɾ���Ĳ�����ܸܺ��ӣ� 
	//ɾ���󷵻���ɾ�����ĸ��ڵ� 
	BinTree tmp = NULL;
	if( !BST ) printf("Target TreeNode Cannot be Found.\n");
	else{
		if( BST->Data > X ){
			BST->Left = Delete(X,BST->Left);
		}else if( BST->Data < X ){
			BST->Right = Delete(X,BST->Right);
		}else if( BST->Data==X ){
			if( BST->Left && BST->Right ){	
			//�ý�㣨��ɾ���Ľ�㣩��������㣨������,������������֣�
			//һ.ѡ��������������СԪ�������ý�� 
			//��.ѡ���������������Ԫ�������ý�㡾���á� 
				tmp = FindMax(BST->Left);
				BST->Data = tmp->Data;			//����䡿
				BST->Left = Delete(BST->Data,BST->Left);	//ɾ�������Ľ�� 
			}else{
				tmp = BST;
				if( !BST->Left ){
					//ֻ���ҽ������ӽ��
					BST = BST->Right ; 
				}else if( !BST->Right ){
					//ֻ����������ӽ��
					BST = BST->Left ;
				}
//				free(tmp);
			}
		}
	}
	return BST;
} 

int IsBinSearchTree(BinTree BST){
	int tag = 1;						//Ĭ����
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
