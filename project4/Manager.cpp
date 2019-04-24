#include"Manager.h"

#define ADDCORE "add_core"
#define ADDPROCESS "add_process"
#define RUNCORES "run_cores"
#define SHOWCORESSTAT "show_cores_stat"
#define FINISHTASKS "finish_tasks"

bool isNumber(char c){
	return (c >= '0' && c <= '9');
}
vector<int> convertToNumber(string command){
	int index = 0, number = 0;
	vector<int> numbers;
	while(index < command.size()){
		while(index < command.size() && !(isNumber(command[index])))
			index++;
		number = 0;
		while(index < command.size() && isNumber(command[index])){
			number = number * 10 + command[index] - '0';
			index++;
		}
		numbers.push_back(number);
	}
	return numbers;
}

void addProcess(string command, Cpu* cpu, Processes& processes){
	int numberOfProcess = processes.size();
	Process* newProcess = new Process(numberOfProcess + 1);
	processes.push_back( newProcess );
	vector<int> numbers = convertToNumber(command);
	for(int i = 1;i < numbers.size();i++){
		processes.back()->addThread(numbers[i]);
		Thread* newThread = processes.back()->getThread(i);
		Core* coreWithMimTask = cpu->getCoreWithMinTask();
		coreWithMimTask->addThread(newThread);
	}
}

string getTopWord(string line){
	int indexOfFirstSpace = line.find_first_of(' ');
	return line.substr(0, indexOfFirstSpace);
}

void doCommand(string command, Cpu* cpu, Processes& processes){
	string masterCommand = getTopWord(command);
	if(masterCommand == ADDCORE){
		cpu->addCore();
		cpu->showCoreAdded();
	}
	else if(masterCommand == ADDPROCESS){
		addProcess(command, cpu, processes);
		processes.back()->showProcessAdded();
	}
	else if(masterCommand == SHOWCORESSTAT){
		cpu->showCoresStat();
	}
	else if(masterCommand == RUNCORES){
		cpu->runCores();
		cpu->showTaskDone();
	}
	else if(masterCommand == FINISHTASKS){
		cpu->finishTasks();
		cpu->showFinishingCore();
	}
	else 
		abort();

}