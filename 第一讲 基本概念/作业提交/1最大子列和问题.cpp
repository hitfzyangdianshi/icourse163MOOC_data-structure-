/*��һ�ܵı����ҵ��

1.������к����⣺�Ǳ��ο���󽲵���4���㷨��ʵ���⣬���ڻ���Ҫ��һ��Ҫ����

2.Maximum Subsequence Sum����2004���㽭��ѧ�����רҵ���и������⣬Ҫ���Ըߣ�ѡ������ʵҲ���ѣ��Ǳ��ο���󽲵����㷨�ĸ��죬��սһ�°�~

3.���ֲ��ң���Ͽκ���������������������⣬ѧ�����������һ�C���Ա�̵�����Գ���һ�¡���ֻ��Ҫ�ύһ�������������ý���main����֮�����������������C���ԵĻ������о�һ�¿κ���ڶ��ַ����������
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
