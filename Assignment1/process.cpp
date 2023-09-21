#include <iostream>
#include "process.h"
using namespace std;

Process::Process(pid_t pid){
    Process::pid = pid;
    Process::active = new char('R');
}


char* Process::getActive(){
    return active;
}

void Process::setActive(char* active) {
    Process::active = active;
}


int Process::getSysTimeTotal(){
    return sys_time;
}

int Process::getUserTimeTotal(){
    return user_time;
}
Process::~Process(){
    delete Process::active;
    cout << Process::active;
}
