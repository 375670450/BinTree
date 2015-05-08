#include<stdio.h>
#include<stdlib.h>
#include"SetType.h"

int SetFind(SetType S[],const int Size,ElementType X){ 
	//��ע�⡿���������S��ÿһ��Ԫ�ض���һ��SetType��Ԫ�أ���һ����㣩 
	// �˺����������յ�Parent(��������)�������Ҳ���X�ŷ���-1 
	// Ӧ���ڲ��ҹ����м������ĸ߶� 
	int i;
	for(i=1;i<=Size;i++){
		if( S[i].Data==X ){
			while(S[i].Parent>0){
				i = S[i].Parent;
			}
			return i;		//�ҵ��������ϣ�����δ�ҵ��򷵻������±꡿�����ַ���ֵ��Ϊ���� 
		}
	}
	return -1;			//δ�ҵ�,Ҳ����-1
}

void SetUnion(SetType S[],const int Size,ElementType X1,ElementType X2){
	int Root1,Root2;
	Root1 = SetFind(S,Size,X1);				//����X1�����ļ��� 
	Root2 = SetFind(S,Size,X2);
	if(Root2>0) S[Root2].Parent = Root1;		//��֤�ҵ��źϲ� 
	return ;
}


 
