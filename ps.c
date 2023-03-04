// Luoyan Zhang Feb 27 2023
#include "types.h"
#include "user.h"

int test(void) {
  int pid;
  
  // Child Sleep
  // By executing sleep()
  printf(1, "-----------------------------\n");
  printf(1, "Test: Create a Child in SLEEP\n");
  pid = fork();
  if (pid < 0) return -1;
  else if (pid == 0) {
    // child
    sleep(100);
    exit();
  } else {
    // parent
    ps();
    wait();
  }

  // Child Zombie
  // Child exited so fast before Parent tried to wait
  printf(1, "-----------------------------\n");
  printf(1, "Test: Create a Child in ZOMBIE\n");
  pid = fork();
  if (pid < 0) return -1;
  else if (pid == 0) {
    // child
    exit();
  } else {
    // parent
    ps();
    wait();
  }

  // Child Runnable
  // Child takes too long so the scheduler moved on to parent
  printf(1, "-----------------------------\n");
  printf(1, "Test: Create a Child in RUNNABLE\n");
  pid = fork();
  if (pid < 0) return -1;
  else if (pid == 0) {
    // child
    for(int i = 0; i < 3000000000; i++) ;
    exit();
  } else {
    // parent
    ps();
    wait();
  }

  return 0;
}

int main(int argc, char **argv) {
  //ps();
  test();
  exit();
}

