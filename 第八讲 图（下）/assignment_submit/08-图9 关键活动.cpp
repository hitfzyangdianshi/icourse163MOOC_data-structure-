//https://pintia.cn/problem-sets/1211841066264109056/problems/1246650197435133954
#include<bits/stdc++.h>
using namespace std;
typedef int Vertex;
#define infinity 32767

int M,N,ECT,g[1001][1001],idx,D[1001][1001];

int getMax( int *a )
{
	int max=0;
	for(int i = 0; i < N; i++)
		if( max < a[i] )	
		{
			max = a[i];
			idx=i;
		}
	return max;
}

int EarliestTime[1001]={0};
bool TopSort_E(  )
{ /* ??Graph????????????,  TopOrder[]???洢??????????±? */
    int Indegree[1001]={0}, cnt=0;
    memset(Indegree,0,sizeof(Indegree[0])*1001);
    Vertex V;
  //  PtrToAdjVNode W;
    queue<int>q;//Queue Q = CreateQueue( Graph->Nv );
  
    /* ?????Indegree[] */
   // for (V=0; V<Graph->Nv; V++)
     //   Indegree[V] = 0;
         
    /* ??????????Indegree[] */
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            if(g[i][j]!=infinity)Indegree[j]++; /* ???????<V, W->AdjV>?????????? */
             
    /* ??????????0????????? */
    for (V=0; V<N; V++)
        if ( Indegree[V]==0 )
            q.push(V);
             
    /* ??????????????? */ 
    while( !q.empty() ){
        V=q.front();//V = DeleteQ(Q); /* ???????????0????? */
        //TopOrder[cnt++] = V; /* ????????????е????????? */
        q.pop();
        cnt++;
		/* ??V?????????W->AdjV */
        for ( int j=0;j<N;j++)
        	if(g[V][j]!=infinity)
        	{
	            if (EarliestTime[V]+g[V][j]>EarliestTime[j] )/* ?????V???W->AdjV????0 */
    	            EarliestTime[j]=EarliestTime[V]+g[V][j];//AddQ(Q, W->AdjV); /* ?????????? */ 
    			if(--Indegree[j]==0) q.push(j);
    		}
	} /* while????*/
    ECT=getMax(EarliestTime); 
    if ( cnt != N)
        return false; /* ???????л?·, ??????????? */ 
    else
        return true;
}

void TopSort_L()
{
	int V,Outdegree[1001]={0}, cnt=0,LatestTime[1001]={0},i,j;
    memset(Outdegree,0,sizeof(Outdegree[0])*1001);
    queue<int> q;
    for(i=0;i<N;i++) for(j=0;j<N;j++) if(g[i][j]!=infinity) Outdegree[i]++;
    for(i=0;i<N;i++) if(Outdegree[i]==0)q.push(i);
    for(i=0;i<N;i++) LatestTime[i]=infinity;
    LatestTime[idx]=ECT;
    while(!q.empty())
    {
    	V=q.front();
    	q.pop();
    	for(j=0;j<N;j++)
    		if(g[j][V]!=infinity)
    		{
    			if(LatestTime[V]-g[j][V]<=LatestTime[j])
    			{
    				LatestTime[j] = LatestTime[V] - g[j][V];
    				D[j][V] = LatestTime[V] - EarliestTime[j] - g[j][V];
				}
				if(--Outdegree[j]==0)q.push(j);
			}	
	}
}


int main()
{
	int a,b,i,j;
	cin>>N>>M;
	for(i=0;i<N;i++)for(j=0;j<N;j++)D[i][j]=g[i][j]=infinity;
	for(i=0;i<M;i++)
	{
		cin>>a>>b;
		cin>>g[--a][--b];
	}
	if(TopSort_E()==false)cout<<"0"<<endl;
	else 
	{
		cout<<ECT<<endl;
		TopSort_L();
		for(i = 0; i < N; i++ )
			for(j = N - 1; j >= 0; j-- )	
				if( D[i][j] == 0 )
					cout<<i+1<<"->"<<j+1<<endl;
	}
	return 0;
}

