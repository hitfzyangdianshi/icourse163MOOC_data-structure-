//https://pintia.cn/problem-sets/1211841066264109056/problems/1249172110099496960
#include<bits/stdc++.h>
using namespace std;

int cmp(const void *a, const void *b)
{
    return *(int*)a-*(int*)b;
}

int main()
{
    int n,*a,i;
    cin>>n;
    a=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)cin>>a[i];
    qsort(a,n,sizeof(int),cmp);
    for(i=0;i<n;i++)
    {
        if(i!=0)cout<<" ";
        cout<<a[i];
    }
    return 0;
}
