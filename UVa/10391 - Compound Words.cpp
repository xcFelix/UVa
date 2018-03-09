#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	set<string> st;
	
	string s;
	while(cin>>s)
	{
		st.insert(s);
	}
	
	for(set<string>::iterator it = st.begin(); it!=st.end(); ++it)
	{
		string s = *it;
		for(int i = 1; i<s.size(); ++i)
		{
			string sub1 = s.substr(0, i);
			string sub2 = s.substr(i);
			
			if(st.count(sub1) && st.count(sub2))
			{
				cout<<s<<endl;
				break;
			}
		}
	}
	
	
	return 0;
}