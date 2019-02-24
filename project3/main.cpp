#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

struct DataCourse{
    string courseId,courseName;
    DataCourse(string id, string name){
        courseId = id;
        courseName = name;
    }
};

DataCourse parseToDataCourse(string str){
    string courseId,courseName;
    int index = 0;
    while(str[index] != ','){
        courseId += str[index];
        index++;
    }
    index++;
    while(index < str.size()){
        courseName += str[index];
        index++;
    }
    return DataCourse(courseId,courseName);
}

void inputFromFile(string fileName, vector<string>& lines){
    ifstream fileStream;
    fileStream.open(fileName);
    string str="";
    while(getline(fileStream,str)){
        lines.push_back(str);
    }
}

void getDataPushToDataCourse(string fileName, vector<DataCourse>& dataCourse){
    vector<string>lines;
    inputFromFile(fileName,lines);
    for(auto thisLine:lines){
        dataCourse.push_back(parseToDataCourse(thisLine));    
    }
}

int main(int argc , char *argv[]){
    string fileName = argv[1];
    string titleName = argv[2];
    vector<DataCourse>dataCourse;
    getDataPushToDataCourse(fileName, dataCourse);
    for(auto data:dataCourse){
       cout<<data.courseId<<" "<<data.courseName<<endl;
    }
    return 0;
}