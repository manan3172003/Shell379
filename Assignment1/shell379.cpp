#include <string>
#include <iostream>
#include "processtable.h"

using namespace std;

int main(int argc, char *argv[]) {
    while(1) {
        string incommand;
        getline(cin, incommand);

        if (incommand.compare("exit") == 0){
            /*
            Code to wait for all processes to finish
            */

            break;
        } else if (incommand.compare("jobs") == 0){
            /*
            Code for jobs command
            */
        } else if (incommand.compare("kill") == 0){
            /*
            Code for kill command
            */
        } else if (incommand.compare("wait") == 0){
            /*
            Code for wait command
            */
        } else{
            /*
            Code for other
            */
        }

    }

    return 0;
}