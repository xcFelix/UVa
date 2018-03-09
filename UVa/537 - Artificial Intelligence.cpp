#include <iostream>
#include <cstdio>
#include <sstream>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int n;
	cin>>n;
	cin.get();
	int sum_case = 0;
	while(n--)
	{
		cout<<"Problem #"<<++sum_case<<endl;
		
		string s;
		getline(cin, s);
		
		bool P = false, U = false, I = false;
		double PP, UU, II, temp;
		char c;
		
		int index = s.find('=');
		stringstream ss(s.substr(index+1));
		ss>>temp>>c;
		if(c=='m') temp/=1000;
		else if(c=='k') temp*=1000;
		else if(c=='M') temp*=1e6;
		
		c = s[index-1];
		if(c=='P')
		{
			P = true;
			PP = temp;
		}
		else if(c=='U')
		{
			U = true;
			UU = temp;
		}
		else
		{
			I = true;
			II = temp;
		}
		
		
		index = s.rfind('=');
		ss.str(s.substr(index+1));
		ss>>temp>>c;
		if(c=='m') temp/=1000;
		else if(c=='k') temp*=1000;
		else if(c=='M') temp*=1e6;
		
		c = s[index-1];
		if(c=='P')
		{
			P = true;
			PP = temp;
		}
		else if(c=='U')
		{
			U = true;
			UU = temp;
		}
		else
		{
			I = true;
			II = temp;
		}
		
		if(P==false) printf("P=%.2lfW\n\n", UU*II);
		else if(U==false) printf("U=%.2lfV\n\n", PP/II);
		else printf("I=%.2lfA\n\n", PP/UU);
	}
	
	
	return 0;
}