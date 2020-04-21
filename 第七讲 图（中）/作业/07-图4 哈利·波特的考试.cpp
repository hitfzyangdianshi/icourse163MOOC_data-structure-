//https://pintia.cn/problem-sets/1211841066264109056/problems/1244270885410840576
#include<iostream>
#include<cstdlib>
#include<climits>
using namespace std;

#define MaxVertexNum 101
#define INFINITY INT_MAX/2-1
typedef int Vertex;
typedef int WeightType;
//typedef char DataType;

typedef struct ENode *PtrToENode;//边 
struct ENode{
	Vertex v1,v2;//有向 
	WeightType weight;
};
typedef PtrToENode Edge;

typedef struct GNode *PtrToGNode;//结点 
struct GNode{
	int Nv;
	int Ne;
	WeightType G[MaxVertexNum][MaxVertexNum];
//	DataType Data[MaxVertexNum];
};
typedef PtrToGNode MGraph;

MGraph CreateGraph(int VertexNum)
{
//	cout<<"CreateGraph\n";
	Vertex V,W;
	MGraph Graph;
	Graph=(MGraph)malloc(sizeof(struct GNode));
	Graph->Nv=VertexNum;
	Graph->Ne=0;
	for(V=0;V<Graph->Nv;V++)
		for(W=0;W<Graph->Nv;W++)
			Graph->G[V][W]=INFINITY;
	return Graph; 
}

void InsertEdge(MGraph Graph, Edge E)
{
	Graph->G[E->v1][E->v2]=E->weight;
	Graph->G[E->v2][E->v1]=E->weight;
//	cout<<"InsertEdge\n";
}

MGraph BuildGraph()
{
//	cout<<"BuildGraph\n";
	MGraph Graph;
	Edge E;
	int Nv,i;
	scanf("%d",&Nv);//cin>>Nv;
	Graph=CreateGraph(Nv);
	scanf("%d",&(Graph->Ne));//cin>>(Graph->Ne);
	if(Graph->Ne!=0)
	{
		E=(Edge)malloc(sizeof(struct ENode));
		for(i=0;i<Graph->Ne;i++)
		{
			scanf("%d %d %d",&(E->v1),&(E->v2),&(E->weight));//cin>> (E->v1)>>(E->v2)>>(E->weight);
			E->v1--;
			E->v2--;
			InsertEdge(Graph,E);
		}
	}
//	cout<<"BuildGraph end\n";
	return Graph;
}

bool Floyd(MGraph Graph,WeightType D[][MaxVertexNum])
{
//	cout<<"FLOYD\n";
	Vertex i,j,k;
	for(i=0;i<Graph->Nv;i++)
		for(j=0;j<Graph->Nv;j++)
		{
				D[i][j]=Graph->G[i][j];
	//			cout<<D[i][j]<<"\t"<<Graph->G[i][j]<<endl;
		}
//	cout<<"floyd step1 end"<<endl;
	for(k=0;k<Graph->Nv;k++)
		for(i=0;i<Graph->Nv;i++)
			for(j=0;j<Graph->Nv;j++	)
				if(D[i][k]+D[k][j]<D[i][j])
				{
					D[i][j]=D[i][k]+D[k][j];
			//		cout<<D[i][j]<<"\tijk"<<endl;
				}
			
//	cout<<"FLOYD end\n";	
	return true;	
}

WeightType FindMaxDist(WeightType D[][MaxVertexNum],Vertex i,int N)
{
//	cout<<"FindMaxDist\n";
	WeightType MaxDist=0;
	Vertex j;
	for(j=0;j<N;j++)
		if(i!=j &&D[i][j]>MaxDist) MaxDist=D[i][j];
//	cout<<"FindMaxDist end\n";
	return MaxDist;
}


void FindAnimal(MGraph Graph)
{
//	cout<<"FindAnimal\n";
	WeightType D[MaxVertexNum][MaxVertexNum], MaxDist, MinDist;
	Vertex Animal, i;
	Floyd (Graph,D);
	MinDist=INFINITY;
	for(i=0;i<Graph->Nv;i++) 
	{
		MaxDist=FindMaxDist(D,i,Graph->Nv);
		if(MaxDist==INFINITY)
		{
			cout<<"0"<<endl;
			return;
		} 
		if(MinDist>MaxDist)
		{
			MinDist=MaxDist;
			Animal=i+1;
		}
	}
	cout<<Animal<<" "<<MinDist<<endl;
}

int main(int argc, char *argv[])
{
	MGraph G=BuildGraph();
	FindAnimal(G);
	
	
	return 0;
} 
