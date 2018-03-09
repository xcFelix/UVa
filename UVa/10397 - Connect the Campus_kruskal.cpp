#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 799;
int x[N];
int y[N];
int par[N];

void init()
{
	for(int i = 0; i<N; ++i) par[i] = i;
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
	
	if(x!=y) par[x] = y;
}

struct T{
	int u;
	int v;
	double cost;
	
	T(const int& _u, const int& _v, const double& _cost)
	: u(_u), v(_v), cost(_cost) {}
	
	bool operator<(const T& t) const
	{
		return cost<t.cost;
	}
};

int main()
{
//	freopen("stdout.txt", "w", stdout);
//	freopen("stdin.txt", "r", stdin);
	
	
	int n;
	while(cin>>n)
	{
		for(int i = 1; i<=n; ++i)
		{
			cin>>x[i]>>y[i];
		}
		
		vector<T> es;
		for(int i = 1; i<=n-1; ++i)
		{
			for(int j = i+1; j<=n; ++j)
			{
				double d = sqrt(pow((y[i]-y[j]), 2)+pow((x[i]-x[j]), 2));
				es.push_back(T(i, j, d));
			}
		}
		
		int m;
		cin>>m;
		for(int i = 0; i<m; ++i)
		{
			int u, v;
			cin>>u>>v;
			es.push_back(T(u, v, 0));
		}
		
		sort(es.begin(), es.end());
		
		init();
		double sum = .0;
		for(int i = 0; i<es.size(); ++i)
		{
			int u = es[i].u;
			int v = es[i].v;
			
			if(find(u)!=find(v))
			{
				unite(u, v);
				sum+=es[i].cost;
			}
		}
		
		printf("%.2lf\n", sum);
	}
	
	
	return 0;
}