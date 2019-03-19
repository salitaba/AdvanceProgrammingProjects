#include<iostraem>
#include<vector>
#include<string>
#include"thread.h"
using namespace std;
class Core{
private:
	Core(int _id);
	void addThread(Thread* thread);
	void processOneSliceTime();	
	bool isEmpty();
	int getNumberOfThread();
	void showStat();
	void logDoThread(Thread* thread);
	void printLog();

public:
	int id;
	queue< string > logs;
	queue< Thread* > threads;
};
