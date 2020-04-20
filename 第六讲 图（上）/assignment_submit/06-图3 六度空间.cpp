//https://pintia.cn/problem-sets/1211841066264109056/problems/1241660123425153026
#include<bits/stdc++.h>
using namespace std;

int N,M;//N 1000, M 33000
int G[1001][1001];
bool visited[1001];
typedef int Vertex;

void visit_init()
{
	memset(visited,false,sizeof(visited));
}


int bfs ( Vertex V )
{ 
	visit_init();
	int count=1,level=0;int q[1001];
	memset(q,0,sizeof(q));
	visited[V] = true; 
	int first=0,last = 0;
	q[++last]=V;
	int flag=q[last];
	while(first<last)
	{
		int f=q[++first];
		for ( int i=1;i<=N;i++)
			if (G[f][i] && !visited[i] ) 
			{
				visited[i] = true;
				q[++last]=i;
				count++;
			}
		if ( f == flag ) 
		{	
			level++; 
			flag=q[last];
		}
		if ( level >= 6 ) break;
	}
	return count;
}


int main(int argc, char *argv[])
{
	memset(G,0,sizeof(G));
	cin>>N>>M;
	int a,b,i;
	for(i=0;i<M;i++)
	{
		cin>>a>>b;
		G[a][b]=G[b][a]=1;
	}
	for(i=1;i<=N;i++)
	{
		double answer;
		answer=(double)bfs(i);
		answer=answer/N;
		answer=answer*100;
		printf("%d: %.2lf\%\n",i,answer);
	}
	return 0;
}

