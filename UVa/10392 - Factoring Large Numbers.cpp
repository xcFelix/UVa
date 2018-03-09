#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

bool is_prime[1000009];
vector<int> v;

void prime()
{
	fill(is_prime+2, is_prime+1000009, true);
	for(int i = 2; i<=1000000; ++i)
	{
		if(is_prime[i])
		{
			for(int j = i+i; j<=1000000; j+=i) is_prime[j] = false;
		}
	}
	
	for(int i = 2; i<=1000000; ++i)
	if(is_prime[i]) v.push_back(i);
}

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);

	
	prime();
	
	long long a;
	while(cin>>a && a>=0)
	{
		for(int i = 0; i<v.size() && a && a!=1; ++i)
		{
			if(a%v[i]==0)
			{
				while(a%v[i]==0)
				{
					a/=v[i];
					printf("    %d\n", v[i]);
				}
			}
		}
		
		if(a>1) printf("    %lld\n", a);
		cout<<endl;
	}
	
	
	return 0;
}