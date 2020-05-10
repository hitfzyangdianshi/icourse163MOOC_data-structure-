//11-散列2 Hashing
//https://pintia.cn/problem-sets/1211841066264109056/problems/1254370586245386241
#include<bits/stdc++.h>
using namespace std;

bool isprime(int n)
{
//	if(n==1)return false;
	if(n==2)return true;
	int i,j;
	for(i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)return false;
	}
	return true;
}

int getprime(int n)
{
	n= (n%2==0?n+1:n+2);
	for(int i=n;;i=i+2)
	{
		if(isprime(i))return i;
	}
}


int main()
{
	int m,n,*key,i;
	bool *value;
	cin>>m>>n;
	key=new int[n];
	for(i=0;i<n;i++)cin>>key[i];
	if(m==1)m=2;
	else if(isprime(m)==false)m=getprime(m);
	value=new bool[m];
	memset(value,false,sizeof(bool)*m);
	for(i=0;i<n;i++)
	{
		if(i!=0)cout<<" ";
		int tmpv;
		tmpv=key[i]%m;
		if(value[tmpv]==false)
		{
			value[tmpv]=true;
			cout<<tmpv;
		}
		else
		{
			int flag=0;
			for(int j=1;j<m;j++)
			{
				tmpv=(key[i]+j*j)%m;
				if(value[tmpv]==false)
				{
					value[tmpv]=true;
					cout<<tmpv;
					flag=1;
					break;
				}
			}	
			if(flag==0)cout<<"-";
		}
	}
	return 0;
}
	
