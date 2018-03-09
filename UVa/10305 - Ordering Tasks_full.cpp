#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int N = 109;

bool G[N][N];
bool vis[N];
vector<int> rs;

int n, m;

bool dfs(int u)
{
	vis[u] = -1;
	
	for(int v = 1; v<=n; ++v)
	{
		if(G[u][v])
		{
			if(vis[v]<0) return false;
			if(!vis[v])
			{
				if(dfs(v)==false) return false;
			}
		}
	}
	
	vis[u] = true;
	rs.push_back(u);
	return true;
}

bool TP()
{
	for(int u = 1; u<=n; ++u)
	{
		if(!vis[u])
		{
			if(dfs(u)==false) return false;
		}
	}
	
	return true;
}

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	while(cin>>n>>m && (n || m))
	{
		memset(G, false, sizeof(G));
		memset(vis, false, sizeof(vis));
		rs.clear();
		
		for(int i = 0; i<m; ++i)
		{
			int a, b;
			cin>>a>>b;
			G[a][b] = true;
		}
		
		TP();
		
		for(int i = rs.size()-1; i>=0; --i) cout<<rs[i]<<' ';
		cout<<endl;
	}
	
	
	return 0;
}