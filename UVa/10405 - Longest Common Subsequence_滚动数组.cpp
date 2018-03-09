#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1009;
int dp[2][N];

void init()
{
	memset(dp, 0, sizeof(dp));
}

int main()
{
//	freopen("stdin.txt", "r", stdin);
//	freopen("stdout.txt", "w", stdout);
	
	string s1, s2;
	while(getline(cin, s1) && getline(cin, s2))
	{
		init();
		
		for(int i = 1; i<=s1.size(); ++i)
		{
			for(int j = 1; j<=s2.size(); ++j)
			{
				int index = i&1;
				if(s1[i-1]==s2[j-1])
				{
					dp[index][j] = dp[!index][j-1]+1;
				}
				else
				{
					dp[index][j] = max(dp[index][j-1], dp[!index][j]);
				}
			}
		}
		
		cout<<dp[s1.size()&1][s2.size()]<<endl;
	}
	
	
	return 0;
}