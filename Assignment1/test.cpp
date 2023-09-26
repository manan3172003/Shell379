#include <string>
#include <iostream>
#include "process.h"
#include "processtable.h"
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <vector>
#include <chrono>
#define LINE_LENGTH 100 // Max # of characters in an input line
#define MAX_ARGS 7 // Max number of arguments to a command
#define MAX_LENGTH 20 // Max # of characters in an argument
#define MAX_PT_ENTRIES 32 // Max entries in the Process Table


using namespace std;

int runner() {
    // Get the current time point
    auto start = chrono::high_resolution_clock::now();

    cout << "Program started." <<endl;

    while (true) {
        // Get the current time point in the loop
        auto now = chrono::high_resolution_clock::now();

        // Calculate the duration between start and now
        auto duration = chrono::duration_cast<chrono::seconds>(now - start);

        // Break the loop if the duration is 10 seconds or more
        if (duration.count() >= 10) {
            break;
        }
    }

    cout << "Program ended after 10 seconds." <<endl;

    return 0;
}

int main(int argc, char *argv[]) {
    pid_t prc = fork();
    ProcessTable table = ProcessTable();
    if (prc != 0){
        cout << "parent_id: " << getpid() << endl;
        Process process = Process(prc, "new");
        table.insertProcess(process);

        sleep(15);
        table.printProcesses();
        
    } else {
        runner();
        cout << "child_id: " <<getpid()<< endl;
    }   


    return 0;
}

// int main(int argc, char *argv[]) {
//     while(1) {
//         string incommand;
//         cout << "shell379: ";
//         getline(cin, incommand);
//         // cout << incommand << endl;
//         vector<string> com_args = vector<string>();
//         string temp = "";
        
//         for (char i: incommand) {
//             if (i == ' ' || i == '\n'){
//                 com_args.push_back(temp);
//                 temp = "";
//             }
//             else {
//                 temp += i;
//             }
//         }
//         bool lenarg_check = false;

//         for (string i: com_args) {
//             cout << i << endl;
//             if (i.length() > MAX_LENGTH){
//                 lenarg_check = true;
//             }
//         }

//         if (incommand.compare("exit") == 0){
//             /*
//             Code to wait for all processes to finish
//             */

//             break;
//         } else if (incommand.compare("jobs") == 0){
//             /*
//             Code for jobs command
//             */
//         } else if (incommand.compare("kill") == 0){
//             /*
//             Code for kill command
//             */
//         } else if (incommand.compare("wait") == 0){
//             /*
//             Code for wait command
//             */
//         } else{
//             /*
//             Code for other
//             */
//         }

//     }

//     return 0;
// }