#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	map<char, char> mp;
	mp['0'] = '0'; mp['1'] = '1'; mp['2'] = '2'; mp['3'] = '3'; mp['4'] = '4'; mp['5'] = '5';
	mp['6'] = '6'; mp['7'] = '7'; mp['8'] = '8'; mp['9'] = '9';
	mp['A'] = '2';mp['B'] = '2';mp['C'] = '2';
	mp['D'] = '3';mp['E'] = '3';mp['F'] = '3';
	mp['G'] = '4';mp['H'] = '4';mp['I'] = '4';
	mp['J'] = '5';mp['K'] = '5';mp['L'] = '5';
	mp['M'] = '6';mp['N'] = '6';mp['O'] = '6';
	mp['P'] = '7';mp['R'] = '7';mp['S'] = '7';
	mp['T'] = '8';mp['U'] = '8';mp['V'] = '8';
	mp['W'] = '9';mp['X'] = '9';mp['Y'] = '9';
	
	int N;
	cin>>N;
	while(N--)
	{
		vector<string> v;
		
		int n;
		cin>>n;
		while(n--)
		{
			string s1, s2;
			cin>>s1;
			for(int i = 0; i<s1.size(); ++i)
			{
				if(isalnum(s1[i])) s2.push_back(mp[s1[i]]);
				if(s2.size()==3) s2.push_back('-');
			}
			
			v.push_back(s2);
		}
	
		sort(v.begin(), v.end());
		v.push_back("###-####");
		
		bool dup = true;
		int sum;
		for(int i = 0; i<v.size()-1; ++i)
		{
			sum = 0;
			for(int j = i+1; j<v.size(); ++j)
			{
				if(v[j]!=v[i])
				{
					if(sum)
					{
						cout<<v[i]<<' '<<++sum<<endl;
						break;
					}
					break;
				}
				++sum;
				++i;
				dup = false;
			}
		}
		
		if(dup) cout<<"No duplicates."<<endl;
		if(N) cout<<endl;
	}
	
	
	return 0;
}