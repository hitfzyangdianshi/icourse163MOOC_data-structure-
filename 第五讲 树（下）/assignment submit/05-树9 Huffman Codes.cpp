//https://pintia.cn/problem-sets/1211841066264109056/problems/1239025765568618498
#include<bits/stdc++.h>
using namespace std;

#define MAXN 64
#define MIN -1
#define QUEUESIZE 100

typedef struct TreeNode *HuffmanTree;
struct TreeNode{
	int weight;
	HuffmanTree left,right;
};
typedef struct HeapStruct *MinHeap;
struct HeapStruct{
	HuffmanTree data;
	int size;
	int capacity;
};
typedef struct Qnode *Queue;
struct QNode{
	HuffmanTree data[QUEUESIZE];
	int rear;
	int front;
};

MinHeap CreateMinHeap(int MaxSize)
{
	MinHeap H=(MinHeap)malloc(sizeof(struct HeapStruct));
	H->data=(HuffmanTree)malloc(sizeof(struct TreeNode)*(MaxSize+1));
	H->size=0;
	H->capacity=MaxSize;
	H->data[0].weight=MIN;
	return H;
}

bool MinHeapIsFull(MinHeap H)
{
	return (H->size == H->capacity);
}

void MinHeapInsert(MinHeap H, HuffmanTree t)
{
	int i;
	if(MinHeapIsFull(H))
	{
	//	cout<<"Heap full"<<endl;
		return;
	}
	i= ++H->size;
	for(;H->data[i/2].weight > t->weight;i=i/2)
	{
		H->data[i].weight=H->data[i/2].weight;
		H->data[i].left=H->data[i/2].left;
		H->data[i].right=H->data[i/2].right;
	}
	H->data[i]=*t;
}

bool IsEmpty(MinHeap H)
{
	return (H->size==0);
}

HuffmanTree DeleteMin(MinHeap H)
{
	int parent,child;
	HuffmanTree MinItem,t;
	MinItem=(HuffmanTree)malloc(sizeof(struct TreeNode));
	t=(HuffmanTree)malloc(sizeof(struct TreeNode));
	if(IsEmpty(H))
	{
	//	cout<<"MinHeap Empty"<<endl;
		return NULL;
	}
	*MinItem=H->data[1];
	*t=H->data[H->size--];
	//cout<<"size"  ""<<H->size<<endl;
	for(parent=1;parent*2<= H->size;parent=child)
	{
		child=parent*2;
		if((child!= H->size) &&(H->data[child].weight > H->data[child+1].weight))
			child++;
		if(t->weight <= H->data[child].weight)break;
		else
		{
			H->data[parent].weight=H->data[child].weight;
			H->data[parent].left=H->data[child].left;
			H->data[parent].right=H->data[child].right;
		}
	}
	H->data[parent]=*t;
	return MinItem;
}

void PrecDown(MinHeap H,int p)
{
	int parent,child;
	HuffmanTree t;
	t=(HuffmanTree)malloc(sizeof(struct TreeNode));
	*t=H->data[p];
	for(parent=p;parent*2<= H->size;parent=child)
	{
		child=parent*2;
		if((child!=H->size) &&(H->data[child].weight> H->data[child+1].weight)) child++;
		if(t->weight <=H->data[child].weight) break;
		else
			H->data[parent].weight=H->data[child].weight;
	}
	H->data[parent]=*t;
}

void BuildMinHeap(MinHeap H)
{
	for(int i=H->size/2;i>0;i--) PrecDown(H,i);
}

void PrintMinHeap(MinHeap H)
{
	for(int i=1;i<=H->size;i++)cout<<" "<<H->data[i].weight; 
	cout<<endl;
}

HuffmanTree Huffman(MinHeap H)
{
	HuffmanTree T;
	BuildMinHeap(H);
	for(int i=1;i<H->size;)
	{
		T=(HuffmanTree)malloc(sizeof(struct TreeNode));
		T->left=DeleteMin(H);
		T->right=DeleteMin(H);
		T->weight=T->left->weight+T->right->weight;
		MinHeapInsert(H,T);
	}
	T=DeleteMin(H);
	return T;
}

void PrintHuffman(HuffmanTree T)
{
	if(T)
	{
		PrintHuffman(T->left);
		PrintHuffman(T->right);
		cout<<T->weight<<" ";
	}
}
MinHeap ReadData(int num, char *ch, int *cf,MinHeap H)
{
	for(int i=0;i<num;i++)
	{
		//cin>>ch[i]>>cf[i];
		if(i==num-1)scanf("%c %d",&ch[i],&cf[i]);
		else scanf("%c %d ",&ch[i],&cf[i]);
		HuffmanTree T=(HuffmanTree)malloc(sizeof(struct TreeNode));
		T->weight=cf[i];
		MinHeapInsert(H,T);
	}
	return H;
}

int WPL(HuffmanTree T,int Depth)
{
	int rw=0,lw=0;
	if(!T->left && !T->right) return (Depth*( T->weight));
	else
	{
		if(T->left)lw=WPL(T->left,Depth+1);
		if(T->right)rw=WPL(T->right,Depth+1);
		return lw+rw;
	}
}

HuffmanTree CreateHuffmanTree()
{
	HuffmanTree T=(HuffmanTree)malloc(sizeof (struct TreeNode));
	T->weight=0;
	T->left=NULL;
	T->right=NULL;
	return T;
}

void DeleteHuffmanTree(HuffmanTree T)
{
	if(T)
	{
		DeleteHuffmanTree(T->left);
		DeleteHuffmanTree(T->right);
		free(T);
	}
}

int Judge(int n, int codelen,char *ch,int*cf)
{
	char s1[MAXN],s2[MAXN];
	int i,j,weight,flag=1;
	HuffmanTree T=CreateHuffmanTree();
	HuffmanTree pt=NULL;
	for(i=0;i<n;i++)
	{
	//	cin>>s1>>s2;
		scanf("%s %s\n",s1,s2);
		if(strlen(s2)>n)
		{
			flag=0;
			break;	
		}
		for(j=0;s1[0]!=ch[j];j++)
			if(j==n)
			{
				flag=0;
				break;
			}
		weight=cf[j];
		pt=T;
		for(j=0;j<strlen(s2);j++)
		{
			if(s2[j]=='0')
			{
				if(!pt->left)pt->left=CreateHuffmanTree();
				else if(pt->left->weight!=0) flag=0;	
				pt=pt->left;
			}
			else if (s2[j]=='1')
			{
				if(!pt->right)pt->right=CreateHuffmanTree();
				else if(pt->right->weight!=0) flag=0;
				pt=pt->right;
			}
			else flag=0;
		}
		pt->weight=weight;
		weight=0;
		if(pt->left||pt->right) flag=0;
	}
	if(flag!=0 && codelen==WPL(T,0)) return 1;
	else
	{
		if(T)DeleteHuffmanTree(T);
		return 0;	
	}
}


int main(int argc,char **argv)
{
	int codelen,n,i;
	MinHeap H;
	char *ch;
	int *cf;
	HuffmanTree T;
	//cin>>n;
	scanf("%d\n",&n);
	H=CreateMinHeap(n);
	ch=(char *)malloc(sizeof(char)*n);
	cf=(int *)malloc(sizeof(int)*n);
	H=ReadData(n,ch,cf,H);
	T=Huffman(H);
	codelen=WPL(T,0);
	int nn;
//	cin>>nn;
	scanf("%d\n",&nn);
	for(i=0;i<nn;i++)
	{
		if(Judge(n,codelen,ch,cf))cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}




