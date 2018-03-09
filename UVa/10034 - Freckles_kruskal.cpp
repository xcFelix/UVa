#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 109;
double x[N];
double y[N];
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
	cin>>n;
	while(n--)
	{
		int m;
		cin>>m;
		for(int i = 0; i<m; ++i)
		{
			cin>>x[i]>>y[i];
		}
		
		vector<T> es;
		for(int i = 0; i<m-1; ++i)
		{
			for(int j = i+1; j<m; ++j)
			{
				double d = sqrt(pow((y[i]-y[j]), 2) + pow((x[i]-x[j]), 2));
				es.push_back(T(i, j, d));
			}
		}
		
		sort(es.begin(), es.end());
		
		init();
		
		double sum = .0;
		for(int i = 0; i<es.size(); ++i)
		{
			int u = es[i].u;
			int v = es[i].v;
			double cost = es[i].cost;
			
			if(find(u)!=find(v))
			{
				unite(u, v);
				sum+=cost;
			}
		}
		
		printf("%.2lf\n", sum);
		if(n) cout<<endl;
	}
	
	
	return 0;
}