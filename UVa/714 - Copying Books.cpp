#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 509;
int arr[N];
bool b[N];
int k, m;

bool valid(long long _max)
{
	memset(b, false, sizeof(b));
	
	int _m = m;
	for(int i = k; i>=1; )
	{
		_m--;
		if(_m<0) return false;
		
		long long sum = 0;
		while(sum<=_max && i>_m)
		{
			sum+=arr[i];
			i--;
		}
		
		if(sum>_max) i++;
		b[i] = true;
		if(i==0) return true;
	}
}

int main()
{
//	freopen("stdout.txt", "w", stdout);
//	freopen("stdin.txt", "r", stdin);
	
	
	int n;
	cin>>n;
	while(n--)
	{
		cin>>k>>m;
		for(int i = 1; i<=k; ++i)
		{
			cin>>arr[i];
		}
		
		long long lo = arr[k];
		long long hi = 0;
		for(int i = 1; i<=k; ++i) hi+=arr[i];
		while(lo+1<hi)
		{
			long long mid = (lo+hi)>>1;
			if(valid(mid)) hi = mid;
			else lo = mid;
		}
		
		valid(hi);
		
		cout<<arr[1];
		if(b[1]) cout<<" /";
		for(int i = 2; i<=k; ++i)
		{
			cout<<' '<<arr[i];
			if(b[i]) cout<<" /";
		}
		cout<<endl;
	}
	
	
	return 0;
}