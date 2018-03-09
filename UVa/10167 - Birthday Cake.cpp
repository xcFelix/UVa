#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

struct T{
	int x;
	int y;
	
	T(const int& _x = 0, const int& _y = 0)
	: x(_x), y(_y) {}
	
	static const int R2 = 100*100;
	bool valid()
	{
		return x*x+y*x<R2;
	}
};

bool same(int A, int B, const vector<T>& v)
{
	int up = 0;
	int down = 0;
	
	bool ok = true;
	for(int i = 0; i<v.size(); ++i)
	{
		int x = v[i].x;
		int y = v[i].y;
		
		if(A*x+B*y==0)
		{
			ok = false;
			break;
		}
		else if(A*x+B*y>0) down++;
		else up++;
	}
	
	if(ok) return down==up;
	return false;
}

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int n;
	while(cin>>n && n)
	{
		n*=2;
		
		vector<T> v;
		for(int i = 0; i<n; ++i)
		{
			int x, y;
			cin>>x>>y;
			
			T t(x, y);
			if(t.valid()) v.push_back(t);
		}
		
		for(int A = -500; A<=500; ++A)
		{
			bool ok = false;
			for(int B = -500; B<=500; ++B)
			{
				if(same(A, B, v))
				{
					cout<<A<<' '<<B<<endl;
					ok = true;
					break;
				}
			}
			
			if(ok) break;
		}
	}
	
	
	return 0;
}