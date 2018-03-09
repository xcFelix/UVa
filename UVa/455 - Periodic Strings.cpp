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
		
		int min_n = s.size();
		for(int i = 1; i<=s.size(); ++i)
		{
			if(s.size()%i) continue;
			
			bool ok = true;
			for(int j = i; j<s.size(); ++j)
			{
				if(s[j]!=s[j%i])
				{
					ok = false;
					break;
				}
			}
			
			if(ok)
			{
				min_n = i;
				break;
			}
		}
		
		cout<<min_n<<endl;
		if(n) cout<<endl;
	}
	
	
	return 0;
}