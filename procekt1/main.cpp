#include<iostream>
#include<string>
#include<map>

#include"checkline.h"


using namespace std;
int main(){

	//initalize
	map<string,int>values;			
	vector<string>variables;		// values is the values of the code is stored
	string line="",total="";		// total is the total of code 
	vector<int>input;				// the numbers in input
	vector<int>output;  			// the output the program
	int state = 0    				// 0 means ok , 1 means input_error
	int counter_of_input_readed = 0;


	// reading ...
	while(getline(cin,line) && line!="run"){    // read and store the code
		total=total+"\n"+line;					//      ...
	}
	while(getline(cin,line)){					// read the inputs 
		input.push_back(str_to_int(line));			//   	...
	}
	
	// checking and running 
	while(total.size()){
		line = get_line_from_string(total);
		int now_state = check_syntax_error(line,input,output,counter_of_input_readed,
			values,variable);   // if return 0 it's ok , if return 1 it's Unexpected end of input , if return 2 it's Syntax error
		if(now_state == 2){
			cout<<"Syntax error at line"<<endl;
		}else if(now_state == 1){   // don't continue the running code
			state = 1;
			break;   
		}

		total = remove_line_from_string(total);
	}

	//print the output
	for(int i=0;i<output.size();i++){
		cout<<output[i]<<endl;
	}
	if(state == 1){
		cout<<"Unexpected end of input"<<endl;
	}


	return 0;

}
	
