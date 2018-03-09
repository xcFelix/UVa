#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <limits>
using namespace std;

const int N = 9;
double arr[N];
double r[N];
double p[N];
bool vis[N];

int m;
double _min;

void dfs(int pos, double lo, double hi)
{
	if(pos>m)
	{
		_min = min(_min, hi-lo);
		return;
	}
	
	for(int i = 1; i<=m; ++i)
	{
		if(!vis[i])
		{
			vis[i] = true;
			r[pos] = arr[i];
			p[pos] = -1;
			
			for(int j = 1; j<pos; ++j)
			{
				p[pos] = max(p[pos], p[j]+2.0*sqrt(r[j]*r[pos]));
			}
			
			double _lo = min(lo, p[pos]-r[pos]);
			double _hi = max(hi, p[pos]+r[pos]);
			
			dfs(pos+1, _lo, _hi);
			
			vis[i] = false;
		}
	}
}

int main()
{
//	freopen("stdout.txt", "w", stdout);
//	freopen("stdin.txt", "r", stdin);
	
	
	int n;
	cin>>n;
	while(n--)
	{
		memset(vis, false, sizeof(vis));
		
		cin>>m;
		for(int i = 1; i<=m; ++i) cin>>arr[i];
		
		_min = numeric_limits<double>::max();
		
		for(int i = 1; i<=m; ++i)
		{
			vis[i] = true;
			r[1] = arr[i];
			p[1] = r[1];
			
			dfs(2, 0, 2*r[1]);
			
			vis[i] = false;
		}
		
		printf("%.3lf\n", _min);
	}
	
	
	return 0;
}