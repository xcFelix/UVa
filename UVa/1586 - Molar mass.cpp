#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <sstream>
#include <cctype>
using namespace std;

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	map<char, double> mp;
	mp['C'] = 12.01;
	mp['H'] = 1.008;
	mp['O'] = 16.0;
	mp['N'] = 14.01;
	
	int n;
	cin>>n;
	while(n--)
	{
		string s;
		cin>>s;
		
		stringstream ss(s);
		double sum = 0;
		char ch;
		int a;
		
		while(ss>>ch)
		{
			if(isdigit(ss.peek())) ss>>a;
			else a = 1;
			
			sum+=mp[ch]*a;
		}
		
		printf("%.3lf\n", sum);
	}
	
	
	return 0;
}