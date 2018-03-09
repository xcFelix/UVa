#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <sstream>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	string s;
	while(getline(cin, s))
	{
		vector<int> v;
		stringstream ss(s);
		int t;
		while(ss>>t) v.push_back(t);
		
		cout<<s<<endl;
		
		for(int i = v.size()-1; i>0; --i)
		{
			vector<int>::iterator it;
			it = max_element(v.begin(), v.begin()+i+1);
			
			if(v[i]!=*it)
			{
				if(it!=v.begin())
				{
					reverse(v.begin(), it+1);
					cout<<distance(it, v.end())<<' ';
				}
				reverse(v.begin(), v.begin()+i+1);
				cout<<v.size()-i<<' ';
			}
		}
		cout<<0<<endl;
	}

	
	return 0;
}