#include <iostream>
#include <set>
#include <map>
#include <cctype>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	set<string> st;
	string s;
	while(cin>>s && s[0]!=':') st.insert(s);
	
	multimap<string, string> mp;
	while(getline(cin, s))
	{
		for(int i = 0; i<s.size(); ++i) s[i] = tolower(s[i]);
		
		for(int lo = 0; lo<s.size(); ++lo)
		{
			if(!isalpha(s[lo])) continue;
			
			int hi = lo+1;
			while(hi<s.size() && isalpha(s[hi])) ++hi;
			
			string s2(s, lo, hi-lo);
			if(st.count(s2)==0)
			{
				for(int i = 0; i<s2.size(); ++i) s2[i] = toupper(s2[i]);
				
				string s3(s);
				s3.replace(lo, hi-lo, s2);
			
				mp.insert(make_pair(s2, s3));
			}
			
			lo = hi;
		}
	}
	
	for(map<string, string>::iterator it = mp.begin(); it!=mp.end(); ++it)
	cout<<it->second<<endl;

	
	return 0;
}