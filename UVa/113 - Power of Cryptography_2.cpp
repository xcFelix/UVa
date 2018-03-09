#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	double n;
	double p;
	while(~scanf("%lf %lf", &n, &p))
	{
		int hi = 1e9;
		int lo = 1;
		
		while(lo<=hi)
		{
			int mid = (hi+lo)/2;
			double temp = pow(mid, n);
			if(temp==p)
			{
				cout<<mid<<endl;
				break;
			}
			else if(temp<p)
			{
				lo = mid+1;
			}
			else
			{
				hi = mid-1;
			}
		}
	}

	
	return 0;
}