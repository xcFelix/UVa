#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 109;
char arr1[N];
char arr2[N];
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
	while(gets(arr1) && gets(arr2))
	{
		init();
		
		int len1 = strlen(arr1);
		int len2 = strlen(arr2);
		
		for(int i = 1; i<=len1; ++i)
		{
			for(int j = 1; j<=len2; ++j)
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
		
		printf("Case #%d: you can visit at most %d cities.\n", ++sum_case, dp[len1&1][len2]);
	}
	
	
	return 0;
}