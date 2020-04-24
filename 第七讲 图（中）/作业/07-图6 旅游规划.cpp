//https://pintia.cn/problem-sets/1211841066264109056/problems/1244270885410840578
#include<bits/stdc++.h>
using namespace std;

int N,M,S,D,length[501][501],price[501][501],dist[501],path[501],cost[501];
typedef int Vertex;
#define INFINITY 32767

void Dijkstra( Vertex s )
{ 
	bool collected[501]={false};
	int V,W;
	for(V=0;V<N;V++)
	{
		dist[V]=length[V][s];
		cost[V]=price[V][s];
		collected[V]=false;
	} 
	dist[s]=0;
	cost[s]=0;
	collected[s]=true;
	while (1) 
	{
		//V = 未收录顶点中dist最小者;
		int mindist=INFINITY,minv;
		for(V=0;V<N;V++)
		{
			if(collected[V]==false && dist[V]<mindist)
			{
				mindist=dist[V];
				minv=V;
			}
		}
		//if ( 这样的V不存在 )	break;
		if(mindist==INFINITY)break; 
		V=minv;
		collected[V] = true;
		for (W=0;W<N;W++)  //( V 的每个邻接点 W )
			if ( collected[W] == false && length[V][W]<INT_MAX )
			{
				if ( dist[V]+length[V][W] < dist[W] ) 
				{	
					dist[W] = dist[V] + length[V][W];
		//			path[W] = V;
					cost[W] = cost[V] + price[V][W] ;
				}
				else if ( (dist[V]+length[V][W] == dist[W])&& (cost[V]+price[V][W] < cost[W]) )
				{
					cost[W] = cost[V] + price[V][W] ;
				//	dist[W]=dist[V]+length[V][W];
	//				path[W] = V;
				}
			}
	}
}


int main(int argc, char *argv[])
{
	cin>>N>>M>>S>>D;
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)length[i][j]=INFINITY;
	for(int i=0;i<M;i++) 
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		length[a][b]=length[b][a]=c;
		price[a][b]=price[b][a]=d;
	}
	Dijkstra(S);
	cout<<dist[D]<<" "<<cost[D];
	
	return 0;
	
}



