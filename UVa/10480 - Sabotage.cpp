//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct E
{
	int to;
	int cap;
	int rev;
	bool real;

	E(const int &_to, const int &_cap, const int &_rev, const bool &_real)
		: to(_to), cap(_cap), rev(_rev), real(_real) {}
};

const int INF = 1<<29;
const int N = 400 + 10;
vector<E> G[N];
int level[N];
int iter[N];
bool con[N][N];
bool arrive[N];

void init()
{
	for(int i = 0; i<N; i++)
	{
		G[i].clear();
	}
}

void add_edge(int from, int to, int cap)
{
	G[from].push_back(E(to, cap, G[to].size(), true));
	G[to].push_back(E(from, 0, G[from].size()-1, false));
}

void bfs(int s)
{
	memset(level, -1, sizeof(level));
	level[s] = 0;
	
	queue<int> Q;
	Q.push(s);
	while(Q.size())
	{
		int v = Q.front(); Q.pop();
		for(int i = 0; i<G[v].size(); i++)
		{
			E &e = G[v][i];
			if(e.cap>0 && level[e.to]<0)
			{
				level[e.to] = level[v]+1;
				Q.push(e.to);
			}
		}
	}
}

int dfs(int v, int t, int f)
{
	if(v==t) return f;
	for(int &i = iter[v]; i<G[v].size(); i++)
	{
		E &e = G[v][i];
		if(e.cap>0 && level[v]<level[e.to])
		{
			int d = dfs(e.to, t, min(f, e.cap));
			if(d>0)
			{
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}

int max_flow(int s, int t)
{
	int flow = 0;
	while(true)
	{
		bfs(s);
		if(level[t]<0) return flow;
		
		int f;
		memset(iter, 0, sizeof(iter));
		while((f = dfs(s, t, INF))>0) flow+=f;
	}
}

void _dfs(int v)
{
	arrive[v] = true;
	for(int i = 0; i<G[v].size(); i++)
	{
		E &e = G[v][i];
		if(e.real && e.cap && !arrive[e.to]) _dfs(e.to);
	}
}

int main()
{
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	
	int n, m;
	while(cin>>n>>m && !(n==0 && m==0))
	{
		init();
		
		memset(con, false, sizeof(con));
		for(int i = 1; i<=m; i++)
		{
			int a, b, cap;
			cin>>a>>b>>cap;
			con[a][b] = true;
			con[b][a] = true;
			add_edge(a, b, cap);
			add_edge(b, a, cap);
		}
		int s = 1;
		int t = 2;
		max_flow(s, t);
		
		memset(arrive, false, sizeof(arrive));
		_dfs(s);
		for(int v = 1; v<n; v++)
		{
			for(int u = v+1; u<=n; u++)
			if(arrive[v]!=arrive[u] && con[u][v]) cout<<v<<" "<<u<<endl;
		}
		cout<<endl;
	}
	
	
	return 0;
}
