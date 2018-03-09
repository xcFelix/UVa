//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
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

int main()
{
//	freopen("stdout.txt", "w", stdout);
//	freopen("stdin.txt", "r", stdin);
	
	int c;
	cin>>c;
	while(c--)
	{
		init();
		
		map<int, string> mp;
		int n;	//插座 
		cin>>n;
		for(int i = 1; i<=n; ++i)
		{
			string s;
			cin>>s;
			mp[i] = s;
		}
		
		int m;	//电器 
		cin>>m;
		for(int i = 1; i<=m; ++i)
		{
			string s;
			cin>>s>>s;
			mp[i+n] = s;
		}
		
		int k;	//转换器 入口和出口 
		cin>>k;
		for(int i = 1; i<=k; ++i)
		{
			string s1, s2;
			cin>>s1>>s2;
			mp[i+n+m] = s1;
			mp[i+n+m+k] = s2;
		}
		
		
		//建图
		//电器到插座 && 电器到转换器入口
		for(int i = 1; i<=m; ++i)
		{
			for(int j = 1; j<=n; ++j)
				if(mp[i+n]==mp[j]) add_edge(i+n, j, INF);
			
			for(int j = 1; j<=k; ++j)
				if(mp[i+n]==mp[j+m+n]) add_edge(i+n, j+m+n, INF);
		}
		
		//转换器入口到出口 
		for(int i = 1; i<=k; ++i) add_edge(i+m+n, i+k+m+n, INF);
		
		//转换器出口到插座
		for(int i = 1; i<=k; ++i)
			for(int j = 1; j<=n; ++j)
				if(mp[i+k+m+n]==mp[j]) add_edge(i+n+m+k, j, INF);
		
		//转换器到转换器 
		for(int i = 1; i<=k; ++i)
			for(int j = i+1; j<=k; ++j)
				if(mp[i+m+n]==mp[j+k+m+n]) add_edge(j+k+m+n, i+m+n, INF);
		//同上
		for(int i = 1; i<=k; ++i)
			for(int j = i+1; j<=k; ++j)
				if(mp[i+k+m+n]==mp[j+m+n]) add_edge(i+k+m+n, j+m+n, INF);
		
		int s = 0;
		int t = 1+k+k+m+n+1;
		for(int i = 1; i<=m; ++i) add_edge(s, i+n, 1);
		for(int i = 1; i<=n; ++i) add_edge(i, t, 1);
		
		int _max = max_flow(s, t);
		cout<<m-_max<<endl;
		if(c) cout<<endl;
	}
	
	
	return 0;
}
