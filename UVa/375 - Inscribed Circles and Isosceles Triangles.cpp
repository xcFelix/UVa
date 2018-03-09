#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);

	
	int n;
	cin>>n;
	while(n--)
	{
		double b, h;
		//cin>>b>>h;
		scanf("%lf %lf", &b, &h);
		
		double l = sqrt(pow(b/2, 2)+pow(h, 2));
		double p = b/(2*l+b);
		
		double _h = 0;
		double r = h*p;
		while(r>=1e-6)
		{
			_h+=2*r;
			h-=2*r;
			r = h*p;
		}
		
		printf("%13.6lf\n", _h*acos(-1));
		//if(n) cout<<endl;
		if(n) printf("\n");
	}
	
	
	return 0;
}