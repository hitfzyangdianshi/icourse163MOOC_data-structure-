/*https://pintia.cn/problem-sets/1211841066264109056/problems/1234055373045018624
03-Ê÷2 List Leaves (25·Ö)
Given a tree, you are supposed to list all the leaves in the order of top down, and left to right.
Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (¡Ü10) which is the total number of nodes in the tree -- and hence the nodes are numbered from 0 to N?1. Then N lines follow, each corresponds to a node, and gives the indices of the left and right children of the node. If the child does not exist, a "-" will be put at the position. Any pair of children are separated by a space.
Output Specification:
For each test case, print in one line all the leaves' indices in the order of top down, and left to right. There must be exactly one space between any adjacent numbers, and no extra space at the end of the line.
*/
#include<bits/stdc++.h>
using namespace std;

#define MaxTree 10
#define ElementType int
#define Tree int
#define Null -1

struct TreeNode
{
//	ElementType Element;
	Tree Left;
	Tree Right;
} T1[MaxTree], T2[MaxTree];

Tree q[MaxTree];

Tree BuildTree(struct TreeNode T[] )
{
	int N,i,check[MaxTree];
	Tree Root=Null;
	memset(check,0,sizeof(check[0])*MaxTree);
	char cl,cr;
	scanf("%d\n",&N);
	if(N>0)
	{
		for(i=0;i<N;i++)
		{
			scanf("%c %c\n",  &cl, &cr);
	//		T[i].Element=i;
			if(cl!='-')
			{
				T[i].Left=cl-'0';
				check[T[i].Left]=1;
			}
			else 
			{
				T[i].Left = Null;
			}
			if(cr!='-')
			{
				T[i].Right=cr-'0';
				check[T[i].Right]=1;
			}
			else 
			{
				T[i].Right = Null;
			}
		}
		for(i=0;i<N;i++)
		    if(check[i]==0) break;
		Root=i;
	}
	return Root;	
}

void LevelOrderTraversal (Tree BT)
{
	Tree T;
	int head=0,tail=0;
	memset(q,Null,sizeof(q[0])*MaxTree);
	if(BT==Null)return;
	q[tail]=BT;
	tail++;
	while(tail!=head)
	{
		T=q[head];
		head++;
	//	cout<<T<<endl;
		if(T1[T].Left!=Null) 
		{
			q[tail]=T1[T].Left;
			tail++;
		}
		if(T1[T].Right!=Null) 
		{
			q[tail]=T1[T].Right;
			tail++;
		}
	}
}

//void PreOrderPrintLeaves(Tree BT )


int main()
{
	Tree R1;
	R1=BuildTree(T1);
	LevelOrderTraversal(R1);
//	for(int i=0;i<10;i++)cout<<q[i]<<"\t"; 
    int i,tag=0;
    for(i=0;i<MaxTree;i++)
    {
    	if(q[i]==Null)break;
    	if(T1[q[i]].Left == Null && T1[q[i]].Right==Null)
		{
			if(tag==0)
			{
				tag++;
				cout<<q[i];
			}
			else cout<<" "<<q[i];
		
		}
	}
	cout<<endl;
	
	return 0;
}

