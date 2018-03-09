#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct T{
	int to;
	int cost;
	
	T(const int& _to, const int& _cost)
	: to(_to), cost(_cost) {}
};

const int N = 20009;
vector<T> G[N];
int n, m, s, t;
int d[N];
bool r[N];
bool inq[N];

void init()
{
	for(int i = 0; i<n; ++i)
	{
		G[i].clear();
		d[i] = 1<<30;
		r[i] = false;
		inq[i] = false;
	}
}

void dfs(int u)
{
	r[u] = true;
	for(int i = 0; i<G[u].size(); ++i)
	{
		int v = G[u][i].to;
		if(!r[v]) dfs(v);
	}
}

void bfs()
{
	d[s] = 0;
	queue<int> Q;
	Q.push(s);
	inq[s] = true;
	
	while(Q.size())
	{
		int u = Q.front(); Q.pop();
		inq[u] = false;
		
		for(int i = 0; i<G[u].size(); ++i)
		{
			int v = G[u][i].to;
			int cost = G[u][i].cost;
			
			if(r[v] && d[u]+cost<d[v])
			{
				d[v] = d[u]+cost;
				
				if(!inq[v])
				{
					inq[v] = true;
					Q.push(v);
				}
			}
		}
	}
}

int main()
{
//	freopen("stdout.txt", "w", stdout);
//	freopen("stdin.txt", "r", stdin);
	
	
	int sum_case = 0;
	int c;
	cin>>c;
	while(c--)
	{
		cin>>n>>m>>s>>t;
		
		init();
		
		for(int i = 0; i<m; ++i)
		{
			int u, v, cost;
			cin>>u>>v>>cost;
			G[u].push_back(T(v, cost));
			G[v].push_back(T(u, cost));
		}
		
		dfs(t);
		
		printf("Case #%d: ", ++sum_case);
		if(!r[s]) cout<<"unreachable"<<endl;
		else
		{
			bfs();
			cout<<d[t]<<endl;
		}
	}
	
	
	return 0;
}