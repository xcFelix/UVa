#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	int n;
	while(cin>>n && n)
	{
		int k = (n-1960)/10+2;
		double d = pow(2, k)*log(2);
		
		double sum = 0;
		int i = 1;
		while(++i)
		{
			sum+=log(i);
			if(sum>d) break;
		}
		
		cout<<i-1<<endl;
	}
	
	
	return 0;
}