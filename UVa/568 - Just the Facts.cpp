#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);


	int n;
	while(cin>>n)
	{
		int sum = 1;
		for(int i = 2; i<=n; ++i)
		{
			sum*=i;
			while(sum%10==0) sum/=10;
			sum%=100000;
		}
		
		printf("%5d -> %d\n", n, sum%10);
	}
	
	
	return 0;
}