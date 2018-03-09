#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 29;
int d[N][N];
const int inf = 1<<29;

void init()
{
	for(int i = 0; i<N; ++i)
	{
		for(int j = 0; j<N; ++j)
		{
			if(i==j) d[i][j] = 0;
			else d[i][j] = inf;
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
				d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
			}
		}
	}
}

int main()
{
//	freopen("stdout.txt", "w", stdout);
//	freopen("stdin.txt", "r", stdin);
	
	
	int sum_case = 0;
	int n;
	while(cin>>n)
	{
		init();
		
		for(int i = 0; i<n; ++i)
		{
			int v;
			cin>>v;
			d[1][v] = d[v][1] = 1;
		}
		
		for(int u = 2; u<20; ++u)
		{
			cin>>n;
			
			for(int i = 0; i<n; ++i)
			{
				int v;
				cin>>v;
				d[u][v] = d[v][u] = 1;
			}
		}
		
		floyd(20);
		
		printf("Test Set #%d\n", ++sum_case);
		cin>>n;
		while(n--)
		{
			int u, v;
			cin>>u>>v;
			printf("%2d to %2d: %d\n", u, v, d[u][v]);
		}
		cout<<endl;
	}
	
	
	return 0;
}