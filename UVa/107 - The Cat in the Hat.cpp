#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	int a, b;
	while(cin>>a>>b && !(a==0 && b==0))
	{
		if(a==1)
		{
			cout<<0<<' '<<a<<endl;
			continue;
		}
		
		if(b==1)
		{
			int x = log(a)/log(2);
			int sum_height = 2*a-1;
			cout<<x<<' '<<sum_height<<endl;
			continue;
		}
		
		int lo = 1;
		int hi = a-1;
		while(lo<=hi)
		{
			int N = (lo+hi)/2;
			if(fabs(log(N)/log(N+1)-log(b)/log(a))<1e-9)
			{
				int not_work = (b-1)/(N-1);
				int sum_height = a*(N+1)-N*b;
				cout<<not_work<<' '<<sum_height<<endl;
				break;
			}
			
			if(log(N)/log(N+1)<log(b)/log(a)) lo = N+1;
			else hi = N-1;
		}
	}
	
	return 0;
}