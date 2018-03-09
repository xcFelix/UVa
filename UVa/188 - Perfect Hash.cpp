#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int arr[5] = { 1 };

int sum_str(string& s)
{
	int sum = 0;
	reverse(s.begin(), s.end());
	for(int i = 0; i<s.size(); ++i)
	{
		sum+=(s[i]-'a'+1)*arr[i];
	}
	
	return sum;
}

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	for(int i = 1; i<=4; ++i) arr[i] = arr[i-1]*32;
	
	string s;
	while(getline(cin, s))
	{
		stringstream ss(s);
		
		int n = 0;
		vector<int> v;
		string sub_str;
		while(ss>>sub_str)
		{
			++n;
			v.push_back(sum_str(sub_str));
		}
		
		sort(v.begin(), v.end());
		
		int c = v[0];
		bool ok = true;
		while(true)
		{
			ok = true;
			
			for(int i = 0; i<v.size()-1; ++i)
			{
				for(int j = i+1; j<v.size(); ++j)
				{
					int a = c/v[i];
					int b = c/v[j];
					
					if(a%n == b%n)
					{
						c = min((a+1)*v[i], (b+1)*v[j]);
						ok = false;
						break;
					}
				}
				
				if(!ok) break;
			}
			
			if(ok) break;
		}
		
		cout<<s<<endl;
		cout<<c<<endl;
		cout<<endl;
	}
	
	
	return 0;
}