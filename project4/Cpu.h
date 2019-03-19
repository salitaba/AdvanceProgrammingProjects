#include<iostream>
#include<string>
#include<vector>
#include"Core.h"
using namespace std;
class Cpu
{
private:
	Core* getCore(int id);
	int getNumberOfCore();
	void addCore();
	void showCoresStat();
	void showCoreAdded();
	Core* getCoreWithMinTask();
	void showTaskDone();
	void finishTasks();
	void showFinishingCore();
public:
	vector< Core* > cores;
};