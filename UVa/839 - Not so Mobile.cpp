#include <iostream>
using namespace std;

int T_sum(int sum)
{
	int a, b, c, d;
	cin>>a>>b>>c>>d;
	
	int l, r;
	if(a) l = (-b+sum)*a;
	else l = T_sum(-b+sum);
	
	if(c) r = (d+sum)*c;
	else r = T_sum(d+sum);
	
	return l+r;
}

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int n;
	cin>>n;
	while(n--)
	{
		if(T_sum(0)==0) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
		if(n) cout<<endl;
	}
	
	
	return 0;
}