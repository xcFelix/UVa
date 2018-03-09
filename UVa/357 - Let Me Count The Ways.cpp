#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;
const int N = 30009;
const int M = 6;
int v[M] = { -1, 1, 5, 10, 25, 50 };
ll dp[N];

void init()
{
	memset(dp, 0, sizeof(dp));
	
	dp[0] = 1;
	for(int i = 1; i<M; ++i)
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
	while(~scanf("%d", &n))
	{
		if(dp[n]==1)
			printf("There is only %lld way to produce %d cents change.\n", dp[n], n);
		else
			printf("There are %lld ways to produce %d cents change.\n", dp[n], n);
	}
	
	
	return 0;
}