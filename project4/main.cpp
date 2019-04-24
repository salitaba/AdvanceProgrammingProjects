#include<iostream>
#include<string>
#include<vector>

#include"Manager.h"

typedef vector< Process* > Processes;

using namespace std;
int main(){
	Cpu cpu;
	Cpu* cpuAddress = &cpu;
	Processes processes;
	string command;
	while(getline(cin, command))
		doCommand(command, cpuAddress, processes);
}