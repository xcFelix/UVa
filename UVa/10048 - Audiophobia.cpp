#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 109;
const int inf = 1<<30;
int d[N][N];

void init()
{
	for(int i = 1; i<N; ++i)
	{
		d[i][i] = inf;
		for(int j = i+1; j<N; ++j)
		{
			d[i][j] = d[j][i] = inf;
		}
	}
}

void floyd(int n)
{
	for(int k = 1; k<=n; ++k)
	{
		for(int i = 1; i<=n; ++i)
		{
			for(int j = 1; j<=n; ++j)
			{
				d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
			}
		}
	}
}

int main()
{
//	freopen("stdout.txt", "w", stdout);
//	freopen("stdin.txt", "r", stdin);
	
	
	int sum_case = 0;
	int c, s, q;
	while(cin>>c>>s>>q && c+s+q)
	{
		init();
		
		if(sum_case) cout<<endl;
		
		for(int i = 0; i<s; ++i)
		{
			int u, v, a;
			cin>>u>>v>>a;
			d[u][v] = d[v][u] = a;
		}
		
		floyd(c);
		
		printf("Case #%d\n", ++sum_case);
		for(int i = 0; i<q; ++i)
		{
			int u, v;
			cin>>u>>v;
			if(d[u][v]!=inf) cout<<d[u][v]<<endl;
			else cout<<"no path"<<endl;
		}
	}
	
	
	return 0;
}