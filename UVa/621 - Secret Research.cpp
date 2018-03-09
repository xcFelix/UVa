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
		string s;
		getline(cin, s);
		if(s[s.size()-1]=='5') cout<<'-'<<endl;
		else if(s[0]=='9') cout<<'*'<<endl;
		else if(s[1]=='9') cout<<'?'<<endl;
		else cout<<'+'<<endl;
	}

	
	return 0;
}