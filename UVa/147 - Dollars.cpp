#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 6009;
const int M = 12;
long long dp[N];
int v[M] = { -1, 1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000 };

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
	
	int a, b;
	while(scanf("%d.%d", &a, &b) && a+b)
	{	
		int sum = (a*100+b)/5;
		
		printf("%3d.%02d%17lld\n", a, b, dp[sum]);
	}
	
	
	return 0;
}