#include <iostream>
#include <sys/resource.h>

#include "processtable.h"
using namespace std;

ProcessTable::ProcessTable(){

}

void ProcessTable::insertProcess(Process process){
    this->processes.push_back(process);
}

void ProcessTable::removeProcess(Process process){
    int counter = 0;
    for (Process i: this->processes){
        if (i.getpid() == process.getpid()){
            break;
        }
        counter++;
    }

    this->processes.erase((this->processes).begin()+counter);
}

bool ProcessTable::isEmpty(){
    if ((this->processes).size() == 0){
        return true;
    } else {
        return false;
    }
}

void ProcessTable::printProcesses(){
    cout << "Running processes:" << endl;

    if (!(isEmpty())) {
        cout << " #      PID S SEC COMMAND" << endl;
    }
    int counter = 0;
    int active_counter = 0;
    for (Process process: processes){
        printf("%2d: %7d %c %3d ",
                    counter,
                    process.getpid(),
                    process.getActive(),
                    process.getTime());
        cout << process.getCommand() << endl;
        counter++;
        if ((process.getActive()) == 'R'){
            active_counter++;
        }

    }

    printf("Processes = %7d active\n", active_counter);

    cout << "Completed processes:" << endl;
    struct rusage usage{};
    getrusage(RUSAGE_CHILDREN, &usage);

    printf("User time = %7d seconds\n", (int) usage.ru_utime.tv_sec);
    printf("Sys  time = %7d seconds\n\n", (int) usage.ru_stime.tv_sec);

}

ProcessTable::~ProcessTable(){
    
}