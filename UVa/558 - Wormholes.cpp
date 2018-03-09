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

const int N = 1009;
const int inf = 1<<30;
vector<T> G[N];
bool inq[N];
int d[N];
int inqs[N];

bool bfs(int n)
{
	d[0] = 0;
	queue<int> Q;
	Q.push(0);
	inq[0] = true;
	inqs[0]++;
	
	bool ok = false;
	while(Q.size())
	{
		int u = Q.front(); Q.pop();
		inq[u] = false;
		
		for(int i = 0; i<G[u].size(); ++i)
		{
			int v = G[u][i].to;
			int cost = G[u][i].cost;
			
			if(d[u]+cost<d[v])
			{
				d[v] = d[u]+cost;
				
				if(!inq[v])
				{
					Q.push(v);
					inq[v] = true;
					if(++inqs[v]==n)
					{
						ok = true;
						break;
					}
				}
			}
		}
		
		if(ok) break;
	}
	
	return ok;
}

int main()
{
//	freopen("stdout.txt", "w", stdout);
//	freopen("stdin.txt", "r", stdin);
	
	
	int c;
	cin>>c;
	while(c--)
	{
		memset(inq, false, sizeof(inq));
		memset(inqs, 0, sizeof(inqs));
		for(int i = 0; i<N; ++i)
		{
			d[i] = inf;
			G[i].clear();
		}
		
		int n, m;
		cin>>n>>m;
		for(int i = 0; i<m; ++i)
		{
			int u, v, t;
			cin>>u>>v>>t;
			G[u].push_back(T(v, t));
		}
		
		if(bfs(n)) cout<<"possible"<<endl;
		else cout<<"not possible"<<endl;
	}
	
	
	return 0;
}