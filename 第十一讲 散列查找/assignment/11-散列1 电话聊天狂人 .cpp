//11-散列1 电话聊天狂人
//https://pintia.cn/problem-sets/1211841066264109056/problems/1254370586245386240
#include<bits/stdc++.h>
using namespace std;

typedef struct LNode *List;
struct LNode{
	string number;
	int count;
	List next;
};
typedef struct HashTbl *HashTable;
struct HashTbl{
	int size;
	List heads;
};

int Hash(int key, int p)
{
	return key%p;
}

int nextprime(int n)
{
	int p=(n%2)?n+2:n+1,i;
	while(p<=1000000)
	{
		for(i=(int)sqrt(p);i>2;i--)
			if(p%i!=0)break;
		if(i==2)break;
		p=p+2;
	}
	return p;
}

HashTable createtable(int tablesize)
{
	HashTable H;
	H=(HashTable)malloc(sizeof(struct HashTbl));
	H->size=nextprime(tablesize);
	H->heads=new LNode[H->size];
	for(int i=0;i< H->size;i++)
	{
		H->heads[i].next=NULL;
		H->heads[i].count=0;
	}
	return H;
}

List find(HashTable h,string key)
{
	List p;
	int pos=Hash(atoi(key.substr(6,5).c_str()),h->size);
	p=h->heads[pos].next;
	while(p&&key!=p->number) p=p->next;
	return p;
}

bool insert(HashTable h,string key)
{
	List p,newcell;
	int pos;
	p=find(h,key);
	if(!p)
	{
		newcell=new LNode();
		newcell->number=key;
		newcell->count=1;
		pos=Hash(atoi(key.substr(6,5).c_str()),h->size);
		newcell->next=h->heads[pos].next;
		h->heads[pos].next=newcell;
		return true;
	}
	else
	{
		p->count++;
		return false;
	}
}

void scanout(HashTable h)
{
	List p;
	int maxcnt=0,pcnt=0,i;
	string minphone;
	for(i=0;i<h->size;i++)
	{
		p=h->heads[i].next;
		while(p)
		{
			if(maxcnt<p->count)
			{
				maxcnt=p->count;
				minphone=p->number;
				pcnt=1;
			}
			else if(p->count==maxcnt)
			{
				if(p->number<minphone)minphone=p->number;
				pcnt++;
			}
			p=p->next;
		}
	}
	cout<<minphone<<" "<<maxcnt;
	if(pcnt>1)cout<<" "<<pcnt;
}


int main()
{
	HashTable h;
	int n,i;
	string key;
	cin>>n;
	h=createtable(n*2);
	for(i=0;i<n;i++)
	{
		cin>>key;
		insert(h,key);
		cin>>key;
		insert(h,key);
	}
	scanout(h);
	return 0;
}






