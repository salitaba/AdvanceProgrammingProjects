#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<vector>
#include<map>

#define line_separator "***"
#define word_file_name "words.txt"

using namespace std;

void mark_words_from_file(map<string,int>& word_available){
	ifstream inFile;
	inFile.open(word_file_name);
	string str;
	while(inFile>>str)
		word_available[str] = true;
	inFile.close();
}

void print_vector(vector<string>& vec){
	for(int i = 0;i < vec.size();i++)
		cout<<vec[i]<<" ";
	cout<<endl;
}
void print_all_valid_answers(map<string,int>& word_available, string& str, vector<string>& answer, int index = 0){
	if(index == str.size())
		print_vector(answer);
	string word_from_index="";
	for(int i = index;i < str.size();i++){
		word_from_index+=str[i];
		if(word_available[word_from_index]){
			answer.push_back(word_from_index);
			print_all_valid_answers(word_available, str, answer, i+1);
			answer.pop_back();
		}
	}
}


int main(){

	map<string,int>word_available;
	mark_words_from_file(word_available);

	string str;
	vector<string>answer;
	while(cin>>str){
		print_all_valid_answers(word_available, str, answer);
		cout<<line_separator<<endl;
	}
}