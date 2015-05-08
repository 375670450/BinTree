#ifndef AVLTREE_H
#define AVLTREE_H
#include"AllTypeDefinition.h" 

//记住凡是插入函数返回类型为本身(如AVLTree)，插入的语句必须写成T = Insert(X,T) 
int AVLHeight(AVLTree T);
AVLTree AVLInsert(ElementType X,AVLTree T);
//调整算法 【注意传入的T都是失衡点而非旋转中心点】 
AVLTree SingleLeftRotation(AVLTree T);
AVLTree SingleRightRotation(AVLTree T);
AVLTree DoubleLeftRightRotation(AVLTree T);
AVLTree DoubleRightLeftRotation(AVLTree T);
void AVLInOrderPrint(AVLTree T);

#endif
