#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

int dx[] = {  2, 2,  1, 1, -1, -1, -2, -2 };
int dy[] = { -1, 1, -2, 2, -2,  2, -1,  1 };

struct T{
	string s;
	int x, y;
	int step;
	
	T(const string& _s = "", const int& _x = -1, const int& _y = -1, const int& _step = -1)
	: s(_s), x(_x), y(_y), step(_step) {}
	
	bool operator==(const T& t) const
	{
		return s==t.s;
	}
	
	int cal() const
	{
		int sum = 0;
		for(int i = 0; i<s.size(); ++i)
		{
			sum<<=1;
			sum+=s[i]-' ';
		}
		
		return sum;
	}
};

bool valid(int x)
{
	return x>=0 && x<5;
}

int bfs(const T src, const T& des)
{
	queue<T> Q;
	Q.push(src);
	set<int> st;
	st.insert(src.cal());
	
	while(Q.size())
	{
		T t = Q.front(); Q.pop();
		
		if(t.step==11) return 11;
		if(t==des) return t.step;
	
		for(int i = 0; i<8; ++i)
		{
			int _x = t.x+dx[i];
			int _y = t.y+dy[i];
			string _s(t.s);
			int _step = t.step+1;
			
			if(valid(_x) && valid(_y))
			{
				swap(_s[_x*5+_y], _s[t.x*5+t.y]);
				T _t(_s, _x, _y, _step);
				
				int n = _t.cal();
				
				if(!st.count(n))
				{
					st.insert(n);
					Q.push(_t);
				}
			}
		}
	}
}

int main()
{
//	freopen("stdout.txt", "w", stdout);
//	freopen("stdin.txt", "r", stdin);
	
	T des("111110111100 110000100000");
	
	int n;
	cin>>n;
	cin.get();
	while(n--)
	{
		string s;
		T src;
		for(int i = 0; i<5; ++i)
		{
			for(int j = 0; j<5; ++j)
			{
				char ch;
				ch = cin.get();
				s+=ch;
				
				if(ch==' ')
				{
					src.x = i;
					src.y = j;
				}
			}
			cin.get();
		}
		
		src.s = s;
		src.step = 0;
		
		int step = bfs(src, des);
		if(step==11) cout<<"Unsolvable in less than 11 move(s)."<<endl;
		else printf("Solvable in %d move(s).\n", step);
	}
	
	
	return 0;
}