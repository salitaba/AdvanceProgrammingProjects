#include<iostream>
#include<string>
#include<vector>
#include"Thread.h"
using namespace std;

class Process
{
public:
	Process(int _id);
	void addThread( int numberOfsliceTime );
	Thread* getThread(int _id);
	void showProcessAdded();
	int getId();
private:
	int id;
	vector< Thread* > Threads;
};