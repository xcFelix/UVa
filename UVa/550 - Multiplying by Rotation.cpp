#include <iostream>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);


	int base, a, b;
	while(cin>>base>>b>>a)
	{
		int sum = 0;
		int end = b;
		int c = 0;
		while(true)
		{
			++sum;
			int t = a*b+c;
			if(t==end) break;
			b = t%base;
			c = t/base;
		}
		
		cout<<sum<<endl;
	}
	
	
	return 0;
}