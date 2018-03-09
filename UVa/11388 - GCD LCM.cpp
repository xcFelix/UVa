//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main()
{
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	
	int T;
	cin>>T; 
	while(T--)
	{
		int a, b;
		cin>>a>>b;
		if(b%a) cout<<"-1"<<endl;
		else cout<<a<<" "<<b<<endl;
	}
	
	
	return 0;
}