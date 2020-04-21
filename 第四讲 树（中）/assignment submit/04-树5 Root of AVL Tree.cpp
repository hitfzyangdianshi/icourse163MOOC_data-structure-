/*https://pintia.cn/problem-sets/1211841066264109056/problems/1236509430527590401
 An AVL tree is a self-balancing binary search tree. In an AVL tree, the heights of the two child subtrees of any node differ by at most one; if at any time they differ by more than one, rebalancing is done to restore this property. Figures 1-4 illustrate the rotation rules.
 Now given a sequence of insertions, you are supposed to tell the root of the resulting AVL tree.
Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (¡Ü20) which is the total number of keys to be inserted. Then N distinct integer keys are given in the next line. All the numbers in a line are separated by a space.
Output Specification:
For each test case, print the root of the resulting AVL tree in one line.
Sample Input 1:
5
88 70 61 96 120
Sample Output 1:
70
Sample Input 2:
7
88 70 61 96 120 90 65 
Sample Output 2:
88
 */
#include<bits/stdc++.h>
using namespace std;

typedef struct AVLNode* AVLTree;
struct AVLNode{
	int val;
	AVLTree left;
	AVLTree right;
	int height;
};

int getheight(AVLTree t)
{
	if(t) return max(getheight(t->left) , getheight(t->right)) + 1;  
	else return 0;
}

AVLTree Left(AVLTree a) 
{
	AVLTree b=a->left;
	a->left=b->right;
	b->right=a;
	a->height=max(getheight(a->left),getheight(a->right))+1;
	b->height=max(getheight(b->left),a->height )+1;
	return b;
}

AVLTree Right(AVLTree a)
{
	AVLTree b=a->right;
	a->right=b->left;
	b->left=a;
	a->height=max(getheight(a->left),getheight(a->right))+1;
	b->height=max(getheight(b->right),a->height )+1;
	return b;
}

AVLTree LeftRight(AVLTree a)
{
	a->left=Right(a->left );
	return Left(a);
}

AVLTree RightLeft(AVLTree a)
{
	a->right=Left(a->right );
	return Right(a);
}

AVLTree insert(int x, AVLTree t)
{
	if(!t)
	{
		t=(AVLTree)malloc(sizeof(struct AVLNode));
		t->val=x;
		t->height=0;
		t->left=NULL;
		t->right=NULL;
	}
	else if(x< t->val )
	{
		t->left=insert(x,t->left);
		if(getheight(t->left )-getheight(t->right)==2)
		{
			if(x< t->left->val )t=Left(t);
			else t=LeftRight(t);
		}
	}
	else if(x> t->val )
	{
		t->right=insert(x,t->right);
		if(getheight(t->right)-getheight(t->left)==2)
		{
			if(x> t->right->val )t=Right(t);
			else t=RightLeft(t);
		}
	}
	t->height=max(getheight(t->left ),getheight(t->right ))+1;
	return t;
}


int main(int argc,char **argv)
{
	int n;
	cin>>n;
	AVLTree a= NULL;
	for(int i=0;i<n;i++)
	{
	    int t;	
		cin>>t;
		a=insert(t,a);
	}
	cout<<a->val;
	return 0;
}






