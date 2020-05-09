//10-排序5 PAT Judge
//https://pintia.cn/problem-sets/1211841066264109056/problems/1251762364668882945
#include<bits/stdc++.h>
using namespace std;

struct User{
	int id;
	int score;
	int cnt;
	int visited;
	int problem[6];
}user[10001];
typedef struct User* USER;
int fullscore[5];

int cmp(const void *a, const void *b)
{
	if( ( (USER)a)->score < ((USER)b)->score )return 1;
	else if ( ((USER)a)->score > ((USER)b)->score )return -1;
	else
	{
		if(((USER)a)->cnt < ((USER)b)->cnt) return 1;
		else if ( ((USER)a)->cnt > ((USER)b)->cnt) return -1;
		else
		{
			if(((USER)a)->id<((USER)b)->id)return -1;
			else return 1;
		}
	}
}


int main()
{
	int n,k,i,j,m,uid,pid,pscore;
	cin>>n>>k>>m;
	for( i=0;i<k;i++)cin>>fullscore[i];
	for(i=0;i<n;i++)
	{
		user[i].id=i+1;
		user[i].cnt=0;
		user[i].score=0;
		user[i].visited=0;
		for(j=0;j<k;j++)user[i].problem[j]=-2;
	}
	for(i=0;i<m;i++)
	{
		cin>>uid>>pid>>pscore;
		if(user[--uid].problem[--pid]<pscore)
		{
			if(pscore>-1)user[uid].visited=1;
			user[uid].problem[pid]=pscore;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<k;j++)
		{
			if(user[i].problem[j]>0)
			{
				user[i].score+=user[i].problem[j];
				if(user[i].problem[j]==fullscore[j])user[i].cnt++;
			}
		}
	}
	qsort(user,n,sizeof(User),cmp);
	int lastscore=user[0].score,lastrank=1;
	for(i=0;i<n;i++)
	{
		if(user[i].visited==1)
		{
			if(lastscore==user[i].score)printf("%d %05d %d",lastrank,user[i].id,lastscore);
			else
			{
				lastscore=user[i].score;
				lastrank=i+1;
				printf("%d %05d %d",i+1,user[i].id,user[i].score);
			}
			for(j=0;j<k;j++)
			{
				if(user[i].problem[j]==-1)user[i].problem[j]=0;
				if(user[i].problem[j]>=0)printf(" %d",user[i].problem[j]);
				else printf(" -");
			}
			cout<<endl;
		}
	}
	return 0;
} 
