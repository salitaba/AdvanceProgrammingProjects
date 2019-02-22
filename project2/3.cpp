#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

void solve_problem(vector<string>&);
void get_table(vector<string>&, int);
string int_to_string(int);
bool can_move(vector<string>&, vector<string>&, int, int);
bool check_and_move_toward(vector<string>&, vector<string>&, int, int, int);
bool update_table_and_continue(vector<string>&,vector<string>&, int, int, int, int, int, int, char);
bool check_and_print_the_valid_moves(vector<string> &, vector<string>&);




int main(){
	int h,w;
	cin>>h>>w;
	vector<string>map;
	get_table(map, h);
	solve_problem(map);
	return 0;
}


void solve_problem(vector<string>& map){
	vector<string>moves;
	if(check_and_print_the_valid_moves(map,moves)==false){
		cout<<"Bad map configuration!"<<endl;
	}else{
		cout<<"Insane!"<<endl;
		for(int i=0;i<moves.size();i++){
			cout<<moves[i]<<endl;
		}
	}
}

void get_table(vector<string>& map, int h){
	string str;
	for(int i = 0;i < h;i++){
		cin>>str;
		map.push_back(str);
	}
}

string int_to_string(int num){
	string answer="";
	while(num>0){
		char now = num%10 + '0';
		answer = now + answer;
		num/=10;
	}
	return answer;
}

bool update_table_and_continue(vector<string>& map,vector<string>& moves, int i,int j,
		int adjacent_x,int adjacent_y,int target_x,int target_y,char directions_name){
	map[i][j]='#';
	map[adjacent_x][adjacent_y]='#';
	map[target_x][target_y]='o';
	string moves_now="";
	moves_now += int_to_string(i+1)+" " + int_to_string(j+1)+ " " + directions_name;
	moves.push_back(moves_now);
	if(check_and_print_the_valid_moves(map,moves))
		return 1;
	moves.pop_back();
	map[i][j]='o';
	map[adjacent_x][adjacent_y]='o';
	map[target_x][target_y]='#';
	return 0;
}
bool check_and_move_toward(vector<string>& map,vector<string>& moves ,int i,int j,int index_direction){
	int directions_x[] = {0, 0, 1, -1},
		directions_y[] = {1, -1, 0, 0};
	char directions_name[] = { 'R', 'L', 'D', 'U'};
	int a = directions_x[index_direction],
		b = directions_y[index_direction];
	int adjacent_x = i+a,
		adjacent_y = j+b,
		h = map.size(),
		w = map[i].size(),
		target_x = i+2*a,
		target_y = j+2*b;
	if(target_x<h && target_x>=0 && target_y<w && target_y>=0)
		if(map[adjacent_x][adjacent_y]=='o' && map[target_x][target_y]=='#')
			if(update_table_and_continue(map,moves,i,j,adjacent_x,adjacent_y,
				target_x,target_y,directions_name[index_direction]))
				return 1;
	return 0;
}

bool can_move(vector<string>& map,vector<string>& moves, int i,int j){
	for(int k = 0;k < 4;k++)
		if(check_and_move_toward(map,moves,i,j,k))
			return 1;
	return 0;
}

bool check_and_print_the_valid_moves(vector<string>& map,vector<string>& moves){
	int cnt_hero = 0;
	for(int i = 0;i < map.size();i++)
		for(int j = 0;j < map[i].size();j++)
			if(map[i][j] == 'o'){
				if(can_move(map,moves,i,j))
					return 1;
				cnt_hero++;
			}
	if(cnt_hero == 1)
		return 1;
	return 0;
}