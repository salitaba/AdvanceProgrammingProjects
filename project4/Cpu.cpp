#include"Cpu.h"

#define SUCCESSFULLYADDED " successfully added!"
#define COREWITHCOREID "Core with core ID = "
#define TIMESLICE "Time Slice : "
#define DOT '.'

Core* Cpu::getCore(int id){
	return cores[id + 1];
}

int Cpu::getNumberOfCore(){
	return cores.size();
}

void Cpu::addCore(){
	Core* core = new Core(cores.size() + 1);
	cores.push_back(core);
}

void Cpu::runCores(){
	for(auto core : cores)
		core->processOneSliceTime();
}

void Cpu::showCoresStat(){
	for(auto core : cores)
		core->showStat();
}

void Cpu::showCoreAdded(){
	int id = cores.size();
	cout << COREWITHCOREID << id << SUCCESSFULLYADDED <<endl;
}

Core* Cpu::getCoreWithMinTask(){
	Core* coreAnswer = NULL;
	for(auto core : cores)
		if(coreAnswer == NULL || core->getNumberOfThread() < coreAnswer->getNumberOfThread() )
			coreAnswer = core ;					
	return coreAnswer;
}

void Cpu::showTaskDone(){
	for(auto core : cores)
		core->printLog();
}

void Cpu::finishTasks(){
	bool finished = false; 
	while(!finished){
		finished = true; 
		for(auto core : cores){
			if(!core->isEmpty() ){
				finished = false;
				core->processOneSliceTime();
			}
		}
	}
}

void Cpu::showFinishingCore(){
	bool finished = false ;
	int timeSlice = 0;
	while(!finished){
		timeSlice++;
		finished = true; 
		for(auto core : cores)
			if(core->haveLog())
				finished = false;
		if(!finished){
			cout<< TIMESLICE << timeSlice << endl;
			for(auto core : cores)
				core->printLog();
		}
	}
}