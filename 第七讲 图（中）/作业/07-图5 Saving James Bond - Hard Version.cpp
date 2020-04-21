//https://pintia.cn/problem-sets/1211841066264109056/problems/1244270885410840577
#include<bits/stdc++.h>
using namespace std;


#define N 101
bool visited[N]={false};
typedef struct Point
{
	double x,y;
}Position;
Position P[N];
int n;
double d;
int path[N]={-1};
//int pathtag=0;

void visit_init()
{
	memset(visited,false,sizeof(visited[0])*N);//for(int i=0;i<N;i++) visited[i]=false;
}

bool IsSafe(int v)
{
	return ( fabs(P[v].x)>=50-d  || fabs(P[v].y)>=50-d );
}

int FirstJump(int v)
{
	double result2=P[v].x*P[v].x+P[v].y*P[v].y ;
//	cout<<"(int)result2\t"<<(int)result2<<endl;
//	double result=sqrt(result2  );
	return result2<=(d+7.5 )*(d+7.5)? ( (int)result2 +1) : 0;
}

bool Jump(int a,int b)
{
	return sqrt((P[a].x-P[b].x)*(P[a].x-P[b].x)+(P[a].y-P[b].y)*(P[a].y-P[b].y))<=d;
}

int cmp(const void *a, const void *b)
{
	return    FirstJump(*(int*)a)-FirstJump(*(int*)b)    ;
}

void bfs()
{
	int b[n],i;
	queue<int>q;
	for(i=0;i<n;i++)b[i]=i;
	qsort(b,n,sizeof(int),cmp);
	int last;
	for(i=0;i<n;i++)
	{
		if(FirstJump(b[i])>0)
		{
			q.push(b[i]);
			visited[b[i]]=true;
			last=b[i];
		}
	}
	int step=2,tail;
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		if(IsSafe(p))
		{
			int k=1;
			stack<int>s;
			cout<<step<<endl;
			while(k<step)
			{
				s.push(p);
				p=path[p];
				k++;
			}
			while(!s.empty())
			{
				p=s.top();
				s.pop();
				cout<<(int)P[p].x<<" "<<(int)P[p].y<<endl;
			}
			return;
		}
		for(int i=0;i<n;i++)
		{
			if(!visited[i] && Jump(p,i))
			{
				q.push(i);
				path[i]=p;
				visited[i]=true;
				tail=i;
			}
		}
		if(p==last)
		{
			step++;
			last=tail;
		}
	}
	if(q.empty())cout<<"0"<<endl;
}


int main(int argc, char *argv[])
{
	cin>>n>>d;
	for(int i=0;i<n;i++)
		cin>>P[i].x>>P[i].y;
	if(d>=42.5)
	{
		cout<<"1"<<endl;
		goto THE_END;
	}
	visit_init();
	bfs();
THE_END:	
	return 0;
}



 
