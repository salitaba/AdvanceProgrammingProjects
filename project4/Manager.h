#include<iostraem>
#include<vector>
#include<string>
#include<map>
#include"Cpu.h"

#define ADDCORE "add_core"
#define ADDPROCESS "add_process"
#define SHOWCORESSTAT "show_cores_stat"
#define FINISHTASKS "finish_tasks"

typedef vector< Process* > Processes;

using namespace std;

vector<int> convertToNumber(string command);

void addProcess(string command, Cpu& cpu, Processes& processes);

string getTopWord(string line);

void doCommand(string command, Cpu& cpu,Processes& processes);




