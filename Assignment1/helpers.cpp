#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include "processtable.h"
#include "helpers.h"
#include <cstring>
#include <string>

void kill(pid_t prc_id, ProcessTable & table) {
    if ((table.contains(prc_id)) && (prc_id > 0)){
        kill(prc_id, SIGCONT);
        kill(prc_id, SIGTERM);
        waitpid(prc_id, NULL, 0);
        kill(prc_id, SIGKILL);
        table.removeProcess(prc_id);
    } else {
        cout << endl << "Incorrect <pid>" << endl;
    }

}

void suspend(pid_t prc_id, ProcessTable & table){
    if ((table.contains(prc_id)) && (prc_id > 0)){
        kill(prc_id, SIGSTOP);
        (table.getProcess(prc_id)).setActive('S');
    } else {
        cout << endl << "Incorrect <pid>" << endl;
    }
}

void resume(pid_t prc_id, ProcessTable & table){
    if ((table.contains(prc_id)) && (prc_id > 0)){
        kill(prc_id, SIGCONT);
        (table.getProcess(prc_id)).setActive('R');
    } else {
        cout << endl << "Incorrect <pid>" << endl;
    }
}

void wait(pid_t prc_id, ProcessTable & table) {
    if ((table.contains(prc_id)) && (prc_id > 0)){
        waitpid(prc_id, NULL, 0);
        table.removeProcess(prc_id);
    } else {
        cout << endl << "Incorrect <pid>" << endl;
    }
}

void custom(vector<string> com_args, ProcessTable * table) {
    pid_t prc_id = fork();

    if (prc_id == 0){
        /* Convert to process (child) */

        bool redirect_o = false;
        bool redirect_i = false;

        int output_index = 0;
        int input_index = 0;
        

        char *args[com_args.size() + 1];
        for (long unsigned int i = 0; i < com_args.size(); i++) {
            if (com_args[i][0] == '<'){
                redirect_i = true;
                input_index = i;
            } else if (com_args[i][0] == '>'){
                redirect_o = true;
                output_index = i;
            }
            args[i] = strdup(com_args[i].c_str());  // Allocate memory for each argument
        }
        args[com_args.size()] = nullptr;

        if (redirect_o) {
            char* filename = strdup(com_args[output_index].c_str());
            freopen(filename+1, "w", stdout);
            delete filename;
        }

        if (redirect_i) {
            char* filename = strdup(com_args[input_index].c_str());
            freopen(filename+1, "r", stdin);
            delete filename;
        }

        if (execvp(args[0], args) < 0) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }

    } else {
        /*Parent*/
        if (com_args.back().compare("&")){
            waitpid(prc_id, nullptr, 0);
        } else {
            Process process = Process(prc_id, com_args[0]);
            (*table).insertProcess(process);
        }
    }
}