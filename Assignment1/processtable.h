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

    void removeProcess(Process process);

    void printProcesses();

    bool isEmpty();

    ~ProcessTable();

    private:
    vector<Process> processes;
};

#endif