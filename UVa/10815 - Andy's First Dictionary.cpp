#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	vector<string> v;
	string s, s_temp;
	while(getline(cin, s))
	{
		if(s.size())
		{
			s.push_back('#');
			for(int i = 0; i<s.size()-1; ++i)
			{
				if(isalpha(s[i]))
				{
					for(int j = i; j<s.size() && isalpha(s[j]); ++j)
					{
						s_temp.push_back(tolower(s[j]));
					}
					v.push_back(s_temp);
					i+=s_temp.size();
					s_temp.clear();
				}
			}
		}
	}
	sort(v.begin(), v.end());
	v.resize(distance(v.begin(), unique(v.begin(), v.end())));
	for(int i = 0; i<v.size(); ++i) cout<<v[i]<<endl;
	
	
	return 0;
}