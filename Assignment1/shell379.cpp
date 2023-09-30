#include <string>
#include <iostream>
#include "helpers.h"
#include <sys/wait.h>
#include <vector>
#include "processtable.h"

using namespace std;
#define LINE_LENGTH 100 // Max # of characters in an input line
#define MAX_ARGS 7 // Max number of arguments to a command
#define MAX_LENGTH 20 // Max # of characters in an argument
#define MAX_PT_ENTRIES 32 // Max entries in the Process Table

int main(int argc, char *argv[]) {
    ProcessTable table = ProcessTable();
    while(1) {
        table.cleanUp();
        string incommand;
        cout << "Shell379:";
        getline(cin, incommand);
        incommand+= " ";
        vector<string> com_args = vector<string>();
        string temp = "";
        
        for (string::iterator i = incommand.begin(); i != incommand.end(); i++) {
            if (*i == ' '){
                com_args.push_back(temp);
                temp = "";
            }
            else {
                temp += *i;
            }
        }
        bool lenarg_check = false;

        for (string i: com_args) {
            if (i.length() > MAX_LENGTH){
                lenarg_check = true;
            }
        }

        if ((com_args.size() > MAX_ARGS) || (incommand.length() > LINE_LENGTH) || (lenarg_check)) {
            cout << "Incorrect arguments";
        } else{
            if (com_args[0].compare("exit") == 0){
                table.waitAll();
                break;
            } else if (com_args[0].compare("jobs") == 0){
                table.printProcesses();
            } else if (com_args[0].compare("kill") == 0){

                if (com_args.size() != 2) {
                    cout << "Incorrect args";
                } else{
                    pid_t prc_id = stoi(com_args[1]);
                    kill(prc_id, table);
                }
                
            } else if (com_args[0].compare("wait") == 0){
                if (com_args.size() != 2) {
                    cout << "Incorrect args";
                } else{
                    pid_t prc_id = stoi(com_args[1]);
                    wait(prc_id, table);
                }
            } else if (com_args[0].compare("suspend") == 0){
                if (com_args.size() != 2) {
                    cout << "Incorrect args";
                } else{
                    pid_t prc_id = stoi(com_args[1]);
                    suspend(prc_id, table);
                }
            } else if (com_args[0].compare("resume") == 0){
                if (com_args.size() != 2) {
                    cout << "Incorrect args";
                } else{
                    pid_t prc_id = stoi(com_args[1]);
                    resume(prc_id, table);
                }
            }else{
                custom(com_args, &table);
            }
        }
    }
    return 0;
}