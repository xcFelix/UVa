#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 299;
vector<string> v;
bool vis[N];
int len1;
int len2;

bool cmp(const string& a, const string& b)
{
	return a.size()<b.size();
}

bool valid(const int a, const int b, const string& s)
{
	memset(vis, false, sizeof(vis));
	
	vis[a] = vis[b] = true;
	
	int sum = 2;
	for(int i = 0; i<v.size(); ++i)
	{
		if(vis[i]) continue;
		for(int j = v.size()-1; j>i; --j)
		{
			if(vis[j]) continue;
			if(v[i].size()+v[j].size() == len1+len2)
			{
				if(v[i]+v[j]==s || v[j]+v[i]==s)
				{
					vis[i] = vis[j] = true;
					sum+=2;
				}
			}
		}
	}
	
	return sum==v.size();
}

int main()
{
//	freopen("stdout.txt", "w", stdout);
//	freopen("stdin.txt", "r", stdin);
	
	int n;
	cin>>n;
	cin.get();
	cin.get();
	while(n--)
	{
		v.clear();
		while(isdigit(cin.peek()))
		{
			string s;
			cin>>s;
			v.push_back(s);
			cin.get();
		}
		cin.get();
		
		sort(v.begin(), v.end(), cmp);
		
		len1 = v[0].size();
		len2 = v[v.size()-1].size();
		
		string s;
		bool ok = false;
		for(int i = 0; v[i].size()==len1; ++i)
		{
			for(int j = v.size()-1; v[j].size()==len2; --j)
			{
				if(valid(i, j, v[i]+v[j]))
				{
					s = v[i]+v[j];
					ok = true;
					break;
				}
				
				if(valid(j, i, v[j]+v[i]))
				{
					s = v[j]+v[i];
					ok = true;
					break;
				}
			}
			
			if(ok) break;
		}
		
		cout<<s<<endl;
		if(n) cout<<endl;
	}
	
	
	return 0;
}