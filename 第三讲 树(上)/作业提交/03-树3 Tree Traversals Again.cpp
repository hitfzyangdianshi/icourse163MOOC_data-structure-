/*Tree Traversals Again 是2014年秋季PAT甲级考试真题，稍微要动下脑筋，想通了其实程序很基础，建议尝试。
https://pintia.cn/problem-sets/1211841066264109056/problems/1234055373045018625
An inorder binary tree traversal can be implemented in a non-recursive way with a stack. For example, suppose that when a 6-node binary tree (with the keys numbered from 1 to 6) is traversed, the stack operations are: push(1); push(2); push(3); pop(); pop(); push(4); pop(); pop(); push(5); push(6); pop(); pop(). Then a unique binary tree (shown in Figure 1) can be generated from this sequence of operations. Your task is to give the postorder traversal sequence of this tree.
Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (≤30) which is the total number of nodes in a tree (and hence the nodes are numbered from 1 to N). Then 2N lines follow, each describes a stack operation in the format: "Push X" where X is the index of the node being pushed onto the stack; or "Pop" meaning to pop one node from the stack.
Output Specification:
For each test case, print the postorder traversal sequence of the corresponding tree in one line. A solution is guaranteed to exist. All the numbers must be separated by exactly one space, and there must be no extra space at the end of the line.
*/
#include<bits/stdc++.h>
using namespace std;

#define MaxTree 30
#define ElementType int
#define Tree int
//#define Null -1

struct TreeNode
{
	ElementType Element;
	TreeNode *Left;
	TreeNode *Right;
	TreeNode(int v):Element(v),Left(NULL),Right(NULL){	}
} *R;

int scanfi=0;

TreeNode *BuildTree(int N)
{
	if(scanfi>=2*N) return NULL;
	char ch[10];
	scanf("%s",ch);
	TreeNode *R=NULL;
	scanfi++;
	if(ch[1]=='u')//push x
	{
		int value;
		cin>>value;
		R=new TreeNode(value);
		R->Left=BuildTree(N);
		R->Right=BuildTree(N);
	}
	return R;
}

void postorder(TreeNode *root)
{
	if(root!=NULL)
	{
		postorder(root->Left);
		postorder(root->Right);
		cout<<root->Element;
		if(root!=R)cout<<" "; 
	}
}

int main()
{
	int n;
	cin>>n;
	R=BuildTree(n);
	postorder(R);
//	cout<<'\b';
	
	return 0;
}


