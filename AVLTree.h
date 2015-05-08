#ifndef AVLTREE_H
#define AVLTREE_H
#include"AllTypeDefinition.h" 

//��ס���ǲ��뺯����������Ϊ����(��AVLTree)�������������д��T = Insert(X,T) 
int AVLHeight(AVLTree T);
AVLTree AVLInsert(ElementType X,AVLTree T);
//�����㷨 ��ע�⴫���T����ʧ��������ת���ĵ㡿 
AVLTree SingleLeftRotation(AVLTree T);
AVLTree SingleRightRotation(AVLTree T);
AVLTree DoubleLeftRightRotation(AVLTree T);
AVLTree DoubleRightLeftRotation(AVLTree T);
void AVLInOrderPrint(AVLTree T);

#endif
