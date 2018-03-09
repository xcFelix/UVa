#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 29;
int par[N];
vector<int> G[N];
int arr[N];
bool vis[N];
int des;
int sum;

void initi()
{
	for(int i = 1; i<N; ++i)
	{
		par[i] = i;
		G[i].clear();
	}
	
	memset(vis, false, sizeof(vis));
	sum = 0;
}

int find(int x)
{
	if(par[x]==x) return x;
	return par[x] = find(par[x]);
}

void unite(int a, int b)
{
	int x = find(a);
	int y = find(b);
	
	if(x==y) return;
	par[x] = y;
}

void _dfs(int u)
{
	for(int i = 0; i<G[u].size(); ++i)
	{
		int v = G[u][i];
		if(find(u)!=find(v))
		{
			unite(u, v);
			_dfs(v);
		}
	}
}


void dfs(int pos, int u)
{
	for(int i = 0; i<G[u].size(); ++i)
	{
		int v = G[u][i];
		if(v==des)
		{
			++sum;
			for(int i = 1; i<pos; ++i) cout<<arr[i]<<' ';
			cout<<v;
			cout<<endl;
		}
		else if(!vis[v] && find(v)==find(des))
		{
			vis[v] = true;
			arr[pos] = v;
			dfs(pos+1, v);
			vis[v] = false;
		}
	}
}

int main()
{
//	freopen("stdout.txt", "w", stdout);
//	freopen("stdin.txt", "r", stdin);
	
	
	int sum_case = 0;
	while(cin>>des)
	{
		initi();
		
		int u, v;
		while(cin>>u>>v && u)
		{
			G[u].push_back(v);
			G[v].push_back(u);
		}
		
		_dfs(des);
		
		for(int i = 1; i<N; ++i) sort(G[i].begin(), G[i].end());
		
		vis[1] = true;
		arr[1] = 1;
		printf("CASE %d:\n", ++sum_case);
		dfs(2, 1);
		printf("There are %d routes from the firestation to streetcorner %d.\n", sum, des);
	}
	
	
	return 0;
}