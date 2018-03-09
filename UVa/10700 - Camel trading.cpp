#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <stack>
using namespace std;

int main()
{
//	freopen("stdout.txt", "w", stdout);
//	freopen("stdin.txt", "r", stdin);
	
	
	int n;
	cin>>n;
	cin.get();
	while(n--)
	{
		string s;
		getline(cin, s);
		stringstream ss(s);
		
		stack<long long> S1;
		stack<char> S2;
		
		long long _min;
		long long _max;
		
		long long a;
		char ch;
		
		ss>>a;
		S1.push(a);
		while(ss>>ch>>a)
		{
			if(ch=='*')
			{
				long long b = S1.top(); S1.pop();
				a*=b;
				S1.push(a);
			}
			else
			{
				S1.push(a);
				S2.push(ch);
			}
		}
		
		a = S1.top(); S1.pop();
		while(S1.size())
		{
			long long b = S1.top(); S1.pop();
			S2.pop();
			
			a+=b;
		}
		_min = a;
		
		
		ss.clear();
		ss.seekg(0);
		ss>>a;
		S1.push(a);
		while(ss>>ch>>a)
		{
			if(ch=='+')
			{
				long long b = S1.top(); S1.pop();
				a+=b;
				S1.push(a);
			}
			else
			{
				S1.push(a);
				S2.push(ch);
			}
		}
		
		a = S1.top(); S1.pop();
		while(S1.size())
		{
			long long b = S1.top(); S1.pop();
			S2.pop();
			
			a*=b;
		}
		_max = a;
		
		printf("The maximum and minimum are %lld and %lld.\n", _max, _min);
	}
	
	
	return 0;
}