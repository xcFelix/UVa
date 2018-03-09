#include <iostream>
#include <cstdio>
using namespace std;

int gcd(int a, int b)
{
	if(b) return gcd(b, a%b);
	return a;
}

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);


	int a, b;
	while(cin>>a>>b)
	{
		int g = gcd(a, b);
		printf("%10d%10d%s\n\n", a, b, g==1?"    Good Choice":"    Bad Choice");
	}
	
	
	return 0;
}