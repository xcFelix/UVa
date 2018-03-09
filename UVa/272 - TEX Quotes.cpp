#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <cctype>
#include <algorithm>
#include <limits>
#include <sstream>
using namespace std;

string base[] = { "``", "''" };

int main()
{
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
	
	
	int i = 0;
	string s;
	while(getline(cin, s))
	{
		int index = 0;
		while((index = s.find("\"", index))!=string::npos) s.replace(index, 1, base[i++%2]);
		
		cout<<s<<endl;
	}
	
	
	return 0;
}