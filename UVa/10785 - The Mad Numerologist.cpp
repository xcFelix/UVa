#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char vowel[] = "AUEOI";
char consonant[] = "JSBKTCLDMVNWFXGPYHQZR";
int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int sum_case = 0;
	int N;
	cin>>N;
	while(N--)
	{
		cout<<"Case "<<++sum_case<<": ";
		
		int n;
		cin>>n;
		
		vector<char>  v_vowel, v_consonant;
		int size_vowel, size_consonant;
		if(n%2) size_vowel = n/2+1;
		else size_vowel = n/2;
		size_consonant = n/2;
		
		int sum = 0;
		int index = 0;
		for(int i = 0; i<size_vowel; ++i)
		{
			v_vowel.push_back(vowel[index]);
			if(++sum%21==0) ++index;
		}
		
		sum = 0;
		index = 0;
		for(int i = 0; i<size_consonant; ++i)
		{
			v_consonant.push_back(consonant[index]);
			if(++sum%5==0) ++index;
		}
		
		sort(v_vowel.begin(), v_vowel.end());
		sort(v_consonant.begin(), v_consonant.end());
		
		for(int i = 0; i<size_vowel; ++i)
		{
			cout<<v_vowel[i];
			if(i<size_consonant) cout<<v_consonant[i];
		}
		cout<<endl;
	}
	
	
	return 0;
}