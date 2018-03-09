#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 109;
string arr[N];
bool vis[N];

int same(const string& a, const string& b)
{
	int sum = 0;
	for(int i = 0; i<a.size() && i<b.size(); i++)
	{
		if(a[i]==b[i]) sum++;
		else break;
	}
	
	return sum;
}

int main()
{
//	freopen("stdout.txt", "w", stdout);
//	freopen("stdin.txt", "r", stdin);
	
	
	int n;
	cin>>n;
	while(n--)
	{
		memset(vis, false, sizeof(vis));
		
		int m;
		cin>>m;
		for(int i = 1; i<=m; ++i)
		{
			cin>>arr[i];
		}
		
		vis[1] = true;
		int sum = arr[1].size();
		int k = 1;
		vector<string> v;
		v.push_back(arr[1]);
		
		bool up = false;
		while(true)
		{
			up = false;
			
			int j = -1;
			int _max = -1;
			for(int i = 2; i<=m; ++i)
			{
				if(!vis[i])
				{
					up = true;
					
					int a = same(arr[k], arr[i]);
					if(a>_max)
					{
						_max = a;
						j = i;
					}
				}
			}
			
			if(!up) break;
			sum+=arr[j].size()-_max;
			vis[j] = true;
			k = j;
			v.push_back(arr[j]);
		}
		
		cout<<sum<<endl;
		for(int i = 0; i<v.size(); ++i) cout<<v[i]<<endl;
	}
	
	
	return 0;
}