/*2. 一元多项式的乘法与加法运算 在“小白专场”里，我们会详细讨论C语言实现的方法。对于不会C语言而不能做第1题的同学，本题一定要做；
02-线性结构2 一元多项式的乘法与加法运算 (20分)
设计函数分别求两个一元多项式的乘积与和。

输入格式:
输入分2行，每行分别先给出多项式非零项的个数，再以指数递降方式输入一个多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。

输出格式:
输出分2行，分别以指数递降方式输出乘积多项式以及和多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。零多项式应输出0 0。
https://pintia.cn/problem-sets/1211841066264109056/problems/1231458941036285953
*/

#include <bits/stdc++.h>
using namespace std;

typedef struct PolyNode *Polynomial;
struct PolyNode {
    int coef;
    int expon;
    Polynomial link; 
};
//typedef Polynomial List;

void Attach( int c, int e, Polynomial *pRear )
{
    Polynomial P;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->coef = c; /* 对新结点赋值 */
    P->expon = e;
    P->link = NULL;
    (*pRear)->link = P;
    *pRear = P; /* 修改pRear值 */
}


void PrintPoly(Polynomial P)
{
	int flag=0;
	if(!P)
	{
		printf("0 0\n");
		return;
	}
	while(P)
	{
	    if(!flag) flag=1;
		else printf(" ");
		printf("%d %d",P->coef,P->expon);
		P=P->link;	
	} 
	printf("\n");
}


Polynomial ReadPoly()
{
	Polynomial P, Rear, t;
	int N,c,e;
    scanf("%d", &N);
    P=(Polynomial)malloc(sizeof(struct PolyNode));
    P->link=NULL;
    Rear=P;
    while ( N-- ) 
	{
        scanf("%d %d", &c, &e);
        Attach(c, e, &Rear);
    }      
    t=P;
    P=P->link;
    free(t);/* 删除临时生成的头结点 */
    return P;
}

Polynomial Add(Polynomial P1, Polynomial P2)
{
	Polynomial front,rear,temp;
	int sum;
	rear=(Polynomial)malloc(sizeof(struct PolyNode));
	front =rear;
	while (P1&&P2)
	{
		if(P1->expon > P2->expon)
		{
			Attach(P1->coef,P1->expon,&rear);
			P1=P1->link;
		}
		else if (P1->expon < P2->expon)
	    {
	    	Attach(P2->coef,P2->expon,&rear);
			P2=P2->link;
		}
		else
		{
			sum=P1->coef + P2->coef;
			if(sum!=0)Attach(sum,P1->expon,&rear);
			P1=P1->link;
			P2=P2->link;
		}
	}
	for(;P1;P1=P1->link) Attach(P1->coef,P1->expon,&rear);
	for(;P2;P2=P2->link) Attach(P2->coef,P2->expon,&rear);
	rear->link=NULL;
	free(temp);
	return front->link;
}

Polynomial Mult(Polynomial P1, Polynomial P2)
{
	Polynomial P, Rear,t1,t2,t;
	int c,e;
	if(!P1 || !P2) return NULL;
	t1=P1; t2=P2;
	P=(Polynomial)malloc(sizeof(struct PolyNode));
	P->link=NULL;
	Rear=P;
	while (t2) // 先用P1的第1项乘以P2，得到P 
	{
		Attach(t1->coef * t2->coef, t1->expon + t2->expon, &Rear);
		t2=t2->link;
	}	
	t1=t1->link;
	while(t1)
	{
		t2=P2; Rear=P;
		while (t2)
		{
			e=t1->expon + t2->expon;
			c=t1->coef * t2->coef;
			while(Rear->link && Rear->link->expon > e) Rear=Rear->link;
			if(Rear->link && Rear->link->expon ==e)
			{
				if(Rear->link->coef +c) Rear->link->coef+=c;
				else
				{
					t= Rear->link;
					Rear->link = t->link;
					free(t);
				}
			}
			else
			{
				t=(Polynomial)malloc(sizeof(struct PolyNode));
				t->coef=c; t->expon=e;
				t->link=Rear->link;
				Rear->link=t; 
				Rear=Rear->link;
			}
			t2=t2->link;
		}
		t1=t1->link;
	}
	t2=P;
	P=P->link;
	free(t2);
	return P;
}

int main()
{
    Polynomial P1, P2, PP, PS;
    P1 = ReadPoly();
    P2 = ReadPoly();
    PP = Mult( P1, P2 );
    PrintPoly( PP );
    PS = Add( P1, P2 );
    PrintPoly( PS );
    return 0;
}

