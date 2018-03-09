#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 10009;
int arr[N][10];

void init()
{
	memset(arr, 0, sizeof(arr));
	
	for(int n = 1; n<N; ++n)
	{
		int _n = n;
		
		while(_n)
		{
			++arr[n][_n%10];
			_n/=10;
		}
		
		for(int i = 0; i<=9; ++i) arr[n][i] += arr[n-1][i];
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
		
		cout<<arr[a][0];
		for(int i = 1; i<=9; ++i) cout<<' '<<arr[a][i];
		cout<<endl;
	}
	
	
	return 0;
}