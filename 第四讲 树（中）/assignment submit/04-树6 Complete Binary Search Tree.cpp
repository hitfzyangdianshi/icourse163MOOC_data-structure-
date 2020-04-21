//https://pintia.cn/problem-sets/1211841066264109056/problems/1236509430527590402
#include<bits/stdc++.h>
using namespace std;

int cmp(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}

int N,A[1001],T[1001];

int GetLeftLength(int n)
{
	double x,L,t;
	int h;
	h=log(n+1)/log(2);
	x=n-pow(2,h)+1;
	t=pow(2,h-1);
	x=min(x,t);
	L=t+x-1;
	return L;
}

void solve( int ALeft, int ARight, int TRoot )
{ /* 初始调用为 solve(0, N-1, 0) */
	int n,L,LeftTRoot,RightTRoot;
	n = ARight - ALeft + 1;
	if (n==0) return;
	L = GetLeftLength(n); /* 计算出n个结点的树其左子树有多少个结点 */
	T[TRoot] = A[ALeft + L];
	LeftTRoot = TRoot * 2 + 1;
	RightTRoot = LeftTRoot + 1;
	solve(ALeft, ALeft+L-1, LeftTRoot);
	solve(ALeft+L+1, ARight, RightTRoot);
}


int main(int argc, char *argv[])
{
	cin>>N;
	for(int i=0;i<N;i++)cin>>A[i];
	qsort(A,N,sizeof(int),cmp);
	solve(0,N-1,0);
	for(int i=0;i<N;i++)
	{
		if(i==0)cout<<T[i];
		else cout<<" "<<T[i];
	}
	
	
	return 0;
}
 
