#include <iostream>
using namespace std;

class Process{
    public:
    
    Process(pid_t pid);

    int getUserTime();

    int getSysTime();

    int getUserTimeTotal();

    int getSysTimeTotal();

    char* getActive();

    void setActive(char* active );


    ~Process();


    private:

    pid_t pid;
    int user_time;
    int sys_time;
    char * active;
};