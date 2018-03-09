#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1009;
int arr[N];
int sum[N*N+9];

int main()
{
//	freopen("stdout.txt", "w", stdout);
//	freopen("stdin.txt", "r", stdin);
	
	
	int sum_case = 0;
	int n;
	while(cin>>n && n)
	{
		for(int i = 0; i<n; ++i)
		{
			cin>>arr[i];
		}
		
		int pos = 0;
		for(int i = 0; i<n-1; ++i)
		{
			for(int j = i+1; j<n; ++j)
			{
				sum[pos++] = arr[i]+arr[j];
			}
		}
		sort(sum, sum+pos);
		
		printf("Case %d:\n", ++sum_case);
		int m;
		cin>>m;
		while(m--)
		{
			int a;
			cin>>a;
			
			int* p= lower_bound(sum, sum+pos, a);
			
			int b;
			if(p==sum+pos) b = *(p-1);
			else if(p==sum) b = *p;
			else
			{
				int lo = *(p-1);
				int hi = *p;
				
				b = a-lo<hi-a?lo:hi;
			}
			
			printf("Closest sum to %d is %d.\n", a, b);
		}
	}
	
	
	return 0;
}