#include"Core.h"

#define CORENUMBER "Core number : "
#define PROCESSID "Process ID : "
#define THREADID " - Thread ID : "
Core::Core(int _id){
	id = _id;
}

void Core::addThread(Thread* thread){
	threads.push(thread);
}

void Core::logDoThread(Thread* thread){
	string log = PROCESSID + to_string(thread->getProcessId()) + THREADID;
	log += to_string(thread->getId());
	logs.push(log);
}

void Core::processOneSliceTime(){
	if(threads.size()){
		Thread* thread = threads.front();
		this->logDoThread(thread);
		thread->doOneTimeSlice();
		threads.pop();
		if(thread->getNumberOfTimeSlice() > 0)
			threads.push(thread);
	}
}

bool Core::isEmpty(){
	return threads.size() == 0 ;
}

int Core::getNumberOfThread(){
	return threads.size();
}

void Core::showStat(){
	cout<< CORENUMBER << id << endl;
	for(auto thread : threads)
		thread->showStat();

}

void Core::printLog(){
	if(logs.size()){
		cout<< CORENUMBER << id << endl;
		cout<< log.front();
		logs.pop();
	}
}