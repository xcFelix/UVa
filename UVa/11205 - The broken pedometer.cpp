#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 19;
bool arr[109][N];
bool use[N];
int p, n;

void subset(int n, int s)
{
	for(int i = 0; i<n; ++i)
	{
		if(s&(1<<i)) use[i] = true;
		else use[i] = false;
	}
}

bool valid()
{
	for(int i = 1; i<n; ++i)
	{
		for(int j = i+1; j<=n; ++j)
		{
			bool same = true;
			for(int k = 1; k<=p; ++k)
			{
				if(use[k-1])
				{
					if(arr[i][k]!=arr[j][k])
					{
						same = false;
						break;
					}
				}
			}
			
			if(same) return false;
		}
	}
	
	return true;
}

int bit_num(int n)
{
	int sum = 0;
	while(n)
	{
		if(n&1) sum++;
		n>>=1;
	}
	
	return sum;
}

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int t;
	cin>>t;
	while(t--)
	{
		cin>>p>>n;
		
		for(int i = 1; i<=n; ++i)
		{
			for(int j = 1; j<=p; ++j)
			{
				cin>>arr[i][j];
			}
		}
		
		int min_n = 1<<30;
		for(int i = 0; i<(1<<p); ++i)
		{
			subset(n, i);
			
			if(valid())
			{
				min_n = min(min_n, bit_num(i));
			}
		}
		
		cout<<min_n<<endl;
	}
	
	
	return 0;
}