#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

struct T{
	string l;
	string r;
	vector<int> v;
	
	T(const string& _l = "", const string& _r="", vector<int> _v = vector<int>())
	: l(_l), r(_r), v(_v) {}
	
	bool operator==(const T& t) const
	{
		return l==t.l && r==t.r;
	}
	
	bool operator<(const T& t) const
	{
		if(l!=t.l) return l<t.l;
		return r<t.r;
	}
};

void r_rota(string& l, string& r, int i)
{
	switch(i)
	{
		case 1:
			{
				rotate(l.begin(), l.begin()+2, l.end());
				r.replace(r.size()-3, 3, l, l.size()-3, 3);
				break;
			}
		case 2:
			{
				rotate(r.begin(), r.end()-2, r.end());
				l.replace(l.size()-3, 3, r, r.size()-3, 3);
				break;
			}
		case 3:
			{
				rotate(l.begin(), l.end()-2, l.end());
				r.replace(r.size()-3, 3, l, l.size()-3, 3);
				break;
			}
		case 4:
			{
				rotate(r.begin(), r.begin()+2, r.end());
				l.replace(l.size()-3, 3, r, r.size()-3, 3);
				break;
			}
	}
}

void rbfs(const T& des, set<T>& rst)
{
	rst.insert(des);
	
	queue<T> Q;
	Q.push(des);
	
	while(Q.size())
	{
		T t = Q.front(); Q.pop();
		
		for(int i = 1; i<=4; ++i)
		{
			string l = t.l;
			string r = t.r;
			
			r_rota(l, r, i);
			T _t(l, r, t.v);
			_t.v.push_back(i);
			
			if(!rst.count(_t) && _t.v.size()<=8)
			{
				rst.insert(_t);
				Q.push(_t);
			}
		}
	}
}


void rota(string& l, string& r, int i)
{
	switch(i)
	{
		case 1:
			{
				rotate(l.begin(), l.end()-2, l.end());
				r.replace(r.size()-3, 3, l, l.size()-3, 3);
				break;
			}
		
		case 2:
			{
				rotate(r.begin(), r.begin()+2, r.end());
				l.replace(l.size()-3, 3, r, r.size()-3, 3);
				break;
			}
			
		case 3:
			{
				rotate(l.begin(), l.begin()+2, l.end());
				r.replace(r.size()-3, 3, l, l.size()-3, 3);
				break;
			}
			
		case 4:
			{
				rotate(r.begin(), r.end()-2, r.end());
				l.replace(l.size()-3, 3, r, r.size()-3, 3);
				break;
			}
	}
}

T bfs(const T& src, const set<T>& rst, set<T>& st)
{
	queue<T> Q;
	Q.push(src);
	
	st.insert(src);
	
	T _min = T("", "", vector<int>(16, 4));
	while(Q.size())
	{
		T t = Q.front(); Q.pop();
		
		if(rst.count(t))
		{
			set<T>::iterator it = rst.find(t);
			const vector<int>& v = it->v;
			
			for(int i = v.size()-1; i>=0; --i)
			{
				t.v.push_back(v[i]);
			}
			
			if(t.v.size()>_min.v.size()) continue;
			if(t.v.size()<_min.v.size())
			{
				_min = t;
				continue;
			}
			for(int i = 0; i<t.v.size(); ++i)
			{
				if(t.v[i]<_min.v[i])
				{
					_min = t;
					break;
				}
			}
			
			continue;
		}
		
		for(int i = 1; i<=4; ++i)
		{
			string l = t.l;
			string r = t.r;
			
			rota(l, r, i);
			T _t(l, r, t.v);
			_t.v.push_back(i);
			
			if(!st.count(_t) && _t.v.size()<=8)
			{
				st.insert(_t);
				Q.push(_t);
			}
		}
	}
	
	return _min;
}

int main()
{
//	freopen("stdout.txt", "w", stdout);
//	freopen("stdin.txt", "r", stdin);
	
	T des("034305650121", "078709:90121"); //':' stands for 10 (acsii code)
	
	set<T> rst;
	rbfs(des, rst); //构造搜索表 
	
	int n;
	cin>>n;
	while(n--)
	{
		string l(12, 0);
		string r(12, 0);
		for(int i = 0; i<12; ++i)
		{
			int a;
			cin>>a;
			l[i] = a+'0';
		}
		for(int i = 0; i<12; ++i)
		{
			int a;
			cin>>a;
			r[i] = a+'0';
		}
		
		T src(l, r);

		if(src==des) cout<<"PUZZLE ALREADY SOLVED"<<endl;
		else
		{
			set<T> st;
			
			T t = bfs(src, rst, st);
			if(t.l=="") cout<<"NO SOLUTION WAS FOUND IN 16 STEPS"<<endl;
			else
			{
				vector<int>& v = t.v;
				for(int i = 0; i<v.size(); ++i) cout<<v[i];
				cout<<endl;
			}
		}
	}
	
	
	return 0;
}