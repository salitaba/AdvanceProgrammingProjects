#include"Manager.h"
bool isNumber(char c){
	return (command[index] >= '0' && command[index] <= '9');
}
vector<int> covertToNumber(string command){
	int index = 0, number = 0;
	vector<int> numbers;
	while(index < command.size()){
		while(!(isNumber(command[index])) && index < command.size() )
			index++;
		number = 0;
		while(isNumber(command[index] && index < command.size())){
			number = number * 10 + command[index] - '0';
			index++;
		}
		numbers.push_back(number);
	}
}

void addProcess(string command, Cpu& cpu, Processes& processes){
	int numberOfProcess = processes.size();
	processes.push_back( &Process(_id = numberOfProcess + 1 ));
	vector<int> numbers = covertToNumber(command);
	for(int i = 1;i < numbers.size();i++){
		processes.back()->addThread(numberOfTimeSlice = numbers[i]);
		Thread* newThread = processes.back()->getThread(_id = i);
		Core* coreWithMimTask = cpu->getCoreWithMinTask();
		coreWithMimTask->addThread(newThread);
	}
}

string getTopWord(string line){
	int indexOfFirstSpace = line.find_fist_of(' ');
	return line.substr(0, indexOfFirstSpace);
}

void doCommand(string command, Cpu& cpu, Processes& processes){
	srting masterCommand = getTopWord(command);

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
	else if(command == RUNCORES){
		cpu->runCores();
		cpu->showTaskDone();
	}
	else if(command == FINISHTASKS){
		cpu->finishTasks();
		cpu->showFinishingCore();
	}
	else 
		abort();

}