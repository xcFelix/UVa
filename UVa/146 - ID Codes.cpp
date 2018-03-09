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
	

	string s;
	while(cin>>s && s[0]!='#')
	{
		if(next_permutation(s.begin(), s.end())) cout<<s<<endl;
		else cout<<"No Successor"<<endl;
	}
	
	
	return 0;
}