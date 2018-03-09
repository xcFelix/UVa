#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int inf = 1<<30;
const int N = 19;
int arr[N];
int dp[N][N];
int cut[N][N];

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

void print(int lo, int hi)
{
	if(lo+1 == hi)
	{
		printf("A%d", lo+1);
		return;
	}
	
	printf("(");
	print(lo, cut[lo][hi]);
	printf(" x ");
	print(cut[lo][hi], hi);
	printf(")");
}

int main()
{
//	freopen("stdin.txt", "r", stdin);
//	freopen("stdout.txt", "w", stdout);
	
	
	int sum_case = 0;
	int n;
	while(scanf("%d", &n) && n)
	{
		for(int i = 0; i<n; ++i)
		{
			scanf("%d%d", arr+i, arr+i+1);
		}
		
		init();
		
		for(int d = 2; d<=n; ++d)
		{
			for(int i = 0, j = i+d; j<=n; ++i, ++j)
			{
				for(int k = i+1; k<j; ++k)
				{
					int temp = dp[i][k] + dp[k][j] + arr[i]*arr[k]*arr[j];
					if(temp<dp[i][j])
					{
						dp[i][j] = temp;
						cut[i][j] = k;
					}
				}
			}
		}
		
		printf("Case %d: ", ++sum_case);
		print(0, n);
		printf("\n");
	}
	
	
	return 0;
}