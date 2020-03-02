/*1. ���������������еĺϲ� ����һ��C���Ժ�������⣬ѵ�������������������������C��̵Ļ���һ��Ҫ����
02-���Խṹ1 ���������������еĺϲ� (15��)
����Ҫ��ʵ��һ�������������������ʾ�ĵ����������кϲ�Ϊһ���ǵݼ����������С�
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

List Read(); /* ϸ���ڴ˲��� */
void Print( List L ); /* ϸ���ڴ˲������������NULL */

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

/* ��Ĵ��뽫��Ƕ������ */
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
