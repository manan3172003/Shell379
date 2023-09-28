#ifndef HELPERS_H
#define HELPERS_H

#include "runner.h"
#include "processtable.h"


void kill(pid_t prc_id, ProcessTable & table);
void wait(pid_t prc_id, ProcessTable & table);
void custom(vector<string> com_args, ProcessTable * table);

#endif