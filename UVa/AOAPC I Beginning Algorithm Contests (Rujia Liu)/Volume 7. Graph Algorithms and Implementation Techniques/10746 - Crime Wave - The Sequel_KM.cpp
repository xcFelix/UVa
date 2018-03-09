#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const double eps = 1e-9;
const int inf = 1<<30;
const int N = 29;
int nx, ny;
int match[N];
bool visx[N], visy[N];
double lx[N], ly[N];
double w[N][N], slack[N];

bool dfs(int x)
{
	visx[x] = true;
	
	for(int y = 1; y<=ny; ++y)
	{
		double t = lx[x]+ly[y]-w[x][y];
		if(t<eps)
		{
			visy[y] = true;
			int w = match[y];
			if(w<0 || !visx[w] && dfs(w))
			{
				match[y] = x;
				
				return true;
			}
		}
		else
		{
			slack[y] = min(slack[y], t);
		}
	}
	
	return false;
}

double KM()
{
	memset(match, -1, sizeof(match));
	memset(ly, 0, sizeof(ly));
	
	for(int x = 1; x<=nx; ++x)
	{
		lx[x] = -inf;
		for(int y = 1; y<=ny; ++y)
		{
			lx[x] = max(lx[x], w[x][y]);
		}
	}
	
	for(int x = 1; x<=nx; ++x)
	{
		fill(slack, slack+N, inf);
		
		while(true)
		{
			memset(visx, false, sizeof(visx));
			memset(visy, false, sizeof(visy));
			
			if(dfs(x)) break;
			
			double d = inf;
			for(int y = 1; y<=ny; ++y)
			{
				if(!visy[y])
				{
					d = min(d, slack[y]);
				}
			}
			
			for(int i = 1; i<=nx; ++i)
			{
				if(visx[i])
				{
					lx[i]-=d;
				}
			}
			for(int i = 1; i<=ny; ++i)
			{
				if(visy[i])
				{
					ly[i]+=d;
				}
			}
		}
	}
	
	double sum = 0;
	for(int i = 1; i<=ny; ++i)
	{
		if(match[i]>0)
		{
			sum+=w[match[i]][i];
		}
	}
	
	return -sum;
}

int main()
{
//	freopen("stdin.txt", "r", stdin);
//	freopen("stdout.txt", "w", stdout);
	
	
	while(cin>>nx>>ny && nx+ny)
	{
		for(int i = 1; i<=nx; ++i)
		{
			for(int j = 1; j<=ny; ++j)
			{
				cin>>w[i][j];
				w[i][j]*=-1;
			}
		}
		
		double sum = KM()/nx;
		printf("%.2lf\n", sum+eps); //很奇怪吧。。但是必须加哦
	}
	
	
	return 0;
}