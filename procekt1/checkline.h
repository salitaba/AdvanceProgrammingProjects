#include<iostream>
#include<string>
#include<map>

using namespace std;

int check_syntax_error(string line ,vector<int>& input , vector<int>& output 
 	, int& counter_of_input_readed,  map<string,int>& values , 
 	vector<int>& variables){   // rerurn 0 if code is ok , return 2 if code has sysntax error

	int state = 0  //  0 means ok , 2 means syntax_error
	line = delete_spaces_from_top(line);
	if(line.size()==0) return 0; // this line is ok
	if(line[0]=='?'){
		line = delete_one_sentence_from_top(line);
		line = delete_spaces_from_top(line);
		string now = get_one_sentence_from_top(line,values,variables);
		if(is_name(now)==false)
			return 2;
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
		string now = get_one_sentence_from_top(line,values,variables);
		if(is_name(now)==false)
			return 2;
		line = delete_one_sentence_from_top(line);
		line = delete_spaces_from_top(line);
		if(line.size() != 0 ) 
			return 2;
		output.push_back(values[now]);
		return 0;
	}else{
		

		string target = get_one_sentence_from_top(line,values,variables);

		if(is_name(target)==false)
			return 2; // this line has syntax error

		line = delete_one_sentence_from_top(line);
		line = delete_spaces_from_top(line);

		if(line.size()==0 || line[0] != '=')
			return 2; // this line has syntax error

		line = delete_one_sentence_from_top(line);
		line = delete_spaces_from_top(line);

		if(line.size()==0)
			return 2; //this line has syntax error 

		int pre_state = 0 	// 0 means first sentence , 
							// 1 means the first statement or addition befor it
							// -1 means Subtraction befor the statement 
		while(line.size()){
			string now = get_one_sentence_from_top(line,values,variables);
			if(is_name(now)==false)
				return 2 ; // invalid input 

			line = delete_one_sentence_from_top(line);
			line = delete_spaces_from_top(line);

			values[target] += var_to_int(now,values,variables) * pre_state; 
			if(pre_state == 0) 
				values[target] = var_to_int(now,values,variables);
			if(line.size()){
				if(line[0]=='+')
					pre_state = 1;
				else if(line[0]=='-')
					pre_state = -1;
				else 
					return 2; // invalid syntax 
				line = delete_one_sentence_from_top(line);
				line = delete_spaces_from_top(line);
			}
		}
		return 0;
	}
}