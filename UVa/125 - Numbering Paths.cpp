#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 999;
int G[N][N];
int m;

int main()
{
//	freopen("stdout.txt", "w", stdout);
//	freopen("stdin.txt", "r", stdin);
	
	
	int sum_case = 0;
	int n;
	while(cin>>n)
	{
		memset(G, 0, sizeof(G));
		
		m = -1;
		for(int i = 0; i<n; ++i)
		{
			int u, v;
			cin>>u>>v;
			m = max(m, max(u, v));
			G[u][v] = 1;
		}
		
		for(int k = 0; k<=m; ++k)
		{
			for(int i = 0; i<=m; ++i)
			{
				for(int j = 0; j<=m; ++j)
				{
					G[i][j]+=G[i][k]*G[k][j];
				}
			}
		}
		
		for(int k = 0; k<=m; ++k)
		{
			if(G[k][k])
			{
				G[k][k] = -1;
				for(int i = 0; i<=m; ++i)
				{
					for(int j = 0; j<=m; ++j)
					{
						if(G[i][k] && G[k][j]) G[i][j] = -1;
					}
				}
			}
		}
		
		printf("matrix for city %d\n", sum_case++);
		for(int i = 0; i<=m; ++i)
		{
			cout<<G[i][0];
			for(int j = 1; j<=m; ++j)
			{
				cout<<' '<<G[i][j];
			}
			cout<<endl;
		}
	}
	
	return 0;
}