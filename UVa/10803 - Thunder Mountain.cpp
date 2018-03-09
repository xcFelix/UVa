#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 109;
const double inf = 1e30;
const double eps = 1e-9;
int x[N];
int y[N];
double d[N][N];

int main()
{
//	freopen("stdout.txt", "w", stdout);
//	freopen("stdin.txt", "r", stdin);
	
	
	int sum_case = 0;
	int n;
	cin>>n;
	while(n--)
	{
		int m;
		cin>>m;
		for(int i = 0; i<m; ++i)
		{
			cin>>x[i]>>y[i];
		}
		
		for(int i = 0; i<m-1; ++i)
		{
			d[i][i] = 0;
			for(int j = i+1; j<m; ++j)
			{
				double dis = sqrt(pow((x[i]-x[j]), 2)+pow((y[i]-y[j]), 2));
				if(dis>10) d[i][j] = d[j][i] = inf;
				else d[i][j] = d[j][i] = dis;
			}
		}
		
		for(int k = 0; k<m; ++k)
		{
			for(int i = 0; i<m; ++i)
			{
				for(int j = 0; j<m; ++j)
				{
					d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
				}
			}
		}
		
		bool ok = true;
		double _max = 0;
		for(int i = 0; i<m-1; ++i)
		{
			for(int j = i+1; j<m; ++j)
			{
				if(fabs(d[i][j]-inf)<eps)
				{
					ok = false;
					break;
				}
				else
				{
					_max = max(_max, d[i][j]);
				}
			}
			
			if(!ok) break;
		}
		
		printf("Case #%d:\n", ++sum_case);
		if(ok) printf("%.4lf\n\n", _max);
		else cout<<"Send Kurdy"<<endl<<endl;
	}
	
	
	return 0;
}