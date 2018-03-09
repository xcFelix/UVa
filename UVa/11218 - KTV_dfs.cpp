//比较奇怪的一题。
//用结构体写了一个剪枝的TLE，dfs回溯没有剪枝可以过。

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

int n;
int max_n;

void dfs(int t, int sum, int pos)
{
	if(t==3)
	{
		max_n = max(max_n, sum);
		return;
	}
	else
	{
		for(int i = pos; i<n; ++i)
		{
			if(vis[a[i]] || vis[b[i]] || vis[c[i]]) continue;
			
			vis[a[i]] = vis[b[i]] = vis[c[i]] = true;
			sum+=w[i];
			
			dfs(t+1, sum, i+1);
			
			sum-=w[i];
			vis[a[i]] = vis[b[i]] = vis[c[i]] = false;
		}
	}
}

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int sum_case = 0;
	while(cin>>n && n)
	{
		memset(vis, false, sizeof(vis));
		
		for(int i = 0; i<n; ++i)
		{
			scanf("%d %d %d %d", a+i, b+i, c+i, w+i);
		}
		
		max_n = -1;
		
		dfs(0, 0, 0);
		
		printf("Case %d: %d\n", ++sum_case, max_n);
	}
	
	
	return 0;
}