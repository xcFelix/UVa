#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iterator>
using namespace std;

const int N = 1000009;
int arr[N];

int main()
{
//	freopen("stdout.txt", "w", stdout);
//	freopen("stdin.txt", "r", stdin);
	
	
	int n;
	while(cin>>n)
	{
		for(int i = 0; i<n; ++i) cin>>arr[i];
		
		sort(arr, arr+n);
		
		int lo = (n-1)>>1;
		int hi = lo;
		if(!(n&1)) hi++;
		
		int sum = distance(lower_bound(arr, arr+n, arr[lo]), upper_bound(arr, arr+n, arr[hi]));
		cout<<arr[lo]<<' '<<sum<<' '<<arr[hi]-arr[lo]+1<<endl;
	}
	
	
	return 0;
}