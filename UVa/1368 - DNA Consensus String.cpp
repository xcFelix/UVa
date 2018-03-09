#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

const int N = 4;
int arr[N];

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	map<char, int> mp;
	mp['A'] = 0;
	mp['C'] = 1;
	mp['G'] = 2;
	mp['T'] = 3;
	
	map<int, char> mp2;
	mp2[0] = 'A';
	mp2[1] = 'C';
	mp2[2] = 'G';
	mp2[3] = 'T';
	
	int n;
	cin>>n;
	while(n--)
	{
		int a, b;
		cin>>a>>b;
		
		vector<string> v;
		
		string s;
		for(int i = 0; i<a; ++i)
		{
			cin>>s;
			v.push_back(s);
		}
		
		int sum = 0;
		for(int i = 0; i<b; ++i)
		{
			memset(arr, 0, sizeof(arr));
			
			for(int j = 0; j<v.size(); ++j) arr[mp[v[j][i]]]++;
			
			int index = max_element(arr, arr+N) - arr;
			s[i] = mp2[index];
			
			sum = accumulate(arr, arr+N, sum);
			sum-=arr[index];
		}
		
		cout<<s<<endl;
		cout<<sum<<endl;
	}
	
	
	return 0;
}