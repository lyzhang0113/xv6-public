// Luoyan Zhang Feb 27 2023
#include "types.h"
#include "user.h"
#include "date.h"

int
main(int argc, char *argv[])
{
  struct rtcdate d;
  date(&d);
  printf(1, "%d/%d/%d %d:%d:%d\n", d.month, d.day, d.year, d.hour, d.minute, d.second);
  exit();
}

