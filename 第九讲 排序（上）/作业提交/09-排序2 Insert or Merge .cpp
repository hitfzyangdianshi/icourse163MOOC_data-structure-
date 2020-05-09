//https://pintia.cn/problem-sets/1211841066264109056/problems/1249172110099496961
#include<bits/stdc++.h>
using namespace std;

bool check(int *a, int *b,int n)
{
	for(int i=0;i<n;i++) if(a[i]!=b[i])return false;
	return true;
}

void Print(int *a, int n)
{
	cout<<a[0];
	for(int i=1;i<n;i++)cout<<" "<<a[i];
}

bool insertsort(int *a, int *b,int n)
{
	bool isinsert=false;
	for(int i=1;i<n;i++)
	{
		int tmp=a[i],j;
		for(j=i;j>0&&a[j-1]>tmp;j--) a[j]=a[j-1];
		a[j]=tmp;
		if(isinsert==true)
		{
			cout<<"Insertion Sort"<<endl;
			Print(a,n);
			break;
		}
		else if(check(a,b,n)==true)isinsert=true;
	}
	return isinsert;
}

void merge(int *a,int left,int right,int rightend)
{
	int tmp[rightend-left+1],leftend=right-1,
	    len=rightend-left+1,i=left,j=right,k=0;
	while(i<=leftend&&j<=rightend)
	{
		if(a[i]<=a[j]) tmp[k++]=a[i++];
		else tmp[k++]=a[j++];
	}
	while(i<=leftend) tmp[k++]=a[i++];
	while(j<=rightend) tmp[k++]=a[j++];
	for(i=left,k=0;i<=rightend;i++)a[i]=tmp[k++];
}

bool mergesort(int *a,int *b,int n)
{
	bool ismerge=false;
	for(int i=1;i<n;i=i*2)
	{	
		for(int j=0;j<n;j=j+i*2)
		{
			if(j+i*2<=n)merge(a,j,j+i,j+i*2-1);
			else if (j+i<=n) merge(a,j,j+i,n-1);
		}
		if(ismerge==true)
		{
			cout<<"Merge Sort"<<endl;
			Print(a,n);
			break;
		}
		else if (check(a,b,n)==true)ismerge=true;
	}
	return ismerge;
}


int main()
{
	int len,*a,*b,*c,i;
	cin>>len;
	a=new int[len];
	b=new int[len];
	c=new int [len];
	for(i=0;i<len;i++)
	{
		cin>>a[i];
		c[i]=a[i];
	}
	for(i=0;i<len;i++)cin>>b[i];
	bool ismerge=mergesort(a,b,len);
	if(ismerge!=true) insertsort(c,b,len);
	return 0;
}





