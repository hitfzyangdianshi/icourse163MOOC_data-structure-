/*3.  Reversing Linked List 根据某大公司笔试题改编的2014年春季PAT真题，不难，可以尝试；
02-线性结构3 Reversing Linked List (25分)
Given a constant K and a singly linked list L, you are supposed to reverse the links of every K elements on L. For example, given L being 1→2→3→4→5→6, if K=3, then you must output 3→2→1→6→5→4; if K=4, you must output 4→3→2→1→5→6.

Input Specification:
Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (≤10
?5
?? ) which is the total number of nodes, and a positive K (≤N) which is the length of the sublist to be reversed. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Data Next

      
    
where Address is the position of the node, Data is an integer, and Next is the position of the next node.

Output Specification:
For each case, output the resulting ordered linked list. Each node occupies a line, and is printed in the same format as in the input.

Sample Input:
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

      
    
Sample Output:
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1

https://pintia.cn/problem-sets/1211841066264109056/problems/1231458941036285954
*/

#include <bits/stdc++.h>
using namespace std;

typedef struct Node *ListNode;
struct Node
{
	int data;
	int nextaddr;
};
typedef struct Node List;

List node[100001];

int main()
{
	int firstaddr, N,K,i,j,temp1,temp2,temp3;
	scanf("%d %d %d",&firstaddr,&N,&K);
	for(i=0;i<N;i++)
	{
		scanf("%d %d %d",&temp1,&temp2,&temp3);
		node[temp1].data=temp2;
		node[temp1].nextaddr=temp3;
	}
	int memaddr[K+1],tempaddr=firstaddr;
	for(i=1;i<=N/K;i++)
	{
		for(j=1;j<=K;j++)
		{
			memaddr[j]=tempaddr;
			tempaddr=node[tempaddr].nextaddr;
			if(tempaddr==-1 && j<K) break;
		}
		if (tempaddr!=-1 || (tempaddr==-1 && j==K+1)) for(j=K;j>=1;j--) 
		                  {
						      if(j==K && i!=1) printf("%05d\n",memaddr[j]);
							  if(j>1)printf("%05d %d %05d\n",memaddr[j],node[memaddr[j]].data,memaddr[j-1]);
	        				  else printf("%05d %d ",memaddr[j],node[memaddr[j]].data);
						  }
		else
		{
			printf("%05d\n",memaddr[1]);
			for(auto int k=1;k<=j;k++)
			{
				if(k<j)printf("%05d %d %05d\n",memaddr[k],node[memaddr[k]].data,node[memaddr[k]].nextaddr);
	        	else printf("%05d %d %d\n",memaddr[k],node[memaddr[k]].data,node[memaddr[k]].nextaddr);
			}
			return 0;
		}
	}
	tempaddr==-1?printf("%d\n",tempaddr):printf("%05d\n",tempaddr);
	for(i= (N/K) *K +1;i<=N;i++)
	{
	//	if(tempaddr==-1) break;
		if(node[tempaddr].nextaddr !=-1) printf("%05d %d %05d\n",tempaddr,node[tempaddr].data,node[tempaddr].nextaddr);
		else  printf("%05d %d %d\n",tempaddr,node[tempaddr].data,node[tempaddr].nextaddr);
		tempaddr=node[tempaddr].nextaddr;
	}
	
	
	return 0;
}

