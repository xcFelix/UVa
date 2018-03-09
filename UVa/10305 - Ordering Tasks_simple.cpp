#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int N = 109;

bool G[N][N];
bool vis[N];
vector<int> rs;

int n, m;

void dfs(int u)
{
	vis[u] = true;
	
	for(int v = 1; v<=n; ++v) if(G[u][v] && !vis[v]) dfs(v);
	
	rs.push_back(u);
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
		
		for(int u = 1; u<=n; ++u)
		{
			if(!vis[u]) dfs(u);
		}
		
		for(int i = rs.size()-1; i>=0; --i) cout<<rs[i]<<' ';
		cout<<endl;
	}
	
	
	return 0;
}