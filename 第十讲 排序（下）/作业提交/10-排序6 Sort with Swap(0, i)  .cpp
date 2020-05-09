//https://pintia.cn/problem-sets/1211841066264109056/problems/1251762364668882946
//10-排序6 Sort with Swap(0, i) 
#include<bits/stdc++.h>
using namespace std;

int a[100001],b[100001],gfindbeginposition=0;
bool checked[100001];

int findunchecked(int n)
{
	for(int i=gfindbeginposition;i<n;i++)
		if(!checked[i])return gfindbeginposition=i;
	return -1;
}


int main()
{
	int n,p,i,sum,ringcount=0,ncount=0,zeroinposition=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		b[a[i]]=i;
	}
	if(a[0]==0)zeroinposition=0;
	else zeroinposition=-2;
	while((p=findunchecked(n))+1)
	{
		checked[p]=true;
		if(a[p]!=p) ncount++;
		else continue;
		while(checked[b[p]]==false)
		{
			p=b[p];
			checked[p]=true;
			ncount++;
		}
		ringcount++;
	}
	sum=ncount+ringcount+zeroinposition;
	cout<<sum;
	return 0;
}


