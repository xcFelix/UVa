#include <iostream>
#include <cmath>
#include <cstdio>
#include <sstream>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);

	
	string s;
	while(cin>>s && !(s.size()==4 && s[0]=='0' && s[2]=='0' && s[3]=='0'))
	{
		stringstream ss(s);
		
		int a, b;
		char ch;
		ss>>a>>ch>>b;
		
		double angle_a = (double)a/12*360;
		double angle_b = (double)b/60*360;
		angle_a+=(double)b/60*360/12;
		
		double angle = fabs(angle_a-angle_b);
		if(angle>180) angle = 360-angle;

		angle*=1000;
		angle+=0.5;
		angle = floor(angle);
		angle/=1000;
		
		printf("%.3lf\n", angle);
	}
	
	
	return 0;
}