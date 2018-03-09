#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int N = 209;
vector<int> G[N];
int color[N];

bool dfs(int u, int c)
{
	color[u] = c;

	for(int i = 0; i<G[u].size(); ++i)
	{
		if(color[G[u][i]]==c) return false;
		if(!color[G[u][i]])
		{
			if(dfs(G[u][i], -c)==false) return false;
		}
	}
	
	return true;
}

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int n;
	while(cin>>n && n)
	{
		for(int i = 0; i<n; ++i) G[i].clear();
		memset(color, false, sizeof(color));
		
		int m;
		cin>>m;
		
		for(int i = 0; i<m; ++i)
		{
			int a, b;
			cin>>a>>b;
			
			G[a].push_back(b);
			G[b].push_back(a);
		}
		
		if(dfs(0, 1)) cout<<"BICOLORABLE."<<endl;
		else cout<<"NOT BICOLORABLE."<<endl;
	}
	
	
	return 0;
}