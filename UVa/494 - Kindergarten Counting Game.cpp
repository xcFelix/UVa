#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);


	string s;
	while(getline(cin, s))
	{
		s.push_back('#');
		int sum = 0;
		for(int i = 0; i<s.size()-1; ++i)
		{
			if(isalpha(s[i]) && !isalpha(s[i+1]))
			{
				++sum;
				++i;
			}
		}
		
		cout<<sum<<endl;
	}
	
	return 0;
}