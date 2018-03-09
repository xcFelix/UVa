#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1000009;
int arr[N];

int main()
{
//	freopen("stdout.txt", "w", stdout);
//	freopen("stdin.txt", "r", stdin);
	
	
	int n;
	cin>>n;
	while(n--)
	{
		int len, m;
		cin>>len>>m;
		for(int i = 0; i<m; ++i) cin>>arr[i];
		
		int _min = 0;
		for(int i = 0; i<m; ++i)
		{
			_min = max(_min, min(arr[i], len-arr[i]));
		}
		
		int _max = 0;
		for(int i = 0; i<m; ++i)
		{
			_max = max(_max, max(arr[i], len-arr[i]));
		}
		
		cout<<_min<<' '<<_max<<endl;
	}
	
	
	return 0;
}