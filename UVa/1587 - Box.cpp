#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iterator>
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
	
	bool operator==(const T& t) const
	{
		return a==t.a && b==t.b;
	}
};

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int a, b;
	while(cin>>a>>b)
	{
		if(a>b) swap(a, b);
		
		vector<T> v;
		v.push_back(T(a, b));
		
		for(int i = 0; i<5; ++i)
		{
			cin>>a>>b;
			
			if(a>b) swap(a, b);
			v.push_back(T(a, b));
		}
		
		sort(v.begin(), v.end());
		if(!(v[0]==v[1] && v[2]==v[3] && v[4]==v[5]))
		{
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}
		
		v.resize(distance(v.begin(), unique(v.begin(), v.end())));
		
		if(v.size()==1)
		{
			if(v[0].a==v[0].b) cout<<"POSSIBLE"<<endl;
			else cout<<"IMPOSSIBLE"<<endl;
		}
		else if(v.size()==2)
		{
			if(v[0].a != v[0].b) swap(v[0], v[1]);
			if(v[0].a==v[0].b && (v[1].a==v[0].a || v[1].b==v[0].b)) cout<<"POSSIBLE"<<endl;
			else cout<<"IMPOSSIBLE"<<endl;
		}
		else
		{
			bool ok = true;
			for(int i = 0; i<3; ++i)
			{
				if(v[i].a==v[i].b)
				{
					ok = false;
					break;
				}
			}
			
			if(ok)
			{
				vector<int> v2;
				for(int i = 0; i<3; ++i)
				{
					v2.push_back(v[i].a);
					v2.push_back(v[i].b);
				}
				
				sort(v2.begin(), v2.end());
				
				for(int i = 0; i<6; i+=2)
				{
					if(v2[i]!=v2[i+1])
					{
						ok = false;
						break;
					}
				}
			}
			
			if(ok) cout<<"POSSIBLE"<<endl;
			else cout<<"IMPOSSIBLE"<<endl;
		}
	}
	
	
	return 0;
}