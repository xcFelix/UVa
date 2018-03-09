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
		int d = b-a;
		
		int n = (sqrt(1+4*d)-1)/2;
		int dx = d-n*(n+1); //等差数列之和 
		
		if(dx>n+1) cout<<2*n+2<<endl; //一步补偿不了 
		else if(dx) cout<<2*n+1<<endl; //一步可以补偿 
		else cout<<2*n<<endl; //不需补偿 
	}
	
	
	return 0;
}