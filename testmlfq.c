// Luoyan Zhang Apr 13 2023
#include "types.h"
#include "user.h"

#define NUM_CHILDS 10
#define SLEEP_TIME 1
#define LOOP_ITER  2000000000

int
main(void)
{
  for(int i = 0; i < NUM_CHILDS; i++) {
    int pid = fork();
    if (pid == 0) {
      // child
      renice(getpid(), getpid() % 3);
      sleep(SLEEP_TIME);
      for(int j = 0; j < LOOP_ITER; j++) {} // do nothing
      //printf(1, "Process %d with priority %d finished.\n", getpid(), getpid() % 3);
      exit();
    }
  }

  for(int i = 0; i < NUM_CHILDS; i++) {
    int pid = wait();
    printf(1, "PID: %d Exited with Priority %d\r\n", pid, pid % 3);
  }

  exit();
}
