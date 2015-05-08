#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H 
#include"AllTypeDefinition.h"
#include"MinHeap.h"

//�������������Ŷ�����������Ȩ·�����ȣ�Weighted Path Length����С�Ķ����� 
//��ע�⡿�����������룺1.ֻ��Ҷ�ڵ���ܴ洢�������ַ� 
//						2.�κ�һ���ַ��ı��붼�����������ַ������ǰ׺���������Ǻ�׺�� 
HuffmanTree Huffman(MinHeap H);			//���������Ĺ��� 
void HuffmanLevelPrint(HuffmanTree HT);	//������� 
int  WPL(HuffmanTree HT);

#endif
