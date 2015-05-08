// All types of Definition
#ifndef ALLTYPEDEF_H
#define ALLTYPEDEF_H
#define ElementType int		//���������򼯺ϴ�ŵ����� 
#define StackElem   int
#define QueueElem   HuffmanTree
#define MinHeapElem HuffmanTree
#define MaxHeapElem int 
#define HuffmanTreeElem char
#define MAXSIZE 100
#define Max(a,b) (a>b? a:b)




typedef int Boolean;
//�������ṹ����
//��ע�⡿����TreeNode����Ϊһ�ֽṹ������������ 
typedef struct TreeNode* BinTree;		//��סBinTree�Ѿ���ָ�룬���ü�* 
typedef BinTree Position;  		//��¼Ŀǰ��λ�ã� 
typedef struct TreeNode{
	ElementType Data;
	int Tag ;			//	���ڼ�¼ѹջ����
	BinTree Left;
	BinTree Right;
} Node; 


typedef struct AVLTreeNode* AVLTree;
typedef struct AVLTreeNode{
	ElementType Data;
	AVLTree Left;
	AVLTree Right;
	int Height;						//�������ͨ�Ķ�����Ҫ��һ�� 
} AVLNode;

//���������Ľṹ���� 
typedef struct HuffmanTreeNode * HuffmanTree;
typedef struct HuffmanTreeNode{
	int Weight;
	int Deepth;
	HuffmanTreeElem Data;
	HuffmanTree Left;
	HuffmanTree Right;
} HuffmanNode;

//��С�ѵ����ݽṹ����(�ѿ��Կ���˳��洢�Ķ������� 

typedef struct MinHeapStruct* MinHeap;
typedef struct MinHeapStruct{
	MinHeapElem * Data;				//��ע�⡿ָ��(�����ָ�������׵�ַ)���洢��Ԫ�ص����� 
			   						// ��ֱ�������飺��Ϊ��Ҫ�õ��ڴ��С��δȷ�� 
	int Size;						//��ǰԪ�ظ��������±��޹ء� 
	int Capacity;					//�ѵ�������� 
} MinHeap_Struct; 


//���ѵ����ݽṹ����
typedef struct MaxHeapStruct* MaxHeap;
typedef struct MaxHeapStruct{
	MaxHeapElem * Data;				//��ע�⡿ָ��(�����ָ�������׵�ַ)���洢��Ԫ�ص����� 
			   						// ��ֱ�������飺��Ϊ��Ҫ�õ��ڴ��С��δȷ�� 
	int Size;						//��ǰԪ�ظ��������±��޹ء� 
	int Capacity;					//�ѵ�������� 
} MaxHeap_Struct; 



//��ջ�����Ͷ���
typedef struct StackNode{ 
	StackElem Data;
	struct StackNode * next ;
} Stack ;


//���е����ݽṹ���Ͷ��壨����ǣ��Ƚ��ر� 
typedef struct Q_Node{
	QueueElem Data;
	struct Q_Node * Next;
} QNode;
typedef struct {			//�����нṹ 
	QNode * front;			//ָ���ͷ��� 
	QNode * rear;			//ָ���β��� 
} Queue;

//���ϵ����ݽṹ���Ͷ���
typedef struct{
	ElementType Data;
	int Parent;				//������Parent���-1��������������� 
} SetType; 


#endif
