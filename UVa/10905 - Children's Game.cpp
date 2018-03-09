#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const string& a, const string& b)
{
	return a+b > b+a;
}

int main()
{
//	freopen("stdout.txt", "w", stdout);
//	freopen("stdin.txt", "r", stdin);
	
	
	int n;
	while(cin>>n && n)
	{
		vector<string> v;
		
		for(int i = 0; i<n; ++i)
		{
			string s;
			cin>>s;
			v.push_back(s);
		}
		
		sort(v.begin(), v.end(), cmp);
		
		for(int i = 0; i<v.size(); ++i) cout<<v[i];
		cout<<endl;
	}
	
	
	return 0;
}