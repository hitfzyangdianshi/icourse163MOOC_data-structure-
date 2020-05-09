//https://pintia.cn/problem-sets/1211841066264109056/problems/1251762364668882944
#include<bits/stdc++.h>
using namespace std;

int cmp(const void *a, const void *b)
{
	return *(int*)a-*(int*)b;
}

int main()
{
	int n,*a,i,cnt=1;
	cin>>n;
	a=new int[n];
	for(i=0;i<n;i++)cin>>a[i];
	qsort(a,n,sizeof(int),cmp);
	for(i=0;i<n;i++)
	{
		if(i<n-1&&a[i]==a[i+1])
		{
			cnt++;
		}
		else
		{
			cout<<a[i]<<":"<<cnt<<endl;
			cnt=1;
		}
	}
	return 0;
}


