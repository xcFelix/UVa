#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

struct T{
	int a, b;
	int sum;
	
	T(const int& _a = 0, const int& _b = 0)
	: a(_a), b(_b), sum(_a+_b) {}
	
	bool operator<(const T& t) const
	{
		return sum<t.sum;
	}
	
	bool operator>(const T& t) const
	{
		return sum>t.sum;
	}
};

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int n;
	while(cin>>n && n)
	{
		vector<int> v;
		for(int i = 0; i<n; ++i)
		{
			int t;
			cin>>t;
			
			v.push_back(t);
		}
		
		sort(v.begin(), v.end(), greater<T>());
		set<T> st;
		for(int i = 0; i<v.size()-1; ++i)
		{
			for(int j = i+1; j<v.size(); ++j)
			{
				st.insert(T(v[i], v[j]));
			}
		}
		
		bool ok = false;
		for(int i = 0; i<v.size()-1; ++i)
		{
			for(int j = i+1; j<v.size(); ++j)
			{
					T t;
					t.sum = v[i]-v[j];
				set<T>::iterator it = st.find(t);
				if(it!=st.end() && it->a!=v[j] && it->b!=v[j] && it->a!=v[i] && it->b!=v[i]) //ÓÐ¸ºÊý 
				{
					cout<<v[i]<<endl;
					ok = true;
					break;
				}
			}
			
			if(ok) break;
		}
		
		if(!ok) cout<<"no solution"<<endl;
	}
	
	
	return 0;
}