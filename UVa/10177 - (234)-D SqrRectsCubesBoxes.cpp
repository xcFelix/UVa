#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int n;
	while(cin>>n)
	{
		long long S2, R2, S3, R3, S4, R4;
		
		S2 = n*(n+1)*(2*n+1)/6;
		S3 = pow(n*(n+1)/2, 2);
		S4 = (6*pow(n, 5)+10*pow(n, 3)+15*pow(n, 4)-n)/30;
		
		R2 = pow(n*(n+1)/2, 2);
		R3 = pow(n*(n+1)/2, 3);
		R4 = pow(n*(n+1)/2, 4);
		
		cout<<S2<<' '<<R2-S2<<' '<<S3<<' '<<R3-S3<<' '<<S4<<' '<<R4-S4<<endl;
	}

	
	return 0;
}