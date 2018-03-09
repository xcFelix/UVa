#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 55999;
const int M = 109;
int v[M];
bool dp[N];

void init()
{
	memset(dp, false, sizeof(dp));
	
	dp[0] = true;
}

int main()
{
//	freopen("stdin.txt", "r", stdin);
//	freopen("stdout.txt", "w", stdout);
	
	
	int c;
	scanf("%d", &c);
	while(c--)
	{
		int sum = 0;
		int n;
		scanf("%d", &n);
		for(int i = 1; i<=n; ++i)
		{
			scanf("%d", v+i);
			sum += v[i];
		}
		
		init();
		for(int i = 1; i<=n; ++i)
		{
			for(int j = sum; j>=v[i]; --j)
			{
				dp[j] |= dp[j-v[i]];
			}
		}
		
		
		int _min = 0;
		for(int i = sum/2; i>=0; --i)
		{
			if(dp[i])
			{
				_min = sum-i*2;
				break;
			}
		}
		
		printf("%d\n", _min);
	}
	
	
	return 0;
}