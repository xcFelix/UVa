#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct T{
	int w;
	int s;
	int pre;
	int id;
	
	T(const int& _w = 0, const int& _s = 0, const int& _id = -1, const int& _pre = -1)
	: w(_w), s(_s), id(_id), pre(_pre) {}
	
	bool operator<(const T& t) const
	{
		if(w!=t.w) return w<t.w;
		return s>t.s;
	}
};

const int N = 1009;
T arr[N];
int dp[N];
int pre[N];

int main()
{
//	freopen("stdin.txt", "r", stdin);
//	freopen("stdout.txt", "w", stdout);
	
	
	int w, s;
	int n = 0;
	while(cin>>w>>s)
	{
		arr[n++] = T(w, s, n);
	}
	
	sort(arr, arr+n);
	fill(dp, dp+n, 1);
	
	for(int i = 1; i<n; ++i)
	{
		for(int j = 0; j<i; ++j)
		{
			if(arr[i].w>arr[j].w && arr[i].s<arr[j].s && dp[i]<=dp[j])
			{
				dp[i] = dp[j]+1;
				pre[i] = j;
			}
		}
	}
	
	int i = max_element(dp, dp+n)-dp;
	
	cout<<dp[i]<<endl;
	
	vector<int> v;
	v.push_back(arr[i].id);
	while((i = pre[i])>0)
	{
		v.push_back(arr[i].id);
	}
	
	for(int i = v.size()-1; i>=0; --i)
	{
		cout<<v[i]<<endl;
	}
	
	
	return 0;
}