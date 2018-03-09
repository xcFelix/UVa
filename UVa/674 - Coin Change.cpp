#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 9999;
int v[6] = { -1, 1, 5, 10, 25, 50 };
int dp[N];

void init()
{
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	
	for(int i = 1; i<=5; ++i)
	{
		for(int j = v[i]; j<N; ++j)
		{
			dp[j] += dp[j-v[i]];
		}
	}
}

int main()
{
//	freopen("stdin.txt", "r", stdin);
//	freopen("stdout.txt", "w", stdout);
	
	
	init();
	
	int n;
	while(cin>>n)
	{	
		cout<<dp[n]<<endl;
	}
	
	
	return 0;
}