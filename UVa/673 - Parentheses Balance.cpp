#include <iostream>
#include <vector>
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
		if(s.size()%2)
		{
			cout<<"No"<<endl;
			continue;
		}
		
		vector<char> v;
		v.push_back('#');
		for(int i = 0; i<s.size(); ++i)
		{
			if(s[i]==v.back()+1 || s[i]==v.back()+2) v.pop_back();
			else v.push_back(s[i]);
		}
		
		if(v.size()==1) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	
	
	return 0;
}