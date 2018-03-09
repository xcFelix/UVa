#include <iostream>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int n;
	cin>>n;
	while(n--)
	{
		int frequency, height;
		cin>>height>>frequency;
		
		while(frequency--)
		{
			for(int i = 1; i<=height; ++i)
			{
				for(int j = 1; j<=i; ++j) cout<<i;
				cout<<endl;
			}
			
			for(int i = height-1; i>=1; --i)
			{
				for(int j = 1; j<=i; ++j) cout<<i;
				cout<<endl;
			}
			
			if(n || frequency) cout<<endl;
		}
	}
	
	
	return 0;
}