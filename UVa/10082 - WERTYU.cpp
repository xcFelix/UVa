#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

string base("`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./  ");

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	string s;
	while(getline(cin, s))
	{
		for(int i = 0; i<s.size(); ++i) s[i] = base[base.rfind(s[i])-1];
		
		cout<<s<<endl;
	}
	
	
	return 0;
}