#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H 
#include"AllTypeDefinition.h"
#include"MinHeap.h"

//哈夫曼树（最优二叉树）：带权路径长度（Weighted Path Length）最小的二叉树 
//【注意】：哈夫曼编码：1.只有叶节点才能存储（代表）字符 
//						2.任何一个字符的编码都不能是其他字符编码的前缀（但可以是后缀） 
HuffmanTree Huffman(MinHeap H);			//哈夫曼树的构造 
void HuffmanLevelPrint(HuffmanTree HT);	//层序输出 
int  WPL(HuffmanTree HT);

#endif
