#include <iostream>
using namespace std;

bool ok;

int T_sum(int sum, const int& des)
{
	char ch;
	cin>>ch;
	int n;
	if(cin>>n)
	{
		sum+=n;
		int l = T_sum(sum, des);
		int r = T_sum(sum, des);
		
		if(l==0 && r==0 && !ok) ok = (sum==des);
		cin>>ch;
		
		return 1;
	}
	else
	{
		cin.clear();
		cin>>ch;
		return 0;
	}
}

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int des;
	while(cin>>des)
	{
		ok = false;
		T_sum(0, des);
		
		if(ok) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	
	
	return 0;
}