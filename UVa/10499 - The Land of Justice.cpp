#include <iostream>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	long long n;
	while(cin>>n && n>0)
	{
		if(n==1) cout<<0<<'%'<<endl;
		else cout<<n*25<<'%'<<endl;	//printf("%.0lf%%\n", d*25);
	}

	
	return 0;
}