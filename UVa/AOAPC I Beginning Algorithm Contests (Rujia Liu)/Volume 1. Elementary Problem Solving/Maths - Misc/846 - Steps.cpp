#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	int t;
	cin>>t;
	while(t--)
	{
		int a, b;
		cin>>a>>b;
		int d = b-a;
		
		int n = (sqrt(1+4*d)-1)/2;
		int dx = d-n*(n+1); //�Ȳ�����֮�� 
		
		if(dx>n+1) cout<<2*n+2<<endl; //һ���������� 
		else if(dx) cout<<2*n+1<<endl; //һ�����Բ��� 
		else cout<<2*n<<endl; //���貹�� 
	}
	
	
	return 0;
}