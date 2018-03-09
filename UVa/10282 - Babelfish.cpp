#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	map<string, string> mp;
	while(cin.peek()!='\n')
	{
		string s1, s2;
		cin>>s1>>s2;
		cin.get();
		
		mp[s2] = s1;
	}
	
	string s;
	while(cin>>s)
	{
		map<string, string>::iterator it = mp.find(s);
		if(it!=mp.end()) cout<<it->second<<endl;
		else cout<<"eh"<<endl;
	}
	
	
	return 0;
}