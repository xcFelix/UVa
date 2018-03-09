#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

string s[] = { "an Unhappy", "a Happy" };

int sum_n(int n)
{
	int sum = 0;
	while(n)
	{
		int t = n%10;
		n/=10;
		
		sum+=t*t;
	}
	
	return sum;
}

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int sum_case = 0;
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		set<int> st;
		st.insert(n);
		
		int _n = n;
		bool happy = false;
		while(true)
		{
			n = sum_n(n);
			
			if(n==1)
			{
				happy = true;
				break;
			}
			else
			{
				if(st.count(n)) break;
				else st.insert(n);
			}
		}
		
		printf("Case #%d: %d is %s number.\n", ++sum_case, _n, s[happy].c_str());
	}
	
	
	return 0;
}