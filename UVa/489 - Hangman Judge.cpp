#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int n;
	while(cin>>n && n>0)
	{
		cout<<"Round "<<n<<endl;
		
		string s1, s2;
		cin>>s1>>s2;
		sort(s1.begin(), s1.end());
		s1.resize(distance(s1.begin(), unique(s1.begin(), s1.end())));
		
		int sum_ok = 0;
		int sum_err = 0;
		set<int> st;
		bool chickened = true;
		for(int i = 0; i<s2.size(); ++i)
		{
			if(st.count(s2[i])) continue;
			st.insert(s2[i]);
			
			if(s1.find(s2[i])==string::npos)
			{
				if(++sum_err==7)
				{
					cout<<"You lose."<<endl;
					chickened = false;
					break;
				}
			}
			else
			{
				if(++sum_ok==s1.size())
				{
					cout<<"You win."<<endl;
					chickened = false;
					break;
				}
			}
		}
		
		if(chickened) cout<<"You chickened out."<<endl;
	}
	
	
	return 0;
}