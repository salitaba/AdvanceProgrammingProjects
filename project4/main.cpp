#include<iostream>

#include"Cpu.h"
#include"Manager.h"

typedef vector< Process* > Processes;

using namespace std;
int main(){
	Cpu cpu;
	Processes processes;
	string command;
	while(get_line(cin, command))
		doCommand(command, cpu, processes);
}