#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;

bool is_latin_char(char now){
	if(now>='a' && now<='z')
		return true;
	if(now>='A' && now<='Z') 
		return true;
	return false;
}

bool is_num(string now){
	for(int i=0;i<now.size();i++)
		if(!(now[i]>='0' && now[i]<='9'))
			return false;
	return true;
}
int str_to_int(string str){
	int num=0;
	for(int i=0;i<str.size();i++){
		num*=10;
		num+=str[i]-'0';
	}
	return num;

}
bool is_digit(char now){
	if(now>='0' && now<='9') 
		return true;
	return false;
}

bool is_name(string s){
	if(s.size()==0) return false;
	for(int i=0;i<s.size();i++){
		int mark = 0;
		if(is_latin_char(s[i])) mark = 1;
		if(is_digit(s[i]) && i!=0) mark = 1;
		if(mark==0) return false;
	}
	return true;
}

string delete_spaces_from_top(string now){
	int pos = 0;
	while(pos<now.size() && now[pos]==' '){
		pos++;
	}
	string answer = &now[pos];
	return answer;
}

string get_one_sentence_from_top(string now){
	if(now.size() == 0) return now ;
	string answer = "";
	int pos = 0; 
	if(is_latin_char(now[0])){
		while(pos<now.size() && (is_latin_char(now[pos]) || is_digit(now[pos]))){
			answer += now[pos];
			pos++;
		}
	}else if(is_digit(now[0])){
		while(pos<now.size() && is_digit(now[pos])){
			answer += now[pos];
			pos++;
		}
	}else{
		answer = now[0];
	}
	return answer;
}

void add_var_to_vec(string now , map<string,int>& values , vector<string>& variables ){
	for(int i=0;i<variables.size();i++){
		if(variables[i]==now)
			return;
	}
	if(is_name(now))
		variables.push_back(now);
	values[now]=0;
}
string delete_one_sentence_from_top(string now){
	int pos = 0 ;
	string sentence = get_one_sentence_from_top(now);
	string answer = &now[sentence.size()];
	return answer;
}
int var_to_int(string now , map<string,int>& values , vector<string>variables ){
	if(is_name(now))
		return values[now];
	else{
		int answer = 0;
		for(int i=0;i<now.size();i++){
			answer*=10;
			answer+=now[i]-'0';
		}
		return answer;
	}
}

string get_line_from_string(string now){
	int pos = 0;
	string answer = "";
	while(pos<now.size() && now[pos]!='\n'){		
		answer +=now[pos];
		pos++;
	}
	return answer;
}
string remove_line_from_string(string now){
	int pos = 0;
	while(pos<now.size() && now[pos]!='\n'){
		pos++;
	}
	if(now[pos]=='\n')
		pos++;
	now = &(now[pos]);
	return now;
}

int check_syntax_error(string line ,vector<int>& input , vector<int>& output 
 	, int& counter_of_input_readed,  map<string,int>& values , 
 	vector<string>& variables){   
	int state = false ;
	line = delete_spaces_from_top(line);
	if(line.size()==0) return 0; 
	if(line[0]=='?'){
		line = delete_one_sentence_from_top(line);
		line = delete_spaces_from_top(line);
		string now = get_one_sentence_from_top(line);
		if(is_name(now)==false)
			return 2;
		add_var_to_vec(now,values,variables);
		
		line = delete_one_sentence_from_top(line);
		line = delete_spaces_from_top(line);
		
		if(line.size() != 0)
			return 2;
		
		if(counter_of_input_readed == input.size())
			return 1;
		values[now]=input[counter_of_input_readed];
		counter_of_input_readed++;
		return 0;
	}else if(line[0]=='!'){
		line = delete_one_sentence_from_top(line);
		line = delete_spaces_from_top(line);
		string now = get_one_sentence_from_top(line);
		add_var_to_vec(now,values,variables);
		
		if(is_name(now)==false)
			return 2;
		line = delete_one_sentence_from_top(line);
		line = delete_spaces_from_top(line);
		if(line.size() != 0 ) 
			return 2;
		output.push_back(var_to_int(now,values,variables));
		return 0;
	}else{
		

		string target = get_one_sentence_from_top(line);
		int sum = 0;
		if(is_name(target)==false)
			return 2; 
		add_var_to_vec(target,values,variables);
		
		line = delete_one_sentence_from_top(line);
		line = delete_spaces_from_top(line);

		if(line.size()==0 || line[0] != '=')
			return 2; 

		line = delete_one_sentence_from_top(line);
		line = delete_spaces_from_top(line);

		if(line.size()==0)
			return 2; 

		int pre_state = 0; 	

		while(line.size()){
		
			string now = get_one_sentence_from_top(line);
			add_var_to_vec(now,values,variables);
			if(!(is_name(now) || is_num(now)))
				return 2 ;  
		

			line = delete_one_sentence_from_top(line);
			line = delete_spaces_from_top(line);

			sum += var_to_int(now,values,variables) * pre_state; 
		
			if(pre_state == 0) 
				sum = var_to_int(now,values,variables);
		
			if(line.size()){
		

				if(line[0]=='+')
					pre_state = 1;
				else if(line[0]=='-')
					pre_state = -1;
				else 
					return 2; 
		

				line = delete_one_sentence_from_top(line);
				line = delete_spaces_from_top(line);
			}
			
		}
		values[target]=sum;
		return 0;
	}
}



int main(){
	
	map<string,int>values;			
	vector<string>variables;		
	string line="",total="";		
	vector<int>input;				
	vector<int>output;  			
	int state = 0 ;    				
	int counter_of_input_readed = 0;
	int line_counter = 1;

	while(getline(cin,line)){    
		line=delete_spaces_from_top(line);
		if(get_one_sentence_from_top(line) == "run")
			break;
		
		if(total.size())
			total=total+"\n"+line;
		else
			total=line;
	}
	while(getline(cin,line)){		
		
		line = delete_spaces_from_top(line);
		line = get_one_sentence_from_top(line);
		input.push_back(var_to_int(line,values,variables));			
	}
	
	while(total.size()){
		line = get_line_from_string(total);
	
		int now_state = check_syntax_error(line,input,output,counter_of_input_readed,
			values,variables); 
		if(now_state == 2){
			cout<<"Syntax error at line "<<line_counter<<endl;
			return 0;
		}else if(now_state == 1){   
			state = 1;
			break;   
		}
		line_counter++;
		total = remove_line_from_string(total);
	}

	for(int i=0;i<output.size();i++){
		cout<<output[i]<<endl;
	}
	if(state == 1){
		cout<<"Unexpected end of input"<<endl;
	}


	return 0;

}
	
