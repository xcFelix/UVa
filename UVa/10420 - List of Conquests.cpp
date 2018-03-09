#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	map<string, int> mp;
	int n;
	cin>>n;
	cin.get();
	for(int i = 0; i<n; ++i)
	{
		string s;
		getline(cin, s);
		int index = s.find(' ');
		s = s.substr(0, index);
		++mp[s];
	}
	
	for(map<string, int>::iterator it = mp.begin(); it!=mp.end(); ++it)
	{
		cout<<it->first<<' '<<it->second<<endl;
	}
	
	
	return 0;
}