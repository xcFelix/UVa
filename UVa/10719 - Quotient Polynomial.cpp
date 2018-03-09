#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	int k;
	while(cin>>k)
	{
		cin.get();
		string s;
		getline(cin, s);
		stringstream ss(s);
		
		int t;
		vector<int> v1;
		while(ss>>t) v1.push_back(t);
		
		vector<int> v2;
		v2.push_back(v1[0]);
		
		for(int i = 1; i<v1.size(); ++i)
		{
			t = v2.back()*-k;
			t = v1[i]-t;
			v2.push_back(t);
		}
		
		cout<<"q(x):";
		for(int i = 0; i<v2.size()-1; ++i)
		{
			cout<<' '<<v2[i];
		}
		cout<<endl<<"r = "<<v2.back()<<endl<<endl;
	}

	
	return 0;
}