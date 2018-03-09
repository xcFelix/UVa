#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct E{
	int to;
	int cap;
	int rev;
	
	E(const int &_to, const int &_cap, const int &_rev)
	: to(_to), cap(_cap), rev(_rev) {}
};

const int INF = 1<<29;
const int N = 109<<1;
vector<E> G[N];
int level[N];
int iter[N];

void init()
{
	for(int i = 0; i<N; ++i)
	{
		G[i].clear();
	}
}

void add_edge(int from, int to, int cap)
{
	G[from].push_back(E(to, cap, G[to].size()));
	G[to].push_back(E(from, 0, G[from].size()-1));
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
		for(int i = 0; i<G[v].size(); ++i)
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
	
	for(int &i = iter[v]; i<G[v].size(); ++i)
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
		
		memset(iter, 0, sizeof(iter));
		
		int f;
		while((f = dfs(s, t, INF))>0)
		{
			flow+=f;
		}
	}
}

int main()
{
//	freopen("stdout.txt", "w", stdout);
//	freopen("stdin.txt", "r", stdin);
	
	
	int n;
	while(cin>>n)
	{
		init();
		
		for(int i = 1; i<=n; ++i)
		{
			int cap;
			cin>>cap;
			add_edge(i, i+n, cap);
		}
		
		int m;
		cin>>m;
		for(int i = 0; i<m; ++i)
		{
			int u, v, cap;
			cin>>u>>v>>cap;
			add_edge(u+n, v, cap);
		}
		
		
		int s = 0;
		int t = n*2+1;
		
		int b, d;
		cin>>b>>d;
		for(int i = 0; i<b; ++i)
		{
			int v;
			cin>>v;
			add_edge(s, v, INF);
		}
		
		for(int i = 0; i<d; ++i)
		{
			int v;
			cin>>v;
			add_edge(v+n, t, INF);
		}
		
		cout<<max_flow(s, t)<<endl;
	}
	
	
	return 0;
}
