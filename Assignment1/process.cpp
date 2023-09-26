#include <iostream>
#include <sys/times.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iterator>
#include <fstream>
#include <sstream>
#include <vector>
#include "process.h"
using namespace std;

Process::Process(pid_t pid, string command){
    this->pid = pid;
    this->active = 'R';
    this->command = command;
}


char Process::getActive(){
    return active;
}

void Process::setActive(char active) {
    this->active = active;
}


// int Process::getSysUserTime(){

//     ifstream statFile;
//     statFile.open("/proc/"+std::to_string(this->pid)+"/stat");
    
//     string line;
//     getline(statFile, line);

//     cout << line << endl;

//     statFile.close();
    
//     return 0;

// }

pid_t Process::getpid() {
    return this->pid;
}

string Process::getCommand(){
    return this->command;
}

int Process::getTime(){
    int process_time;
    char buffer[100];
    FILE *fp;

    sprintf(buffer, "ps -p %d -o times=", this->pid);
    fp = popen(buffer, "r");
    fscanf(fp, "%d", &process_time);
    pclose(fp);

    return process_time;
}

Process::~Process(){
}
