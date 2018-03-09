#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <queue>
#include <functional>
using namespace std;

const int N = 19;
bool prime[N];

void init_prime()
{
	fill(prime, prime+N, true);
	
	for(int i = 2; i<N; ++i)
	{
		if(prime[i])
		{
			for(int j = i+i; j<N; j+=i) prime[j] = false;
		}
	}
}

struct T{
	static const int N = 8;
	string s;
	string b;
	int step;
	
	T(const char* _s = "", const int& _step = 0)
	: s(_s), step(_step) {}
	
	friend
	istream& operator>>(istream& in, T& t)
	{
		for(int i = 0; i<N; ++i)
		{
			int a;
			cin>>a;
			
			if(a<0)
			{
				a*=-1;
				t.b += '\0'; //false
			}
			else t.b += true;
			
			t.s += a+'0';
		}
		
		t.step = 0;
		return in;
	}
	
	bool operator==(const T& t) const
	{
		return s==t.s;
	}
	
	bool operator<(const T& t) const
	{
		return s<t.s;
	}
	
	bool operator>(const T& t) const
	{
		return step>t.step;
	}
};

int bfs(T& src, T& des)
{
	priority_queue< T, vector<T>, greater<T> > Q;
	Q.push(src);
	
	set<T> st;
	st.insert(src);
	while(Q.size())
	{
		T t = Q.top(); Q.pop();
		
		if(t==des)
		{
			des.step = t.step;
			break;
		}
		
		for(int i = 0; i<8-1; ++i)
		{
			for(int j = i+1; j<8; ++j)
			{
				if(t.b[i]+t.b[j]==1 && prime[t.s[i]+t.s[j]-2*'0'])
				{
					T _t;
					if(t.s[i]<t.s[j])
					{
						_t = t;
						_t.s.insert(j, 1, _t.s[i]);
						_t.b.insert(j, 1, _t.b[i]);
						
						_t.s.erase(i, 1);
						_t.b.erase(i, 1);
						
						if(!st.count(_t))
						{
							st.insert(_t);
							
							_t.step++;
							Q.push(_t);
						}
						
						
						_t = t;
						_t.s.insert(i+1, 1, _t.s[j]);
						_t.b.insert(i+1, 1, _t.b[j]);
						
						_t.s.erase(j+1, 1);
						_t.b.erase(j+1, 1);
						
						if(!st.count(_t))
						{
							st.insert(_t);
							
							_t.step++;
							Q.push(_t);
						}
					}
					else
					{
						_t = t;
						_t.s.insert(j+1, 1, _t.s[i]);
						_t.b.insert(j+1, 1, _t.b[i]);
						
						_t.s.erase(i, 1);
						_t.b.erase(i, 1);
						
						if(!st.count(_t))
						{
							st.insert(_t);
							
							_t.step++;
							Q.push(_t);
						}
						
						_t = t;
						_t.s.insert(i, 1, _t.s[j]);
						_t.b.insert(i, 1, _t.b[j]);
						
						_t.s.erase(j+1, 1);
						_t.b.erase(j+1, 1);
						
						if(!st.count(_t))
						{
							st.insert(_t);
							
							_t.step++;
							Q.push(_t);
						}
					}
				}
			}
		}
	}
	
	return des.step;
}

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	init_prime();
	
	int sum_case = 0;
	while(cin.peek()!='0')
	{
		T src, des("12345678", -1);
		cin>>src;
		cin.get();
		
		printf("Case %d: %d\n", ++sum_case, bfs(src, des));
	}
	
	
	return 0;
}