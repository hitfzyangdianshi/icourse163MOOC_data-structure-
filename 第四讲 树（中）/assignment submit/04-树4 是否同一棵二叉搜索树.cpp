/*https://pintia.cn/problem-sets/1211841066264109056/problems/1236509430527590400
04-��4 �Ƿ�ͬһ�ö��������� (25��)
����һ���������оͿ���Ψһȷ��һ�ö�����������Ȼ����һ�ø����Ķ���������ȴ�����ɶ��ֲ�ͬ�Ĳ������еõ�������ֱ�������{2, 1, 3}��{2, 3, 1}�����ʼΪ�յĶ��������������õ�һ���Ľ�������Ƕ�������ĸ��ֲ������У�����Ҫ�ж������Ƿ�������һ���Ķ�����������
�����ʽ:
�������������������ݡ�ÿ�����ݵĵ�1�и�������������N (��10)��L���ֱ���ÿ�����в���Ԫ�صĸ�������Ҫ�������и�������2�и���N���Կո�ָ�������������Ϊ��ʼ�������С����L�У�ÿ�и���N�������Ԫ�أ�����L����Ҫ�������С�
����������Ǳ�֤ÿ���������ж���1��N��һ�����С�������NΪ0ʱ����־����������������ݲ�Ҫ����
�����ʽ:
��ÿһ����Ҫ�������У���������ɵĶ�������������Ӧ�ĳ�ʼ�������ɵ�һ���������Yes�������������No����
*/
#include<bits/stdc++.h>
using namespace std;

#define NMax 10
typedef struct TreeNode *Tree;
struct TreeNode {
	int v;
	Tree Left, Right;
	int flag;
};

Tree NewNode(int V)
{
	Tree T=(Tree)malloc(sizeof(struct TreeNode));
	T->v=V;
	T->Left=T->Right=NULL;
	T->flag=0;
	return T;
}

Tree Insert(Tree T, int V)
{
	if(!T)T=NewNode(V);
	else
	{
		if(V>T->v) T->Right=Insert(T->Right,V);
		else T->Left=Insert(T->Left,V);
	}
	return T;
}

Tree MakeTree(int N)
{
	Tree T;
	int i,V;
	cin>>V;
	T=NewNode(V);
	for(i=1;i<N;i++)
	{
		cin>>V;
		T=Insert(T,V);
	}
	return T;
}

int check(Tree T, int V)
{
	if(T->flag)
	{
		if(V<T->v )return check(T->Left,V);
		else if(V>T->v ) return check (T->Right,V);
		else return 0;
	}
	else
	{
		if(V==T->v)
		{
			T->flag=1;
			return 1;
		}
		else return 0;
	}
}

int Judge(Tree T, int N)
{
	int i, V, flag = 0;/* flag: 0����Ŀǰ��һ�£� 1�����Ѿ���һ��*/
	cin>>V;
	if(V!=T->v) flag=1;
	else T->flag=1;
	for(i=1;i<N;i++)
	{
		cin>>V;
		if(  (!flag) && (!check(T,V))) flag=1;
	}
	if(flag)return 0;
	else return 1;
}

void ResetT(Tree T)
{
	if (T->Left) ResetT(T->Left);
	if (T->Right) ResetT(T->Right);
	T->flag = 0;
}

void FreeTree ( Tree T ) /* �ͷ�T�Ŀռ� */
{
	if (T->Left) FreeTree(T->Left);
	if (T->Right) FreeTree(T->Right);
	free(T);
}

int main()
{
	int N,L,i;
	Tree T;
	cin>>N;
	while(N)
	{
		cin>>L;
		T=MakeTree(N);
		for(i=0;i<L;i++)
		{
			if (Judge(T, N))printf("Yes\n");
			else printf("No\n");
			ResetT(T);
		}
		FreeTree(T);
		cin>>N;
	}
	
	return 0;
} 
