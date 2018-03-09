#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
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
		sort(s.begin(), s.end());
		
		cout<<s<<endl;
		while(next_permutation(s.begin(), s.end())) cout<<s<<endl;
		cout<<endl;
	}
	
	
	return 0;
}