#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int inf = 1<<30;
const int N = 19;
const int M = 109;
int arr[N][M];
int dp[N][M];
int next[N][M];

int dx[3] = { 1, -1, 0 };
int xx[3];

int main()
{
//	freopen("stdin.txt", "r", stdin);
//	freopen("stdout.txt", "w", stdout);
	
	
	int n, m;
	while(cin>>n>>m)
	{
		for(int i = 0; i<n; ++i)
		{
			for(int j = 0; j<m; ++j)
			{
				dp[i][j] = inf;
				cin>>arr[i][j];
				
				if(j==m-1)
				{
					dp[i][j] = arr[i][j];
				}
			}
		}
		
		for(int j = m-2; j>=0; --j)
		{
			for(int i = 0; i<n; ++i)
			{
				for(int k = 0; k<3; ++k)
				{
					xx[k] = (i+dx[k]+n)%n;
				}
				
				sort(xx, xx+3);
				
				for(int k = 0; k<3; ++k)
				{
					if(dp[xx[k]][j+1]<dp[i][j])
					{
						dp[i][j] = dp[xx[k]][j+1];
						next[i][j] = xx[k];
					}
				}
				
				dp[i][j] += arr[i][j];
			}
		}
		
		int _min = dp[0][0];
		int _i = 0;
		for(int i = 1; i<n; ++i)
		{
			if(dp[i][0]<_min)
			{
				_min = dp[i][0];
				_i = i;
			}
		}
		
		cout<<_i+1;
		for(int j = 0; j<m-1; ++j)
		{
			_i = next[_i][j];
			cout<<' '<<_i+1;
		}
		cout<<endl;
		cout<<_min<<endl;
	}
	
	
	return 0;
}