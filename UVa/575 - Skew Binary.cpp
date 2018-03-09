#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int arr[39] ={ 1, 2 };

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);


	for(int i = 2; i<=31; ++i) arr[i] = arr[i-1]*2;
	for(int i = 1; i<=31; ++i) --arr[i];
	
	string s;
	while(cin>>s && !(s.size()==1 && s[0]=='0'))
	{
		int sum = 0;
		reverse(s.begin(), s.end());
		for(int i = 0; i<s.size(); ++i) sum+=(s[i]-'0')*arr[i+1];
		cout<<sum<<endl;
	}
	
	return 0;
}