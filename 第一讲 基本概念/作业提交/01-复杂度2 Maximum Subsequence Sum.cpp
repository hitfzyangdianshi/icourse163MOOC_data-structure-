/*��һ�ܵı����ҵ��

1.������к����⣺�Ǳ��ο���󽲵���4���㷨��ʵ���⣬���ڻ���Ҫ��һ��Ҫ����

2.Maximum Subsequence Sum����2004���㽭��ѧ�����רҵ���и������⣬Ҫ���Ըߣ�ѡ������ʵҲ���ѣ��Ǳ��ο���󽲵����㷨�ĸ��죬��սһ�°�~

3.���ֲ��ң���Ͽκ���������������������⣬ѧ�����������һ�C���Ա�̵�����Գ���һ�¡���ֻ��Ҫ�ύһ�������������ý���main����֮�����������������C���ԵĻ������о�һ�¿κ���ڶ��ַ����������
*/
#include<bits/stdc++.h>
using namespace std;
//***   2.Maximum Subsequence Sum����2004���㽭��ѧ�����רҵ���и������⣬Ҫ���Ըߣ�ѡ������ʵҲ���ѣ��Ǳ��ο���󽲵����㷨�ĸ��죬��սһ�°�~
int K;
int main()
{
	cin>>K;
	int a[10001],i,head=0,tail=K-1,thisvalue=0,max=-1,headtemp=0;
	for(i=0;i<K;i++) cin>>a[i];
	for(i=0;i<K;i++)
	{
		thisvalue+=a[i];
		if(thisvalue>max) 
		{
			max=thisvalue;
			head=headtemp;
			tail=i;
		}
		else if(thisvalue<0) 
		{
			thisvalue=0;
			headtemp=i+1;
		}
	}
	if(max<0)max=0;
	cout<<max<<" "<<a[head]<<" "<<a[tail];
	return 0;
}
