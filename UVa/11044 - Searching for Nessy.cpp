#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	int t;
	cin>>t;
	while(t--)
	{
		int a, b;
		cin>>a>>b;
		a-=2;
		b-=2;
		a = ceil(a/3.);
		b = ceil(b/3.);
		cout<<a*b<<endl;
	}
	
	
	return 0;
}