#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);

	
	int sum_case = 0;
	int n;
	cin>>n;
	while(n--)
	{
		int k, a, b, c, d;
		cin>>k;
		int i;
		for(i = 2; ; ++i)
		{
			if(k%i==0)
			{
				a = i;
				b = k/i;
				break;
			}
		}
		
		for(++i; ; ++i)
		{
			if(k%i==0)
			{
				c = i;
				d = k/i;
				break;
			}
		}
		
		printf("Case #%d: %d = %d * %d = %d * %d\n", ++sum_case, k, a, b, c, d);
	}
	
	
	return 0;
}