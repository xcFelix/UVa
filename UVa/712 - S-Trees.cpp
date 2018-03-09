#include <iostream>
#include <string>
using namespace std;

const int N = 259;
const int M = 9;
int order[M];
char arr[N];

int exp[10] = { 1 };

void cal_exp()
{
	for(int i = 1; i<=8; ++i) exp[i] = exp[i-1]*2;
}

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	cal_exp();
	
	int sum_case = 0;
	int n;
	while(cin>>n && n)
	{
		cin.get();
		
		string s;
		getline(cin, s);
		for(int i = 1, j = 0; i<s.size(); i+=3) order[j++] = s[i]-'1';
		
		getline(cin, s);
		int index = exp[n];
		for(int i = 0; i<s.size(); ++i) arr[index++] = s[i];
		
		string res;
		
		int m;
		cin>>m;
		while(m--)
		{
			cin>>s;
			index = 1;
			
			for(int i = 0; i<s.size(); ++i)
			{
				if(s[order[i]]=='0') index*=2;
				else index = index*2+1;
			}
			
			res+=arr[index];
		}
		
		cout<<"S-Tree #"<<++sum_case<<':'<<endl;
		cout<<res<<endl<<endl;
	}
	
	
	return 0;
}