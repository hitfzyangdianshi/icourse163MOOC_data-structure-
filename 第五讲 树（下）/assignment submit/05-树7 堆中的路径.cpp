/*https://pintia.cn/problem-sets/1211841066264109056/problems/1239025765568618496
将一系列给定数字插入一个初始为空的小顶堆H[]。随后对任意给定的下标i，打印从H[i]到根结点的路径。
输入格式:
每组测试第1行包含2个正整数N和M(≤1000)，分别是插入元素的个数、以及需要打印的路径条数。下一行给出区间[-10000, 10000]内的N个要被插入一个初始为空的小顶堆的整数。最后一行给出M个下标。
输出格式:
对输入中给出的每个下标i，在一行中输出从H[i]到根结点的路径上的数据。数字间以1个空格分隔，行末不得有多余空格。
输入样例:
5 3
46 23 26 24 10
5 4 3  
输出样例:
24 23 10
46 23 10
26 10    
作者: 陈越
单位: 浙江大学
时间限制: 400 ms
内存限制: 64 MB
*/
#include<bits/stdc++.h>
using namespace std;

#define MAXN 1001
#define MINH -10001

int H[MAXN], size;

void Create ()
{
	size = 0;
	H[0] = MINH;
		/*设置“岗哨”*/
}

void Insert ( int X )
{
/* 将X插入H。这里省略检查堆是否已满的代码 */
	int i;
	for (i=++size; H[i/2] > X; i/=2)
		H[i] = H[i/2];
	H[i] = X;
}

int main(int argc, char **argv)
{
	int n, m, x, i, j;
	scanf("%d %d", &n, &m);
	Create(); /* 堆初始化 */
	for (i=0; i<n; i++) 
	{ /*以逐个插入方式建堆 */
		scanf("%d", &x);
		Insert(x);
	}
	for (i=0; i<m; i++) 
	{
		scanf("%d", &j);
		printf("%d", H[j]);
		while (j>1) 
		{ /*沿根方向输出各结点*/
			j /= 2;
			printf(" %d", H[j]);
		}
		printf("\n");
	}
	return 0;
}









