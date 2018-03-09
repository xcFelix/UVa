#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct edge{
	int to;
	int cap;
	int rev;
	
	edge(const int& _to, const int& _cap, const int& _rev)
	: to(_to), cap(_cap), rev(_rev) {}
};

const int inf = 1<<30;
const int N = 59*59*2;
vector<edge> G[N];
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
	G[from].push_back(edge(to, cap, G[to].size()));
	G[to].push_back(edge(from, 0, G[from].size()-1));
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
			edge& e = G[v][i];
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
	
	for(int& i = iter[v]; i<G[v].size(); ++i)
	{
		edge& e = G[v][i];
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
		while((f = dfs(s, t, inf))>0)
		{
			flow+=f;
		}
	}
}

int dx[] = { 0, 1 };
int dy[] = { 1, 0 };

int main()
{
//	freopen("stdout.txt", "w", stdout);
//	freopen("stdin.txt", "r", stdin);
	
	
	int p;
	cin>>p;
	while(p--)
	{
		init();
		
		int s, a, b;
		cin>>s>>a>>b;
		
		int n = s*a;
		for(int i = 1; i<=s; ++i)
		{
			for(int j = 1; j<=a; ++j)
			{
				int u = (i-1)*a+j;
				add_edge(u, u+n, 1);
				
				for(int k = 0; k<2; ++k)
				{
					int _i = i+dx[k];
					int _j = j+dy[k];
					
					if(_i<=s && _j<=a)
					{
						int v = (_i-1)*a+_j;
						add_edge(u+n, v, 1);
						add_edge(v+n, u, 1);
					}
				}
			}
		}
		
		int _s = 0;
		int t = 2*n+1;
		
		for(int i = 0; i<b; ++i)
		{
			int x, y;
			cin>>x>>y;
			
			int v = (x-1)*a+y;
			add_edge(_s, v, 1);
		}
		
		for(int i = 1; i<=a; ++i)
		{
			add_edge(i+n, t, 1);
		}
		for(int i = n-a+1; i<=n; ++i)
		{
			add_edge(i+n, t, 1);
		}
		for(int i = a+1; i<=n-a; i+=a)
		{
			add_edge(i+n, t, 1);
		}
		for(int i = a+a; i<=n-a; i+=a)
		{
			add_edge(i+n, t, 1);
		}
		
		int _max = max_flow(_s, t);
		if(_max==b) cout<<"possible"<<endl;
		else cout<<"not possible"<<endl;
	}
	
	
	return 0;
}