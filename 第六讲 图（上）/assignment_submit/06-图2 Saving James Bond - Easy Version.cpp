//https://pintia.cn/problem-sets/1211841066264109056/problems/1241660123425153025
#include<bits/stdc++.h>
using namespace std;

#define N 100
bool visited[N];
typedef struct Point
{
	double x,y;
}Position;
Position P[N];
int n;
double d;

void visit_init()
{
	memset(visited,false,sizeof(visited[0])*N);//for(int i=0;i<N;i++) visited[i]=false;
}

bool IsSafe(int v)
{
	return ( fabs(P[v].x)>=50-d  || fabs(P[v].y)>=50-d );
}

bool FirstJump(int v)
{
	return sqrt(P[v].x*P[v].x+P[v].y*P[v].y   )<=d+7.5;
}

bool Jump(int a,int b)
{
	return sqrt((P[a].x-P[b].x)*(P[a].x-P[b].x)+(P[a].y-P[b].y)*(P[a].y-P[b].y))<=d;
}

bool dfs(int v)
{
	bool answer=false;
	visited[v]=true;
//	cout<<v<<" ";
	if(IsSafe(v))  answer= true;
	else 	for(int i=0;i<n;i++)
		{
			if(Jump(v,i) && !visited[i]) answer=dfs(i);
			if(answer==true) break;
		}
	return answer;
}

/*void listdfs()
{
	for(int v=0;v<n;v++)
		if(!visited[v])	   dfs(v);
}*/

void save007()
{
	bool answer=false;
	for(int v=0;v<n;v++)
	{
		if(!visited[v] && FirstJump(v)) answer=dfs(v);
		if(answer==true)break;
	}
	if(answer==true)cout<<"Yes";
	else cout<<"No";
}

int main(int argc, char *argv[])
{
	cin>>n>>d;
	for(int i=0;i<n;i++)
	{
		cin>>P[i].x>>P[i].y;
	}
	visit_init();
	save007();
	
	return 0;
}




