#include<iostream>
#include<vector>
#include<string>
#include<queue>

#include"Thread.h"
using namespace std;
class Core{
public:
	Core(int _id);
	void addThread(Thread* thread);
	void processOneSliceTime();	
	bool isEmpty();
	int getNumberOfThread();
	void showStat();
	void logDoThread(Thread* thread);
	void printLog();
	bool haveLog();
private:
	int id;
	queue< string > logs;
	queue<Thread*> threads;
};