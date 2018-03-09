#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct T{
	int a, b;
	
	T(const int _a = 0, const int _b = 0) 
	: a(_a), b(_b) {}
	
	int operator*(const T& t) const
	{
		if(b!=t.a) return -1;
		return a*b*t.b;
	}
};

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);

	
	int n;
	cin>>n;
	map<int, T> mp;
	for(int i = 0; i<n; ++i)
	{
		char c;
		int a, b;
		cin>>c>>a>>b;
		
		mp[c] = T(a, b);
	}
	
	cin.get();
	string s;
	while(getline(cin, s))
	{
		if(s.size()==1)
		{
			cout<<0<<endl;
			continue;
		}
		
		map<int, T> _mp(mp);
		
		int ext = 299;
		bool err = false;
		vector<int> v;
		int sum = 0;
		for(int i = 0; i<s.size(); ++i)
		{
			if(s[i]==')')
			{
				if(v[v.size()-3]!='(')
				{
					err = true;
					break;
				}
				else
				{
					int b = v.back(); v.pop_back();
					int a = v.back(); v.pop_back(); v.pop_back();
					
					_mp[ext] = T(_mp[a].a, _mp[b].b);
					v.push_back(ext++);
					
					int _sum = _mp[a]*_mp[b];
					if(_sum==-1)
					{
						err = true;
						break;
					}
					else sum+=_sum;
				}
			}
			else v.push_back(s[i]);
		}
		
		if(err) cout<<"error"<<endl;
		else cout<<sum<<endl;
	}
	
	return 0;
}