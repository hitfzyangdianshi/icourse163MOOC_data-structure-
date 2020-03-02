/*1. 两个有序链表序列的合并 这是一道C语言函数填空题，训练最基本的链表操作。如果会用C编程的话，一定要做；
02-线性结构1 两个有序链表序列的合并 (15分)
本题要求实现一个函数，将两个链表表示的递增整数序列合并为一个非递减的整数序列。
*/

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */
List Merge( List L1, List L2 )
{
	List L=( List )malloc( sizeof( struct Node ) );;
	List p,q;
	p=L1->Next;
	q=L2->Next;
	List l=L;
	while(p!=NULL && q!=NULL)
	{
		if(p->Data > q->Data)
		{
			l->Next =q;
			q =q->Next;
		}
		else
		{
			l->Next =p;
			p =p->Next;
		}
		l= l->Next;
	}
	l->Next =NULL;
	if(p!=NULL) l->Next =p;
	if(q!=NULL) l->Next =q;
	L1->Next=NULL;
    L2->Next=NULL;
    return L;
}
