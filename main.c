#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"AllTypeDefinition.h"
#include"BinTree.h"
#include"Queue.h"
#include"Stack.h"
#include"BinSearchTree.h"
#include"AVLTree.h"
#include"HuffmanTree.h"
#include"MaxHeap.h" 
#include"MinHeap.h"
#include"SetType.h" 


//二叉搜索树关键：左小右大 

//正常运行莫名崩溃，用调试（不设断点）运行可行 

int main(){
	int amount,i,j,k,m,n,weight[MAXSIZE];
	HuffmanTree HT;
	char data;
	MinHeap H = CreateMinHeap();
	
	scanf("%d",&amount);
	for(i=0;i<amount;i++){
		do{
			data = getchar();
		}while( data=='\n' || data==' ' );
		scanf("%d",&weight[i]);
		HT = (HuffmanTree)malloc(sizeof(struct HuffmanTreeNode));
		HT->Deepth=0;
		HT->Data = data;
		HT->Weight = weight[i];
		HT->Left = HT->Right = NULL;
		MinHeapInsert(H,HT);
	}
	
	while( H->Size>1 ){			//总共做 H->Size - 1 次合并（用for循环？） 
		HuffmanTree HT = (HuffmanTree)malloc(sizeof(struct HuffmanTreeNode));
		HT->Deepth = 0;
		HT->Data = '?';
		HT->Left = DeleteMin(H);
//		printf("HT->Left:%c :Deepth=%d ,Weight=%d \n",HT->Left->Data,HT->Left->Deepth,HT->Left->Weight);
		HT->Left->Deepth++;
		HT->Right = DeleteMin(H);
//		printf("HT->Right:%c :Deepth=%d ,Weight=%d \n",HT->Right->Data,HT->Right->Deepth,HT->Right->Weight);
		HT->Right->Deepth++;   
		HT->Weight = HT->Left->Weight + HT->Right->Weight;
		H = MinHeapInsert(H,HT);   
	}
//	HT  = Huffman(H);
	HT = DeleteMin(H);
//	HuffmanLevelPrint(HT);
	
	// Identify the answer //
	int wpl = WPL(HT);
	int repeat,answer,isPrefix;
	char *str[amount];
	char *temp;
	scanf("%d",&repeat);
	for(i=0;i<repeat;i++){
		answer = 0;
		for(j=0;j<amount;j++){
			do{
			   data = getchar();
			}while( data=='\n' || data==' ' );
			str[j] = (char*)malloc(sizeof(char)*amount);
			scanf("%s",str[j]);
			answer+= weight[j]*strlen(str[j]);
		}
		// Check the prefix
  		// 1.sort out ,front to rear,small to large
		for(k=1;k<amount;k++){
			for(m=0;m<amount-k;m++){
				if( strlen(str[m]) > strlen(str[m+1]) ){
					temp = str[m];
					str[m] = str[m+1];
					str[m+1] = temp;	
				}
			} 
		} 
		// 2.compare the prefix
		isPrefix = 0;
		for(k=0;k<amount;k++){
			for(m=k+1;m<amount;m++){
				for(n=0;str[k][n]!='\0';n++){
					if( str[k][n]!=str[m][n] )
						break;
				}
				if( str[k][n]=='\0' ){
					isPrefix = 1;
					k = amount;
					break;
				}
			}
		}
		if( answer==wpl && !isPrefix ){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	

////////////////////////////////////////////////////////////////////////// 
	printf("\nInput a number to close the Console:\n");
	scanf("%d",&i);
	return 0;
}

