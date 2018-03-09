#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool is_prime[801];
vector<int> v;

void prime()
{
	fill(is_prime+2, is_prime+801, true);
	
	for(int i = 2; i<=800; ++i)
	{
		if(is_prime[i])
		{
			for(int j = i+i; j<=800; j+=i) is_prime[j] = false;
		}
	}
	
	for(int i = 2; i<=800; ++i)
	{
		if(is_prime[i])
		{
			v.push_back(i);
		}
	}
}

int cal_sum(int n, int p)
{
	if(n) return cal_sum(n/p, p) + n/p;
	else return 0;
}

int sum_in_B(int B, int p)
{
	int sum = 0;
	while(B%p==0 && B)
	{
		B/=p;
		++sum;
	}
	
	return sum;
}

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);


	prime();
	
	int N, B;
	while(cin>>N>>B)
	{
		int p = 0;
		for(int i = v.size()-1; i>=0; --i)
		{
			if(B%v[i]==0)
			{
				p = v[i];
				break;
			}
		}
		
		int num = sum_in_B(B, p);
		
		int sum_zero = cal_sum(N, p)/num;
		
		double d = 0;
		for(int i = 1; i<=N; ++i) d+=log(i);
		d/=log(B);
		
		int sum_digit = d+1;
		
		cout<<sum_zero<<' '<<sum_digit<<endl;
	}
	
	
	return 0;
}