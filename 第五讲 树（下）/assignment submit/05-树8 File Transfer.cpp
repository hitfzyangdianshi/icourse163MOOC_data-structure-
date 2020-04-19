/*https://pintia.cn/problem-sets/1211841066264109056/problems/1239025765568618497
We have a network of computers and a list of bi-directional connections. Each of these connections allows a file transfer from one computer to another. Is it possible to send a file from any computer on the network to any other?
Input Specification:
Each input file contains one test case. For each test case, the first line contains N (2��N��10?4?? ), the total number of computers in a network. Each computer in the network is then represented by a positive integer between 1 and N. Then in the following lines, the input is given in the format:
I c1 c2    
where I stands for inputting a connection between c1 and c2; or
C c1 c2    
where C stands for checking if it is possible to transfer files between c1 and c2; or
S 
where S stands for stopping this case.
Output Specification:
For each C case, print in one line the word "yes" or "no" if it is possible or impossible to transfer files between c1 and c2, respectively. At the end of each case, print in one line "The network is connected." if there is a path between any pair of computers; or "There are k components." where k is the number of connected components in this network.
Sample Input 1:
5
C 3 2
I 3 2
C 1 5
I 4 5
I 2 4
C 3 5
S   
Sample Output 1:
no
no
yes
There are 2 components.    
Sample Input 2:
5
C 3 2
I 3 2
C 1 5
I 4 5
I 2 4
C 3 5
I 1 3
C 1 5
S    
Sample Output 2:
no
no
yes
yes
The network is connected.
*/
#include<bits/stdc++.h>
using namespace std;
#define MaxSize 10001

typedef int ElementType; /*Ĭ��Ԫ�ؿ����÷Ǹ�������ʾ*/
typedef int SetName; /*Ĭ���ø������±���Ϊ��������*/
typedef ElementType SetType[MaxSize];

void Initialization(SetType S,int n)
{
	for(int i=0;i<n;i++) S[i]=-1;
}

SetName Find( SetType S, ElementType X )
{ /* Ĭ�ϼ���Ԫ��ȫ����ʼ��Ϊ-1 */
	for ( ; S[X]>=0; X=S[X] ) ;
	return X;
}

void Union( SetType S, SetName Root1, SetName Root2 )
{ /* ����Ĭ��Root1��Root2�ǲ�ͬ���ϵĸ����*/
//	S[Root2] = Root1;
	if ( S[Root2]<S[Root1] )
	{
		S[Root2] += S[Root1];
		S[Root1] = Root2;
	}
	else
	{
		S[Root1] += S[Root2];
		S[Root2] = Root1;
	}
}


void Input_connection( SetType S )
{ 
	ElementType u, v;
	SetName Root1, Root2;
	scanf("%d %d\n", &u, &v);
	Root1 = Find(S, u-1);
	Root2 = Find(S, v-1);
	if ( Root1 != Root2 )
		Union( S, Root1, Root2 );
}

void Check_connection( SetType S )
{ 
	ElementType u, v;
	SetName Root1, Root2;
	scanf("%d %d\n", &u, &v);
	Root1 = Find(S, u-1);
	Root2 = Find(S, v-1);
	if ( Root1 == Root2 ) printf("yes\n");
	else printf("no\n");
}

void Check_network( SetType S, int n )
{ 
	int i, counter = 0;
	for (i=0; i<n; i++) 
		if ( S[i] < 0 ) counter++;
	if ( counter == 1 )printf("The network is connected.\n");
	else	printf("There are %d components.\n", counter);
}


int main(int argc, char **argv)
{ 
	SetType S;
	int n;
	char in;
	scanf("%d\n", &n);
	Initialization( S, n );
	do 
	{
		scanf("%c", &in);
		switch (in) {
			case 'I': Input_connection( S ); break;
			case 'C': Check_connection( S ); break;
			case 'S': Check_network( S, n ); break;
		}
	} while ( in != 'S');
	return 0;
}









