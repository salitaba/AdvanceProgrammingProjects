#include"Thread.h"

#define PROCESSID "Process ID : "
#define THREADID " - Thread ID : "
#define NUMBEROFTIMESLICE " Number of time slots : "
int Thread::getProcessId(){
	return process->getId();
}

int Thread::getId(){
	return id;
}

int Thread::getNumberOfSliceTime(){
	return numberOfSliceTime;
}

void Thread::doOneSliceTime(){
	numberOfSliceTime--;
}

void Thread::showStat(){
	cout<< PROCESSID << this->getProcessId() << THREADID << id << endl;
	cout<< NUMBEROFTIMESLICE << numberOfSliceTime << endl;
}