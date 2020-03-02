/*第一周的编程作业：

1.最大子列和问题：是本次课最后讲到的4种算法的实验题，属于基本要求，一定要做；

2.Maximum Subsequence Sum：是2004年浙江大学计算机专业考研复试真题，要求略高，选做。其实也不难，是本次课最后讲到的算法的改造，挑战一下吧~

3.二分查找：配合课后讨论题给出这道函数填空题，学有余力、并且会C语言编程的你可以尝试一下。你只需要提交一个函数，而不用交如main函数之类的其他函数。不会C语言的话，就研究一下课后关于二分法的讨论题吧
*/
 
 //#########################%^*********************************************************8
//3.二分查找：


#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}

/* 你的代码将被嵌在这里 */
Position BinarySearch( List L, ElementType X )
{
	int head=1,tail=L->Last,pos=NotFound;
	int mid=(head+tail)/2;
	while(tail-head>1)
	{
		if(X==L->Data[mid])
		{
			pos=mid;
			break;
		}
		else if (X>L->Data[mid])
		{
			head=mid;
			mid=(head+tail)/2;
			continue;
		}
		else 
		{
			tail=mid;
			mid=(head+tail)/2;
			continue;
		}
	}
	if (pos==NotFound)
	{
		if(X==L->Data[head])pos=head;
		else if (X==L->Data[tail])pos=tail;
	}
	return pos;
}

