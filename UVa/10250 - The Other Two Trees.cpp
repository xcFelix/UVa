#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

const double eps = 1e-9;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);

	
	double x1, x2, y1, y2;
	while(cin>>x1>>y1>>x2>>y2)
	{
		if(fabs(x1-x2)<eps && fabs(y1-y2)<eps)
		{
			cout<<"Impossible."<<endl;
			continue;
		}
		
		double a = (y1-y2)/2-(x2-x1)/2;
		double b = (y1-y2)/2+(x2-x1)/2;
		
		x1 = x1-a;
		y1 = y1-b;
		
		x2 = x2+a;
		y2 = y2+b;
		
		printf("%.10lf %.10lf %.10lf %.10lf\n", x1, y1, x2, y2);
	}
	
	
	return 0;
}