#include "procinfo.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"


int
main(void)
{
  enum procstate {UNUSED, EMBRYO, SLEEPING, RUNNABLE, RUNNING, ZOMBIE};
  
  static char *states[] = {
    [UNUSED]        "UNUSED",
    [EMBRYO]        "EMBRYO",
    [SLEEPING]      "SLEEPING",
    [RUNNABLE]      "RUNNABLE",
    [RUNNING]       "RUNNING",
    [ZOMBIE]        "ZOMBIE",
  };

  struct procinfo procinfo_table[NPROC];
  int numbers = getprocs(procinfo_table);

  for (int i = 0; i < numbers; i++) {
    if (procinfo_table[i].state == UNUSED)
        continue;

    printf(1, "%d %d", procinfo_table[i].pid, procinfo_table[i].ppid);
    printf(1, " %s %s", states[procinfo_table[i].state], procinfo_table[i].name); 
    printf(1, " %d", procinfo_table[i].sz);
    printf(1, "\n");
  }

  exit();
}
