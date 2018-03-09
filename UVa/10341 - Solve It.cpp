#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const double eps = 1e-9;
int p, q, r, s, t, u;

double cal(double x)
{
	return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*pow(x, 2) + u;
}

int main()
{
//	freopen("stdout.txt", "w", stdout);
//	freopen("stdin.txt", "r", stdin);
	
	
	while(cin>>p>>q>>r>>s>>t>>u)
	{
		double lo = .0;
		double hi = 1.;
		
		if(cal(lo)*cal(hi)>0)
		{
			cout<<"No solution"<<endl;
		}
		else
		{
			while(fabs(hi-lo)>eps)
			{
				double mid = (hi+lo)/2;
				double d = cal(mid);
				
				if(d<=0) hi = mid;
				else lo = mid;
			}
			
			printf("%.4lf\n", hi);
		}
	}
	
	
	return 0;
}