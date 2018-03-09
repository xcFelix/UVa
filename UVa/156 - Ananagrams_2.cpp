#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

struct T{
	string s1, s2;
	
	T(const string& _s1, const string& _s2)
	:s1(_s1), s2(_s2) {}
	
	bool operator<(const T& t) const
	{
		return s2<t.s2;
	}
};

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	map<string, int> mp;
	set<T> st;
	while(true)
	{
		string s1;
		cin>>s1;
		if(s1[0]=='#') break;
		string s2(s1);
		
		for(int i = 0; i<s1.size(); ++i) s1[i] = tolower(s1[i]);
		sort(s1.begin(), s1.end());
		
		++mp[s1];
		st.insert(T(s1, s2));
	}
	
	for(set<T>::iterator it = st.begin(); it!=st.end(); ++it)
	{
		if(mp[it->s1]==1) cout<<it->s2<<endl;
	}
	
	return 0;
}