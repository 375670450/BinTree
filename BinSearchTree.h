#ifndef BINSEARCHTREE_H
#define BINSEARCHTREE_H
#include"AllTypeDefinition.h"

//����������(������������������
Position Find(ElementType X,BinTree BST);	//�Ӷ������������ҵ�Ԫ��X���ؽ���ַ
Position FindMin(BinTree BST);				//�ҵ���СԪ�� 
Position FindMax(BinTree BST);				//�ҵ����Ԫ�� 
BinTree Insert(ElementType X,BinTree BST);	//��Ԫ��X����Ӧ�ò����λ��(���Ѵ������ӡ��Ϣ���ش����BST�� 
BinTree Delete(ElementType X,BinTree BST);	//ɾ�����������е�ĳ��� 
int IsBinSearchTre(BinTree BST);

#endif
