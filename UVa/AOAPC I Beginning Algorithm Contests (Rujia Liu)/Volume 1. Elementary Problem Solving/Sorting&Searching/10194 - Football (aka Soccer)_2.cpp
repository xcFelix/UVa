#include <iostream>
#include <string>
#include <map>
#include <set>
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
	
	T(const string& _name = "")	//map[]需要  
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
	
		map<string, T> mp;
		int team;
		cin>>team;
		cin.get();
		while(team--)
		{
			string s;
			getline(cin, s);
			mp[s] = T(s);
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
			
			mp[s2].game_played++; mp[s3].game_played++;
			mp[s2].goals_scored+=a; mp[s2].goals_against+=b;
			mp[s3].goals_scored+=b; mp[s3].goals_against+=a;
			if(a==b) { mp[s2].ties++; mp[s3].ties++; }
			else if(a>b) { mp[s2].wins++; mp[s3].losses++; }
			else { mp[s2].losses++; mp[s3].wins++; }
		}
		
		set<T> st;
		for(map<string, T>::iterator it = mp.begin(); it!=mp.end(); ++it)
		{
			it->second.cal_goal_difference().cal_points();
			st.insert(it->second);
		}
		
		int i = 0;
		for(set<T>::iterator it = st.begin(); it!=st.end(); ++it)
		{
			printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", ++i, it->name.c_str(), it->points, it->game_played,
			it->wins, it->ties, it->losses, it->goal_difference, it->goals_scored, it->goals_against);
		}
		
		if(N) cout<<endl;
	}

	
	return 0;
}