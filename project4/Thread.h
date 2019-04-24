#ifndef THREAD_H
#define THREAD_H
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Thread
{
public:
	Thread(int _id, int numberOfTimeSlice,int _processId);
	int getProcessId();
	int getId();
	int getNumberOfTimeSlice();
	void doOneTimeSlice();
	void showStat();
private:
	int numberOfTimeSlice, id, processId;
};

#endif