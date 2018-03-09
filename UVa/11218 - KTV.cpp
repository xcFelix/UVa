#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 89;
int a[N];
int b[N];
int c[N];
int w[N];
bool vis[10];

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int sum_case = 0;
	int n;
	while(cin>>n && n)
	{
		memset(vis, false, sizeof(vis));
		
		for(int i = 0; i<n; ++i)
		{
			scanf("%d %d %d %d", a+i, b+i, c+i, w+i);
		}
		
		int max_n = -1;
		for(int i = 0; i<n-2; ++i)
		{
			int sum = 0;
			vis[a[i]] = vis[b[i]] = vis[c[i]] = true;
			sum+=w[i];
			
			for(int j = i+1; j<n-1; ++j)
			{
				if(vis[a[j]] || vis[b[j]] || vis[c[j]]) continue;
				else
				{
					vis[a[j]] = vis[b[j]] = vis[c[j]] = true;
					sum+=w[j];
				}
				
				for(int k = j+1; k<n; ++k)
				{
					if(vis[a[k]] || vis[b[k]] || vis[c[k]]) continue;
					else
					{
						max_n = max(max_n, sum+w[k]);
						break;
					}
				}
				
				vis[a[j]] = vis[b[j]] = vis[c[j]] = false;
				sum-=w[j];
			}
			
			vis[a[i]] = vis[b[i]] = vis[c[i]] = false;
			sum-=w[i];
		}
		
		printf("Case %d: %d\n", ++sum_case, max_n);
	}
	
	
	return 0;
}