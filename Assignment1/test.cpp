#include <string>
#include <iostream>
#include "process.h"
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>


using namespace std;

int main(int argc, char *argv[]) {
    pid_t prc = fork();

    if (prc != 0){
        Process process = Process(prc);
        cout << process.getActive() << endl;
        process.setActive(new char('S'));
        cout << process.getActive() << endl;
        cout << "child_id: " << getpid() << endl;
    } else {
        cout << "parent_id: " << getpid() << endl;
    }   


    return 0;
}