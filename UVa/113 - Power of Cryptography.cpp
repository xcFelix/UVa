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
	while(cin>>n>>p)
	{
		printf("%.lf\n", pow(p, 1/n));
	}

	
	return 0;
}