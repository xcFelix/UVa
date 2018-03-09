#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int case_n = 0;
	long long a, b;
	while(cin>>a>>b && !(a<0 && b<0))
	{
		long long temp_a = a;
		int term = 0;
		while(a!=1 && a<=b)
		{
			if(a%2) a = a*3+1;
			else a>>=1;
			++term;
		}
		if(a==1) ++term;
		
		printf("Case %d: A = %d, limit = %d, number of terms = %d\n", ++case_n, temp_a, b, term);
	}
	
	
	return 0;
}