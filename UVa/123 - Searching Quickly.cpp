#include <iostream>
#include <set>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

struct T{
	string s1, s2;
	T(const string& _s1, const string& _s2)
	:s1(_s1), s2(_s2) {}
	
	bool operator<(const T& t) const
	{
		return s1<t.s1;
	}
};

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	set<string> st;
	string s;
	while(cin>>s && s[0]!=':') st.insert(s);
	
	vector<T> v;
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
			
				v.push_back(T(s2, s3));
			}
			
			lo = hi;
		}
	}
	
	stable_sort(v.begin(), v.end());
	for(int i = 0; i<v.size(); ++i) cout<<v[i].s2<<endl;

	
	return 0;
}