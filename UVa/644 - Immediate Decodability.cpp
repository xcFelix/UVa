#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct cmp{
	bool operator()(const string& s1, const string& s2)
	{
		return s1.size()<s2.size();
	}
};

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	string s;
	int sum_case = 0;
	while(cin>>s)
	{
		vector<string> v;
		v.push_back(s);
		while(cin>>s && !(s[0]=='9'))
		{
			v.push_back(s);
		}
		
		sort(v.begin(), v.end(), cmp());
		
		bool ok = true;
		for(int i = 0; i<v.size()-1; ++i)
		{
			for(int j = i+1; j<v.size(); ++j)
			{
				if(v[j].find(v[i])==0)
				{
					ok = false;
					break;
				}
				if(ok==false) break;
			}
		}
		
		if(ok) cout<<"Set "<<++sum_case<<" is immediately decodable"<<endl;
		else cout<<"Set "<<++sum_case<<" is not immediately decodable"<<endl;
	}
	
	
	return 0;
}