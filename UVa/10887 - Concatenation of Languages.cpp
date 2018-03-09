#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
using namespace std;

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int sum_case = 0;
	int n;
	cin>>n;
	while(n--)
	{
		vector<string> v1;
		vector<string> v2;
		
		int a, b;
		cin>>a>>b;
		cin.get();
		for(int i = 0; i<a; ++i)
		{
			string s;
			getline(cin, s);
			
			v1.push_back(s);
		}
		
		for(int i = 0; i<b; ++i)
		{
			string s;
			getline(cin, s);
			
			v2.push_back(s);
		}
		
		set<string> st;
		for(int i = 0; i<a; ++i)
		{
			for(int j = 0; j<b; ++j)
			{
				st.insert(v1[i]+v2[j]);
			}
		}
		
		printf("Case %d: ", ++sum_case);
		cout<<st.size()<<endl;
	}
	
	
	return 0;
}