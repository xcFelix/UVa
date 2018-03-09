#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

const int N = 30009;
int par[N];

void init(int n)
{
	for(int i = 0; i<=n; ++i) par[i] = i;
}

int find(int x)
{
	if(par[x]==x) return x;
	return par[x] = find(par[x]);
}

void unite(int a, int b)
{
	int x = find(a);
	int y = find(b);
	
	if(x!=y) par[x] = y;
}

int main()
{
//	freopen("stdout.txt", "w", stdout);
//	freopen("stdin.txt", "r", stdin);
	
	
	int c;
	cin>>c;
	while(c--)
	{
		int n, m;
		cin>>n>>m;
		
		init(n);
		
		for(int i = 0; i<m; ++i)
		{
			int a, b;
			cin>>a>>b;
			unite(a, b);
		}
		
		map<int, int> mp;
		for(int i = 1; i<=n; ++i) mp[find(i)]++;
		map<int, int>::iterator it;
		int _max = 0;
		for(it = mp.begin(); it!=mp.end(); ++it)
		{
			_max = max(_max, it->second);
		}
		
		cout<<_max<<endl;
	}
	
	
	return 0;
}