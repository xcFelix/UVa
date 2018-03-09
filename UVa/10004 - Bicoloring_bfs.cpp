#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int N = 209;
vector<int> G[N];
int color[N];

bool bfs()
{
	color[0] = 1;
	
	queue<int> Q;
	Q.push(0);
	while(Q.size())
	{
		int u = Q.front(); Q.pop();
		
		for(int i = 0; i<G[u].size(); ++i)
		{
			if(color[G[u][i]]==color[u]) return false;
			if(!color[G[u][i]])
			{
				color[G[u][i]] = -color[u];
				Q.push(G[u][i]);
			}
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
		
		if(bfs()) cout<<"BICOLORABLE."<<endl;
		else cout<<"NOT BICOLORABLE."<<endl;
	}
	
	
	return 0;
}