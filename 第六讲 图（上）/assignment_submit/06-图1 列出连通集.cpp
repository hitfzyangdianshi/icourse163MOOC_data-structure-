//https://pintia.cn/problem-sets/1211841066264109056/problems/1241660123425153024
#include<bits/stdc++.h>
using namespace std;

#define N 11
bool visited[N];
int G[N][N],n;

void visit_init()
{
	for(int i=0;i<N;i++) visited[i]=false;
}

void dfs(int v)
{
	visited[v]=true;
	cout<<v<<" ";
	for(int i=0;i<n;i++)
		if(G[v][i] && !visited[i]) dfs(i);
}

void bfs(int v)
{
	int Queue[100];
	int first=-1,last=-1;
	Queue[++last]=v;
	visited[v]=true;
	while(first<last)
	{
		int f=Queue[++first];
		cout<<f<<" ";
		for(int i=0;i<n;i++)
			if(G[f][i] && !visited[i])
			{
				Queue[++last]=i;
				visited[i]=true;
			}
	}
}

void listdfs()
{
	for(int v=0;v<n;v++)
		if(!visited[v])
		{
			cout<<"{ ";
			dfs(v);
			cout<<"}"<<endl;
		}
}

void listbfs()
{
	for(int v=0;v<n;v++)
		if(!visited[v])
		{
			cout<<"{ ";
			bfs(v);
			cout<<"}"<<endl;
		}
}


int main(int argc, char *argv[])
{
	memset(G, 0, N *N* sizeof(G[0][0]));
	int e;
	cin>>n>>e;
	for(int i=0;i<e;i++)
	{
		int a,b;
		cin>>a>>b;
		G[a][b]=1;
		G[b][a]=1;
	}
	listdfs();
	visit_init();
	listbfs();
	
	return 0;
}



