//11-散列3 QQ帐户的申请与登陆
//https://pintia.cn/problem-sets/1211841066264109056/problems/1254370586245386242
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,i;
	map<string,string>qq;
	cin>>n;
	for(i=0;i<n;i++)
	{
		char c;
		string id,pw;
		cin>>c>>id>>pw;
		if(c=='L')
		{
			auto p=qq.find(id);
			if(p==qq.end()) cout<<"ERROR: Not Exist"<<endl;
			else if(p->second==pw) cout<<"Login: OK"<<endl;
			else cout<<"ERROR: Wrong PW"<<endl;
		}
		else if(c=='N')
		{
			auto it=qq.insert(pair<string,string>(id,pw));
			if(it.second==true) cout<<"New: OK"<<endl;
			else  cout<<"ERROR: Exist"<<endl;
		}
	}
	return 0;
}
