#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 109;
int arr1[N];
int arr2[N];
int dp[2][N];

void init()
{
	memset(dp, 0, sizeof(dp));
}

int main()
{
//	freopen("stdin.txt", "r", stdin);
//	freopen("stdout.txt", "w", stdout);
	
	
	int sum_case = 0;
	int n, m;
	while(cin>>n>>m && n+m)
	{
		init();
		
		for(int i = 0; i<n; ++i)
		{
			cin>>arr1[i];
		}
		
		for(int i = 0; i<m; ++i)
		{
			cin>>arr2[i];
		}
		
		for(int i = 1; i<=n; ++i)
		{
			for(int j = 1; j<=m; ++j)
			{
				int index = i&1;
				if(arr1[i-1]==arr2[j-1])
				{
					dp[index][j] = dp[!index][j-1]+1;
				}
				else
				{
					dp[index][j] = max(dp[index][j-1], dp[!index][j]);
				}
			}
		}
		
		printf("Twin Towers #%d\n", ++sum_case);
		printf("Number of Tiles : %d\n\n", dp[n&1][m]);
	}
	
	
	return 0;
}