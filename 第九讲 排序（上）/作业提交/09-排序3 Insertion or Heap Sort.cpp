// https://pintia.cn/problem-sets/1211841066264109056/problems/1249172110099496962
#include<bits/stdc++.h>
using namespace std;

void insertsort(int *a, int n, int mark)
{
	int i=mark,tmp=a[mark];
	for(;i>0&&tmp<a[i-1];i--) a[i]=a[i-1];
	a[i]=tmp;
	cout<<"Insertion Sort"<<endl;
} 
 
void ajust(int *a,int i,int n)
{
	int child,tmp=a[i];
	for(;i*2+1<n;i=child)
	{
		child=i*2+1;
		if(child+1<n &&a[child+1]>a[child])child++;
		if(tmp<a[child])a[i]=a[child];
		else break;
	}
	a[i]=tmp;
} 
 
void heapsort(int *a,int n)
{
	int i,tmp;
	for(i=n-1;i>0;i--)	if(a[i-1]>a[i])break;
	tmp=a[i];
	a[i]=a[0];
	a[0]=tmp;
	ajust(a,0,i);
	cout<<"Heap Sort"<<endl;
}

void judge(int *a,int *tmp,int n)
{
	int i,mark=1;
	for(i=1;i<n;i++) if(tmp[i]<tmp[i-1])break;
	mark=i;
	for(;i<n;i++) if(a[i]!=tmp[i])mark=0;
	if(mark)insertsort(tmp,n,mark);
	else heapsort(tmp,n);
}


int main()
{
	int n,*a,*tmp,i;
	cin>>n;
	a=new int[n];
	tmp=new int[n];
	for(i=0;i<n;i++)		cin>>a[i];
	for(i=0;i<n;i++)cin>>tmp[i];
	judge(a,tmp,n);
	for(i=0;i<n-1;i++)cout<<tmp[i]<<" ";
	cout<<tmp[n-1];
 	return 0;
}





