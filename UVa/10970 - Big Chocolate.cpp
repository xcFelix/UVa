#include <iostream>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int m, n;
	while(cin>>m>>n)
	{
		cout<<(m-1)+m*(n-1)<<endl;
	}

	
	return 0;
}