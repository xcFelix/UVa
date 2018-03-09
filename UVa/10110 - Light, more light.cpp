#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);


	unsigned a;
	while(cin>>a && a)
	{
		unsigned b = sqrt(a);
		if(b*b==a) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	
	
	return 0;
}