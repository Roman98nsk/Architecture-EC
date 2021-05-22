#include "myBigChars.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

int main() {

  mt_clrscr();
  bc_box(0, 4, 10, 9);

  int bc_2 = open("bc_2.bin", O_WRONLY);

  int big_2[2] = {33717760, 131646};

  int cnt;
  bc_bigcharwrite(bc_2, big_2, 1);
  bc_bigcharread(bc_2, big_2, 1, &cnt);

  bc_setbigcharpos(big_2, 7, 7, 1);

  bc_printbigchar(big_2, 2, 5, cl_red, cl_black);
  printf("\n\n");
  mt_gotoXY(0, 20);

  return 0;
}
