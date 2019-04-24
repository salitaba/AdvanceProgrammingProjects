#include"Thread.h"

#define PROCESSID "Process ID : "
#define THREADID " - Thread ID : "
#define NUMBEROFTIMESLICE "Number of time slots : "

Thread::Thread(int _id, int _numberOfTimeSlice, int _processId){
	id = _id;
	numberOfTimeSlice = _numberOfTimeSlice;
	processId = _processId;
}

int Thread::getProcessId(){
	return processId;
}

int Thread::getId(){
	return id;
}

int Thread::getNumberOfTimeSlice(){
	return numberOfTimeSlice;
}

void Thread::doOneTimeSlice(){
	numberOfTimeSlice--;
}

void Thread::showStat(){
	cout<< PROCESSID << this->getProcessId() << THREADID << id << endl;
	cout<< NUMBEROFTIMESLICE << numberOfTimeSlice << endl;
}