#include <iostream>
#include <numeric>
#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1029;
bool arr[N];

void solve(int lo, int hi)
{
	char ch;
	cin>>ch;
	
	if(ch=='e') return;
	if(ch=='f')
	{
		fill(arr+lo, arr+hi, true);
		return;
	}
	
	int len = (hi-lo)/4;
	for(int i = 0; i<4; ++i) solve(lo+len*i, lo+len*(i+1));
}

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int n;
	cin>>n;
	while(n--)
	{
		solve(0, 1024);
		solve(0, 1024);
		
		printf("There are %d black pixels.\n", count(arr, arr+1024, true));
		
		fill(arr, arr+N, false);
	}
	
	
	return 0;
}