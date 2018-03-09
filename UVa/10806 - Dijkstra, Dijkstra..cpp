#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct E{
	int to;
	int cap;
	int rev;
	int cost;
	
	E(const int &_to, const int &_cap, const int &_rev, const int &_cost)
	: to(_to), cap(_cap), rev(_rev), cost(_cost) {}
};

const int INF = 1<<30;
const int N = 109;
vector<E> G[N];
int dist[N];
int prev[N], pree[N];
bool inq[N];
int n;

void init()
{
	for(int i = 0; i<N; ++i)
	{
		G[i].clear();
	}
}

void add_edge(int from, int to, int cap, int cost)
{
	G[from].push_back(E(to, cap, G[to].size(), cost));
	G[to].push_back(E(from, 0, G[from].size()-1, -cost));
}

void bfs(int s)
{
	fill(dist+1, dist+1+n, INF);
	memset(inq, false, sizeof(inq));
	
	dist[s] = 0;
	inq[s] = true;
	queue<int> Q;
	Q.push(s);
	
	while(Q.size())
	{
		int v = Q.front(); Q.pop();
		inq[v] = false;
		
		for(int i = 0; i<G[v].size(); ++i)
		{
			E &e = G[v][i];
			if(e.cap>0 && dist[v]+e.cost<dist[e.to])
			{
				dist[e.to] = dist[v]+e.cost;
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

int min_cost_flow(int s, int t, int f)
{
	int sum = 0;
	
	while(f)
	{
		bfs(s);
		if(dist[t]==INF) return -1;
		
		int _min = f;
		for(int v = t; v!=s; v = prev[v])
		{
			_min = min(_min, G[prev[v]][pree[v]].cap);
		}
		
		f -= _min;
		sum += _min*dist[t];
		
		for(int v = t; v!=s; v = prev[v])
		{
			E &e = G[prev[v]][pree[v]];
			
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
	
	
	while(cin>>n && n)
	{
		init();
		
		int m;
		cin>>m;
		for(int i = 0; i<m; ++i)
		{
			int from, to, cost;
			cin>>from>>to>>cost;
			
			add_edge(from, to, 1, cost);
			add_edge(to, from, 1, cost);
		}
		
		int cost = min_cost_flow(1, n, 2);
		if(cost>=0)
		{
			cout<<cost<<endl;
		}
		else
		{
			cout<<"Back to jail"<<endl;
		}
	}
	
	
	return 0;
}
