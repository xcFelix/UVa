#include <iostream>
#include <sstream>
#include <map>
using namespace std;

const int M = 10009;
int in[M];
int post[M];

struct T{
	int data;
	T *l, *r;
	
	T(const int& _data = 0, T *_l = 0, T *_r = 0)
	: data(_data), l(_l), r(_r) {}
};

T* Tree(const int* in, const int* post, int len)
{
	if(len==0) return NULL;
	
	int i = --len;
	while(in[i]!=post[len]) --i;
	
	T* root = new T(in[i]);
	root->l = Tree(in, post, i);
	root->r = Tree(in+i+1, post+i, len-i);
	
	return root;
}

void dfs(T* root, int sum, map<int, int>& mp)
{
	if(root->l==0 && root->r==0)
	{
		mp[sum+root->data] = root->data;
		return;
	}
	
	if(root->l) dfs(root->l, sum+root->data, mp);
	if(root->r) dfs(root->r, sum+root->data, mp);
}

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	string s;
	while(getline(cin, s))
	{
		int len = 0;
		stringstream ss(s);
		while(ss>>in[len]) ++len;
		
		getline(cin, s);
		ss.clear(); //зЂвт!!!!!!!!!!!!
		ss.str(s);
		
		len = 0;
		while(ss>>post[len]) ++len;
		
		T* root = Tree(in, post, len);
		
		map<int, int> mp;
		dfs(root, 0, mp);
		
		cout<<mp.begin()->second<<endl;
	}
	
	
	return 0;
}