#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 109;
int par[N];

void init()
{
	for(int i = 0; i<N; ++i) par[i] = i;
}

int find(int x)
{
	if(x==par[x]) return x;
	return par[x] = find(par[x]);
}

void unite(int a, int b)
{
	int x = find(a);
	int y = find(b);
	
	if(x!=y) par[x] = y;
}

struct T{
	int u, v;
	int cost;
	
	T(const int& _u, const int& _v, const int& _cost)
	: u(_u), v(_v), cost(_cost) {}
	
	bool operator<(const T& t) const
	{
		return cost>t.cost;
	}
};

int main()
{
//	freopen("stdout.txt", "w", stdout);
//	freopen("stdin.txt", "r", stdin);
	
	
	int sum_case = 0;
	int n, r;
	while(cin>>n>>r && (n+r))
	{
		vector<T> es;
		for(int i = 0; i<r; ++i)
		{
			int u, v, cost;
			cin>>u>>v>>cost;
			es.push_back(T(u, v, cost));
		}
		
		sort(es.begin(), es.end());
		
		int src, des, sum;
		cin>>src>>des>>sum;
		
		init();
		int _max;
		for(int i = 0; i<es.size(); ++i)
		{
			int u = es[i].u;
			int v = es[i].v;
			int cost = es[i].cost;
			
			if(find(u)!=find(v))
			{
				unite(u, v);
				
				if(find(src)==find(des))
				{
					_max = cost-1;
					break;
				}
			}
		}
		
		printf("Scenario #%d\n", ++sum_case);
		int a = sum/_max;
		if(sum%_max) ++a;
		printf("Minimum Number of Trips = %d\n\n", a);
	}
	
	
	return 0;
}