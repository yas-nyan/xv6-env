#ifndef _PROCINFO_H_INCLUDED_
#define _PROCINFO_H_INCLUDED_

#include "types.h"
#define PROC_NAME_LENGTH 16 

struct procinfo {
  int pid;
  int ppid;
  int state;
  int sz;
  char name[PROC_NAME_LENGTH];
};

#endif // _PROCINFO_H_INCLUDED_
