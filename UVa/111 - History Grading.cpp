#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 29;
int dp[N][N];
int arr1[N];
int arr2[N];

void init()
{
	memset(dp, 0, sizeof(dp));
}

int main()
{
//	freopen("stdin.txt", "r", stdin);
//	freopen("stdout.txt", "w", stdout);
	
	
	init();
	
	int n;
	cin>>n;
	for(int i = 1; i<=n; ++i)
	{
		int a;
		cin>>a;
		arr1[a-1] = i;
	}
	
	int a;
	while(cin>>a)
	{
		arr2[a-1] = 1;
		for(int i = 2; i<=n; ++i)
		{
			int a;
			cin>>a;
			arr2[a-1] = i;
		}
		
		for(int i = 1; i<=n; ++i)
		{
			for(int j = 1; j<=n; ++j)
			{
				if(arr1[i-1]==arr2[j-1])
				{
					dp[i][j] = dp[i-1][j-1]+1;
				}
				else
				{
					dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
				}
			}
		}
		
		cout<<dp[n][n]<<endl;
	}
	
	return 0;
}