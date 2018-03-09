#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
using namespace std;

struct P{
	int x;
	int y;
	
	P(const int& _x, const int& _y)
	: x(_x), y(_y) {}
};

struct T{
	string s;
	
	T(const int& n)
	:s(string(n*n, 0)) {}
	
	bool operator<(const T& t) const
	{
		return s<t.s;
	}
};

void rotate(T& t, const int& n)
{
	string s(t.s);
	
	for(int i = 0; i<s.size(); ++i)
	{
		int x = i/n;
		int y = i%n;
		
		int _x = y;
		int _y = n-x-1;
		
		t.s[_x*n+_y] = s[i];
	}
}

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int n;
	while(cin>>n && n)
	{
		vector<P> v;
		
		for(int i = 0; i<2*n; ++i)
		{
			int x, y;
			char ch;
			cin>>x>>y>>ch;
			
			v.push_back(P(x-1, y-1));
		}
		
		set<T> st;
		T t(n);
		st.insert(t);
		
		int ok = false;
		for(int i = 0; i<v.size(); ++i)
		{
			int x = v[i].x;
			int y = v[i].y;
			int index = x*n+y;
			
			t.s[index] = t.s[index]?0:1;
			
			bool has = false;
			set<T> _st;
			for(int j = 0; j<4; ++j)
			{
				rotate(t, n);
				if(st.count(t))
				{
					has = true;
					break;
				}
				else
				{
					_st.insert(t);
				}
			}
			
			if(has)
			{
				ok = i;
				break;
			}
			
			st.insert(_st.begin(), _st.end());
		}
		
		if(ok) printf("Player %d wins on move %d\n", (ok+1)%2+1, ok+1);
		else cout<<"Draw"<<endl;
	}
	
	
	return 0;
}