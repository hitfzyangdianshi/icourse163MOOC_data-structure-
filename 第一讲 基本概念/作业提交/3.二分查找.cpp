/*��һ�ܵı����ҵ��

1.������к����⣺�Ǳ��ο���󽲵���4���㷨��ʵ���⣬���ڻ���Ҫ��һ��Ҫ����

2.Maximum Subsequence Sum����2004���㽭��ѧ�����רҵ���и������⣬Ҫ���Ըߣ�ѡ������ʵҲ���ѣ��Ǳ��ο���󽲵����㷨�ĸ��죬��սһ�°�~

3.���ֲ��ң���Ͽκ���������������������⣬ѧ�����������һ�C���Ա�̵�����Գ���һ�¡���ֻ��Ҫ�ύһ�������������ý���main����֮�����������������C���ԵĻ������о�һ�¿κ���ڶ��ַ����������
*/
 
 //#########################%^*********************************************************8
//3.���ֲ��ң�


#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List ReadInput(); /* ����ʵ�֣�ϸ�ڲ���Ԫ�ش��±�1��ʼ�洢 */
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

/* ��Ĵ��뽫��Ƕ������ */
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

