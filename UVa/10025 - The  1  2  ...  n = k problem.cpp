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
		long long k;
		cin>>k;
		if(k==0)
		{
			cout<<3<<endl;
			if(t) cout<<endl;
			continue;
		}
		
		if(k<0) k*=-1;
		
		long long n = ceil((sqrt(1+8*k)-1)/2);
		long long sum = n*(n+1)/2;
		while(sum-k<0 || (sum-k)&1)
		{
			sum+=++n;
		}
		cout<<n<<endl;
		
		if(t) cout<<endl;
	}
	
	
	return 0;
}