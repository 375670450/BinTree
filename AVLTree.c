#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"Queue.h"
#include"Stack.h"
#include"AVLTree.h"
//ƽ����������壺��һ�������������ΪAVL���������������߶Ȳ�ľ���ֵ������1
//ƽ�����Ӷ��壺Balanced Factor(BF) = Height��Left�� - Height��Right�� (BF = -1,0,1)

//�μǲ���Ԫ��ʱ���ѡ��������� 

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
	//�ݹ��㷨ʵ�ֱȷǵݹ��������ǳ���ɶ���ǿ�ܶ࣬���AVL����Ҳһ���õݹ��㷨
	//���ص��ǲ����ĸ��ڵ� 
	//�����ѵ㡿�ж�ʲôʱ��ѡ�������ĵ������� 
	if( !T ){
		//�ҵ���Ҫ����ĵط�
		T = (AVLTree)malloc(sizeof(AVLNode));		//��������һ����㣬ֱ���ô����Ŀս�㼴�� 
		T->Height = 1;
		T->Data = X;
		T->Left = T->Right = NULL;
	}else{										//T->Data == X��������ر�˵�������κβ������� 
		if( T->Data > X ){
			T->Left = AVLInsert(X,T->Left);
			if( AVLHeight(T->Left)-AVLHeight(T->Right)==2 ){
				//��Ҫ����
				if( X < T->Left->Data ){
					// ��������ֵС��ʧ����������ֵ��
					//��ʾ�Ų����Ͳ���ʧ�������������
					//Ҳ���ǲ�����LL��ʧ�⣬���Լ򵥵�ֱ����һ����������
					T = SingleLeftRotation(T); 
				}else{
					//��Ҫ������ת
					T = DoubleLeftRightRotation(T); 
				}
			}
		}else if( T->Data < X ){
			T->Right = AVLInsert(X,T->Right);
			if( AVLHeight(T->Left)-AVLHeight(T->Right)==-2 ){
				//��Ҫ����
				if( X > T->Right->Data ){
					//����ͬ�� 
					T = SingleRightRotation(T);
				}else{
					T = DoubleRightLeftRotation(T);
				}
			}
		}
	}
	T->Height = Max(AVLHeight(T->Left),AVLHeight(T->Right))+1;		//���¸߶�ר����� 
	return T;
}

AVLTree SingleLeftRotation(AVLTree A){
	//��A��Ϊ���ڵ��������,�α��ϵĸ�ͼ�������� 
	//ע�⣺A������һ�����ӽ��B
	//��A��B������������A��B�ĸ߶ȣ������µĸ��ڵ�B
	//���ر�����ڵ㣬��Ϊ����һ���µĽ�㣬��ԭ���ڵ��ס����(T=....)
	AVLTree B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	//�ǵ�Ҫ���¸߶�(�䶯���ܱȽϴ�) 
	A->Height = Max(AVLHeight(A->Left),AVLHeight(A->Right))+1;		//�߶ȵĹ�ʽ�̶���ôд
	B->Height = Max(AVLHeight(B->Left),AVLHeight(B->Right))+1; 
	return B;					//����ԭ���ĸ��ڵ� 
}

AVLTree SingleRightRotation(AVLTree A){
	AVLTree B = A->Right;
	A->Right = B->Left;
	B->Left = A;
	//�ǵ�Ҫ���¸߶�(�䶯���ܱȽϴ�) 
	A->Height = Max(AVLHeight(A->Left),AVLHeight(A->Right))+1;		//�߶ȵĹ�ʽ�̶���ôд
	B->Height = Max(AVLHeight(B->Left),AVLHeight(B->Right))+1; 
	//��ʵB�ĸ߶�Ҳ��д�� B->Height = Max(AVLHeight(B->Left),A->Height); 
	return B;					//����ԭ���ĸ��ڵ� 
}

AVLTree DoubleLeftRightRotation(AVLTree A){
	//ע�⣺A������һ�����ӽ�㣨B����B������һ�����ӽ��C 
	// First Right then Left , converse from the Name	 
	A->Left = SingleRightRotation(A->Left);
	return SingleLeftRotation(A);			//ֱ�ӷ��ص��Ǹı��˵��µĸ��ڵ㣨C�� 
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


