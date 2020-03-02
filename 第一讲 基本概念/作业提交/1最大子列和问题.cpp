/*第一周的编程作业：

1.最大子列和问题：是本次课最后讲到的4种算法的实验题，属于基本要求，一定要做；

2.Maximum Subsequence Sum：是2004年浙江大学计算机专业考研复试真题，要求略高，选做。其实也不难，是本次课最后讲到的算法的改造，挑战一下吧~

3.二分查找：配合课后讨论题给出这道函数填空题，学有余力、并且会C语言编程的你可以尝试一下。你只需要提交一个函数，而不用交如main函数之类的其他函数。不会C语言的话，就研究一下课后关于二分法的讨论题吧
*/
#include<bits/stdc++.h>
using namespace std;
	
long K;

int main()
{
	cin>>K;
	long a[100000],i;
	for(i=0;i<K;i++) cin>>a[i];
	long thisvalue=0,max=0;
	for(i=0;i<K;i++)
	{
		thisvalue+=a[i];
		if(thisvalue>max) max=thisvalue;
		else if(thisvalue<0) thisvalue=0;
	}
	cout<<max;
	return 0;
}
