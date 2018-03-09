#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct T{
	int l, r;
	
	T(const int& _l, const int& _r)
	: l(_l), r(_r) {}
	
	bool operator<(const T& t) const 
	{
		return l<t.l;
	}
};

int main()
{
//	freopen("stdout.txt", "w", stdout);
//	freopen("stdin.txt", "r", stdin);
	
	
	int n;
	cin>>n;
	while(n--)
	{
		int m;
		cin>>m;
		
		vector<T> v;
		int a, b;
		while(cin>>a>>b && !(a==0 && b==0))
		{
			if(a>=m || b<=0) continue;
			v.push_back(T(a, b));
		}
		
		sort(v.begin(), v.end());
		
		if(!v.size() || v.front().l>0)
		{
			cout<<0<<endl;
			if(n) cout<<endl;
		}
		else
		{
			bool ok = true;
			vector<T> v1;
			int lo = 0;
			for(int i = 0; i<v.size(); )
			{	
				int k = i;
				if(v[i].l>lo)
				{
					ok = false;
					break;
				}
				
				int j;
				for(j = i+1; j<v.size(); ++j)
				{
					if(v[j].l>lo) break;
					if(v[j].r>v[k].r) k = j;
				}
				
				v1.push_back(v[k]);
				lo = v[k].r;
				i = j;
				
				if(lo>=m) break;
			}
			
			if(ok && v1.back().r>=m)
			{
				cout<<v1.size()<<endl;
				for(int i = 0; i<v1.size(); ++i)
				{
					cout<<v1[i].l<<' '<<v1[i].r<<endl;
				}
				
				if(n) cout<<endl;
			}
			else
			{
				cout<<0<<endl;
				if(n) cout<<endl;
			}
		}
	}
	
	
	return 0;
}