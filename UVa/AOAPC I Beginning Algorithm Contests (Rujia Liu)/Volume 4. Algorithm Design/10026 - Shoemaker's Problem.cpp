#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct T{
	int n;
	double d;
	
	T(const int& _n, const double& _d)
	: n(_n), d(_d) {}
	
	bool operator<(const T& t) const
	{
		return d<t.d;
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
		vector<T> v;
		
		int m;
		cin>>m;
		for(int i = 0; i<m; ++i)
		{
			int a, b;
			cin>>a>>b;
			
			v.push_back(T(i+1, a/(b+.0)));
		}
		
		stable_sort(v.begin(), v.end()); //sort() Ò²ÄÜ¹ý
		
		cout<<v[0].n;
		for(int i = 1; i<m; ++i) cout<<' '<<v[i].n;
		cout<<endl;
		if(n) cout<<endl;
	}
	
	
	return 0;
}