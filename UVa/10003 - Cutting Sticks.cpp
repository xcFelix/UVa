#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int inf = 1<<30;
const int N = 59;
int dp[N][N];
int pos[N];

void init()
{
	for(int i = 0; i<N; ++i)
	{
		dp[i][i+1] = 0;
		for(int j = i+2; j<N; ++j)
		{
			dp[i][j] = inf;
		}
	}
}

int main()
{
//	freopen("stdin.txt", "r", stdin);
//	freopen("stdout.txt", "w", stdout);
	
	
	int len;
	while(cin>>len && len)
	{
		init();
		
		int n;
		cin>>n;
		for(int i = 1; i<=n; ++i)
		{
			cin>>pos[i];
		}
		
		pos[0] = 0;
		pos[n+1] = len;
		
		for(int d = 2; d<=n+1; ++d)
		{
			for(int i = 0, j = i+d; j<=n+1; ++i, ++j)
			{
				for(int k = i+1; k<j; ++k)
				{
					dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]+pos[j]-pos[i]);
				}
			}
		}
		
		printf("The minimum cutting is %d.\n", dp[0][n+1]);
	}
	
	
	return 0;
}