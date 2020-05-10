//KMP 串的模式匹配
//https://pintia.cn/problem-sets/1211841066264109056/problems/1256768759978348544
#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s1;
	cin>>s1;
	int n,i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		string s2;
		cin>>s2;
		const char* p = strstr(s1.c_str(), s2.c_str());
		if(p)printf("%s\n",p);
		else cout<<"Not Found"<<endl;
	}
	
	return 0;
}
		
		
	
