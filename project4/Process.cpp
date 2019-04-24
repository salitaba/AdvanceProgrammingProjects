#include"Process.h"

#define PROCESSWITHID  "Process with pid = "
#define ADDED " added!"

Process::Process(int _id){
	id = _id;
}

void Process::addThread(int numberOfTimeSlice){
	Thread* thread = new Thread(threads.size() + 1, numberOfTimeSlice, id);
	threads.push_back(thread);
}

Thread* Process::getThread(int _id){
	return threads[_id - 1];
}

void Process::showProcessAdded(){
	cout<< PROCESSWITHID << id << ADDED << endl;
}

int Process::getId(){
	return id;
}