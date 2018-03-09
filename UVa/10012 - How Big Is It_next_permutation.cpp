#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <limits>
#include <algorithm>
using namespace std;

const int N = 9;
double r[N];
double p[N];

int main()
{
//	freopen("stdout.txt", "w", stdout);
//	freopen("stdin.txt", "r", stdin);
	
	
	int n;
	cin>>n;
	while(n--)
	{
		int m;
		cin>>m;
		for(int i = 1; i<=m; ++i) cin>>r[i];
		
		sort(r+1, r+m+1);
		
		double _min = numeric_limits<double>::max();
		
		do
		{
			double lo = .0;
			double hi = 2.0*r[1];
			
			p[1] = r[1];
			
			for(int i = 2; i<=m; ++i)
			{
				p[i] = -1;
				for(int j = 1; j<i; ++j)
				{
					p[i] = max(p[i], p[j]+2.0*sqrt(r[j]*r[i]));
				}
				
				lo = min(lo, p[i]-r[i]);
				hi = max(hi, p[i]+r[i]);
			}
			
			_min = min(_min, hi-lo);
		}while(next_permutation(r+1, r+m+1));
		
		printf("%.3lf\n", _min);
	}
	
	
	return 0;
}