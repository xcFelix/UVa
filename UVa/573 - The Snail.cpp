#include <iostream>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	double H, U, D, F;
	while(cin>>H>>U>>D>>F && H!=0)
	{
		F*=.01;
		F*=U;
		
		double sum = .0;
		int days = 0;
		while(sum<=H && sum>=0)
		{
			++days;
			
			if(U>=0) sum+=U;
			U-=F;
			if(sum>H) break;
			
			sum-=D;
			if(sum<0) break;
		}
		
		if(sum>H) cout<<"success on day "<<days<<endl;
		else cout<<"failure on day "<<days<<endl;
	}

	
	return 0;
}