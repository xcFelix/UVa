#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

const int N = 99;
vector<int> G[N];
int match[N];
bool vis[N];

void init()
{
	for(int i = 0; i<N; ++i)
	{
		G[i].clear();
	}
}

void add_edge(int u, int v)
{
	G[u].push_back(v);
	G[v].push_back(u);
}

bool dfs(int u)
{
	vis[u] = true;
	
	for(int i = 0; i<G[u].size(); ++i)
	{
		int v = G[u][i];
		int w = match[v];
		
		if(w<0 || !vis[w] && dfs(w))
		{
			match[u] = v;
			match[v] = u;
			return true;
		}
	}
	
	return false;
}

int bi_match(int n)
{
	memset(match, -1, sizeof(match));
	
	int sum = 0;
	for(int v = 1; v<=n; ++v)
	{
		if(match[v]<0)
		{
			memset(vis, false, sizeof(vis));
			
			if(dfs(v))
			{
				++sum;
			}
		}
	}
	
	return sum;
}

int main()
{
//	freopen("stdout.txt", "w", stdout);
//	freopen("stdin.txt", "r", stdin);
	
	
	map<string, int> mp;
	mp["XS"] = 1;
	mp["S"] = 2;
	mp["M"] = 3;
	mp["L"] = 4;
	mp["XL"] = 5;
	mp["XXL"] = 6;
	
	int c;
	cin>>c;
	while(c--)
	{
		init();
		
		int n, m;
		cin>>n>>m;
		
		string s;
		for(int i = 1; i<=m; ++i)
		{
			for(int j = 0; j<2; ++j)
			{
				string s;
				cin>>s;
				int delt = mp[s];
				for(int k = delt; k<=n; k+=6)
				{
					add_edge(k, n+i);
				}
			}
		}
		
		int _max = bi_match(n+m);
		if(_max==m) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	
	return 0;
}