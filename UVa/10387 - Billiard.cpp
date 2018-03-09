#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

const double eps = 1e-9;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);

	
	int a, b, s, m, n;
	while(cin>>a>>b>>s>>m>>n && a)
	{
		int la = a*m;
		int lb = b*n;
		
		double va = (double)la/s;
		double vb = (double)lb/s;
		
		double v = sqrt(pow(va, 2)+pow(vb, 2));
		double angle = atan(vb/va)/acos(-1.0)*180;
		
		printf("%.2lf %.2lf\n", angle, v);
	}
	
	
	return 0;
}