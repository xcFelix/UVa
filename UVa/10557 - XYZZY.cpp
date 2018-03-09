#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int N = 109;
int d[N], w[N];
bool r[N], inq[N];
int inq_sum[N];
vector<int> G[N], rG[N];

int n;

void dfs(int u)
{
	for(int i = 0; i<rG[u].size(); ++i)
	{
		int v = rG[u][i];
		
		if(!r[v])
		{
			r[v] = true;
			dfs(v);
		}
	}
}

bool bfs()
{
	queue<int> Q;
	Q.push(1);
	inq[1] = true;
	++inq_sum[1];
	
	bool cir = false;
	while(Q.size())
	{
		int u = Q.front(); Q.pop();
		inq[u] = false;
		
		for(int i = 0; i<G[u].size(); ++i)
		{
			int v = G[u][i];
			
			if(r[v] && !inq[v] && d[v]<d[u]+w[v])
			{
				d[v] = d[u] + w[v];
				
				Q.push(v);
				inq[v] = true;
				
				if(++inq_sum[v]==n)
				{
					cir = true;
					break;
				}
			}
		}
		
		if(cir) break;
	}
	
	if(cir || d[n]>0) return true;
	return false;
}

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
//	int n;
	while(cin>>n && n!=-1)
	{
		memset(d, 0, sizeof(d));
		memset(w, 0, sizeof(w));
		memset(r, false, sizeof(r));
		memset(inq, false, sizeof(inq));
		memset(inq_sum, 0, sizeof(inq_sum));
		for(int i = 0; i<N; ++i)
		{
			G[i].clear();
			rG[i].clear();
		}
		
		for(int u = 1; u<=n; ++u)
		{
			cin>>w[u];
			
			int m;
			cin>>m;
			while(m--)
			{
				int v;
				cin>>v;
				
				G[u].push_back(v);
				rG[v].push_back(u);
			}
		}
		
		r[n] = true;
		dfs(n);
		
		if(!r[1])
		{
			cout<<"hopeless"<<endl;
			continue;
		}
		
		d[1] = 100;
		if(bfs()) cout<<"winnable"<<endl;
		else cout<<"hopeless"<<endl;
	}
	
	
	return 0;
}