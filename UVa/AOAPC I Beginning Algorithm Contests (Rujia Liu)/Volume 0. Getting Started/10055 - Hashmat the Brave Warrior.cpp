#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);


	long long a, b;
	while(cin>>a>>b)
	cout<<abs(a-b)<<endl; //C++11 Ö§³Ö long long 
	
	return 0;
}