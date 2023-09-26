#ifndef PROCESS_H
#define PROCESS_H

using namespace std;

class Process{
    public:
    
    Process(pid_t pid, string command);

    int getSysUserTime();

    char getActive();

    void setActive(char active );

    pid_t getpid();

    string getCommand();

    int getTime();

    ~Process();


    private:

    pid_t pid;
    char active;
    string command;
};


#endif