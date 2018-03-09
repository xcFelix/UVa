#include <iostream>
#include <string>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);


	string s;
	while(cin>>s)
	{
		for(int i = 0; i<s.size(); ++i) cout<<(char)(s[i]-7);
		cout<<endl;
	}
	
	return 0;
}