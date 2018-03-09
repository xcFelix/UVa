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
		int f;
		int sum = 0;
		cin>>f;
		while(f--)
		{
			int a, b;
			cin>>a>>b>>b;
			sum+=a*b;
		}
		
		cout<<sum<<endl;
	}
	
	return 0;
}