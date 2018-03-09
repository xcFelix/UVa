#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

const int N = 13;
vector<int> G1[N]; //door
vector<int> G2[N]; //switch

string conv[] = { "", "- Move to room ", "- Switch off light in room ", "- Switch on light in room " };

void init()
{
	for(int i = 1; i<N; ++i)
	{
		G1[i].clear();
		G2[i].clear();
	}
}

struct P{
	int op;
	int x;
	
	P(const int& _op = 0, const int& _x = 0)
	: op(_op), x(_x) {}
};

struct T{
	int r;
	int step;
	int statu;
	vector<P> v;
	
	T(const int& _r = 0, const int& _step = 0, const int& _statu = 0, const vector<P>& _v = vector<P>())
	: r(_r), step(_step), statu(_statu), v(_v) {}
	
	bool operator==(const T& t) const
	{
		return r==t.r && statu==t.statu;
	}
};

struct H{
	int r;
	int statu;
	
	H(const int& _r, const int& _statu)
	: r(_r), statu(_statu) {}
	
	bool operator<(const H& h) const
	{
		if(r!=h.r) return r<h.r;
		return statu<h.statu;
	}
};

T bfs(const T& src, const T& des)
{
	set<H> st;
	st.insert(H(src.r, src.statu));
	
	queue<T> Q;
	Q.push(src);
	
	while(Q.size())
	{
		T t = Q.front(); Q.pop();
		
		if(t==des) return t;
		
		int u = t.r;
		for(int i = 0; i<G1[u].size(); ++i)
		{
			int v = G1[u][i];
			if(1<<v & t.statu)
			{
				T _t(t);
				_t.r = v;
				_t.step++;
				_t.v.push_back(P(1, v));
				
				H h(_t.r, _t.statu);
				if(!st.count(h))
				{
					st.insert(h);
					Q.push(_t);
				}
			}
		}
		
		for(int i = 0; i<G2[u].size(); ++i)
		{
			if(G2[u][i]==u) continue;
			
			int v = G2[u][i];
			if(1<<v & t.statu)
			{
				T _t(t);
				_t.statu ^= 1<<v;
				_t.step++;
				_t.v.push_back(P(2, v));
				
				H h(_t.r, _t.statu);
				if(!st.count(h))
				{
					st.insert(h);
					Q.push(_t);
				}
			}
			else
			{
				T _t(t);
				_t.statu ^= 1<<v;
				_t.step++;
				_t.v.push_back(P(3, v));
				
				H h(_t.r, _t.statu);
				if(!st.count(h))
				{
					st.insert(h);
					Q.push(_t);
				}
			}
		}
	}
	
	return src;
}

int main()
{
//	freopen("stdout.txt", "w", stdout);
//	freopen("stdin.txt", "r", stdin);
	
	
	int sum_case = 0;
	int r, d, s;
	while(cin>>r>>d>>s && !(r==0 && d==0 && s==0))
	{
		init();
		
		for(int i = 1; i<=d; ++i)
		{
			int u, v;
			cin>>u>>v;
			
			G1[u].push_back(v);
			G1[v].push_back(u);
		}
		
		for(int i = 1; i<=s; ++i)
		{
			int u, v;
			cin>>u>>v;
			
			G2[u].push_back(v);
		}
		
		for(int i = 1; i<=r; ++i)
		{
			sort(G1[i].begin(), G1[i].end());
			sort(G2[i].begin(), G2[i].end());
		}
		
		T src(1, 0, 1<<1);
		T des(r, 0, 1<<r);
		
		printf("Villa #%d\n", ++sum_case);
		
		if(src==des)
		{
			cout<<"The problem can be solved in 0 steps:"<<endl;
			cout<<endl;
			continue;
		}
		
		T t = bfs(src, des);
		if(t==src) cout<<"The problem cannot be solved."<<endl;
		else
		{
			printf("The problem can be solved in %d steps:\n", t.step);
			vector<P>& v = t.v;
			for(int i = 0; i<v.size(); ++i)
			{
				cout<<conv[v[i].op]<<v[i].x<<'.'<<endl;
			}
		}
		
		cout<<endl;
	}
	
	
	return 0;
}