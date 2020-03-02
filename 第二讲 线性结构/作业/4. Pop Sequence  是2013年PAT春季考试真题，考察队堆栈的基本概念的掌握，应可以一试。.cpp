/*4. Pop Sequence  是2013年PAT春季考试真题，考察队堆栈的基本概念的掌握，应可以一试。
02-线性结构4 Pop Sequence (25分)
Given a stack which can keep M numbers at most. Push N numbers in the order of 1, 2, 3, ..., N and pop randomly. You are supposed to tell if a given sequence of numbers is a possible pop sequence of the stack. For example, if M is 5 and N is 7, we can obtain 1, 2, 3, 4, 5, 6, 7 from the stack, but not 3, 2, 1, 7, 5, 6, 4.

Input Specification:
Each input file contains one test case. For each case, the first line contains 3 numbers (all no more than 1000): M (the maximum capacity of the stack), N (the length of push sequence), and K (the number of pop sequences to be checked). Then K lines follow, each contains a pop sequence of N numbers. All the numbers in a line are separated by a space.

Output Specification:
For each pop sequence, print in one line "YES" if it is indeed a possible pop sequence of the stack, or "NO" if not.

Sample Input:
5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2

      
    
Sample Output:
YES
NO
NO
YES
NO

https://pintia.cn/problem-sets/1211841066264109056/problems/1231458941036285955
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int M,N,K,i,j,k;
	cin>>M>>N>>K;
	int stackseq[M],dataseq[N];
	for(int thenumberofdata=0;thenumberofdata<K;thenumberofdata++)
	{
		memset(stackseq,0,sizeof(stackseq[0]*M));
		if(M==0){cout<<"NO"<<endl;continue;	}
		for(i=0;i<N;i++)cin>>dataseq[i];
		i=0,j=0;
		stackseq[0]=1;
		k=1;
		while(1)
		{
			if(dataseq[j]==stackseq[i])
			{
				if(i==0)
				{
					k++;
				    stackseq[i]=k;    
				}
				else	
				{
				    i--;
				}
				j++;
				if(j>=N)
				{
					cout<<"YES"<<endl;
					break;
				}	
			}
			else
			{
				i++;
				k++;
				if(i>=M)
				{
					cout<<"NO"<<endl;
					break;
				}
				stackseq[i]=k;
		//		k++;
				if(k>N)
				{
					cout<<"NO"<<endl;
					break;
				}	   
			}
		}	
	}
	return 0;
}
