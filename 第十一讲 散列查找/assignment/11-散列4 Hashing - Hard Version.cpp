//11-散列4 Hashing - Hard Version
//https://pintia.cn/problem-sets/1211841066264109056/problems/1254370586245386243
#include <vector>
#include <queue>
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

int conflicttimes(int i, int key,int size)
{
	return (i-key%size+size)%size;
}

int Hash(int k,int s)
{
	return k%s;
}

int a[1001];
struct cmp
{
	bool operator() (int i,int j)
	{
		return a[i]>a[j];
	}
};


int main()
{
	int n,x,flag=0,*indegree,i;
	cin>>n;
	indegree=new int[n];
	vector< vector<int> >v(n);
	priority_queue<int,vector<int>,cmp>q;
	for(i=0;i<n;i++)
	{
		cin>>x;
		a[i]=x;
		if(x>=0)
		{
			int pos=Hash(x,n);
			indegree[i]=conflicttimes(i,x,n);
			if(indegree[i])
				for(int j=0;j<=indegree[i];j++)
					v[Hash(pos+j,n)].push_back(i);
			else q.push(i);
		}
	}
	while(!q.empty())
	{
		int pos=q.top();
		q.pop();
		if(flag==1)cout<<" ";
		cout<<a[pos];
		flag=1;
		for(i=0;i<v[pos].size();i++)
		{
			if(--indegree[v[pos][i]]==0) q.push(v[pos][i]);
		}
	}
	return 0;
}
		
			
