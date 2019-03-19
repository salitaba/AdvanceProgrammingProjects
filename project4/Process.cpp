#include"Process.h"

#define PROCESSWITHID  "Process with pid = "
#define ADDED " added!"

Process::Process(int _id){
	id = _id;
}

void Process::addThread(int numberOfTimeSlice){
	Thread thread(_id = threads.size() + 1, numberOfTimeSlice);
	threads.push_back(&thread);
}

Thread* Process::getThread(int _id){
	return threads[id - 1];
}

void Process::showProcessAdded(){
	cout<< PROCESSWITHID << id << ADDED << endl;
}

int Process::getId(){
	return id;
}