#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include "runner.h"
#include "processtable.h"
#include "helpers.h"

void kill(pid_t prc_id, ProcessTable & table) {

}

void wait(pid_t prc_id, ProcessTable & table) {

}

void custom(vector<string> com_args, ProcessTable * table) {
    pid_t prc_id = fork();

    if (prc_id == 0){
        /*Convert to process (child)*/
        // execve();
        execve("./runner", NULL, NULL);
        _exit(0);

    } else {
        /*Parent*/
        if (com_args.back().compare("&")){
            wait(0);
        } else {
            Process process = Process(prc_id, com_args[0]);
            (*table).insertProcess(process);
            //message?
        }
    }
}