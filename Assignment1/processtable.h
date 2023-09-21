#include <iostream>
#include "process.h"
#include <vector>
using namespace std;

class ProcessTable {
    public:
    ProcessTable();

    void insertProcess(Process process);

    void removeProcess(Process process);

    ~ProcessTable();

    private:
    vector<Process> processes;
};