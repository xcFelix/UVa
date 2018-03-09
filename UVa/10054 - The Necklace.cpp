#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int N = 59;
int G[N][N];
int d[N];
int p[N];

int find(int x)
{
	if(x==p[x]) return x;
	return p[x] = find(p[x]);
}

void unite(int a, int b)
{
	int x = find(a);
	int y = find(b);
	
	if(x==y) return;
	p[x] = y;
}

bool con()
{
	int sum = 0;
	for(int i = 1; i<=50; ++i)
	{
		if(d[i] && p[i]==i) ++sum;
	}
	
	return sum==1;
}

bool euler_c()
{
	for(int i = 1; i<=50; ++i)
	{
		if(d[i]&1) return false;
	}
	
	return true;
}

void dfs(int u)
{
	for(int v = 1; v<=50; ++v)
	{
		if(G[u][v])
		{
			--G[u][v];
			--G[v][u];
			
			dfs(v);
			cout<<v<<' '<<u<<endl;
		}
	}
}

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int sum_case = 0;
	int t;
	cin>>t;
	while(t--)
	{	
		memset(G, 0, sizeof(G));
		memset(d, 0, sizeof(d));
		for(int i = 1; i<=50; ++i) p[i] = i;
		
		int n;
		cin>>n;
		for(int i = 0; i<n; ++i)
		{
			int u, v;
			cin>>u>>v;
			
			d[u]++;
			d[v]++;
			unite(u, v);
			
			G[u][v]++;
			G[v][u]++;
		}
		
		cout<<"Case #"<<++sum_case<<endl;
		
		if(con() && euler_c())
		{
			for(int u = 1; ; ++u)
			{
				if(d[u])
				{
					dfs(u);
					break;
				}
			}
		}
		else cout<<"some beads may be lost"<<endl;
		
		if(t) cout<<endl;
	}
	
	
	return 0;
}