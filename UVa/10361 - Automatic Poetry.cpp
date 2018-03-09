#include <iostream>
#include <string>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int n;
	cin>>n;
	cin.get();
	while(n--)
	{
		string s1, s2;
		getline(cin, s1);
		getline(cin, s2);
		
		for(int i = 0; i<s1.size(); ++i)
		{
			if(s1[i]!='<' && s1[i]!='>') cout<<s1[i];
		}
		cout<<endl;
		
		for(int i = 0; i<s2.size(); ++i)
		{
			if(s2[i]!='.') cout<<s2[i];
		}
		
		int f1 = s1.find('<');
		int f2 = s1.find('>');
		int f3 = s1.rfind('<');
		int f4 = s1.rfind('>');
		
		for(int i = f3+1; i<f4; ++i) cout<<s1[i];
		for(int i = f2+1; i<f3; ++i) cout<<s1[i];
		for(int i = f1+1; i<f2; ++i) cout<<s1[i];
		for(int i = f4+1; i<s1.size(); ++i) cout<<s1[i];
		cout<<endl;
	}
	
	
	return 0;
}