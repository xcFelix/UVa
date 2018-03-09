#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

const int N = 109;
int G[N][N];
int d[N];
bool r[N];
bool inq[N];

void dfs(int u)
{
	r[u] = true;
	
	for(int v = 0; v<N; ++v)
	{
		if(G[u][v] && !r[v])
		{
			dfs(v);
		}
	}
}

void bfs()
{
	d[0] = 0;
	queue<int> Q;
	Q.push(0);
	inq[0] = true;
	
	while(Q.size())
	{
		int u = Q.front(); Q.pop();
		inq[u] = false;
		
		if(u==0)
		{
			for(int v = 0; v<N; ++v)
			{
				if(r[v] && G[u][v] && d[u]+G[u][v]<d[v])
				{
					d[v] = d[u]+G[u][v];
					if(!inq[v])
					{
						Q.push(v);
						inq[v] = true;
					}
				}
			}
		}
		else
		{
			for(int v = 0; v<N; ++v)
			{
				if(r[v] && G[u][v] && d[u]+G[u][v]+60<d[v])
				{
					d[v] = d[u]+G[u][v]+60;
					if(!inq[v])
					{
						Q.push(v);
						inq[v] = true;
					}
				}
			}
		}
	}
}

int main()
{
//	freopen("stdout.txt", "w", stdout);
//	freopen("stdin.txt", "r", stdin);
	
	
	int n, k;
	while(cin>>n>>k)
	{
		memset(G, 0, sizeof(G));
		memset(r, false, sizeof(r));
		memset(inq, false, sizeof(inq));
		for(int i = 0; i<N; ++i) d[i] = 1<<30;
		
		vector<int> v1;
		for(int i = 0; i<n; ++i)
		{
			int a;
			cin>>a;
			v1.push_back(a);
		}
		cin.get();
		
		for(int i = 0; i<n; ++i)
		{
			vector<int> vv;
			
			string s;
			getline(cin, s);
			stringstream ss(s);
			int a;
			while(ss>>a)
			{
				if(a>=0) vv.push_back(a);
			}
			
			for(int j = 0; j<vv.size()-1; ++j)
			{
				for(int k = j+1; k<vv.size(); ++k)
				{
					int u = vv[j];
					int v = vv[k];
					int t = (v-u)*v1[i];
					
					if(!G[u][v] || G[u][v]>t) G[u][v] = t;
					if(!G[v][u] || G[v][u]>t) G[v][u] = t;
				}
			}
		}
		
		dfs(k);
		
		if(!r[0]) cout<<"IMPOSSIBLE"<<endl;
		else
		{
			bfs();
			
			cout<<d[k]<<endl;
		}
	}
	
	
	return 0;
}