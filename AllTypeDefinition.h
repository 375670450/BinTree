// All types of Definition
#ifndef ALLTYPEDEF_H
#define ALLTYPEDEF_H
#define ElementType int		//二叉树结点或集合存放的数据 
#define StackElem   int
#define QueueElem   HuffmanTree
#define MinHeapElem HuffmanTree
#define MaxHeapElem int 
#define HuffmanTreeElem char
#define MAXSIZE 100
#define Max(a,b) (a>b? a:b)




typedef int Boolean;
//二叉树结构定义
//【注意】这里TreeNode是作为一种结构名而非类型名 
typedef struct TreeNode* BinTree;		//记住BinTree已经是指针，不用加* 
typedef BinTree Position;  		//记录目前的位置？ 
typedef struct TreeNode{
	ElementType Data;
	int Tag ;			//	用于记录压栈次数
	BinTree Left;
	BinTree Right;
} Node; 


typedef struct AVLTreeNode* AVLTree;
typedef struct AVLTreeNode{
	ElementType Data;
	AVLTree Left;
	AVLTree Right;
	int Height;						//相比于普通的二叉树要多一项 
} AVLNode;

//哈夫曼树的结构定义 
typedef struct HuffmanTreeNode * HuffmanTree;
typedef struct HuffmanTreeNode{
	int Weight;
	int Deepth;
	HuffmanTreeElem Data;
	HuffmanTree Left;
	HuffmanTree Right;
} HuffmanNode;

//最小堆的数据结构定义(堆可以看作顺序存储的二叉树） 

typedef struct MinHeapStruct* MinHeap;
typedef struct MinHeapStruct{
	MinHeapElem * Data;				//【注意】指针(必须恒指向数组首地址)：存储堆元素的数组 
			   						// 不直接用数组：因为需要用的内存大小还未确定 
	int Size;						//当前元素个数【与下标无关】 
	int Capacity;					//堆的最大容量 
} MinHeap_Struct; 


//最大堆的数据结构定义
typedef struct MaxHeapStruct* MaxHeap;
typedef struct MaxHeapStruct{
	MaxHeapElem * Data;				//【注意】指针(必须恒指向数组首地址)：存储堆元素的数组 
			   						// 不直接用数组：因为需要用的内存大小还未确定 
	int Size;						//当前元素个数【与下标无关】 
	int Capacity;					//堆的最大容量 
} MaxHeap_Struct; 



//堆栈的类型定义
typedef struct StackNode{ 
	StackElem Data;
	struct StackNode * next ;
} Stack ;


//队列的数据结构类型定义（特殊记，比较特别） 
typedef struct Q_Node{
	QueueElem Data;
	struct Q_Node * Next;
} QNode;
typedef struct {			//链队列结构 
	QNode * front;			//指向队头结点 
	QNode * rear;			//指向队尾结点 
} Queue;

//集合的数据结构类型定义
typedef struct{
	ElementType Data;
	int Parent;				//根结点的Parent存放-1以区别于其他结点 
} SetType; 


#endif
