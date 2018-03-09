#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

struct T{
	int a;
	int b;
	
	T(const int& _a = 0, const int& _b = 0)
	: a(_a), b(_b) {}
	
	bool operator<(const T& t) const
	{
		if(a!=t.a) return a<t.a;
		return b<t.b;
	}
};

int main()
{
//	freopen("stdout.txt", "w", stdout);
//	freopen("stdin.txt", "r", stdin);
	
	
	int n;
	while(cin>>n && n)
	{
		map<T, int> mp;
		
		for(int i = 0; i<n; ++i)
		{
			int a, b;
			cin>>a>>b;
			mp[T(a, b)]++;
			mp[T(b, a)]--;
		}
		
		bool ok = true;
		for(map<T, int>::iterator it = mp.begin();
		it!=mp.end(); ++it)
		{
			if(it->second)
			{
				ok = false;
				break;
			}
		}
		
		if(ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	
	return 0;
}