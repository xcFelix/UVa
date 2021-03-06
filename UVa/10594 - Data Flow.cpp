#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct edge{
	int to;
	int cap;
	int rev;
	long long cost;
	
	edge(const int& _to, const int& _cap, const int& _rev, const long long& _cost)
	: to(_to), cap(_cap), rev(_rev), cost(_cost) {}
};

const long long inf = 1LL<<60;
const int N = 109;
vector<edge> G[N];
long long d[N];
int prev[N], pree[N];
bool inq[N];
int n; //bfs使用

void init()
{
	for(int i = 0; i<N; ++i)
	{
		G[i].clear();
	}
}

void add_edge(int from, int to, int cap, long long cost)
{
	G[from].push_back(edge(to, cap, G[to].size(), cost));
	G[to].push_back(edge(from, 0, G[from].size()-1, -cost));
}

void bfs(int s)
{
	memset(inq, false, sizeof(inq));
	fill(d+1, d+1+n, inf);
	
	d[s] = 0;
	inq[s] = true;
	queue<int> Q;
	Q.push(s);
	
	while(Q.size())
	{
		int v = Q.front(); Q.pop();
		inq[v] = false;
		
		for(int i = 0; i<G[v].size(); ++i)
		{
			edge& e = G[v][i];
			if(e.cap>0 && d[v]+e.cost < d[e.to])
			{
				d[e.to] = d[v]+e.cost;
				prev[e.to] = v;
				pree[e.to] = i;
				
				if(!inq[e.to])
				{
					inq[e.to] = true;
					Q.push(e.to);
				}
			}
		}
	}
}

long long min_cost_flow(int s, int t, int f)
{
	long long sum = 0;
	
	while(f)
	{
		bfs(s);
		if(d[t]==inf) return -1;
		
		int _min = f;
		for(int v = t; v!=s; v = prev[v])
		{
			_min = min(_min, G[prev[v]][pree[v]].cap);
		}
		f -= _min;
		sum += _min*d[t];
		
		for(int v = t; v!=s; v = prev[v])
		{
			edge& e = G[prev[v]][pree[v]];
			e.cap -= _min;
			G[e.to][e.rev].cap += _min;
		}
	}
	
	return sum;
}

int main()
{
//	freopen("stdin.txt", "r", stdin);
//	freopen("stdout.txt", "w", stdout);
	
	
//	int n, m;
	int m;
	while(cin>>n>>m)
	{
		init();
		
		for(int i = 1; i<=m; ++i)
		{
			int from, to;
			long long cost;
			cin>>from>>to>>cost;
			
			add_edge(from, to, -1, cost);
			add_edge(to, from, -1, cost);
		}
		
		int flow, cap;
		cin>>flow>>cap;
		
		for(int i = 1; i<=n; ++i)
		{
			for(int j = 0; j<G[i].size(); ++j)
			{
				if(G[i][j].cap<0)
				{
					G[i][j].cap = cap;
				}
			}
		}
		
		long long cost = min_cost_flow(1, n, flow);
		if(cost>=0)
		{
			cout<<cost<<endl;
		}
		else
		{
			cout<<"Impossible."<<endl;
		}
	}
	
	
	return 0;
}