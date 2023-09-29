#ifndef PROCESSTABLE_H
#define PROCESSTABLE_H

#include <iostream>
#include "process.h"
#include <vector>
using namespace std;

class ProcessTable {
    public:
    ProcessTable();

    void insertProcess(Process process);

    void removeProcess(pid_t process);

    void printProcesses();

    void clearProcesses();

    bool isEmpty();

    void waitAll();

    ~ProcessTable();

    private:
    vector<Process> processes;
};

#endif