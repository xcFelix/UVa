#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int n;
	cin>>n;
	while(n--)
	{
		string s;
		cin>>s;
		
		int sum = 0;
		int base = 0;
		for(int i = 0; i<s.size(); ++i)
		{
			if(s[i]=='X') base = 0;
			else sum += ++base;
		}
		
		cout<<sum<<endl;
	}
	
	
	return 0;
}