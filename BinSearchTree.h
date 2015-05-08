#ifndef BINSEARCHTREE_H
#define BINSEARCHTREE_H
#include"AllTypeDefinition.h"

//二叉搜索树(二叉排序树）操作集
Position Find(ElementType X,BinTree BST);	//从二叉搜索树中找到元素X返回结点地址
Position FindMin(BinTree BST);				//找到最小元素 
Position FindMax(BinTree BST);				//找到最大元素 
BinTree Insert(ElementType X,BinTree BST);	//将元素X插入应该插入的位置(若已存在则打印消息返回传入的BST） 
BinTree Delete(ElementType X,BinTree BST);	//删除并返回树中的某结点 
int IsBinSearchTre(BinTree BST);

#endif
