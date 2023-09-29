#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include "runner.h"
#include "processtable.h"
#include "helpers.h"

void kill(pid_t prc_id, ProcessTable & table) {
    if ((table.contains(prc_id)) && (prc_id > 0)){
        kill(prc_id, SIGCONT);
        kill(prc_id, SIGTERM);
        waitpid(prc_id, NULL, NULL);
        kill(prc_id, SIGKILL);
        table.removeProcess(prc_id);
    } else {
        cout << endl << "Incorrect <pid>" << endl;
    }

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
        }
    }
}