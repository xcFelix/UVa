#include <iostream>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int sum_case = 0;
	long long a, b;
	while(cin>>a>>b && !(a==0 && b==0))
	{
		cout<<"Case "<<++sum_case<<": "<<a*(a-1)*b*(b-1)/4<<endl;
	}
	
	
	return 0;
}