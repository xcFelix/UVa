#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1009;
int dp[N][N];

int main()
{
//	freopen("stdin.txt", "r", stdin);
//	freopen("stdout.txt", "w", stdout);
	
	
	memset(dp, 0, sizeof(dp));
	
	string s1, s2;
	while(getline(cin, s1) && getline(cin, s2))
	{
		for(int i = 1; i<=s1.size(); ++i)
		{
			for(int j = 1; j<=s2.size(); ++j)
			{
				if(s1[i-1]==s2[j-1])
				{
					dp[i][j] = dp[i-1][j-1]+1;
				}
				else
				{
					dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
				}
			}
		}
		
		cout<<dp[s1.size()][s2.size()]<<endl;
	}
	
	
	return 0;
}