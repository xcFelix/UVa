#include <iostream>
#include <string>
#include <map>
using namespace std;

map<char, char> mp;

bool is_palindrome(const string& s)
{
	int lo = 0;
	int hi = s.size()-1;
	
	while(lo<=hi) if(s[lo++]!=s[hi--]) return false;
	return true;
}

bool is_mirrored(const string& s)
{
	int lo = 0;
	int hi = s.size()-1;
	
	while(lo<=hi) if(mp[s[lo++]]!=s[hi--]) return false;
	return true;
	
	return true;
}

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	//map<char, int> mp;
	mp['A'] = 'A';
	mp['E'] = '3'; mp['3'] = 'E';
	mp['H'] = 'H';
	mp['I'] = 'I';
	mp['J'] = 'L'; mp['L'] = 'J';
	mp['M'] = 'M';
	mp['O'] = 'O';
	mp['S'] = '2'; mp['2'] = 'S';
	mp['T'] = 'T';
	mp['U'] = 'U';
	mp['V'] = 'V';
	mp['W'] = 'W';
	mp['X'] = 'X';
	mp['Y'] = 'Y';
	mp['Z'] = '5'; mp['5'] = 'Z';
	mp['1'] = '1';
	mp['8'] = '8';
	
	string s;
	while(cin>>s)
	{
		cout<<s<<" -- ";
		
		bool _palindrome = is_palindrome(s);
		bool _mirrored = is_mirrored(s);
		
		if(_palindrome && _mirrored) cout<<"is a mirrored palindrome."<<endl;
		else if(_palindrome) cout<<"is a regular palindrome."<<endl;
		else if(_mirrored) cout<<"is a mirrored string."<<endl;
		else cout<<"is not a palindrome."<<endl;
		cout<<endl;
	}
	
	
	return 0;
}