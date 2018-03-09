#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	int N;
	while(cin>>N && N)
	{
		int n = ceil(sqrt(N))-1;
		
		int corner = n*n+n+1;
		if(n&1)
		{
			if(corner>N)
			{
				cout<<n-(corner-N)+1<<' '<<n+1<<endl;
			}
			else
			{
				cout<<n+1<<' '<<n-(N-corner)+1<<endl;
			}
		}
		else
		{
			if(corner>N)
			{
				cout<<n+1<<' '<<n-(corner-N)+1<<endl;
			}
			else
			{
				cout<<n-(N-corner)+1<<' '<<n+1<<endl;
			}
		}
	}
	
	
	return 0;
}