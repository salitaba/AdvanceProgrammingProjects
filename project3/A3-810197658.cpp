#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>

#define startDayTime 14
#define endDayTime 41
#define sepratorCharacter ','
#define starterBox "+---------"
#define insideBox "----------"
#define endBox "---------+"
#define beginnerDay 0
#define endDay 7
#define saturday "Saturday"
#define sunday "Sunday"
#define monday "Monday"
#define tuesday "Tuesday"
#define wednesday "Wednesday"
#define thursday "Thursday"
#define friday "Friday"
#define starterTitleInfo "# "
#define starterDayInfo "## "
#define sat "SAT"
#define sun "SUN"
#define mon "MON"
#define tue "TUE"
#define wed "WED"
#define thu "THU"
#define fri "FRI"
#define leftAndRightBorder '|'
using namespace std;

typedef string CourseId;
typedef string CourseName;
typedef vector< vector<string> > Table;

struct CourseTime{
    string id, code, name;
    vector<string>day, startTime, endTime;
    string giveCode(){
        string answer = code;
        if(code[0] == '0')
            answer = code[1];
        return answer;
    }
};


void addCourseToCourseName(string course, map<CourseId, CourseName>& courseName){
    string id,name;
    int index = 0;
    while(course[index] != sepratorCharacter){
        id += course[index];
        index++;
    }
    index++;
    while(index < course.size()){
        name += course[index];
        index++;
    }
    courseName[id] = name;
}


void inputFromFile(string fileName, vector<string>& lines){
    ifstream fileStream;
    fileStream.open(fileName);
    string str="";
    while(getline(fileStream, str)){
        lines.push_back(str);
    }
    fileStream.close();
}

void PushDataToCourseName(string fileName, map<string,string>& courseName){
    vector<string>courses;
    inputFromFile(fileName, courses);
    for(auto thisCourse : courses){
        addCourseToCourseName(thisCourse, courseName);
    }
}

void getWordFromIndex(string& line, int& index, string& word){
    word = "";
    while(index < line.size() && line[index] != ' ' && line[index] != '-'){
        word += line[index];
        index++;
    }
    index++;
}

void getTime(string& line,int& index,CourseTime& nowCourse){
    while(index < line.size()){
        string day, startTime, endTime;
        getWordFromIndex(line, index, day);
        getWordFromIndex(line, index, startTime);
        getWordFromIndex(line, index, endTime);
        nowCourse.day.push_back(day);
        nowCourse.startTime.push_back(startTime);
        nowCourse.endTime.push_back(endTime);
    }
}

void parseToCourseTime(vector<CourseTime>& courseTime, map<CourseId, CourseName>& courseName, vector<string>& lines){
    for(auto thisLine : lines){
        int index = 0;
        CourseTime nowCourse;
        getWordFromIndex(thisLine, index, nowCourse.id);
        nowCourse.name = courseName[nowCourse.id];
        getWordFromIndex(thisLine, index, nowCourse.code);
        getTime(thisLine, index, nowCourse);
        courseTime.push_back(nowCourse);
    }
}

void printTitle(string title){
    cout<<starterTitleInfo;
    for(int index = 0;index < title.size();index++)
        cout<<title[index];
    cout<<endl<<endl;
}

void printInformationDay(int day){
    string dayName[] = { saturday, sunday, monday, tuesday, wednesday, thursday, friday};
    cout<<starterDayInfo<<dayName[day]<<endl<<endl;
    for(int i = 7;i <= 20;i++){
        printf("%02d:00     ",i);
        printf("%02d:30",i);
        if(i != 20)
            cout<<"     ";
    }
    cout<<endl;
    for(int i = 0;i < 275;i++)
        cout<<'_';
    cout<<endl;
}

int getIdDay(string day){
    string dayName[] = { sat, sun, mon, tue, wed, thu, fri};
    for(int dayNum = beginnerDay;dayNum < endDay; dayNum++){
        if(day == dayName[dayNum])
            return dayNum;
    }
}

int getIdTime(string nowTime){
    int id = (nowTime[0]-'0')*10 + (nowTime[1]-'0');
    id *= 2;
    id += (nowTime[3] == '3');
    return id;
}
bool checkCanAdd(vector<string>& line, int startIdTime, int endIdTime){
    bool couresCanAdd = true;
    for(int houreId = startIdTime ;houreId < endIdTime;houreId++)
        if(line[houreId] != ""){
            couresCanAdd = false;
            break;
        }
    return couresCanAdd;

}

void pushCourseNameToTable(Table& tableTime, CourseTime courseTime, int index){
    int startIdTime = getIdTime(courseTime.startTime[index]),
        endIdTime = getIdTime(courseTime.endTime[index]), 
        lineIndex = tableTime.size()-1;
    while(lineIndex >=0 && checkCanAdd(tableTime[lineIndex], startIdTime, endIdTime))
        lineIndex--;
    if(lineIndex == tableTime.size()-1)
        tableTime.push_back(vector<string>(100));
    lineIndex++;
    for(int houreId = startIdTime ; houreId < endIdTime ; houreId++)
        tableTime[lineIndex][houreId] = courseTime.name + " (" + courseTime.giveCode() + ")" ;
}

void createTable(Table& tableTime, vector<CourseTime>& courseTime, int day){
    for(auto course:courseTime)
        for(int index = 0 ;index < course.day.size();index++)
            if(getIdDay(course.day[index]) == day)
               pushCourseNameToTable(tableTime, course, index);
}

string ignorExtraSpace(string str){
    int index = str.size() - 1;
    while(index >= 0 && str[index] == ' ')
        index--;
    index++;
    str.erase(index);
    return str;
}

void printBorder(vector<string>& line){
    string answer = ""; 
    answer += "  ";
    for(int index = startDayTime ; index <= endDayTime ; index ++){
        if(line[index] != ""){
            if(index == startDayTime || line[index-1] != line[index])
                answer += starterBox;
            else if(index == endDayTime || line[index+1] != line[index])
                answer += endBox;
            else
                answer += insideBox;
        }else if(index != endDayTime)
            answer += "          ";
        else
            answer += "   ";
    }
    answer = ignorExtraSpace(answer);
    cout<<answer;
}
string getStringCourseName(int sizeContent, string courseName){
    string answer = "";
    int numberWhiteSpace = sizeContent - courseName.size()-2;
    answer += leftAndRightBorder;
    for(int i = 0 ;i < (numberWhiteSpace + 1) / 2;i++)
        answer += " ";
    answer += courseName;
    for(int i = 0;i < numberWhiteSpace / 2 ;i++)
        answer += " ";
    answer += leftAndRightBorder;
    return answer ;
}

void printContent(vector<string>& line){
    string answer = "";
    answer += "  ";
    for(int index = startDayTime;index < endDayTime;index++){
        if(line[index] == ""){
            answer += "          ";
        }else{
            int startCourseTime = index;
            while(index+1 <= endDayTime && line[index+1] == line[index])
                index++;
            int endCourseTime = index;
            int sizeContent = (endCourseTime - startCourseTime + 1)*10;
            answer += getStringCourseName(sizeContent, line[index]);
        }
    }
    answer +="   ";
    answer = ignorExtraSpace(answer);
    cout<<answer<<endl;

}
void printDayCourse(Table& tableTime, int day){
    for(auto line : tableTime){
        printBorder(line);
        cout<<endl;
        printContent(line);
        printBorder(line);
        cout<<endl;
    }
}
void printTable(vector<CourseTime>& courseTime, string title){
    printTitle(title);
    for(int day = beginnerDay;day < endDay;day++){
        printInformationDay(day);
        Table tableTime;
        createTable(tableTime, courseTime, day);
        printDayCourse(tableTime,day);
        cout<<endl;
    }
}

void inputCourseTime(vector<CourseTime>& courseTime, map<CourseId, CourseName>& courseName){
    vector<string>linesInput;
    string line;
    while(getline(cin,line)){
        linesInput.push_back(line);
    }
    parseToCourseTime(courseTime, courseName, linesInput);
}

int main(int argc , char *argv[]){
    string fileName = argv[1], title = argv[2];
    map<CourseId, CourseName> courseName;
    vector<CourseTime>courseTime;
    PushDataToCourseName(fileName, courseName);
    inputCourseTime(courseTime, courseName);
    printTable(courseTime, title);
    return 0;
}