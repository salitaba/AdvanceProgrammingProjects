#include<iostream>
#include<string>
#include<vector>
#include"Core.h"
using namespace std;
class Cpu
{
public:
	Core* getCore(int id);
	int getNumberOfCore();
	void addCore();
	void showCoresStat();
	void showCoreAdded();
	void runCores();
	Core* getCoreWithMinTask();
	void showTaskDone();
	void finishTasks();
	void showFinishingCore();
private:
	vector< Core* > cores;
};