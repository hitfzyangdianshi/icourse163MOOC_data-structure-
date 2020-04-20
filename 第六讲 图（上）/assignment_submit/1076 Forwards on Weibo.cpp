//https://pintia.cn/problem-sets/994805342720868352/problems/994805392092020736
#include<bits/stdc++.h>
using namespace std;

bool visited[1001]={false};
//int G[1001][1001]={0},
int N,L,K,layer[1001]={-1};
vector<int> G[1001];

void dfs(int v,int level)
{
	visited[v]=true;
	layer[v]=level;
	if(level!=L)
	//	for(int i=1;i<=N;i++)
	//		if(G[v][i] && (!visited[i] || layer[i]>level+1 )) dfs(i,level+1); 	
		for(int i:G[v])
				if(!visited[i] || layer[i]>level+1 ) dfs(i,level+1); 	
}

int main(int argc, char *argv[])
{
	memset(G,0,sizeof(G));
	cin>>N>>L;
	for(int i=1;i<=N;i++)
	{
		int num,a;
		cin>>num;
		for(int j=0;j<num;j++)
		{
			cin>>a;
			//G[a][i]=1;
			G[a].push_back(i);
		}
	}
	cin>>K;
	for(int i=1;i<=K;i++)
	{
		memset(layer,-1,sizeof(layer));
		memset(visited,false,sizeof(visited));
		int a,f=0;
		cin>>a;
		dfs(a,0);
		for(int j=1;j<=N;j++)
			if(layer[j]>0)f++;
		cout<<f<<endl;
	}
}


