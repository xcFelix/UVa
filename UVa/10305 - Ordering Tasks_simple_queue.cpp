#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

const int N = 109;

vector<int> G[N];
int ind[N];
vector<int> rs;

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int n, m;
	while(cin>>n>>m && (n || m))
	{
		for(int i = 1; i<=n; ++i) G[i].clear();
		memset(ind, 0, sizeof(ind));
		rs.clear();
		
		for(int i = 0; i<m; ++i)
		{
			int a, b;
			cin>>a>>b;
			G[a].push_back(b);
			ind[b]++;
		}
		
		priority_queue< int, vector<int>, greater<int> > Q;
		for(int u = 1; u<=n; ++u)
		{
			if(ind[u]==0) Q.push(u);
		}
		
		while(Q.size())
		{
			int u = Q.top(); Q.pop();
			rs.push_back(u);
			
			for(int i = 0; i<G[u].size(); ++i) if(--ind[G[u][i]]==0) Q.push(G[u][i]);
		}
		
		for(int i = 0; i<rs.size(); ++i) cout<<rs[i]<<' ';
		cout<<endl;
	}
	
	
	return 0;
}