#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 100009;
int arr[N];

void init()
{
	memset(arr, 0, sizeof(arr));
	
	for(int n = 1; n<N; ++n)
	{
		int _n = n;
		
		int sum = _n;
		while(_n)
		{
			sum+=_n%10;
			_n/=10;
		}
		
		if(!arr[sum] || n<arr[sum]) arr[sum] = n;
	}
}

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	init();
	
	int n;
	cin>>n;
	while(n--)
	{
		int a;
		cin>>a;
		
		cout<<arr[a]<<endl;
	}
	
	
	return 0;
}