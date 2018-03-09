#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cctype>
using namespace std;

struct T{
	string name;
	//int rank;
	int points;
	int game_played;
	int wins, ties, losses;
	int goal_difference;
	int goals_scored, goals_against;
	
	T(const string& _name)
	: name(_name), points(0), game_played(0), wins(0), ties(0), losses(0), goal_difference(0), goals_scored(0), goals_against(0) {}
	
	T& cal_points() { points = wins*3+ties; return *this; }
	T& cal_goal_difference() { goal_difference = goals_scored - goals_against; return *this; }
	
	bool operator<(const T& t) const
	{
		if(points!=t.points) return points>t.points;
		if(wins!=t.wins) return wins>t.wins;
		if(goal_difference!=t.goal_difference) return goal_difference>t.goal_difference;
		if(goals_scored!=t.goals_scored) return goals_scored>t.goals_scored;
		if(game_played!=t.game_played) return game_played<t.game_played;
		
		string s1(name);	//题目没有说清楚，不区分大小写
		string s2(t.name);
		for(int i = 0; i<s1.size(); ++i) s1[i] = tolower(s1[i]);
		for(int i = 0; i<s2.size(); ++i) s2[i] = tolower(s2[i]);
		return s1<s2;
	}
};

struct CMP{
	string name;
	CMP(const string& _name): name(_name) {}
	
	bool operator()(const T& t) const
	{
		return t.name==name;
	}
};

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int N;
	cin>>N;
	cin.get();
	while(N--)
	{
		string name;
		getline(cin, name);
		cout<<name<<endl;
	
		vector<T> v;
		int team;
		cin>>team;
		cin.get();
		while(team--)
		{
			string s;
			getline(cin, s);
			v.push_back(T(s));
		}
		
		int G;
		cin>>G;
		cin.get();
		while(G--)
		{
			string s;
			getline(cin, s);
			int l = s.find('#');
			int r = s.rfind('#');
			
			stringstream ss(s.substr(l+1, r-l));
			string s2(s, 0, l);
			string s3(s, r+1);
			
			int a, b;
			char ch;
			ss>>a>>ch>>b;
			
			vector<T>::iterator it1, it2;
			it1 = find_if(v.begin(), v.end(), CMP(s2));
			it2 = find_if(v.begin(), v.end(), CMP(s3));
			
			it1->game_played++; it2->game_played++;
			it1->goals_scored+=a; it1->goals_against+=b;
			it2->goals_scored+=b; it2->goals_against+=a;
			if(a==b) { it1->ties++; it2->ties++; }
			else if(a>b) { it1->wins++; it2->losses++; }
			else { it1->losses++; it2->wins++; }
		}
		
		for(int i = 0; i<v.size(); ++i)
		{
			v[i].cal_goal_difference().cal_points();
		}
		
		sort(v.begin(), v.end());
		for(int i = 0; i<v.size(); ++i)
		{
			printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", i+1, v[i].name.c_str(), v[i].points, v[i].game_played,
			v[i].wins, v[i].ties, v[i].losses, v[i].goal_difference, v[i].goals_scored, v[i].goals_against);
		}
		
		if(N) cout<<endl;
	}

	
	return 0;
}